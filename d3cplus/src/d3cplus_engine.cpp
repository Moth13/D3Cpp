#include <d3cplus_engine.h>

#include <resources/include/parser.h>
#include <resources/include/qobjecthelper.h>
#include <resources/include/serializer.h>

#include <d3cplus_data.h>

namespace d3cplus
{
    d3cplus_Engine::d3cplus_Engine()
        :   m_pNetworkManager   ( NULL )
    {

//        qRegisterMetaType<Data::D3_Hero>("d3cplus::Data::D3_Hero");

        m_pNetworkManager   = new QNetworkAccessManager( this );

        bool bIsConnected   = QObject::connect( m_pNetworkManager
                                                , SIGNAL( finished( QNetworkReply* ) )
                                                , this
                                                , SLOT( onNetworkManagerReply( QNetworkReply* ) )
                                                , Qt::UniqueConnection );

        Q_ASSERT( bIsConnected && "Network manager has been not successfully connected" );
    }

    d3cplus_Engine::~d3cplus_Engine()
    {
        delete m_pNetworkManager;
    }

    uint d3cplus_Engine::getCareerProfileFromBattleTag( const QString& _rstrBattleTag, uint _uiBattleNumber, eRegion _eRegion )
    {
        QString strRegion;
        switch( _eRegion )
        {
            case E_Reg_America :
                strRegion = "us";
            break;
            case E_Reg_Europe :
                strRegion = "eu";
            break;
            case E_Reg_Asia :
                strRegion = "asia";
            break;
            default :
            break;
        }

        QNetworkRequest request;
        QNetworkReply* pReply = NULL;

        request.setRawHeader( "Accept","application/json" );
        request.setUrl( QUrl( "http://"
                              + strRegion
                              + ".battle.net/api/d3/profile/"
                              + _rstrBattleTag + "-" + QString::number( _uiBattleNumber ) + "/" ) );


        qDebug() << strRegion
                    + ".battle.net/api/d3/profile/"
                    + _rstrBattleTag + "-" + QString::number( _uiBattleNumber ) + "/";

        pReply = m_pNetworkManager->get( request );

        uint uiQueryId = qHash( _rstrBattleTag + "-" + QString::number( _uiBattleNumber ) );
        m_mQuery.insert( pReply, PQT( uiQueryId, 0 ) );

        return uiQueryId;
    }

    uint d3cplus_Engine::getHeroesInfoFromBattleTag( const QString& _rstrHeroesName, const QString& _rstrBattleTag, uint _uiBattleNumber, eRegion _eRegion )
    {
        return 0;
    }

    void d3cplus_Engine::onNetworkManagerReply( QNetworkReply* _pReply )
    {
        qDebug() << "Received answer : "/* << _pReply->readAll()*/;

        PQT pairQueryType = m_mQuery[ _pReply ];
        QJson::Parser parser;
        bool bOk;
        switch( pairQueryType.second )
        {
            case 0 :
            {
                QVariant res = parser.parse( _pReply->readAll(), &bOk );
                if( bOk )
                {
                    Data::D3_Career* pCareer = new Data::D3_Career();
                    qv2o( res.toMap(), pCareer );
                    QJson::QObjectHelper::qvariant2qobject( res.toMap(), pCareer );
                    qDebug() << pCareer->toString();

                    qDebug( "parsing success" );

                    QVariantMap variant = QJson::QObjectHelper::qobject2qvariant( pCareer );
                    QJson::Serializer seria;
                    qDebug( "try to json" );
                    qDebug() << seria.serialize( variant );
                }
                else
                {
                    qDebug( "parsing failed" );
                }
            }
            break;
            default :
            break;
        }
    }

    void d3cplus_Engine::qv2o(const QVariantMap& variant, QObject* object)
    {
        const QMetaObject *metaobject = object->metaObject();

        QVariantMap::const_iterator iter;
        for( iter = variant.constBegin(); iter != variant.constEnd(); ++iter)
        {
            qDebug() << iter.key().toAscii();
            int pIdx = metaobject->indexOfProperty( iter.key().toAscii() );

            if ( pIdx < 0 )
            {
                continue;
            }

            QMetaProperty metaproperty = metaobject->property( pIdx );
            QVariant::Type type = metaproperty.type();
            qDebug() << "Type : " << type;
            QVariant v( iter.value() );
            if ( v.canConvert( type ) )
            {
                qDebug() << "Can convert1";
                v.convert( type );
                metaproperty.write( object, v );
            }
            else if (QString(QLatin1String("QVariant")).compare(QLatin1String(metaproperty.typeName())) == 0)
            {
                qDebug() << "Can convert2";
                metaproperty.write( object, v );
            }
            else
            {
                qDebug() << "Can't convert";
            }
        }
    }
}
