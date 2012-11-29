#include <d3cplus_data_skill_container.h>

#include <d3cplus_data_skill.h>

#include <resources/include/parser.h>
#include <resources/include/qobjecthelper.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        D3_Skill_Container::D3_Skill_Container( QObject* parent ) : D3_Data( parent ){ m_strClassName = "D3_Skill_Container"; }
        D3_Skill_Container::D3_Skill_Container( const D3_Skill_Container& _rD3_Skill_Container ) : D3_Data( _rD3_Skill_Container.parent() )
        {
            m_strClassName  = "D3_Skill_Container";
        }

        D3_Skill_Container::~D3_Skill_Container()
        {
            clearActiveSkills();
            clearPassiveSkills();
        }

        // setFunction
        void D3_Skill_Container::setActiveSkills( QVariant _activeSkills )
        {
            clearActiveSkills();
            foreach( QVariant vActiveSkill, _activeSkills.toList() )
            {
                D3_Skill* pSkill = new D3_Skill();
                D3_Skill* pRune = new D3_Skill();
                QJson::QObjectHelper::qvariant2qobject( vActiveSkill.toMap()[ "skill" ].toMap(), pSkill );
                QJson::QObjectHelper::qvariant2qobject( vActiveSkill.toMap()[ "rune" ].toMap(), pRune );

                m_lpActiveSkills.push_back( D3_ActiveSkill( pSkill, pRune ) );
            }
        }

        void D3_Skill_Container::setPassiveSkills( QVariant _passiveSkills )
        {
            clearPassiveSkills();
            foreach( QVariant vPassiveSkill, _passiveSkills.toList() )
            {
                D3_Skill* pPassiveSkill = new D3_Skill();
                QJson::QObjectHelper::qvariant2qobject( vPassiveSkill.toMap()[ "skill" ].toMap(), pPassiveSkill );

                m_lpPassiveSkills.push_back( pPassiveSkill );
            }
        }

        // getFunction
        const D3_ActiveSkills& D3_Skill_Container::getActiveSkills() const { return m_lpActiveSkills; }
        QVariant D3_Skill_Container::getActiveSkillsAsQVariant() const
        {
            QList< QVariant > lActiveSkills;
            foreach( D3_ActiveSkill activeSkills, m_lpActiveSkills )
            {
                QMap< QString, QVariant > lSkills;
                lSkills.insert( "skill", QVariant::fromValue( *activeSkills.first ) );
                lSkills.insert( "rune", QVariant::fromValue( *activeSkills.second ) );
                lActiveSkills.push_back( QVariant::fromValue( lSkills ) );
            }
            return QVariant::fromValue( lActiveSkills );
        }

        const D3_PassiveSkills& D3_Skill_Container::getPassiveSkills() const { return m_lpPassiveSkills; }
        QVariant D3_Skill_Container::getPassiveSkillsAsQVariant() const
        {
            QList< QVariant > lPassiveSkills;
            foreach( D3_Skill* pSkills, m_lpPassiveSkills )
            {
                QMap< QString, QVariant > lSkills;
                lSkills.insert( "skill", QVariant::fromValue( *pSkills) );
                lPassiveSkills.push_back( QVariant::fromValue( lSkills ) );
            }
            return QVariant::fromValue( lPassiveSkills );
        }

        // tools
        bool D3_Skill_Container::isValid() const { return true; }
        QString D3_Skill_Container::toString() const
        {
            QString strReturn;

            strReturn   += "\nActiveSkill : \n{ ";
            foreach( D3_ActiveSkill ActiveSkill, m_lpActiveSkills )
            {
                strReturn += "\n\t{";
                strReturn += "\n\t" + ActiveSkill.first->toString() + ";";
                strReturn += "\n\t" + ActiveSkill.second->toString() + ";";
                strReturn += "\n\t}";
            }
            strReturn   += "\n}";

            strReturn   += "\nPassiveSkill : \n{ ";
            foreach( D3_Skill* pPassiveSkill, m_lpPassiveSkills )
            {
                strReturn += "\n\t" + pPassiveSkill->toString() + ";";
            }
            strReturn   += "\n}";

            return strReturn;
        }

        D3_Skill_Container& D3_Skill_Container::operator=( const D3_Skill_Container& _rD3_Skill_Container )
        {
            Q_ASSERT( m_strClassName == _rD3_Skill_Container.getType() );
            return *this;
        }
        bool D3_Skill_Container::operator==( const D3_Skill_Container& _rD3_Skill_Container )
        {
            return m_strClassName == _rD3_Skill_Container.getType();
        }

        void D3_Skill_Container::clearActiveSkills()
        {
            while( !m_lpActiveSkills.isEmpty() )
            {
                delete m_lpActiveSkills.last().first;
                delete m_lpActiveSkills.last().second;
                m_lpActiveSkills.takeLast();
            }
        }

        void D3_Skill_Container::clearPassiveSkills()
        {
            while( !m_lpPassiveSkills.isEmpty() )
            {
                delete m_lpPassiveSkills.last();
                m_lpPassiveSkills.takeLast();
            }
        }
        //----------------------------------//
    }
}
