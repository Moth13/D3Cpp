#ifndef D3CPLUS_DATA_H
#define D3CPLUS_DATA_H

#include <QtCore>

namespace d3cplus
{
    namespace Data
    {
        class D3_Hero;
//        class D3_Artisan;
//        class D3_Followers;
//        class D3_Follower;
//        class D3_Skills;
//        class D3_Stats;
//        class D3_Items;
//        class D3_Item;
//        class D3_KillsInfo;
//        class D3_PlayedInfo;
//        class D3_Progression;
//        class D3_Difficulty;
//        class D3_Act;
//        class D3_Quest;

        typedef QList<D3_Hero*> D3_Heroes_List;
//        typedef QList<D3_Artisan> D3_Artisans_List;
//        typedef QList<D3_Quest> D3_Quests_List;

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

        /*! \class*/
        class  D3_Career : public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QVariant heroes READ getHeroesAsQVariant WRITE setHeroes)
                Q_PROPERTY(QString battleTag READ getBattleTag WRITE setBattleTag)

            public:
                explicit D3_Career( QObject* parent = NULL );
                D3_Career( const D3_Career& _rD3_Career );
                ~D3_Career();

                // setFunction
                void setHeroes( QVariant _lHeroes );
                void setBattleTag( const QString& _rstrBattleTag );

                // getFunction
                QVariant getHeroesAsQVariant() const;
                const QList< D3_Hero* >&  getHeroes() const;

                const QString& getBattleTag() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Career& operator=( const D3_Career& _rD3_Career );
                bool operator==( const D3_Career& _rD3_Career );

            private:
                QList< D3_Hero* >   m_lpHeroes;
//                D3_Artisans_List    m_lArtisans;

                QString             m_strBattleTag;
                QString             m_strLastUpdated;

                void clearHero();
        };

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

            public:
                explicit D3_Hero( QObject* parent = NULL );
                D3_Hero( const D3_Hero& _rD3_Heroes );
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

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Hero& operator=( const D3_Hero& _rD3_Heroes );
                bool operator==( const D3_Hero& _rD3_Heroes );

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
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Hero )
Q_DECLARE_METATYPE( QList<d3cplus::Data::D3_Hero*> )

#endif // D3CPLUS_DATA_H
