#include <d3cplus_data_artisan.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        D3_Artisan::D3_Artisan( QObject* parent ) : D3_Data( parent ){ m_strClassName = "D3_Artisan"; }
        D3_Artisan::D3_Artisan( const D3_Artisan& _rD3_Artisan ) : D3_Data( _rD3_Artisan.parent() )
        {
            m_strClassName  = "D3_Artisan";
            m_strSlug       = _rD3_Artisan.getSlug();
        }
        D3_Artisan::~D3_Artisan(){}

        // setFunction
        void D3_Artisan::setSlug( const QString& _rstrSlut ) { m_strSlug     = _rstrSlut; }
        void D3_Artisan::setLevel( int _iLevel )             { m_iLevel      = _iLevel; }
        void D3_Artisan::setStepCurrent( int _iStepCurrent ) { m_iStepCurrent = _iStepCurrent; }
        void D3_Artisan::setStepMax( int _iStepMax )         { m_iStepMax     = _iStepMax; }

        // getFunction
        const QString& D3_Artisan::getSlug() const          { return m_strSlug; }
        int D3_Artisan::getLevel() const                    { return m_iLevel; }
        int D3_Artisan::getStepCurrent() const              { return m_iStepCurrent; }
        int D3_Artisan::getStepMax() const                  { return m_iStepMax; }

        // tools
        bool D3_Artisan::isValid() const { return !m_strSlug.isEmpty(); }
        QString D3_Artisan::toString() const
        {
            QString strReturn;
            strReturn += m_strSlug;
            strReturn += "; " + QString::number( m_iLevel );
            strReturn += "; " + QString::number( m_iStepCurrent );
            strReturn += "; " + QString::number( m_iStepMax );

            return strReturn;
        }

        D3_Artisan& D3_Artisan::operator=( const D3_Artisan& _rD3_Artisan )
        {
            Q_ASSERT( m_strClassName == _rD3_Artisanes.getType() );
            m_strSlug = _rD3_Artisan.getSlug();
            return *this;
        }
        bool D3_Artisan::operator==( const D3_Artisan& _rD3_Artisan )
        {
            return m_strClassName == _rD3_Artisan.getType();
        }
        //----------------------------------//
    }
}
