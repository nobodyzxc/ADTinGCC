#define Elt(TYPE) typedef TYPE * ptr; ptr

#include<stdio.h>
int main(void){
    Elt(int) a , b;
    Elt(int) d , c;
    printf("%lu %lu\n" , sizeof(a) , sizeof(b));
    printf("%lu %lu\n" , sizeof(c) , sizeof(d));
}

