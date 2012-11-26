#ifndef D3CPLUS_DATA_H
#define D3CPLUS_DATA_H

#include <QtCore>

namespace d3cplus
{
    namespace Data
    {
        /*! \class  */
        class D3_Data : public QObject
        {
            public:
                explicit D3_Data( QObject* parent = NULL );
                D3_Data( const D3_Data& _rD3_Data );
                ~D3_Data();

                const QString& getType() const;
                D3_Data& operator=( const D3_Data& _rD3_Data );
                bool operator==( const D3_Data& _rD3_Data );

                virtual bool isValid() const = 0;
                virtual QString toString() const = 0;

            protected :
                QString m_strClassName;
        };
    }
}

#endif // D3CPLUS_DATA_H
