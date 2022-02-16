#pragma once
//реализуйте паттерн хранитель так, что бы данные об объекте player сериализовывались в бинарный файл.
#include <iostream>
#include <QDataStream>
#include <QFile>
class Momento{
private:
    float hp;
    int speed=0;
    QString name;
    const std::string FileName = "./player.bin";
public:
    Momento(float hp, int speed, const QString &name): hp(hp),speed(speed),name(name){
        QFile file( FileName.c_str() );
        QDataStream stream( &file );
        file.open( QIODevice::WriteOnly );
        stream << hp << speed << name;
        file.close();
    }
    Momento (const Momento &m){
        hp=m.getHp();
        speed = m.getSpeed();
        name= m.getName();
    }
    Momento (const std::string _FileName){
        QFile file( _FileName.c_str() );
        QDataStream stream( &file );
        file.open( QIODevice::ReadOnly );
        stream >> hp >> speed >> name;
        file.close();
    }
    float getHp() const {return hp;}
    int getSpeed() const {return speed;}
    const QString &getName() const {return name;}
};
class Player{
private:
    float hp;
    int speed=0;
    QString name;
public:
    Player(float hp, int speed, const QString &name): hp(hp),speed(speed),name(name){}
    void changeSpeed(int change){
        speed+=change;
    }
    void changeHp(float change){
        hp+=change;
    }
    float getHp(){return hp;}
    int getSpeed() {return speed;}
    const QString &getName(){return name;}
    Momento createMomento(){
        Momento m(hp, speed, name);
        return m;
    }
    void reinstateMomento( Momento &m)
    {
        hp=m.getHp();
        speed=m.getSpeed();
        name=m.getName();
    }
};
