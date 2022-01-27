/*Command
Вы решили запрограммировать умную лампочку,
которую можно включать и выключать и задавать цвет свечения.
В вашем распоряжении есть следующий класс:

enum class Colors {
   RED,
   ORANGE,
   YELLOW,
   GREEN,
   CYAN,
   BLUE,
   VIOLET,
   WHITE
};

class Light{
public:
   Light():state(false), color(Colors::WHITE){};
   void On(){
       if(!state){
           state = true;
       }
   };

   void Off(){
       if(state){
           state = false;
       }
   };

   void changeColor(Colors newColor){
       color = newColor;
   }

   bool getState() const {
       return state;
   }

private:
   bool state;
   Colors color;
};


Реализуйте паттерн команда,
чтобы можно было сохранять состояние лампочки и проигрывать её мерцание как в прямом так и в обратном направлении.
*/
#pragma once
#include <iostream>
#include <vector>
enum class Colors {
   RED,
   ORANGE,
   YELLOW,
   GREEN,
   CYAN,
   BLUE,
   VIOLET,
   WHITE
};
std::ostream& operator << (std::ostream& out, const Colors& t)
{
   switch(t) {
      case Colors::RED: return (out << "RED");
      case Colors::ORANGE: return (out << "ORANGE");
      case Colors::YELLOW: return (out << "YELLOW");
      case Colors::GREEN: return (out << "GREEN");
      case Colors::CYAN: return (out << "CYAN");
      case Colors::BLUE: return (out << "BLUE");
      case Colors::VIOLET: return (out << "VIOLET");
      case Colors::WHITE: return (out << "WHITE");
   }
   return (out);
}
class Light{
public:
   Light():state(false), color(Colors::WHITE){}

   void On(){
       if(!state){
           state = true;
       }
   }

   void Off(){
       if(state){
           state = false;
       }
   }

   void changeColor(Colors newColor){
       color = newColor;
   }

   bool getState() const {
       return state;
   }
   void info(){std::cout<<"light color: "<< color <<" state: "<<getState()<<std::endl;}
   Colors getColor(){return color;}
private:
   bool state;
   Colors color;
};
class Command {
protected:
    Light* light;
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
    virtual void unSet() = 0;

    void setLight(Light* _light){
        light = _light;
    }

};

class ChangeLightSettinds : public Command {
    Colors color;
    Colors prevColor;
public:

    ChangeLightSettinds(Colors _color) : color(_color),prevColor(Colors::WHITE) {}

    void Execute() override{
        prevColor=light->getColor();
        light->changeColor(color);
        light->On();
        light->info();
    }
    void unSet() override
    {
        light->changeColor(prevColor);
    }

};

class LightPlayer {
    std::vector<Command*> m_cmd;
    Light light;
    Command* pCmd;

public:

    LightPlayer() : pCmd(nullptr) { }

    ~LightPlayer(){
        for (Command* ptr : m_cmd){
            delete ptr;
        }
    }

    void Add(Colors color){
        pCmd = new ChangeLightSettinds(color);
        pCmd->setLight(&light);
        pCmd->Execute();
        m_cmd.push_back(pCmd);
    }

    void Undo()
    {
        if (m_cmd.size() == 0){
            std::cout << "There is nothing to undo!" << std::endl;
        }
        else
        {
            std::cout<<"undo "<< std::endl;
            pCmd = m_cmd.back();
            pCmd->unSet();
            m_cmd.pop_back();

            delete pCmd;
        }
    }
    void getInfo(){
        light.info();
    }
};
