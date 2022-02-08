#pragma once
/*
Представьте систему домашнего кинотеатра.
У вас есть усилитель, медиаплеер, проектор, радиотюнер, экран, попкорн машина, система управления освещением.
Для того, чтобы посмотреть фильм, вам нужно:
1 Включить аппарат для попкорна
2 Запустить приготовление попкорна
3 Выключить свет
4 Опустить экран
5 Включить проектор
6 Выбрать на проекторе вход медиаплеера
7 Включить полноэкранный режим на проекторе
8 Включить усилитель
9 Выбрать на усилителе вход медиаплеера
10 Включить на усилителе режим объемного звука
11 Установить на усилителе среднюю громкость (5)
12 Включить медиаплеер
13 Запустить фильм на воспроизведение

В вашем распоряжении есть следующий код.
Загляните в main и вы всё поймете)
Реализуйте паттерн Facade, чтобы спрятать весь этот ужас.
Фасад должен включать и выключать всю систему вызовом соответствующих методов.
При желании можете еще сделать методы для включения и выключения радио в том же фасаде.
*/
#include <iostream>

class Device{
public:
   std::string type;

   Device(const std::string &type) : type(type) {}
   virtual void On(){
       std::cout << type <<" is on" << std::endl;
   }
   virtual void Off(){
       std::cout << type <<" is off" << std::endl;
   }


};

class MediaPlayer: public Device{
private:
   std::string currentMovie;
public:
   MediaPlayer(const std::string &type) : Device(type) {}
   void play(std::string newMovie) {
       currentMovie = newMovie;
       std::cout << "Movie " << currentMovie << " started" << std::endl;
   }
   virtual ~MediaPlayer(){}
};

class Amplifier: public Device{
   Device* streamingPLayer;
   int volume;
public:
   Amplifier(const std::string &type) : Device(type), volume(0) {}
   void setStreamingPlayer(Device* d){
       streamingPLayer = d;
       std::cout << "Streaming player is " << d->type << std::endl;
   }

   void setSurroundSound(){
       std::cout << "Surround Sound Mode" << std::endl;
   }

   void setVolume(int v){
       volume = v;
   }
   virtual ~Amplifier(){}

};

class Projector: public Device{
private:
   Amplifier* _amplifier;
   Device* _input;
public:
   Projector(const std::string &type) : Device(type) {}

   void setInput(Device* d){
       _input = d;
       std::cout << "Projector input is " << d->type << std::endl;
   }
   void wideScreenMode(){
       std::cout << "Wide Screen Mode" << std::endl;
   }
   virtual ~Projector(){}
};

class Tuner{
private:
   Amplifier* _amplifier;
public:
   void on(){
       std::cout << "Tuner on" << std::endl;
   }

   void off(){
       std::cout << "Tuner off" << std::endl;
   }
   virtual ~Tuner(){}
};

class Popper: public Device{
public:
   Popper(const std::string &type) : Device(type) {}

   void pop(){
       std::cout << "Popcorn will be ready soon" << std::endl;
   }
   virtual ~Popper(){}
};

class Lights: public Device{
private:
   int currentLight;
public:
   Lights(const std::string &type) : Device(type), currentLight(100) {}
   void dim(int light){
       currentLight = light;
   }
   virtual ~Lights(){}
};

class Screen: public Device{
public:
   Screen(const std::string &type) : Device(type) {}
   void down(){
       std::cout << "Screen is down" << std::endl;
   }
   void up(){
       std::cout << "Screen is up" << std::endl;
   }
   virtual ~Screen(){}
};

class FacadeForMediaPlayer{
protected:
    MediaPlayer* mp;
    Popper* popper;
    Lights* light;
    Projector* projector;
    Screen* screen;
    Amplifier* amp;
public:
    FacadeForMediaPlayer(){
        mp = new MediaPlayer("media player");
        popper= new Popper("popper");
        light=new Lights("light");
        projector = new Projector("projector");
        screen = new Screen("screen");
        amp  = new Amplifier("Amplifier");
    }
    void OnAndPlay(std::string newMovie){
        // Садимся смотреть фильм
        popper->On();                    // Включаем попкорн машину
        popper->pop();                   // Готовим попкорн

        light->dim(0);              // Глушим свет
        screen->down();                  // Опускаем экран

        projector->On();                 // Включаем проектор
        projector->setInput(mp);       // Выбираем вход проектора
        projector->wideScreenMode();     // Широкоэкранный режим

        amp->On();                       // Включаем усилитель
        amp->setStreamingPlayer(mp);   // Выбираем куда отправлять звук
        amp->setSurroundSound();         // Режим объемного звука
        amp->setVolume(5);             // Средняя громкость

        mp->On();                       // Включаем медиаплеер
        mp->play(newMovie); // Наконец смотрим фильм

    }
    void ChangeMovie(std::string newMovie){
        if(mp) mp->play(newMovie);
    }
    void Off(){
      if (mp) mp->Off();
      if (amp) amp->Off();
      if (projector) projector->Off();
      if (screen) {
          screen->Off();
          screen->up();
      }
      if(light) {
          light->dim(100);
          light->Off();
      }
      if (popper) popper->Off();
    }
    ~FacadeForMediaPlayer(){
        if (mp) delete(mp);
        if (popper) delete(popper);
        if (light) delete(light);
        if (projector) delete(projector);
        if (screen) delete(screen);
        if (amp) delete(amp);
    }
};
/*
int main() {
   // Инициализируем классы
   MediaPlayer* mp = new MediaPlayer("media player");
   Popper popper("popper");
   Lights light("light");
   Projector projector("projector");
   Screen screen("screen");
   Amplifier amp("Amplifier");

   // Садимся смотреть фильм
   popper.On();                    // Включаем попкорн машину
   popper.pop();                   // Готовим попкорн

   light.dim(0);              // Глушим свет
   screen.down();                  // Опускаем экран

   projector.On();                 // Включаем проектор
   projector.setInput(mp);       // Выбираем вход проектора
   projector.wideScreenMode();     // Широкоэкранный режим

   amp.On();                       // Включаем усилитель
   amp.setStreamingPlayer(mp);   // Выбираем куда отправлять звук
   amp.setSurroundSound();         // Режим объемного звука
   amp.setVolume(5);             // Средняя громкость

   mp->On();                       // Включаем медиаплеер
   mp->play("Star Wars"); // Наконец смотрим фильм

   // Посмотрели? А теперь все обратно надо выключить)

   return 0;
}
*/
