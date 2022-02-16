#include <QCoreApplication>
#include "momento.h"
#include "pimpl.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Player p(1.2,3,"PLAYER1");

    Momento m=p.createMomento();
    p.changeSpeed(-1);
    std::cout<<"1 speed= "<<p.getSpeed()<<std::endl;
    p.reinstateMomento(m);
    std::cout<<"2 speed= "<<p.getSpeed()<<std::endl;

    PlayerPimpl pimpl(1.2,3,"PLAYER2");
    std::cout<< (pimpl.getName()).toStdString() <<std::endl;
    return a.exec();
}
