#include <d3cplus_data_stats.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        D3_Stats::D3_Stats( QObject* parent ) : D3_Data( parent ){ m_strClassName = "D3_Stats"; resetValue(); }
        D3_Stats::D3_Stats( const D3_Stats& _rD3_Stats ) : D3_Data( _rD3_Stats.parent() )
        {
            m_strClassName  = "D3_Stats";
            resetValue();
        }
        D3_Stats::~D3_Stats(){}

        // setFunction
        void D3_Stats::setLife( int _iLife )                            { m_iLife               = _iLife; }
        void D3_Stats::setArmor( int _iArmor )                          { m_iArmor              = _iArmor; }
        void D3_Stats::setStrength( int _iStrength )                    { m_iStrength           = _iStrength; }
        void D3_Stats::setDexterity( int _iDexterity )                  { m_iDexterity          = _iDexterity; }
        void D3_Stats::setVitality( int _iVitality )                    { m_iVitality           = _iVitality; }
        void D3_Stats::setIntelligence( int _iIntelligence )            { m_iIntelligence       = _iIntelligence; }
        void D3_Stats::setFireResist( int _iFireResist )                { m_iFireResist         = _iFireResist; }
        void D3_Stats::setColdResist( int _iColdResist )                { m_iColdResist         = _iColdResist; }
        void D3_Stats::setLightningResist( int _iLightningResist )      { m_iLightningResist    = _iLightningResist; }
        void D3_Stats::setPoisonResist( int _iPoisonResist )            { m_iPoisonResist       = _iPoisonResist; }
        void D3_Stats::setArcaneResist( int _iArcaneResist )            { m_iArcaneResist       = _iArcaneResist; }
        void D3_Stats::setDamage( float _fDamage )                      { m_fDamage             = _fDamage; }
        void D3_Stats::setAttackSpeed( float _fAttackSpeed )            { m_fAttackSpeed        = _fAttackSpeed; }
        void D3_Stats::setCritDamage( float _fCritChance )              { m_fCritDamage         = _fCritChance; }
        void D3_Stats::setCritChance( float _fCritDamage )              { m_fCritChance         = _fCritDamage; }
        void D3_Stats::setBlockChance( float _fBlockChance )            { m_fBlockChance        = _fBlockChance; }
        void D3_Stats::setBlockAmountMin( float _fBlockAmountMin )      { m_fBlockAmountMin     = _fBlockAmountMin; }
        void D3_Stats::setBlockAmountMax( float _fBlockAmountMax )      { m_fBlockAmountMax     = _fBlockAmountMax; }
        void D3_Stats::setDamageIncrease( float _fDamageIncrease )      { m_fDamageIncrease     = _fDamageIncrease; }
        void D3_Stats::setDamageReduction( float _fDamageReduction )    { m_fDamageReduction    = _fDamageReduction; }
        void D3_Stats::setThorns( float _fThorns )                      { m_fThorns             = _fThorns; }
        void D3_Stats::setLifeSteal( float _fLifeSteal )                { m_fLifeSteal          = _fLifeSteal; }
        void D3_Stats::setLifePerKill( float _fLifePerKill )            { m_fLifePerKill        = _fLifePerKill; }
        void D3_Stats::setLifeOnHit( float _fDamageReduction )          { m_fLifeOnHit          = _fDamageReduction; }
        void D3_Stats::setPrimaryResource( int _iPrimaryResource )      { m_iPrimaryResource    = _iPrimaryResource; }
        void D3_Stats::setSecondaryResource( int _iSecondaryResource )  { m_iSecondaryResource  = _iSecondaryResource; }
        void D3_Stats::setMagicFind( float _fMagicFind )                { m_fMagicFind          = _fMagicFind; }
        void D3_Stats::setGoldFind( float _fGoldFind )                  { m_fGoldFind           = _fGoldFind; }
        void D3_Stats::setExperienceBonus( float _fExperienceBonus )    { m_fExperienceBonus    = _fExperienceBonus; }

        int D3_Stats::getLife() const                                   { return m_iLife; }
        int D3_Stats::getArmor() const                                  { return m_iArmor; }
        int D3_Stats::getStrength() const                               { return m_iStrength; }
        int D3_Stats::getDexterity() const                              { return m_iDexterity; }
        int D3_Stats::getVitality() const                               { return m_iVitality; }
        int D3_Stats::getIntelligence() const                           { return m_iIntelligence; }
        int D3_Stats::getFireResist() const                             { return m_iFireResist; }
        int D3_Stats::getColdResist() const                             { return m_iColdResist; }
        int D3_Stats::getLightningResist() const                        { return m_iLightningResist; }
        int D3_Stats::getPoisonResist() const                           { return m_iPoisonResist; }
        int D3_Stats::getArcaneResist() const                           { return m_iArcaneResist; }
        float D3_Stats::getDamage() const                               { return m_fDamage; }
        float D3_Stats::getAttackSpeed() const                          { return m_fAttackSpeed; }
        float D3_Stats::getCritDamage() const                           { return m_fCritDamage; }
        float D3_Stats::getCritChance() const                           { return m_fCritChance; }
        float D3_Stats::getBlockChance() const                          { return m_fBlockChance; }
        float D3_Stats::getBlockAmountMin() const                       { return m_fBlockAmountMin; }
        float D3_Stats::getBlockAmountMax() const                       { return m_fBlockAmountMax; }
        float D3_Stats::getDamageIncrease() const                       { return m_fDamageIncrease; }
        float D3_Stats::getDamageReduction() const                      { return m_fDamageReduction; }
        float D3_Stats::getThorns() const                               { return m_fThorns; }
        float D3_Stats::getLifeSteal() const                            { return m_fLifeSteal; }
        float D3_Stats::getLifePerKill() const                          { return m_fLifePerKill; }
        float D3_Stats::getLifeOnHit() const                            { return m_fLifeOnHit; }
        int D3_Stats::getPrimaryResource() const                        { return m_iPrimaryResource; }
        int D3_Stats::getSecondaryResource() const                      { return m_iSecondaryResource; }
        float D3_Stats::getMagicFind() const                            { return m_fMagicFind; }
        float D3_Stats::getGoldFind() const                             { return m_fGoldFind; }
        float D3_Stats::getExperienceBonus() const                      { return m_fExperienceBonus; }

        // tools
        bool D3_Stats::isValid() const { return true; }
        QString D3_Stats::toString() const
        {
            QString strReturn ="\n{ ";
            strReturn += QString::number( m_iLife );
            strReturn += "; " + QString::number( m_iArmor );
            strReturn += "; " + QString::number( m_iStrength );
            strReturn += "; " + QString::number( m_iDexterity );
            strReturn += "; " + QString::number( m_iVitality );
            strReturn += "; " + QString::number( m_iIntelligence );
            strReturn += "; " + QString::number( m_iFireResist );
            strReturn += "; " + QString::number( m_iColdResist );
            strReturn += "; " + QString::number( m_iLightningResist );
            strReturn += "; " + QString::number( m_iPoisonResist );
            strReturn += "; " + QString::number( m_iArcaneResist );
            strReturn += "; " + QString::number( m_fDamage );
            strReturn += "; " + QString::number( m_fAttackSpeed );
            strReturn += "; " + QString::number( m_fCritDamage );
            strReturn += "; " + QString::number( m_fCritChance );
            strReturn += "; " + QString::number( m_fBlockChance );
            strReturn += "; " + QString::number( m_fBlockAmountMin );
            strReturn += "; " + QString::number( m_fBlockAmountMax );
            strReturn += "; " + QString::number( m_fDamageIncrease );
            strReturn += "; " + QString::number( m_fDamageReduction );
            strReturn += "; " + QString::number( m_fThorns );
            strReturn += "; " + QString::number( m_fLifeSteal );
            strReturn += "; " + QString::number( m_fLifePerKill );
            strReturn += "; " + QString::number( m_fLifeOnHit );
            strReturn += "; " + QString::number( m_iPrimaryResource );
            strReturn += "; " + QString::number( m_iSecondaryResource );
            strReturn += "; " + QString::number( m_fMagicFind );
            strReturn += "; " + QString::number( m_fGoldFind );
            strReturn += "; " + QString::number( m_fExperienceBonus );
            strReturn += ";\n}";

            return strReturn;
        }

        D3_Stats& D3_Stats::operator=( const D3_Stats& _rD3_Stats )
        {
            Q_ASSERT( m_strClassName == _rD3_Stats.getType() );
            return *this;
        }
        bool D3_Stats::operator==( const D3_Stats& _rD3_Stats )
        {
            return m_strClassName == _rD3_Stats.getType();
        }

        void D3_Stats::resetValue()
        {
            m_iLife             = 0;
            m_iArmor            = 0;
            m_iStrength         = 0;
            m_iDexterity        = 0;
            m_iVitality         = 0;
            m_iIntelligence     = 0;
            m_iFireResist       = 0;
            m_iColdResist       = 0;
            m_iLightningResist  = 0;
            m_iPoisonResist     = 0;
            m_iArcaneResist     = 0;
            m_fDamage           = 0;
            m_fAttackSpeed      = 0;
            m_fCritDamage       = 0;
            m_fCritChance       = 0;
            m_fBlockChance      = 0;
            m_fBlockAmountMin   = 0;
            m_fBlockAmountMax   = 0;
            m_fDamageIncrease   = 0;
            m_fDamageReduction  = 0;
            m_fThorns           = 0;
            m_fLifeSteal        = 0;
            m_fLifePerKill      = 0;
            m_fLifeOnHit        = 0;
            m_iPrimaryResource  = 0;
            m_iSecondaryResource= 0;
            m_fMagicFind        = 0;
            m_fGoldFind         = 0;
            m_fExperienceBonus  = 0;
        }

        //----------------------------------//
    }
}
