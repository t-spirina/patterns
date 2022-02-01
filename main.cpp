#include <iostream>
#include "strategy.h"
#include "adapter.h"
#include "iterator.h"
int main()
{
   /* TextEditor text_editor("  ");

    DivideByScreenWidth* divide_by_screen_width = new DivideByScreenWidth;
    DivideBySentence* divide_by_sentence = new DivideBySentence;
    DivideByUserWidth* divide_by_user_width = new DivideByUserWidth;

    text_editor.SetDivideStrategy(divide_by_screen_width);
    text_editor.SetWigth(100);
    text_editor.Divide();


    Figure figure(10,10);
    Text text("text",10,0,false);

    Figure* textAdapter = new TextAdapter(text);

    figure.flip();
    text.reverse();
    textAdapter->flip();
*/

    MyContainer<int> cntr;

    for (auto i = 0; i < 5; i++) {
        cntr.Add(i);


    }

    myIterator<int> *it = cntr.createIterator();
    for( it->begin();it->end(); it++)
            std::cout<<  it->data()<<" ";
std::cout<<std::endl;
    return 0;
}
