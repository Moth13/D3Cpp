#include <d3cplus_data_act.h>
#include <d3cplus_data_quest.h>

#include <resources/include/parser.h>
#include <resources/include/qobjecthelper.h>

namespace d3cplus
{
    namespace Data
    {
        //----------------------------------//
        D3_Act::D3_Act( QObject* parent ) : D3_Data( parent ){ m_strClassName = "D3_Act"; }
        D3_Act::D3_Act( const D3_Act& _rD3_Act ) : D3_Data( _rD3_Act.parent() )
        {
            m_strClassName  = "D3_Act";
        }
        D3_Act::~D3_Act(){}

        // setFunction
        void D3_Act::setIsCompleted( bool _bIsCompleted ) { m_bIsCompleted  = _bIsCompleted; }
        void D3_Act::setCompletedQuests( QVariant _lCompletedQuests )
        {
            clearCompletedQuests();
            foreach( QVariant vQuest, _lCompletedQuests.toList() )
            {
                D3_Quest* pQuest = new D3_Quest();
                QJson::QObjectHelper::qvariant2qobject( vQuest.toMap(), pQuest );

                m_lpCompletedQuests.push_back( pQuest );
            }
        }

        // getFunction
        bool D3_Act::getIsCompleted() const   { return m_bIsCompleted; }

        QVariant D3_Act::getCompletedQuestsAsQVariant() const
        {
            QList< QVariant > lQuests;
            foreach( D3_Quest* pQuest, m_lpCompletedQuests )
            {
                lQuests.push_back( QVariant::fromValue( *pQuest) );
            }
            return QVariant::fromValue( lQuests );
        }

        const QList< D3_Quest* >& D3_Act::getCompletedQuests() const { return m_lpCompletedQuests; }

        // tools
        bool D3_Act::isValid() const { return true; }
        QString D3_Act::toString() const
        {
            QString strReturn;
            strReturn += m_bIsCompleted ? "Completed" : "Not Completed";

            strReturn   += "\nCompleted Quests : \n{ ";
            foreach( D3_Quest* pQuest, m_lpCompletedQuests )
            {
                strReturn += "\n\t" + pQuest->toString() + ";";
            }
            strReturn   += "\n}";

            return strReturn;
        }

        D3_Act& D3_Act::operator=( const D3_Act& _rD3_Act )
        {
            Q_ASSERT( m_strClassName == _rD3_Act.getType() );
            return *this;
        }
        bool D3_Act::operator==( const D3_Act& _rD3_Act )
        {
            return m_strClassName == _rD3_Act.getType();
        }

        void D3_Act::clearCompletedQuests()
        {
            while( !m_lpCompletedQuests.isEmpty() )
            {
                delete m_lpCompletedQuests.last();
                m_lpCompletedQuests.takeLast();
            }
        }

        //----------------------------------//
    }
}
