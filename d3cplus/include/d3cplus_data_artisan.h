#ifndef D3CPLUS_DATA_ARTISAN_H
#define D3CPLUS_DATA_ARTISAN_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        /*! \class*/
        class D3_Artisan: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QString slug READ getSlug WRITE setSlug)
                Q_PROPERTY(int level READ getLevel WRITE setLevel)
                Q_PROPERTY(int stepCurrent READ getStepCurrent WRITE setStepCurrent)
                Q_PROPERTY(int stepMax READ getStepMax WRITE setStepMax)

            public:
                explicit D3_Artisan( QObject* parent = NULL );
                D3_Artisan( const D3_Artisan& _rD3_Artisan );
                virtual ~D3_Artisan();

                // setFunction
                void setSlug( const QString& _rstrSlut );
                void setLevel( int _iLevel );
                void setStepCurrent( int _iStepCurrent );
                void setStepMax( int _iStepMax );

                // getFunction
                const QString& getSlug() const;
                int getLevel() const;
                int getStepCurrent() const;
                int getStepMax() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Artisan& operator=( const D3_Artisan& _rD3_Artisan );
                bool operator==( const D3_Artisan& _rD3_Artisan );

            private:
                QString m_strSlug;
                int     m_iLevel;
                int     m_iStepCurrent;
                int     m_iStepMax;
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Artisan )

#endif // D3CPLUS_DATA_ARTISAN_H
