#pragma once
/*
 *Представьте, что вы разрабатываете текстовый редактор и вам необходимо реализовать деление текста на строки
 * (перенос строк).
 * Это удобный функционал, когда текст оказывается слишком длинным и приходится постоянно
 * выполнять горизонтальную прокрутку, чтобы его читать.
 *  Для выполнения данной задачи было представлено 3 алгоритма:
Деление текста на строки в зависимости от ширины клиентского окна
Деление текста на строки указанной ширины (передается в качестве параметра)
Автоматическое деление текста по предложениям (учитываются знаки препинания .!?)
Реализуйте паттерн стратегия, чтобы иметь возможность выбирать нужный алгоритм деления на предложения.

Сами методы DivideBy… реализовывать не обязательно. Главное сам паттерн. Но если хочется, то можно)

*/

#include <iostream>
#include <fstream>

enum class DivideMethod{
    ByScreenWidth,
    ByUserWidth,
    BySentence
};

class DivideStrategy {
private:
    int m_width=0;
public:
    virtual void Divide(std::string &text, int width = 0 ) = 0;
    //virtual void Divide(std::string &text) = 0;
};

class DivideByScreenWidth: public DivideStrategy{
private:
    int m_width=0;
public:
    void Divide(std::string &text, int width = 0 ) override {
        m_width=width;
        std::cout << "DivideByScreenWidth by screen width = " << m_width << std::endl;
    }
};

class DivideBySentence: public DivideStrategy{
private:
    int m_width=0;
public:
    void Divide(std::string &text, int width = 0 ) override {
        std::cout << "Divided by Sentences" << std::endl;
    }
};

class DivideByUserWidth: public DivideStrategy{
private:
    int m_width=0;
public:
    void Divide(std::string &text, int width = 0 ) override {
        m_width=width;
        std::cout << "DivideByScreenWidth by user width = " << m_width << std::endl;
    }
};

class ITextWork{
private:
    DivideStrategy *m_divideStrategy;
public:
    virtual void SetDivideStrategy(DivideStrategy *divideStrategy) = 0;
    virtual void Divide() = 0;
};

class TextEditor:  public ITextWork{
private:
    DivideStrategy *m_divideStrategy;
    size_t EditorWidth;
    std::string all_text;
    int textWigth = 0;
public:
    TextEditor(){}
    TextEditor(const std::string &text) : all_text(text) {}

    TextEditor(std::ifstream& file) {
        std::string line;
        if (file.is_open()){
            while (getline(file, line))
            {
                all_text+=line;
            }
        }
    }

    void PrintText() const{
        std::cout << all_text << std::endl;
    }

    void Divide() override {  m_divideStrategy->Divide(all_text,textWigth); }

    void SetWigth(int wigth) {
        textWigth = wigth;
    }
    void SetDivideStrategy(DivideStrategy *divideStrategy) override {
        m_divideStrategy=divideStrategy;
    }


};
