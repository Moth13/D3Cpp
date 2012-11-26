#ifndef D3CPLUS_ENGINE_H
#define D3CPLUS_ENGINE_H

#include <QtCore>
#include <QtNetwork>

#include <d3cplus_data.h>

namespace d3cplus
{
//    namespace Data
//    {
//        class D3_Career;
//        class D3_Heroes;
//    }

    typedef QPair< uint, int > PQT;

    class d3cplus_Engine : public QObject
    {
            Q_OBJECT
        public :
            enum eRegion
            {   E_Reg_America   =   0
                ,   E_Reg_Europe
                ,   E_Reg_Asia
            };

            /*! Constructor */
            d3cplus_Engine();
            /*! Destructor */
            virtual ~d3cplus_Engine();

            //------------------------------------------------------//
            // Search functions
            /*!  */
            uint getCareerProfileFromBattleTag( const QString& _rstrBattleTag, uint _uiBattleNumber, eRegion _eRegion );
            /*! */
            uint getHeroesInfoFromBattleTag( const QString& _rstrHeroesName, const QString& _rstrBattleTag, uint _uiBattleNumber, eRegion _eRegion );
            //------------------------------------------------------//

        signals :
            //------------------------------------------------------//
            // Signals
            /*! */
            void sigCareerProfileFound( uint _uiQueryID, Data::D3_Career _pD3Career );
            /*! */
            void sigHeroesInfoFound( uint _uiQueryID, Data::D3_Hero _pD3Hereos );
            //------------------------------------------------------//

        private :
            //------------------------------------------------------//
            // Attributs
            //            enum eQueryType
            //            {   Movie_Search = 0
            //            ,   Movie_Info
            //            ,   Movie_Cast

            //            ,   Person_Search
            //            ,   Person_Info
            //            ,   Person_Credits

            //            ,   DataImage_Get
            //            ,   Image_Get
            //            };

            QNetworkAccessManager *         m_pNetworkManager;      ///< Network request manager
            QMap< QNetworkReply*, PQT >     m_mQuery;               ///< Map of research
            //------------------------------------------------------//

            //------------------------------------------------------//
            // Tools
            void qv2o(const QVariantMap& variant, QObject* object);
            //------------------------------------------------------//
        private slots :
            //------------------------------------------------------//
            // Query slots
            void onNetworkManagerReply( QNetworkReply* _pReply );
            //------------------------------------------------------//
    };
}

#endif // D3CPLUS_ENGINE_H
