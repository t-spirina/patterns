#pragma once
/*Представьте графический редактор, благодаря которому пользователи могут рисовать 
 * на экране графические элементы. 
 * Для упрощения возьмем один объект - прямоугольник. 
 * Пусть у вас будет абстрактный класс (Implementer):
   И также абстрактный класс (Abstraction):
    Abstraction
Создайте вашему Implementer 2 реализации - рисование кистью и рисование карандашом.
Создайте реализацию Абстракции class Rectangle: public Shape которая будет реализовывать метод draw, 
вызывая рисование прямоугольника у конкретного implementer.

*/
#include <iostream>
// Implementor
class DrawingImplementor {
public:
    virtual void drawRectangle(double) = 0;
    virtual ~DrawingImplementor() {
    }
};
// Abstraction
class Shape {
protected:
    DrawingImplementor* drawingMethod;
public:
    Shape(DrawingImplementor* method) : drawingMethod(method){}
    virtual void draw()= 0; // low-level
    virtual void resize(double pct) = 0; // high-level
    virtual ~Shape() {}
};

class DrawWithBrush: public DrawingImplementor{
public:
    void drawRectangle(double size) override{
        std::cout<<"Draw with brush size:"<<size<<std::endl;
    }
};

class DrawWithPencil: public DrawingImplementor{
    void drawRectangle(double size) override{
        std::cout<<"Draw with pencil"<<size<<std::endl;
    }
};
class Rectangle: public Shape{
protected:
    double m_size;
public:
    Rectangle(DrawingImplementor* method, double size): Shape(method), m_size(size){}
    void draw() override{
        drawingMethod->drawRectangle(m_size);
    }
    void resize(double pct) override{
        m_size = pct;
    }
};
