#include <d3cplus_data_progression.h>

#include <d3cplus_data_difficulty.h>

#include <resources/include/parser.h>
#include <resources/include/qobjecthelper.h>

namespace d3cplus
{
    namespace Data
    {
        D3_Progression::D3_Progression( QObject* parent )
            :   D3_Data             ( parent )
            ,   m_vpDifficulties    ( e_Diff_MAX, NULL )
        {
            m_strClassName  = "D3_Progression";
        }

        D3_Progression::D3_Progression( const D3_Progression& _rD3_Progression )
            :   D3_Data( _rD3_Progression.parent() )
        {
            m_strClassName  = "D3_Progression";
        }

        D3_Progression::~D3_Progression()
        {
            clearDifficulties();
        }

        // setFunction
        void D3_Progression::setNormal( QVariant _normal )
        {
            setDifficulty( _normal, e_Normal );
        }

        void D3_Progression::setNightmare( QVariant _nightmare )
        {
            setDifficulty( _nightmare, e_Nightmare );
        }

        void D3_Progression::setHell( QVariant _hell )
        {
            setDifficulty( _hell, e_Hell );
        }

        void D3_Progression::setInferno( QVariant _inferno )
        {
            setDifficulty( _inferno, e_Inferno );
        }

        // getFunction
        QVariant D3_Progression::getNormalAsQVariant() const
        {
            return QVariant::fromValue( *m_vpDifficulties[ e_Normal ] );
        }

        QVariant D3_Progression::getNightmareAsQVariant() const
        {
            return QVariant::fromValue( *m_vpDifficulties[ e_Nightmare ] );
        }

        QVariant D3_Progression::getHellAsQVariant() const
        {
            return QVariant::fromValue( *m_vpDifficulties[ e_Hell ] );
        }

        QVariant D3_Progression::getInfernoAsQVariant() const
        {
            return QVariant::fromValue( *m_vpDifficulties[ e_Inferno ] );
        }

        const QVector< D3_Difficulty* >& D3_Progression::getDifficulties() const
        {
            return m_vpDifficulties;
        }

        // tools
        bool D3_Progression::isValid() const { return true; }
        QString D3_Progression::toString() const
        {
            QString strReturn;
            for( uint i = 0; i<e_Diff_MAX; ++i )
            {
                strReturn += "Difficulty " + QString::number( i ) + " : ";
                strReturn += "\n\t" + m_vpDifficulties[ i ]->toString() + ";";
            }
            return strReturn;
        }

        D3_Progression& D3_Progression::operator=( const D3_Progression& _rD3_Progression )
        {
            Q_ASSERT( m_strClassName == _rD3_Progression.getType() );
            return *this;
        }

        bool D3_Progression::operator==( const D3_Progression& _rD3_Progression )
        {
            return m_strClassName == _rD3_Progression.getType();
        }

        void D3_Progression::setDifficulty( QVariant _difficulty, eDifficulty _eDifficulty )
        {
            Q_ASSERT( _eDifficulty >= e_Normal && _eDifficulty < e_Diff_MAX );

            if( NULL != m_vpDifficulties[ _eDifficulty ] )
            {
                delete m_vpDifficulties[ _eDifficulty ];
                m_vpDifficulties[ _eDifficulty ] = NULL;
            }

            D3_Difficulty* pDiff = new D3_Difficulty();
            QJson::QObjectHelper::qvariant2qobject( _difficulty.toMap(), pDiff );
            m_vpDifficulties[ _eDifficulty ] = pDiff;
        }

        void D3_Progression::clearDifficulties()
        {
            for( uint i = 0; i<e_Diff_MAX; ++i )
            {
                delete m_vpDifficulties[ i ];
                m_vpDifficulties[ i ] = NULL;
            }
        }
    }
}

