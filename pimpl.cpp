#include "pimpl.h"
class PlayerPimpl_impl {
public:
    float hp;
    int speed=0;
    QString name;

    PlayerPimpl_impl (float hp, int speed, const QString &name):
        hp(hp),speed(speed),name(name){}

    void changeSpeed(int change){
        speed+=change;
    }
    void changeHp(float change){
        hp+=change;
    }
    float getHp(){return hp;}
    int getSpeed() {return speed;}
    const QString &getName(){return name;}

};

PlayerPimpl::PlayerPimpl(float hp, int speed, const QString &name):
    _obj{std::make_unique<PlayerPimpl_impl>(hp,  speed, name)} {}

PlayerPimpl::~PlayerPimpl() = default;

void PlayerPimpl::changeSpeed(int change)  {
    //assert(_obj);
    _obj->changeSpeed(change);
}
void PlayerPimpl::changeHp(float change)  {
    //assert(_obj);
    _obj->changeHp(change);
}
float PlayerPimpl::getHp(){
    //assert(_obj);
    return _obj->getHp();
}
int PlayerPimpl::getSpeed(){
    //assert(_obj);
    return _obj->getSpeed();
}
const QString& PlayerPimpl::getName()
{
    //assert(_obj);
    return _obj->getName();
}
