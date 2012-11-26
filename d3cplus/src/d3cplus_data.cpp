#include <d3cplus_data.h>

#include <resources/include/parser.h>
#include <resources/include/qobjecthelper.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        // D3_Data part
        D3_Data::D3_Data( QObject* parent ) : QObject( parent ), m_strClassName( "D3_Data" ){}
        D3_Data::D3_Data( const D3_Data& _rD3_Data ) : QObject( _rD3_Data.parent() ), m_strClassName( "D3_Data" ){}
        D3_Data::~D3_Data(){}

        const QString& D3_Data::getType() const { return m_strClassName; }
        D3_Data& D3_Data::operator=( const D3_Data& _rD3_Data )
        {
            m_strClassName = _rD3_Data.getType();
            return *this;
        }
        bool D3_Data::operator==( const D3_Data& _rD3_Data )
        {
            return m_strClassName == _rD3_Data.getType();
        }
        //----------------------------------//

        //----------------------------------//
        // D3_Career
        D3_Career::D3_Career( QObject* parent ) : D3_Data( parent ){ m_strClassName = "D3_Career"; }
        D3_Career::D3_Career( const D3_Career& _rD3_Career ) : D3_Data( _rD3_Career.parent() )
        {
            m_strClassName  = "D3_Career";
        }
        D3_Career::~D3_Career(){}

        // setFunction
        void D3_Career::setHeroes( QVariant _lHeroes )
        {
            clearHero();
            foreach( QVariant vHero, _lHeroes.toList() )
            {
                D3_Hero* pHero = new D3_Hero();
                QJson::QObjectHelper::qvariant2qobject( vHero.toMap(), pHero );

                m_lpHeroes.push_back( pHero );
            }
        }
        void D3_Career::setBattleTag( const QString& _rstrBattleTag ){ m_strBattleTag = _rstrBattleTag; }

        // getFunction
        QVariant D3_Career::getHeroesAsQVariant() const
        {
            QList< QVariant > lHeroes;
            foreach( D3_Hero* pHero, m_lpHeroes )
            {
                lHeroes.push_back( QVariant::fromValue( *pHero) );
            }
            return QVariant::fromValue( lHeroes );
        }

        const QList< D3_Hero* >& D3_Career::getHeroes() const
        {
            return m_lpHeroes;
        }

        const QString& D3_Career::getBattleTag() const { return m_strBattleTag; }

        // tools
        bool D3_Career::isValid() const { return true; }
        QString D3_Career::toString() const
        {
            QString strReturn;
            strReturn   += m_strBattleTag + "; ";

            strReturn   += "size : " + QString::number( m_lpHeroes.size() ) + "{ ";
            foreach( D3_Hero* heroes, m_lpHeroes )
            {
                strReturn += heroes->toString() + ";";
            }
            strReturn   += " }";

            return strReturn;
        }

        D3_Career& D3_Career::operator=( const D3_Career& _rD3_Career )
        {
            Q_ASSERT( m_strClassName == _rD3_Career.getType() );
//            m_strName = _rD3_Career.getName();
            return *this;
        }
        bool D3_Career::operator==( const D3_Career& _rD3_Career )
        {
            return m_strClassName == _rD3_Career.getType();
        }

        void D3_Career::clearHero()
        {
            while( !m_lpHeroes.isEmpty() )
            {
                delete m_lpHeroes.last();
                m_lpHeroes.takeLast();
            }
        }

        //----------------------------------//

        //----------------------------------//
        // D3_Heroes
        D3_Hero::D3_Hero( QObject* parent ) : D3_Data( parent ){ m_strClassName = "D3_Heroes"; }
        D3_Hero::D3_Hero( const D3_Hero& _rD3_Heroes ) : D3_Data( _rD3_Heroes.parent() )
        {
            m_strClassName  = "D3_Heroes";
            m_strName       = _rD3_Heroes.getName();
        }
        D3_Hero::~D3_Hero(){}

        // setFunction
        void D3_Hero::setName( const QString& _rstrName ) { m_strName     = _rstrName; }
        void D3_Hero::setID( int _iID )                   { m_iID         = _iID; }
        void D3_Hero::setLevel( int _iLevel )             { m_iLevel      = _iLevel; }
        void D3_Hero::setHardcore( bool _bHardcore )      { m_bHardcore   = _bHardcore; }
        void D3_Hero::setParagonLvl( int _iParagonLvl )   { m_iParagonLvl = _iParagonLvl; }
        void D3_Hero::setGender( int _iGender )           { m_iGender     = _iGender; }
        void D3_Hero::setDead( bool _bDead )              { m_bDead       = _bDead; }
        void D3_Hero::setClass( const QString& _rstrClass ) { m_strClass  = _rstrClass; }
        void D3_Hero::setLastUpdate( int _iLastUpdated )  { m_iLastUpdated = _iLastUpdated; }

        // getFunction
        const QString& D3_Hero::getName() const { return m_strName; }
        int D3_Hero::getID() const { return m_iID; }
        int D3_Hero::getLevel() const { return m_iLevel; }
        bool D3_Hero::getHardcore() const { return m_bHardcore; }
        int D3_Hero::getParagonLvl() const { return m_iParagonLvl; }
        int D3_Hero::getGender() const { return m_iGender; }
        bool D3_Hero::getDead() const { return m_bDead; }
        const QString& D3_Hero::getClass() const { return m_strClass; }
        int D3_Hero::getLastUpdate() const { return m_iLastUpdated; }

        // tools
        bool D3_Hero::isValid() const { return m_iID > 0; }
        QString D3_Hero::toString() const
        {
            QString strReturn;
            strReturn += m_strName + "; ";
            strReturn += QString::number( m_iID ) + "; ";
            strReturn += QString::number( m_iLevel ) + "; ";
            strReturn += QString( ( m_bHardcore ? "Hardcore" : "Softcore" ) ) + "; ";
            strReturn += QString::number( m_iParagonLvl ) + "; ";
            strReturn += QString::number( m_iGender ) + "; ";
            strReturn += QString( ( m_bDead ? "Dead" : "Alive" ) ) + "; ";
            strReturn += m_strClass + "; ";
            strReturn += QString::number( m_iLastUpdated ) + "; ";

            return strReturn;
        }

        D3_Hero& D3_Hero::operator=( const D3_Hero& _rD3_Heroes )
        {
            Q_ASSERT( m_strClassName == _rD3_Heroes.getType() );
            m_strName = _rD3_Heroes.getName();
            return *this;
        }
        bool D3_Hero::operator==( const D3_Hero& _rD3_Heroes )
        {
            return m_strClassName == _rD3_Heroes.getName();
        }
        //----------------------------------//
    }
}

