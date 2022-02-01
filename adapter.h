#pragma once
/*
Представьте графический редактор, благодаря которому пользователи могут рисовать на экране графические элементы
(линии, многоугольники, текст и т.д.).
Каждый объект имеет возможность быть отрисован на экране и подвержен изменению формы.
Если с графическими объектами всё просто, то текст всегда обрабатывается иначе.
Разработайте адаптер для класса TextView, чтобы иметь возможность работать со всеми объектами графического редактора
одинаковыми методами.
*/


class IShape{
public:
   virtual void scale(double scale_percentage) = 0;// Масштабируем фигуру
   virtual void rotate(double angle) = 0;          // Поворачиваем фигуру
   virtual void flip() = 0;                        // Отражаем фигуру
};

class Figure: IShape{
private:
   int width;
   int height;
   double angle;
   bool isFlipped;
public:
   Figure(int width, int height) : width(width), height(height), angle(0.0), isFlipped(false) {}
   Figure():width(0),  height(0), angle(0.0), isFlipped(false) {}
   void scale(double scale_percentage) override {
       width *= scale_percentage;
       height *= scale_percentage;
   }

   void rotate(double angle) override {
       angle += angle;
   }

   void flip() override {
       isFlipped = !isFlipped;
   }
};

class IText{
   virtual void newSize(int size) = 0;   // Изменяем размер шрифта текста
   virtual void rotate(double angle) = 0;   // Поворачиваем текст
   virtual void reverse() = 0;              // Изменяем направление текста
};

class Text: IText{
private:
   int size;
   double angle;
   bool isReversed;
   std::string text;
public:
   Text(const std::string text, int size, double angle, bool isReversed) : text(text), size(size), angle(0.0), isReversed(false) {}

   void newSize(int newSize) override {
       size = newSize;
   }

   void rotate(double newAngle) override {
       angle = newAngle;
   }

   void reverse() override {
       for (int i = 0; i < text.size()/2; ++i) {
           char c = text[i];
           text[i] = text[text.size() - 1 - i];
           text[text.size() - 1 - i] = c;
       }
   }
};

class TextAdapter: public Figure
{
private:
    Text *m_text;
public:
    TextAdapter( Text &text) {this->m_text=&text;}
    void scale(double scale_percentage)  {m_text->newSize(static_cast<int> (scale_percentage));}
    void rotate(double angle)  {m_text->rotate(angle);}
    void flip()  {m_text->reverse();}
};
