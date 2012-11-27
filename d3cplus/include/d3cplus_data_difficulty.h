#ifndef D3CPLUS_DATA_DIFFICULTY_H
#define D3CPLUS_DATA_DIFFICULTY_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        class D3_Act;

        /*! \class*/
        class D3_Difficulty: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QVariant act1 READ getAct1AsQVariant WRITE setAct1)
                Q_PROPERTY(QVariant act2 READ getAct2AsQVariant WRITE setAct2)
                Q_PROPERTY(QVariant act3 READ getAct3AsQVariant WRITE setAct3)
                Q_PROPERTY(QVariant act4 READ getAct4AsQVariant WRITE setAct4)

            public:
                enum eAct
                {   e_Act1      = 0
                ,   e_Act2      = 1
                ,   e_Act3      = 2
                ,   e_Act4      = 3
                ,   e_Act_MAX   = 4
                };

                explicit D3_Difficulty( QObject* parent = NULL );
                D3_Difficulty( const D3_Difficulty& _rD3_Difficulty );
                virtual ~D3_Difficulty();

                // setFunction
                void setAct1( QVariant _act1 );
                void setAct2( QVariant _act2 );
                void setAct3( QVariant _act3 );
                void setAct4( QVariant _act4 );

                // getFunction
                QVariant getAct1AsQVariant() const;
                QVariant getAct2AsQVariant() const;
                QVariant getAct3AsQVariant() const;
                QVariant getAct4AsQVariant() const;

                const QVector< D3_Act* >& getActs() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Difficulty& operator=( const D3_Difficulty& _rD3_Difficulty );
                bool operator==( const D3_Difficulty& _rD3_Difficulty );

            private:
                QVector< D3_Act* >    m_vpActs;

                void setAct( QVariant _act, eAct _eAct );
                void clearActs();
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Difficulty )

#endif // D3CPLUS_DATA_DIFFICULTY_H
