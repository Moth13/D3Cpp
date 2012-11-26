#ifndef D3CPLUS_DATA_QUEST_H
#define D3CPLUS_DATA_QUEST_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        /*! \class*/
        class D3_Quest: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QString slug READ getSlug WRITE setSlug)
                Q_PROPERTY(QString name READ getName WRITE setName)

            public:
                explicit D3_Quest( QObject* parent = NULL );
                D3_Quest( const D3_Quest& _rD3_Quest );
                virtual ~D3_Quest();

                // setFunction
                void setSlug( const QString& _rstrSlut );
                void setName( const QString& _rstrName );

                // getFunction
                const QString& getSlug() const;
                const QString& getName() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Quest& operator=( const D3_Quest& _rD3_Quest );
                bool operator==( const D3_Quest& _rD3_Quest );

            private:
                QString m_strSlug;
                QString m_strName;
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Quest )

#endif // D3CPLUS_DATA_QUEST_H
