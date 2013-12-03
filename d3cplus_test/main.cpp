#include <QtCore/QCoreApplication>
#include <d3cplus_engine.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"ssdfsdf";

    d3cplus::d3cplus_Engine* pEngine = new d3cplus::d3cplus_Engine();
    pEngine->getHeroesInfoFromBattleTag( 4912155, "MothyV", 1261, d3cplus::d3cplus_Engine::E_Reg_Europe );

    return a.exec();
}
