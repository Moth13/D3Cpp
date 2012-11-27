#ifndef D3CPLUS_DATA_SKILL_H
#define D3CPLUS_DATA_SKILL_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        /*! \class*/
        class D3_Skill: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QString slug READ getSlug WRITE setSlug)
                Q_PROPERTY(QString name READ getName WRITE setName)
                Q_PROPERTY(QString icon READ getIcon WRITE setIcon)
                Q_PROPERTY(QString tooltipParams READ getTooltipParams WRITE setTooltipParams)
                Q_PROPERTY(QString description READ getDescription WRITE setDescription)
                Q_PROPERTY(QString simpleDescription READ getSimpleDescription WRITE setSimpleDescription)
                Q_PROPERTY(QString type READ getType WRITE setType)
                Q_PROPERTY(QString orderIndex READ getOrderIndex WRITE setOrderIndex)
                Q_PROPERTY(QString flavor READ getFlavor WRITE setFlavor)

            public:
                explicit D3_Skill( QObject* parent = NULL );
                D3_Skill( const D3_Skill& _rD3_Skill );
                virtual ~D3_Skill();

                // setFunction
                void setSlug( const QString& _rstrSlut );
                void setName( const QString& _rstrName );
                void setIcon( const QString& _rstrIcon );
                void setTooltipParams( const QString& _rstrTooltipParams );
                void setDescription( const QString& _rstrDescription );
                void setSimpleDescription( const QString& _rstrSimpleDescription );
                void setType( const QString& _rstrType );
                void setOrderIndex( const QString& _rstrOrderIndex );
                void setFlavor( const QString& _rstrFlavor );

                // getFunction
                const QString& getSlug() const;
                const QString& getName() const;
                const QString& getIcon() const;
                const QString& getTooltipParams() const;
                const QString& getDescription() const;
                const QString& getSimpleDescription() const;
                const QString& getType() const;
                const QString& getOrderIndex() const;
                const QString& getFlavor() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Skill& operator=( const D3_Skill& _rD3_Skill );
                bool operator==( const D3_Skill& _rD3_Skill );

            private:
                QString m_strSlug;
                QString m_strName;
                QString m_strIcon;
                QString m_strTooltipParams;
                QString m_strDescription;
                QString m_strSimpleDescription;
                QString m_strType;
                QString m_strOrderIndex;
                QString m_strFlavor;
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Skill )

#endif // D3CPLUS_DATA_SKILL_H
