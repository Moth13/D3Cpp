#include <d3cplus_data_item.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        D3_Item::D3_Item( QObject* parent ) : D3_Data( parent ){ m_strClassName = "D3_Item"; }
        D3_Item::D3_Item( const D3_Item& _rD3_Item ) : D3_Data( _rD3_Item.parent() )
        {
            m_strClassName  = "D3_Item";
        }
        D3_Item::~D3_Item(){}

        // setFunction
        void D3_Item::setID( const QString& _rstrID )                       { m_strID               = _rstrID; }
        void D3_Item::setName( const QString& _rstrName )                   { m_strName             = _rstrName; }
        void D3_Item::setIcon( const QString& _strIcon )                    { m_strIcon             = _strIcon; }
        void D3_Item::setDisplayColor( const QString& _strDisplayColor )    { m_strDisplayColor     = _strDisplayColor; }
        void D3_Item::setTooltipParams( const QString& _strTooltipParams )  { m_strTooltipParams    = _strTooltipParams; }

        // getFunction
        const QString& D3_Item::getID() const           { return m_strID; }
        const QString& D3_Item::getName() const         { return m_strName; }
        const QString& D3_Item::getIcon() const         { return m_strIcon; }
        const QString& D3_Item::getDisplayColor() const { return m_strDisplayColor; }
        const QString& D3_Item::getTooltipParams() const{ return m_strTooltipParams; }

        // tools
        bool D3_Item::isValid() const { return true; }
        QString D3_Item::toString() const
        {
            QString strReturn ="\n{ ";
            strReturn += m_strID;
            strReturn += "; " + m_strName;
            strReturn += "; " + m_strIcon;
            strReturn += "; " + m_strDisplayColor;
            strReturn += "; " + m_strTooltipParams;
            strReturn += ";\n}";

            return strReturn;
        }

        D3_Item& D3_Item::operator=( const D3_Item& _rD3_Item )
        {
            Q_ASSERT( m_strClassName == _rD3_Item.getType() );
            return *this;
        }
        bool D3_Item::operator==( const D3_Item& _rD3_Item )
        {
            return m_strClassName == _rD3_Item.getType();
        }
        //----------------------------------//
    }
}

