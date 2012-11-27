#include <d3cplus_data_difficulty.h>

#include <d3cplus_data_act.h>

#include <resources/include/parser.h>
#include <resources/include/qobjecthelper.h>

namespace d3cplus
{
    namespace Data
    {
        D3_Difficulty::D3_Difficulty( QObject* parent )
            :   D3_Data     ( parent )
            ,   m_vpActs    ( e_Act_MAX, NULL )
        {
            m_strClassName  = "D3_Difficulty";
        }

        D3_Difficulty::D3_Difficulty( const D3_Difficulty& _rD3_Difficulty )
            :   D3_Data( _rD3_Difficulty.parent() )
        {
            m_strClassName  = "D3_Difficulty";
        }

        D3_Difficulty::~D3_Difficulty()
        {
            clearActs();
        }

        // setFunction
        void D3_Difficulty::setAct1( QVariant _act1 )
        {
            setAct( _act1, e_Act1 );
        }

        void D3_Difficulty::setAct2( QVariant _act2 )
        {
            setAct( _act2, e_Act2 );
        }

        void D3_Difficulty::setAct3( QVariant _act3 )
        {
            setAct( _act3, e_Act3 );
        }

        void D3_Difficulty::setAct4( QVariant _act4 )
        {
            setAct( _act4, e_Act4 );
        }

        // getFunction
        QVariant D3_Difficulty::getAct1AsQVariant() const
        {
            return QVariant::fromValue( *m_vpActs[ e_Act1 ] );
        }

        QVariant D3_Difficulty::getAct2AsQVariant() const
        {
            return QVariant::fromValue( *m_vpActs[ e_Act2 ] );
        }

        QVariant D3_Difficulty::getAct3AsQVariant() const
        {
            return QVariant::fromValue( *m_vpActs[ e_Act3 ] );
        }

        QVariant D3_Difficulty::getAct4AsQVariant() const
        {
            return QVariant::fromValue( *m_vpActs[ e_Act4 ] );
        }

        const QVector< D3_Act* >& D3_Difficulty::getActs() const
        {
            return m_vpActs;
        }

        // tools
        bool D3_Difficulty::isValid() const { return true; }
        QString D3_Difficulty::toString() const
        {
            QString strReturn;
            for( uint i = 0; i<e_Act_MAX; ++i )
            {
                strReturn += "Act" + QString::number( i + 1 ) + " : ";
                strReturn += "\n\t" + m_vpActs[ i ]->toString() + ";";
            }
            return strReturn;
        }

        D3_Difficulty& D3_Difficulty::operator=( const D3_Difficulty& _rD3_Difficulty )
        {
            Q_ASSERT( m_strClassName == _rD3_Difficulty.getType() );
            return *this;
        }

        bool D3_Difficulty::operator==( const D3_Difficulty& _rD3_Difficulty )
        {
            return m_strClassName == _rD3_Difficulty.getType();
        }

        void D3_Difficulty::setAct( QVariant _act, eAct _eAct )
        {
            Q_ASSERT( _eAct >= e_Act1 && _eAct < e_Act_MAX );

            if( NULL != m_vpActs[ _eAct ] )
            {
                delete m_vpActs[ _eAct ];
                m_vpActs[ _eAct ] = NULL;
            }

            D3_Act* pAct = new D3_Act();
            QJson::QObjectHelper::qvariant2qobject( _act.toMap(), pAct );
            m_vpActs[ _eAct ] = pAct;
        }

        void D3_Difficulty::clearActs()
        {
            for( uint i = 0; i<e_Act_MAX; ++i )
            {
                delete m_vpActs[ i ];
                m_vpActs[ i ] = NULL;
            }
        }
    }
}
