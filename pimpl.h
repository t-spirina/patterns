#pragma once
#include <iostream>
#include <memory>
#include <QString>


class PlayerPimpl_impl;

class PlayerPimpl {
public:
    PlayerPimpl(float hp, int speed, const QString &name);
    ~PlayerPimpl();
    void changeSpeed(int change);
    void changeHp(float change);
    float getHp();
    int getSpeed();
    const QString &getName();
private:
    std::unique_ptr<PlayerPimpl_impl> _obj;
};
