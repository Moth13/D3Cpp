#ifndef D3CPLUS_DATA_STATS_H
#define D3CPLUS_DATA_STATS_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        /*! \class*/
        class D3_Stats: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(int life READ getLife WRITE setLife)
                Q_PROPERTY(int armor READ getArmor WRITE setArmor)
                Q_PROPERTY(int strength READ getStrength WRITE setStrength)
                Q_PROPERTY(int dexterity READ getDexterity WRITE setDexterity)
                Q_PROPERTY(int vitality READ getVitality WRITE setVitality)
                Q_PROPERTY(int intelligence READ getIntelligence WRITE setIntelligence)
                Q_PROPERTY(int fireResist READ getFireResist WRITE setFireResist)
                Q_PROPERTY(int coldResist READ getColdResist WRITE setColdResist)
                Q_PROPERTY(int lightningResist READ getLightningResist WRITE setLightningResist)
                Q_PROPERTY(int poisonResist READ getPoisonResist WRITE setPoisonResist)
                Q_PROPERTY(int arcaneResist READ getArcaneResist WRITE setArcaneResist)
                Q_PROPERTY(float damage READ getDamage WRITE setDamage)
                Q_PROPERTY(float attackSpeed READ getDamage WRITE setAttackSpeed)
                Q_PROPERTY(float critDamage READ getCritDamage WRITE setCritDamage)
                Q_PROPERTY(float critChance READ getCritChance WRITE setCritChance)
                Q_PROPERTY(float blockChance READ getBlockChance WRITE setBlockChance)
                Q_PROPERTY(float blockAmountMin READ getBlockAmountMin WRITE setBlockAmountMin)
                Q_PROPERTY(float blockAmountMax READ getBlockAmountMax WRITE setBlockAmountMax)
                Q_PROPERTY(float damageIncrease READ getDamageIncrease WRITE setDamageIncrease)
                Q_PROPERTY(float damageReduction READ getDamageReduction WRITE setDamageReduction)
                Q_PROPERTY(float thorns READ getThorns WRITE setThorns)
                Q_PROPERTY(float lifeSteal READ getLifeSteal WRITE setLifeSteal)
                Q_PROPERTY(float lifePerKill READ getLifePerKill WRITE setLifePerKill)
                Q_PROPERTY(float lifeOnHit READ getLifeOnHit WRITE setLifeOnHit)
                Q_PROPERTY(int primaryResource READ getPrimaryResource WRITE setPrimaryResource)
                Q_PROPERTY(int secondaryResource READ getSecondaryResource WRITE setSecondaryResource)
                Q_PROPERTY(float magicFind READ getMagicFind WRITE setMagicFind)
                Q_PROPERTY(float goldFind READ getGoldFind WRITE setGoldFind)
                Q_PROPERTY(float experienceBonus READ getExperienceBonus WRITE setExperienceBonus)

            public:
                explicit D3_Stats( QObject* parent = NULL );
                D3_Stats( const D3_Stats& _rD3_Stats );
                virtual ~D3_Stats();

                // setFunction
                void setLife( int _iLife );
                void setArmor( int _iArmor );
                void setStrength( int _iStrength );
                void setDexterity( int _iDexterity );
                void setVitality( int _iVitality );
                void setIntelligence( int _iIntelligence );
                void setFireResist( int _iFireResist );
                void setColdResist( int _iColdResist );
                void setLightningResist( int _iLightningResist );
                void setPoisonResist( int _iPoisonResist );
                void setArcaneResist( int _iArcaneResist );
                void setDamage( float _fDamage );
                void setAttackSpeed( float _fAttackSpeed );
                void setCritDamage( float _fCritChance );
                void setCritChance( float _fCritDamage );
                void setBlockChance( float _fBlockChance );
                void setBlockAmountMin( float _fBlockAmountMin );
                void setBlockAmountMax( float _fBlockAmountMax );
                void setDamageIncrease( float _fDamageIncrease );
                void setDamageReduction( float _fDamageReduction );
                void setThorns( float _fThorns );
                void setLifeSteal( float _fLifeSteal );
                void setLifePerKill( float _fLifePerKill );
                void setLifeOnHit( float _fDamageReduction );
                void setPrimaryResource( int _iPrimaryResource );
                void setSecondaryResource( int _iSecondaryResource );
                void setMagicFind( float _fMagicFind );
                void setGoldFind( float _fGoldFind );
                void setExperienceBonus( float _fExperienceBonus );

                // getFunction
                int getLife() const;
                int getArmor() const;
                int getStrength() const;
                int getDexterity() const;
                int getVitality() const;
                int getIntelligence() const;
                int getFireResist() const;
                int getColdResist() const;
                int getLightningResist() const;
                int getPoisonResist() const;
                int getArcaneResist() const;
                float getDamage() const;
                float getAttackSpeed() const;
                float getCritDamage() const;
                float getCritChance() const;
                float getBlockChance() const;
                float getBlockAmountMin() const;
                float getBlockAmountMax() const;
                float getDamageIncrease() const;
                float getDamageReduction() const;
                float getThorns() const;
                float getLifeSteal() const;
                float getLifePerKill() const;
                float getLifeOnHit() const;
                int getPrimaryResource() const;
                int getSecondaryResource() const;
                float getMagicFind() const;
                float getGoldFind() const;
                float getExperienceBonus() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Stats& operator=( const D3_Stats& _rD3_Stats );
                bool operator==( const D3_Stats& _rD3_Stats );

            private:
                int     m_iLife;
                int     m_iArmor;
                int     m_iStrength;
                int     m_iDexterity;
                int     m_iVitality;
                int     m_iIntelligence;
                int     m_iFireResist;
                int     m_iColdResist;
                int     m_iLightningResist;
                int     m_iPoisonResist;
                int     m_iArcaneResist;
                float   m_fDamage;
                float   m_fAttackSpeed;
                float   m_fCritDamage;
                float   m_fCritChance;
                float   m_fBlockChance;
                float   m_fBlockAmountMin;
                float   m_fBlockAmountMax;
                float   m_fDamageIncrease;
                float   m_fDamageReduction;
                float   m_fThorns;
                float   m_fLifeSteal;
                float   m_fLifePerKill;
                float   m_fLifeOnHit;
                int     m_iPrimaryResource;
                int     m_iSecondaryResource;
                float   m_fMagicFind;
                float   m_fGoldFind;
                float   m_fExperienceBonus;

                void resetValue();
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Stats )

#endif // D3CPLUS_DATA_STATS_H
