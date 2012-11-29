#include <d3cplus_data_quest.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        D3_Quest::D3_Quest( QObject* parent ) : D3_Data( parent ){ m_strClassName = "D3_Quest"; }
        D3_Quest::D3_Quest( const D3_Quest& _rD3_Quest ) : D3_Data( _rD3_Quest.parent() )
        {
            m_strClassName  = "D3_Quest";
            m_strSlug       = _rD3_Quest.getSlug();
        }
        D3_Quest::~D3_Quest(){}

        // setFunction
        void D3_Quest::setSlug( const QString& _rstrSlut ) { m_strSlug     = _rstrSlut; }
        void D3_Quest::setName( const QString& _rstrName ) { m_strName     = _rstrName; }

        // getFunction
        const QString& D3_Quest::getSlug() const          { return m_strSlug; }
        const QString& D3_Quest::getName() const          { return m_strName; }

        // tools
        bool D3_Quest::isValid() const { return !m_strSlug.isEmpty(); }
        QString D3_Quest::toString() const
        {
            QString strReturn ="\n{ ";
            strReturn += m_strSlug;
            strReturn += ";\n " + m_strName;
            strReturn += ";\n}";

            return strReturn;
        }

        D3_Quest& D3_Quest::operator=( const D3_Quest& _rD3_Quest )
        {
            Q_ASSERT( m_strClassName == _rD3_Quest.getType() );
            m_strSlug = _rD3_Quest.getSlug();
            return *this;
        }
        bool D3_Quest::operator==( const D3_Quest& _rD3_Quest )
        {
            return m_strClassName == _rD3_Quest.getType();
        }
        //----------------------------------//
    }
}
