#include <d3cplus_data_skill.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        D3_Skill::D3_Skill( QObject* parent ) : D3_Data( parent ){ m_strClassName = "D3_Skill"; }
        D3_Skill::D3_Skill( const D3_Skill& _rD3_Skill ) : D3_Data( _rD3_Skill.parent() )
        {
            m_strClassName  = "D3_Skill";
            m_strSlug       = _rD3_Skill.getSlug();
        }
        D3_Skill::~D3_Skill(){}

        // setFunction
        void D3_Skill::setSlug( const QString& _rstrSlut )                          { m_strSlug = _rstrSlut; }
        void D3_Skill::setName( const QString& _rstrName )                          { m_strName = _rstrName; }
        void D3_Skill::setIcon( const QString& _rstrIcon )                          { m_strIcon = _rstrIcon; }
        void D3_Skill::setTooltipParams( const QString& _rstrTooltipParams )        { m_strTooltipParams = _rstrTooltipParams; }
        void D3_Skill::setDescription( const QString& _rstrDescription )            { m_strDescription = _rstrDescription; }
        void D3_Skill::setSimpleDescription( const QString& _rstrSimpleDescription ){ m_strSimpleDescription = _rstrSimpleDescription; }
        void D3_Skill::setType( const QString& _rstrType )                          { m_strType = _rstrType; }
        void D3_Skill::setOrderIndex( const QString& _rstrOrderIndex )              { m_strOrderIndex = _rstrOrderIndex; }
        void D3_Skill::setFlavor( const QString& _rstrFlavor )                      { m_strFlavor = _rstrFlavor; }

        // getFunction
        const QString& D3_Skill::getSlug() const { return m_strSlug; }
        const QString& D3_Skill::getName() const { return m_strName; }
        const QString& D3_Skill::getIcon() const { return m_strIcon; }
        const QString& D3_Skill::getTooltipParams() const { return m_strTooltipParams; }
        const QString& D3_Skill::getDescription() const { return m_strDescription; }
        const QString& D3_Skill::getSimpleDescription() const { return m_strSimpleDescription; }
        const QString& D3_Skill::getType() const { return m_strType; }
        const QString& D3_Skill::getOrderIndex() const { return m_strOrderIndex; }
        const QString& D3_Skill::getFlavor() const { return m_strFlavor; }

        // tools
        bool D3_Skill::isValid() const { return !m_strSlug.isEmpty(); }
        QString D3_Skill::toString() const
        {
            QString strReturn;
            strReturn += m_strSlug;
            strReturn += "; " + m_strName;
            strReturn += "; " + m_strIcon;
            strReturn += "; " + m_strTooltipParams;
            strReturn += "; " + m_strDescription;
            strReturn += "; " + m_strSimpleDescription;
            strReturn += "; " + m_strType;
            strReturn += "; " + m_strOrderIndex;
            strReturn += "; " + m_strFlavor;

            return strReturn;
        }

        D3_Skill& D3_Skill::operator=( const D3_Skill& _rD3_Skill )
        {
            Q_ASSERT( m_strClassName == _rD3_Skilles.getType() );
            m_strSlug = _rD3_Skill.getSlug();
            return *this;
        }
        bool D3_Skill::operator==( const D3_Skill& _rD3_Skill )
        {
            return m_strClassName == _rD3_Skill.getType();
        }
        //----------------------------------//
    }
}
