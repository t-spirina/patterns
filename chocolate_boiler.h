#pragma once
/*На современных шоколадных фабриках используются нагреватели с компьютерным управлением.
 * Смесь молока и шоколада в нагревателе доводится до кипения и передается на следующий этап изготовления.
 * Ниже приведен код класса, управляющего таким нагревателем.
 * Сейчас попытка создать новый объект данного класса будет успешной и это приведет к неверному управлению бойлером.
 * Оптимизируйте его так,
 * чтобы любые другие объекты обращаясь к этому нагревателю получали только один экземпляр, если он существует.*/
#include <mutex>
#include <iostream>
std::mutex boilerMutex;

class ChocolateBoiler{
private:
   bool _empty;
   bool _boiled;

   ChocolateBoiler(){
       _empty = true;
       _boiled = false;
   }
   static ChocolateBoiler* _instance;
public:
   virtual ~ChocolateBoiler(){
       delete _instance;
   }
   ChocolateBoiler(ChocolateBoiler& other) = delete;
   void operator=(ChocolateBoiler&) = delete;
   static ChocolateBoiler* GetInstance(){
       const std::lock_guard<std::mutex> lock(boilerMutex);
       if (_instance == nullptr){
           std::cout<<"new Chocolate boiler"<<std::endl;
           _instance = new ChocolateBoiler;
       }
       else {
           std::cout<<"return exist Chocolate boiler"<<std::endl;
       }
       return _instance;
   }

   bool isEmpty() const{
       const std::lock_guard<std::mutex> lock(boilerMutex);
       return _empty;
   }

   bool isBoiled() const{
       const std::lock_guard<std::mutex> lock(boilerMutex);
       return _boiled;
   }

   void fill(){
      const std::lock_guard<std::mutex> lock(boilerMutex);
       if (isEmpty()){
           _empty = false;
           _boiled = false;
       }
   }

   void drain(){
       const std::lock_guard<std::mutex> lock(boilerMutex);
       if (!isEmpty() && isBoiled()){
           _empty = true;
       }
   }

   void boil(){
       const std::lock_guard<std::mutex> lock(boilerMutex);
       if (!isEmpty() && !isBoiled()){
           _boiled = true;
       }
  }
};

