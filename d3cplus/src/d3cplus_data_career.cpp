#include <d3cplus_data_career.h>

#include <d3cplus_data_hero.h>
#include <d3cplus_data_artisan.h>
#include <d3cplus_data_progression.h>

#include <resources/include/parser.h>
#include <resources/include/qobjecthelper.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        D3_Career::D3_Career( QObject* parent )
            :   D3_Data                 ( parent )
            ,   m_pSoftcoreProgression  ( NULL )
            ,   m_pHardcoreProgression  ( NULL )
        {
            m_strClassName = "D3_Career";
        }

        D3_Career::D3_Career( const D3_Career& _rD3_Career )
            :   D3_Data                 ( _rD3_Career.parent() )
            ,   m_pSoftcoreProgression  ( NULL )
            ,   m_pHardcoreProgression  ( NULL )
        {
            m_strClassName  = "D3_Career";
        }

        D3_Career::~D3_Career()
        {
            clearHero();
            clearSoftcoreArtisans();
            clearHardcoreArtisans();

            delete m_pSoftcoreProgression;
            delete m_pHardcoreProgression;
        }
        //----------------------------------//

        //----------------------------------//
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

        void D3_Career::setSoftcoreArtisans( QVariant _lSoftcoreArtisans )
        {
            clearSoftcoreArtisans();
            foreach( QVariant vArtisan, _lSoftcoreArtisans.toList() )
            {
                D3_Artisan* pArtisan = new D3_Artisan();
                QJson::QObjectHelper::qvariant2qobject( vArtisan.toMap(), pArtisan );

                m_lpSoftcoreArtisans.push_back( pArtisan );
            }
        }

        void D3_Career::setHardcoreArtisans( QVariant _lHardcoreArtisans )
        {
            clearHardcoreArtisans();
            foreach( QVariant vArtisan, _lHardcoreArtisans.toList() )
            {
                D3_Artisan* pArtisan = new D3_Artisan();
                QJson::QObjectHelper::qvariant2qobject( vArtisan.toMap(), pArtisan );

                m_lpHardcoreArtisans.push_back( pArtisan );
            }
        }

        void D3_Career::setSoftcoreProgression( QVariant _lSoftcoreProgression )
        {
            if( NULL != m_pSoftcoreProgression )
            {
                delete m_pSoftcoreProgression;
            }

            m_pSoftcoreProgression = new D3_Progression();
            QJson::QObjectHelper::qvariant2qobject( _lSoftcoreProgression.toMap(), m_pSoftcoreProgression );
        }

        void D3_Career::setHardcoreProgression( QVariant _lHardcoreProgression )
        {
            if( NULL != m_pHardcoreProgression )
            {
                delete m_pHardcoreProgression;
            }

            m_pHardcoreProgression = new D3_Progression();
            QJson::QObjectHelper::qvariant2qobject( _lHardcoreProgression.toMap(), m_pHardcoreProgression );
        }

        //----------------------------------//

        //----------------------------------//
        // getFunction
        const QList< D3_Hero* >& D3_Career::getHeroes() const { return m_lpHeroes; }
        QVariant D3_Career::getHeroesAsQVariant() const
        {
            QList< QVariant > lHeroes;
            foreach( D3_Hero* pHero, m_lpHeroes )
            {
                lHeroes.push_back( QVariant::fromValue( *pHero) );
            }
            return QVariant::fromValue( lHeroes );
        }

        const QList< D3_Artisan* >& D3_Career::getSoftcoreArtisans() const { return m_lpSoftcoreArtisans; }
        QVariant D3_Career::getSoftcoreArtisansAsQVariant() const
        {
            QList< QVariant > lArtisans;
            foreach( D3_Artisan* pArtisan, m_lpSoftcoreArtisans )
            {
                lArtisans.push_back( QVariant::fromValue( *pArtisan) );
            }
            return QVariant::fromValue( lArtisans );
        }

        const QList< D3_Artisan* >& D3_Career::getHardcoreArtisans() const { return m_lpHardcoreArtisans; }
        QVariant D3_Career::getHardcoreArtisansAsQVariant() const
        {
            QList< QVariant > lArtisans;
            foreach( D3_Artisan* pArtisan, m_lpHardcoreArtisans )
            {
                lArtisans.push_back( QVariant::fromValue( *pArtisan) );
            }
            return QVariant::fromValue( lArtisans );
        }

        D3_Progression* D3_Career::getSoftcoreProgression() const { return m_pSoftcoreProgression; }
        QVariant D3_Career::getSoftcoreProgressionAsQVariant() const
        {
            return QVariant::fromValue( *m_pSoftcoreProgression );
        }

        D3_Progression* D3_Career::getHardcoreProgression() const { return m_pHardcoreProgression; }
        QVariant D3_Career::getHardcoreProgressionAsQVariant() const
        {
            return QVariant::fromValue( *m_pHardcoreProgression );
        }

        const QString& D3_Career::getBattleTag() const { return m_strBattleTag; }
        //----------------------------------//

        // tools
        bool D3_Career::isValid() const { return true; }
        QString D3_Career::toString() const
        {
            QString strReturn;
            strReturn   += "BattleTag : " + m_strBattleTag + ";";

            strReturn   += "\nHeroes : \n{ ";
            foreach( D3_Hero* pHero, m_lpHeroes )
            {
                strReturn += "\n\t" + pHero->toString() + ";";
            }
            strReturn   += "\n}";

            strReturn   += "\nArtisans : \n{ ";
            foreach( D3_Artisan* pArtisan, m_lpSoftcoreArtisans )
            {
                strReturn += "\n\t" + pArtisan->toString() + ";";
            }
            strReturn   += "\n}";

            strReturn   += "\nHardcore Artisans : \n{ ";
            foreach( D3_Artisan* pArtisan, m_lpHardcoreArtisans )
            {
                strReturn += "\n\t" + pArtisan->toString() + ";";
            }
            strReturn   += "\n}";

            strReturn   += "\nProgression : \n{ ";
            strReturn   += m_pSoftcoreProgression->toString();
            strReturn   += "\n}";

            strReturn   += "\nHardcoreProgression : \n{ ";
            strReturn   += m_pHardcoreProgression->toString();
            strReturn   += "\n}";

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

        void D3_Career::clearSoftcoreArtisans()
        {
            while( !m_lpSoftcoreArtisans.isEmpty() )
            {
                delete m_lpSoftcoreArtisans.last();
                m_lpSoftcoreArtisans.takeLast();
            }
        }

        void D3_Career::clearHardcoreArtisans()
        {
            while( !m_lpHardcoreArtisans.isEmpty() )
            {
                delete m_lpHardcoreArtisans.last();
                m_lpHardcoreArtisans.takeLast();
            }
        }
        //----------------------------------//
    }
}
