#ifndef D3CPLUS_ITEM_H
#define D3CPLUS_ITEM_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        class D3_Item;

        typedef QPair< QString, QString > D3_Item_SubInfo;

        struct D3_Item_Salvage
        {
            float       m_fChance;
            uint        m_uiQuantity;
            D3_Item*    m_pSalvage;

            explicit D3_Item_Salvage();
            ~D3_Item_Salvage();
        };
        struct D3_Item_Gem
        {
            D3_Item*    m_pGem;

            explicit D3_Item_Gem();
            ~D3_Item_Gem();
        };

        /*! \class*/
        class D3_Item: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QString id                   READ getID                      WRITE setID)
                Q_PROPERTY(QString name                 READ getName                    WRITE setName)
                Q_PROPERTY(QString icon                 READ getIcon                    WRITE setIcon)
                Q_PROPERTY(QString displayColor         READ getDisplayColor            WRITE setDisplayColor)
                Q_PROPERTY(QString tooltipParams        READ getTooltipParams           WRITE setTooltipParams)
                Q_PROPERTY(QString requiredLevel        READ getRequiredLevel           WRITE setRequiredLevel)
                Q_PROPERTY(QString itemLevel            READ getItemLevel               WRITE setItemLevel)
                Q_PROPERTY(QString bonusAffixes         READ getBonusAffixes            WRITE setBonusAffixes)
                Q_PROPERTY(QString typeName             READ getTypeName                WRITE setTypeName)
                Q_PROPERTY(QString type                 READ getType                    WRITE setType)
                Q_PROPERTY(QVariant dps                 READ getDpsAsQVariant           WRITE setDps)
                Q_PROPERTY(QVariant attacksPerSecond    READ getAttackPerSecAsQVariant  WRITE setAttackPerSec)
                Q_PROPERTY(QVariant minDamage           READ getMinDamageAsQVariant     WRITE setMinDamage)
                Q_PROPERTY(QVariant maxDamage           READ getMaxDamageAsQVariant     WRITE setMaxDamage)
                Q_PROPERTY(QStringList attributes       READ getAttributs               WRITE setAttributs)
                Q_PROPERTY(QVariant attributesRaw       READ getAttributsRawAsQVariant  WRITE setAttributsRaw)
                Q_PROPERTY(QVariant socketEffets        READ getSocketEffectsAsQVariant WRITE setSocketEffects)
                Q_PROPERTY(QVariant salvage             READ getSalvageAsQVariant       WRITE setSalvage)
                Q_PROPERTY(QVariant gems                READ getGemsAsQVariant          WRITE setGems)


            public:
                explicit D3_Item( QObject* parent = NULL );
                D3_Item( const D3_Item& _rD3_Item );
                virtual ~D3_Item();

                // setFunction
                void setID              ( const QString& _rstrID );
                void setName            ( const QString& _rstrName );
                void setIcon            ( const QString& _rstrIcon);
                void setDisplayColor    ( const QString& _rstrDisplayColor );
                void setTooltipParams   ( const QString& _rstrTooltipParams );
                void setRequiredLevel   ( const QString& _rstrRequiredLevel );
                void setItemLevel       ( const QString& _rstrItemLevel );
                void setBonusAffixes    ( const QString& _rstrBonusAffixes );
                void setTypeName        ( const QString& _rstrTypeName );
                void setType            ( const QString& _rstrType );
                void setDps             ( QVariant _dps );
                void setAttackPerSec    ( QVariant _attackPerSec );
                void setMinDamage       ( QVariant _minDamage );
                void setMaxDamage       ( QVariant _maxDamage );
                void setAttributs       ( const QStringList& _rlstrAttributs );
                void setAttributsRaw    ( QVariant _attributsRaw );
                void setSocketEffects   ( QVariant _socketEffects );
                void setSalvage         ( QVariant _salvage );
                void setGems            ( QVariant _gems );

                // getFunction
                const QString&                      getID() const;
                const QString&                      getName() const;
                const QString&                      getIcon() const;
                const QString&                      getDisplayColor() const;
                const QString&                      getTooltipParams() const;
                const QString&                      getRequiredLevel() const;
                const QString&                      getItemLevel() const;
                const QString&                      getBonusAffixes() const;
                const QString&                      getTypeName() const;
                const QString&                      getType() const;
                const D3_Item_SubInfo&              getDps() const;
                const D3_Item_SubInfo&              getAttackPerSec() const;
                const D3_Item_SubInfo&              getMinDamage() const;
                const D3_Item_SubInfo&              getMaxDamage() const;
                const QStringList&                  getAttributs() const;
                const D3_Item_SubInfo&              getAttributsRaw() const;
                const D3_Item_SubInfo&              getSocketEffects() const;
                const QList< D3_Item_Salvage* >&    getSalvage() const;
                const QList< D3_Item_Gem* >&        getGems() const;

                QVariant            getDpsAsQVariant() const;
                QVariant            getAttackPerSecAsQVariant() const;
                QVariant            getMinDamageAsQVariant() const;
                QVariant            getMaxDamageAsQVariant() const;
                QVariant            getAttributsRawAsQVariant() const;
                QVariant            getSocketEffectsAsQVariant() const;
                QVariant            getSalvageAsQVariant() const;
                QVariant            getGemsAsQVariant() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Item& operator=( const D3_Item& _rD3_Item );
                bool operator==( const D3_Item& _rD3_Item );

            private:
                QString                     m_strID;
                QString                     m_strName;
                QString                     m_strIcon;
                QString                     m_strDisplayColor;
                QString                     m_strTooltipParams;
                QString                     m_strRequiredLevel;
                QString                     m_strItemLevel;
                QString                     m_strBonusAffixes;
                QString                     m_strTypeName;
                QString                     m_strType;
                D3_Item_SubInfo             m_dps;
                D3_Item_SubInfo             m_attackPerSec;
                D3_Item_SubInfo             m_minDamage;
                D3_Item_SubInfo             m_maxDamage;
                QStringList                 m_lstrAttributs;
                D3_Item_SubInfo             m_attributsRaw;
                D3_Item_SubInfo             m_SocketEffects;
                QList< D3_Item_Salvage* >   m_lpSalvage;
                QList< D3_Item_Gem* >       m_lpGems;
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Item )

#endif // D3CPLUS_ITEM_H
