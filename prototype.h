#pragma once
#include <iostream>
class Prototype{
private:
    int hp;
    int atk;
    int def;
    std::string type;
public:
    Prototype(){}
    Prototype(int hp, int atk, int def, const std::string &type):
        hp(hp), atk(atk), def(def), type(type){}
    virtual ~Prototype() {}
    virtual Prototype* Clone() const = 0;

    void chandeHp(int change){hp += change;}
    void chandeAtk(int change){atk += change;}
    void chandeDef(int change){def += change;}
    int getHp(){return hp;}
    int getAtk(){return atk;}
    int getDef(){return def;}
    std::string getType(){return type;}
};
class Monster: public Prototype {
private:
    int hp;
    int atk;
    int def;
    std::string type;
public:
    Monster(int hp, int atk, int def, const std::string &type):
        Prototype(hp, atk, def, type){}
    Prototype* Clone() const override {
        return new Monster(*this);
    }
};
