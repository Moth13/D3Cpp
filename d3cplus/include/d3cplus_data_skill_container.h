#ifndef D3CPLUS_DATA_SKILL_CONTAINER_H
#define D3CPLUS_DATA_SKILL_CONTAINER_H

#include <d3cplus_data.h>

namespace d3cplus
{
    namespace Data
    {
        class D3_Skill;
        typedef QPair< D3_Skill*, D3_Skill* > D3_ActiveSkill;
        typedef QList< D3_ActiveSkill > D3_ActiveSkills;
        typedef QList< D3_Skill* > D3_PassiveSkills;

        /*! \class*/
        class D3_Skill_Container: public D3_Data
        {
                Q_OBJECT
                Q_PROPERTY(QVariant active READ getActiveSkillsAsQVariant WRITE setActiveSkills)
                Q_PROPERTY(QVariant passive READ getPassiveSkillsAsQVariant WRITE setPassiveSkills)

            public:
                explicit D3_Skill_Container( QObject* parent = NULL );
                D3_Skill_Container( const D3_Skill_Container& _rD3_Skill_Container );
                virtual ~D3_Skill_Container();

                // setFunction
                void setActiveSkills( QVariant _activeSkills );
                void setPassiveSkills( QVariant _passiveSkills );

                // getFunction
                QVariant getActiveSkillsAsQVariant() const;
                const D3_ActiveSkills&  getActiveSkills() const;

                QVariant getPassiveSkillsAsQVariant() const;
                const D3_PassiveSkills&  getPassiveSkills() const;

                // tools
                virtual bool isValid() const;
                virtual QString toString() const;
                D3_Skill_Container& operator=( const D3_Skill_Container& _rD3_Skill_Container );
                bool operator==( const D3_Skill_Container& _rD3_Skill_Container );

            private:
                D3_ActiveSkills     m_lpActiveSkills;
                D3_PassiveSkills    m_lpPassiveSkills;

                void clearActiveSkills();
                void clearPassiveSkills();
        };
    }
}
Q_DECLARE_METATYPE( d3cplus::Data::D3_Skill_Container )
Q_DECLARE_METATYPE( d3cplus::Data::D3_ActiveSkills )
Q_DECLARE_METATYPE( d3cplus::Data::D3_PassiveSkills )

#endif // D3CPLUS_DATA_SKILL_CONTAINER_H
