#ifndef D3CPLUS_DATA_PROGRESSION_H
#define D3CPLUS_DATA_PROGRESSION_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        class D3_Quest;

        /*! \class*/
        class D3_Progression: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(bool completed READ getIsCompleted WRITE setIsCompleted)
                Q_PROPERTY(QVariant completedQuests READ getActAsQVariant WRITE setAct)

            public:
                explicit D3_Progression( QObject* parent = NULL );
                D3_Progression( const D3_Progression& _rD3_Progression );
                virtual ~D3_Progression();

                // setFunction
                void setIsCompleted( bool _bIsCompleted );
                void setAct( QVariant _lCompletedQuests );

                // getFunction
                bool getIsCompleted() const;
                QVariant getActAsQVariant() const;
                const QList< D3_Quest* >&  getAct() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Progression& operator=( const D3_Progression& _rD3_Progression );
                bool operator==( const D3_Progression& _rD3_Progression );

            private:
                bool                m_bIsCompleted;
                QList< D3_Quest* >  m_lpAct;

                void clearAct();
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Progression )

#endif // D3CPLUS_DATA_PROGRESSION_H
