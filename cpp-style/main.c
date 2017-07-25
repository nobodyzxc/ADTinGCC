#include "list.h"
#include <stdio.h>

int main(void){
    pList pls = new(List);
    /* List *pls = new(List); */
    List(ls);
    /* List ls; init(List , &ls); */
    for(int i = 0 ; i < 10 ; i++){
        ls.push_front(&ls , newElt(int , i));
        pls->push_front(pls , newElt(int , i));
    }
    Elt(int) a = ls.front(&ls);
    printf("%d\n" , *a);
    printf("%u\n" , ls.length(&ls));
    return 0;
}
