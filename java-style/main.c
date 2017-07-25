#include "list.h"
#include <stdio.h>

int main(void){
    List ls = new(List);
    for(int i = 0 ; i < 10 ; i++)
        ls->push_front(ls , newElt(int , i));
    Elt(int) a = ls->front(ls);
    printf("%d\n" , *a);
    printf("%u\n" , ls->length(ls));
    return 0;
}
