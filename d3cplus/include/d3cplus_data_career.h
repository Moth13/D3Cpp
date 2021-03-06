#ifndef D3CPLUS_DATA_CAREER_H
#define D3CPLUS_DATA_CAREER_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        class D3_Hero;
        class D3_Artisan;
        class D3_Progression;

        /*! \class*/
        class  D3_Career : public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QVariant heroes READ getHeroesAsQVariant WRITE setHeroes)
                Q_PROPERTY(QString battleTag READ getBattleTag WRITE setBattleTag)
                Q_PROPERTY(QVariant artisans READ getSoftcoreArtisansAsQVariant WRITE setSoftcoreArtisans)
                Q_PROPERTY(QVariant hardcoreArtisans READ getHardcoreArtisansAsQVariant WRITE setHardcoreArtisans)
                Q_PROPERTY(QVariant progression READ getSoftcoreProgressionAsQVariant WRITE setSoftcoreProgression)
                Q_PROPERTY(QVariant hardcoreProgression READ getHardcoreProgressionAsQVariant WRITE setHardcoreProgression)

            public:
                explicit D3_Career( QObject* parent = NULL );
                D3_Career( const D3_Career& _rD3_Career );
                virtual ~D3_Career();

                // setFunction
                void setHeroes( QVariant _lHeroes );
                void setBattleTag( const QString& _rstrBattleTag );
                void setSoftcoreArtisans( QVariant _lSoftcoreArtisans );
                void setHardcoreArtisans( QVariant _lHardcoreArtisans );
                void setSoftcoreProgression( QVariant _lSoftcoreProgression );
                void setHardcoreProgression( QVariant _lHardcoreProgression );

                // getFunction
                QVariant getHeroesAsQVariant() const;
                const QList< D3_Hero* >&  getHeroes() const;

                QVariant getSoftcoreArtisansAsQVariant() const;
                const QList< D3_Artisan* >&  getSoftcoreArtisans() const;

                QVariant getHardcoreArtisansAsQVariant() const;
                const QList< D3_Artisan* >&  getHardcoreArtisans() const;

                QVariant getSoftcoreProgressionAsQVariant() const;
                D3_Progression* getSoftcoreProgression() const;

                QVariant getHardcoreProgressionAsQVariant() const;
                D3_Progression* getHardcoreProgression() const;

                const QString& getBattleTag() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Career& operator=( const D3_Career& _rD3_Career );
                bool operator==( const D3_Career& _rD3_Career );

            private:
                QList< D3_Hero* >       m_lpHeroes;
                QList< D3_Artisan* >    m_lpSoftcoreArtisans;
                QList< D3_Artisan* >    m_lpHardcoreArtisans;
                D3_Progression*         m_pSoftcoreProgression;
                D3_Progression*         m_pHardcoreProgression;

                QString                 m_strBattleTag;
                QString                 m_strLastUpdated;

                void clearHero();
                void clearSoftcoreArtisans();
                void clearHardcoreArtisans();
        };
    }
}

#endif // D3CPLUS_DATA_CAREER_H
