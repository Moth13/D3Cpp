#include <d3cplus_data.h>

#include <resources/include/parser.h>
#include <resources/include/qobjecthelper.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
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
    }
}

