#ifndef D3CPLUS_DATA_PROGRESSION_H
#define D3CPLUS_DATA_PROGRESSION_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        class D3_Difficulty;

        /*! \class*/
        class D3_Progression: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QVariant normal READ getNormalAsQVariant WRITE setNormal)
                Q_PROPERTY(QVariant nightmare READ getNightmareAsQVariant WRITE setNightmare)
                Q_PROPERTY(QVariant hell READ getHellAsQVariant WRITE setHell)
                Q_PROPERTY(QVariant inferno READ getInfernoAsQVariant WRITE setInferno)

            public:
                enum eDifficulty
                {   e_Normal    = 0
                ,   e_Nightmare = 1
                ,   e_Hell      = 2
                ,   e_Inferno   = 3
                ,   e_Diff_MAX  = 4
                };

                explicit D3_Progression( QObject* parent = NULL );
                D3_Progression( const D3_Progression& _rD3_Progression );
                virtual ~D3_Progression();

                // setFunction
                void setNormal( QVariant _normal );
                void setNightmare( QVariant _nightmare );
                void setHell( QVariant _hell );
                void setInferno( QVariant _inferno );

                // getFunction
                QVariant getNormalAsQVariant() const;
                QVariant getNightmareAsQVariant() const;
                QVariant getHellAsQVariant() const;
                QVariant getInfernoAsQVariant() const;

                const QVector< D3_Difficulty* >& getDifficulties() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Progression& operator=( const D3_Progression& _rD3_Progression );
                bool operator==( const D3_Progression& _rD3_Progression );

            private:
                QVector< D3_Difficulty* >    m_vpDifficulties;

                void setDifficulty( QVariant _difficulty, eDifficulty _eDifficulty );
                void clearDifficulties();
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Progression )

#endif // D3CPLUS_DATA_PROGRESSION_H
