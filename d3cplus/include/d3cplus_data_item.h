#ifndef D3CPLUS_ITEM_H
#define D3CPLUS_ITEM_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        /*! \class*/
        class D3_Item: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QString id READ getID WRITE setID)
                Q_PROPERTY(QString name READ getName WRITE setName)
                Q_PROPERTY(QString icon READ getIcon WRITE setIcon)
                Q_PROPERTY(QString displayColor READ getDisplayColor WRITE setDisplayColor)
                Q_PROPERTY(QString tooltipParams READ getTooltipParams WRITE setTooltipParams)

            public:
                explicit D3_Item( QObject* parent = NULL );
                D3_Item( const D3_Item& _rD3_Item );
                virtual ~D3_Item();

                // setFunction
                void setID( const QString& _rstrID );
                void setName( const QString& _rstrName );
                void setIcon( const QString& _rstrIcon);
                void setDisplayColor( const QString& _rstrDisplayColor );
                void setTooltipParams( const QString& _rstrTooltipParams );

                // getFunction
                const QString& getID() const;
                const QString& getName() const;
                const QString& getIcon() const;
                const QString& getDisplayColor() const;
                const QString& getTooltipParams() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Item& operator=( const D3_Item& _rD3_Item );
                bool operator==( const D3_Item& _rD3_Item );

            private:
                QString m_strID;
                QString m_strName;
                QString m_strIcon;
                QString m_strDisplayColor;
                QString m_strTooltipParams;
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Item )

#endif // D3CPLUS_ITEM_H
