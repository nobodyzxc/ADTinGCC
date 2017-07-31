#include "../list.h"
#include <stdio.h>

int main(void){
    List ls; // Empty Object
    ls = List_new(); // malloc a new empty List to ls
    delete(ls);      // destructor
    ls = new(List);  // use macro to implement adts polymorphism
                     // syntax sugar of List_new()
    delete(ls);
    ls = List("I'm a list's head member obj" ,
             "I'm second!" , "I'm third");
    // syntax sugar of
    // push_back(push_back(push_back ...push_back(new(List) , elt) , elt) , elt)
    // you can also make a empty list with List()
    delete(ls);
    return 0;
}
