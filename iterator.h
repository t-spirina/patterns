#pragma once
/*Реализовать паттерн итератор,
 * с помощью которого можно будет проитерироваться по контейнеру с объектами (одного любого класса)
 * в оба направления (возьмите контейнеры - список, массив, вектор, дек).
(Дополнительно) Попробуйте улучшить вашу реализацию, чтобы не было четкой привязки к классу объектов,
хранящихся в контейнерах.
*/


#include <iostream>
#include <string>
#include <vector>
class IIterator{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
};

template <typename T, typename R>
class Iterator : public IIterator{
public:
    typedef typename std::vector<T>::iterator it_type;
    Iterator( bool _reverse = false) :  reverse(_reverse) {
        if(reverse==false){
            it = p_data->data.begin();
        }
        else {
            it = p_data->data.end();

        }
    }

    void First() override {
        if(reverse==false){
            it = p_data->data.begin();
        }
        else {
            it = p_data->data.end();
        }
    }

    void Next() override{
        if(reverse==false) it++;
        else it--;
    }

    bool IsDone() override {
        if (reverse==false){
            return (it == p_data->data.end());
        }
        return (it == p_data->data.begin());

    }

    it_type Current() {
        return it  ;
    }

private:
    R *p_data;
    it_type it;
    bool reverse;
};
//---------------------------------------
template <class T>
class myIterator
{
    T* p_begin;
    T* p_end;
    typename std::vector<T>::iterator  it;
public:

    myIterator(std::vector<T> &vecIn_)
    {
        p_begin = vecIn_.empty() ? 0 : &vecIn_.front();
        p_end= p_begin + vecIn_.size();
        it=vecIn_.begin();
    }

    T* begin()
    {

        return p_begin;
    }
    T* end()
    {
        return p_end;
    }
    T operator *()
    {
        return *p_begin;
    }
    T* operator ++()
    {
        it++;
        return p_begin++;;
    }
    T data(){
        return *(it);
    }
};
template <class T>
class MyContainer{
friend class myIterator<T>;
std::vector<T> data;
public:
    void Add(T a) {
        data.push_back(a);
    }

    myIterator<T> *createIterator(){
        return new myIterator<T>(this->data);
    }

};





