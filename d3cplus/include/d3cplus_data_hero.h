#ifndef D3CPLUS_DATA_HERO_H
#define D3CPLUS_DATA_HERO_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        class D3_Skill_Container;
        class D3_Stats;
        class D3_Item;

        typedef QHash< uint, D3_Item* > D3_Items;

        /*! \class*/
        class D3_Hero: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QString name READ getName WRITE setName)
                Q_PROPERTY(int id READ getID WRITE setID)
                Q_PROPERTY(int level READ getLevel WRITE setLevel)
                Q_PROPERTY(bool hardcore READ getHardcore WRITE setHardcore)
                Q_PROPERTY(int paragonLevel READ getParagonLvl WRITE setParagonLvl)
                Q_PROPERTY(int gender READ getGender WRITE setGender)
                Q_PROPERTY(bool dead READ getDead WRITE setDead)
                Q_PROPERTY(QString class READ getClass WRITE setClass)
                Q_PROPERTY(int lastUpdated READ getLastUpdate WRITE setLastUpdate)
                Q_PROPERTY(QVariant skills READ getSkillContainerAsQVariant WRITE setSkillContainer )
                Q_PROPERTY(QVariant stats READ getStatsAsQVariant WRITE setStats )
                Q_PROPERTY(QVariant items READ getItemsAsQVariant WRITE setItems )

            public:
                enum eItems_ID
                {   e_Item_Head =   0
                    ,   e_Item_Torso
                    ,   e_Item_Feet
                    ,   e_Item_Hands
                    ,   e_Item_Shoulders
                    ,   e_Item_Legs
                    ,   e_Item_Bracers
                    ,   e_Item_Waist
                    ,   e_Item_MainHand
                    ,   e_Item_OffHand
                    ,   e_Item_RightFinger
                    ,   e_Item_LeftFinger
                    ,   e_Item_Neck
                    ,   e_Item_Special
                    ,   e_Item_MAX
                };

                explicit D3_Hero( QObject* parent = NULL );
                D3_Hero( const D3_Hero& _rD3_Hero );
                ~D3_Hero();

                // setFunction
                void setName( const QString& _rstrName );
                void setID( int _iID );
                void setLevel( int _iLevel );
                void setHardcore( bool _bHardcore );
                void setParagonLvl( int _iParagonLvl );
                void setGender( int _iGender );
                void setDead( bool _bDead );
                void setClass( const QString& _rstrClass );
                void setLastUpdate( int _iLastUpdated );
                void setSkillContainer( QVariant _skills );
                void setStats( QVariant _stats );
                void setItems( QVariant _items );

                // getFunction
                const QString& getName() const;
                int getID() const;
                int getLevel() const;
                bool getHardcore() const;
                int getParagonLvl() const;
                int getGender() const;
                bool getDead() const;
                const QString& getClass() const;
                int getLastUpdate() const;

                QVariant getSkillContainerAsQVariant() const;
                const D3_Skill_Container&  getSkillContainer() const;

                QVariant getStatsAsQVariant() const;
                const D3_Stats& getStats() const;

                QVariant getItemsAsQVariant() const;
                const D3_Items& getItems() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Hero& operator=( const D3_Hero& _rD3_Hero );
                bool operator==( const D3_Hero& _rD3_Hers );

            private:
                QString m_strName;
                int     m_iID;
                int     m_iLevel;
                bool    m_bHardcore;
                int     m_iParagonLvl;
                int     m_iGender;
                QString m_strClass;
                int     m_iLastUpdated;
                bool    m_bDead;
                D3_Skill_Container* m_pSkillContainer;
                D3_Stats* m_pStats;
                D3_Items m_hItems;

                void clearItems();
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Hero )

#endif // D3CPLUS_DATA_HERO_H
