#ifndef D3CPLUS_DATA_ACT_H
#define D3CPLUS_DATA_ACT_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        class D3_Quest;

        /*! \class*/
        class D3_Act: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(bool completed READ getIsCompleted WRITE setIsCompleted)
                Q_PROPERTY(QVariant completedQuests READ getCompletedQuestsAsQVariant WRITE setCompletedQuests)

            public:
                explicit D3_Act( QObject* parent = NULL );
                D3_Act( const D3_Act& _rD3_Act );
                virtual ~D3_Act();

                // setFunction
                void setIsCompleted( bool _bIsCompleted );
                void setCompletedQuests( QVariant _lCompletedQuests );

                // getFunction
                bool getIsCompleted() const;
                QVariant getCompletedQuestsAsQVariant() const;
                const QList< D3_Quest* >&  getCompletedQuests() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Act& operator=( const D3_Act& _rD3_Act );
                bool operator==( const D3_Act& _rD3_Act );

            private:
                bool                m_bIsCompleted;
                QList< D3_Quest* >  m_lpCompletedQuests;

                void clearCompletedQuests();
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Act )

#endif // D3CPLUS_DATA_ACT_H
