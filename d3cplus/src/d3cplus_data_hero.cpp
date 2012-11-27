#include <d3cplus_data_hero.h>

#include <d3cplus_data_skill_container.h>

#include <resources/include/parser.h>
#include <resources/include/qobjecthelper.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        D3_Hero::D3_Hero( QObject* parent )
            :   D3_Data             ( parent )
            ,   m_pSkillContainer   ( NULL )
        {
            m_strClassName = "D3_Heroes";
        }
        D3_Hero::D3_Hero( const D3_Hero& _rD3_Heroes )
            :   D3_Data             ( _rD3_Heroes.parent() )
            ,   m_pSkillContainer   ( NULL )
        {
            m_strClassName  = "D3_Heroes";
            m_strName       = _rD3_Heroes.getName();
        }
        D3_Hero::~D3_Hero()
        {
            if( NULL != m_pSkillContainer )
            {
                delete m_pSkillContainer;
            }
        }

        // setFunction
        void D3_Hero::setName( const QString& _rstrName ) { m_strName     = _rstrName; }
        void D3_Hero::setID( int _iID )                   { m_iID         = _iID; }
        void D3_Hero::setLevel( int _iLevel )             { m_iLevel      = _iLevel; }
        void D3_Hero::setHardcore( bool _bHardcore )      { m_bHardcore   = _bHardcore; }
        void D3_Hero::setParagonLvl( int _iParagonLvl )   { m_iParagonLvl = _iParagonLvl; }
        void D3_Hero::setGender( int _iGender )           { m_iGender     = _iGender; }
        void D3_Hero::setDead( bool _bDead )              { m_bDead       = _bDead; }
        void D3_Hero::setClass( const QString& _rstrClass ) { m_strClass  = _rstrClass; }
        void D3_Hero::setLastUpdate( int _iLastUpdated )  { m_iLastUpdated = _iLastUpdated; }        
        void D3_Hero::setSkillContainer( QVariant _skills )
        {
            if( NULL != m_pSkillContainer )
            {
                delete m_pSkillContainer;
            }

            m_pSkillContainer = new D3_Skill_Container();
            QJson::QObjectHelper::qvariant2qobject( _skills.toMap(), m_pSkillContainer );
        }

        // getFunction
        const QString& D3_Hero::getName() const { return m_strName; }
        int D3_Hero::getID() const { return m_iID; }
        int D3_Hero::getLevel() const { return m_iLevel; }
        bool D3_Hero::getHardcore() const { return m_bHardcore; }
        int D3_Hero::getParagonLvl() const { return m_iParagonLvl; }
        int D3_Hero::getGender() const { return m_iGender; }
        bool D3_Hero::getDead() const { return m_bDead; }
        const QString& D3_Hero::getClass() const { return m_strClass; }
        int D3_Hero::getLastUpdate() const { return m_iLastUpdated; }
        QVariant D3_Hero::getSkillContainerAsQVariant() const
        {
            return QVariant::fromValue( *m_pSkillContainer );
        }

        const D3_Skill_Container& D3_Hero::getSkillContainer() const
        {
            return *m_pSkillContainer;
        }

        // tools
        bool D3_Hero::isValid() const { return m_iID > 0; }
        QString D3_Hero::toString() const
        {
            QString strReturn;
            strReturn += m_strName;
            strReturn += "; " + QString::number( m_iID );
            strReturn += "; " + QString::number( m_iLevel );
            strReturn += "; " + QString( ( m_bHardcore ? "Hardcore" : "Softcore" ) );
            strReturn += "; " + QString::number( m_iParagonLvl );
            strReturn += "; " + QString::number( m_iGender );
            strReturn += "; " + QString( ( m_bDead ? "Dead" : "Alive" ) );
            strReturn += "; " + m_strClass;
            strReturn += "; " + QString::number( m_iLastUpdated );

            return strReturn;
        }

        D3_Hero& D3_Hero::operator=( const D3_Hero& _rD3_Heroes )
        {
            Q_ASSERT( m_strClassName == _rD3_Heroes.getType() );
            m_strName = _rD3_Heroes.getName();
            return *this;
        }
        bool D3_Hero::operator==( const D3_Hero& _rD3_Heroes )
        {
            return m_strClassName == _rD3_Heroes.getName();
        }
        //----------------------------------//
    }
}
