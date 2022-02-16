#pragma once
/*
В сфере 2-мерной графики есть два основных направления. Растровая и векторная. И
там и там картинки. Но разница в том, что в растровой графике отрисовка картинки
происходит посредством геометрических фигур или их частей с указанием параметров.
То есть по сути это текстовое описание картинки, которое интерпретируется каждый
раз графическим редактором и отрисовывает полученную информацию на экране. А в
растровой отрисовка происходит попиксельно. То есть каждый пиксель имеет
параметры цвета и координаты на экране. Ниже представлен код для работы с двумя
типами график. Реализуйте класс, который позволит вам отрисовывать
соответствующую картинку с использованием паттерна Шаблонный метод.
*/
#include <iostream>
#include <vector>
template <typename T>
class TemplateImage{
protected:
    std::vector<T*> elements;
    std::vector<T> buffer;
    void openFile(const std::string& filename){
        std::cout << "Open file " << filename << std::endl;
    }

    virtual void readFile(){
        for (auto element: elements) {
            buffer.push_back(*element); //Имитируем чтение пикселей из файла в буфер
        }
    }
    virtual void draw() const =0;
    void final(){std::cout << "Drawing image complete" << std::endl;}
public:
    void DrawFromFile(const std::string& filename){
        this->openFile(filename);
        this->readFile();
        this->draw();
        this->final();
    }
};
struct Pixel{
    int x;
    int y;
    std::string color;
    void draw(){
        std::cout << "("<< x << ", " << y << ", " << color << ") ";
    }
};

class BitmapImage: public TemplateImage<Pixel>{
// Растровое изображение
protected:

    void draw() const override{
        for (auto element: this->elements) {
            element->draw();// Рисуем каждый пиксель из буфера
        }
    }
};

struct Figure{
    int x;
    int y;
    std::string figure;
    void draw(){
        std::cout << "("<< x << ", " << y << ", " << figure << ") ";
    }
};

class VectorImage : public TemplateImage<Figure>{
// Векторное изображение
protected:
    void draw() const  override{
        for (const auto element: elements) {
            element->draw(); // Рисуем каждую фигуру из буфера
        }
    }

};
