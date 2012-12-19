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
        void D3_Item::setTooltipParams( const QString& _strTooltipParams )  { m_strTooltipParams    = _strTooltipParams; }                void setRequiredLevel   ( const QString& _rstrRequiredLevel );
        void D3_Item::setRequiredLevel( const QString& _rstrRequiredLevel ) { m_strTooltipParams    = _strTooltipParams; }
        void D3_Item::setItemLevel( const QString& _rstrItemLevel )         { m_strTooltipParams    = _strTooltipParams; }
        void D3_Item::setBonusAffixes( const QString& _rstrBonusAffixes )   { m_strTooltipParams    = _strTooltipParams; }
        void D3_Item::setTypeName( const QString& _rstrTypeName )           { m_strTooltipParams    = _strTooltipParams; }
        void D3_Item::setType( const QString& _rstrType )                   { m_strTooltipParams    = _strTooltipParams; }
        void D3_Item::setDps( QVariant _dps )
        {
            m_strTooltipParams    = _strTooltipParams;
        }
        void D3_Item::setAttackPerSec( QVariant _attackPerSec )
        {
            m_strTooltipParams    = _strTooltipParams;
        }
        void D3_Item::setMinDamage( QVariant _minDamage )
        {
            m_strTooltipParams    = _strTooltipParams;
        }
        void D3_Item::setMaxDamage( QVariant _maxDamage )
        {
            m_strTooltipParams    = _strTooltipParams;
        }
        void D3_Item::setAttributs( const QStringList& _rlstrAttributs )    { m_strTooltipParams    = _strTooltipParams; }
        void D3_Item::setAttributsRaw( QVariant _attributsRaw )
        {
            m_strTooltipParams    = _strTooltipParams;
        }
        void D3_Item::setSocketEffects( QVariant _socketEffects )
        {
            m_strTooltipParams    = _strTooltipParams;
        }
        void D3_Item::setSalvage( QVariant _salvage )
        {
            m_strTooltipParams    = _strTooltipParams;
        }
        void D3_Item::setGems( QVariant _gems )
        {
            m_strTooltipParams    = _strTooltipParams;
        }

        // getFunction
        const QString& D3_Item::getID() const                   { return m_strID; }
        const QString& D3_Item::getName() const                 { return m_strName; }
        const QString& D3_Item::getIcon() const                 { return m_strIcon; }
        const QString& D3_Item::getDisplayColor() const         { return m_strDisplayColor; }
        const QString& D3_Item::getTooltipParams() const        { return m_strTooltipParams; }
        const QString& D3_Item::getRequiredLevel() const        { return m_strRequiredLevel; }
        const QString& D3_Item::getItemLevel() const            { return m_strItemLevel; }
        const QString& D3_Item::getBonusAffixes() const         { return m_strBonusAffixes; }
        const QString& D3_Item::getTypeName() const             { return m_strTypeName; }
        const QString& D3_Item::getType() const                 { return m_strType; }
        const D3_Item_SubInfo& D3_Item::getDps() const          { return m_dps; }
        const D3_Item_SubInfo& D3_Item::getAttackPerSec() const { return m_attackPerSec; }
        const D3_Item_SubInfo& D3_Item::getMinDamage() const    { return m_minDamage; }
        const D3_Item_SubInfo& D3_Item::getMaxDamage() const    { return m_maxDamage; }
        const QStringList& D3_Item::getAttributs() const        { return m_lstrAttributs; }
        const D3_Item_SubInfo& D3_Item::getAttributsRaw() const { return m_attributsRaw; }
        const D3_Item_SubInfo& D3_Item::getSocketEffects() const{ return m_socketEffects; }
        QList< D3_Item_Salvage* > D3_Item::getSalvage() const   { return m_lpSalvage; }
        const QList< D3_Item_Gem* >& D3_Item::getGems() const   { return m_lpGems; }

        QVariant D3_Item::getDpsAsQVariant() const
        {
            return QVariant();
        }
        QVariant D3_Item::getAttackPerSecAsQVariant() const
        {
            return QVariant();
        }
        QVariant D3_Item::getMinDamageAsQVariant() const
        {
            return QVariant();
        }
        QVariant D3_Item::getMaxDamageAsQVariant() const
        {
            return QVariant();
        }
        QVariant D3_Item::getAttributsRawAsQVariant() const
        {
            return QVariant();
        }
        QVariant D3_Item::getSocketEffectsAsQVariant() const
        {
            return QVariant();
        }
        QVariant D3_Item::getSalvageAsQVariant() const
        {
            return QVariant();
        }
        QVariant D3_Item::getGemsAsQVariant() const
        {
            return QVariant();
        }

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

