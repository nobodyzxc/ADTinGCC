#include "../list.h"
#include <stdio.h>

void addOne(Node node){
    elt(int , node) += 1;
}

void print_i(Node node){
    printf("%d " , elt(int , node));
}

void toUpper(Node node){
    elt(char , node) += ('A' - 'a');
}

void print_c(Node node){
    printf("%c " , elt(char , node));
}

void print_s(Node node){
    printf("%s " , arr(char , node));
}

void print_mix(Node node){
    int cond[] = {
        isInt(node) ,
        isChar(node) ,
        isChar(node) && isArray(node)
    } , p;
    for(int i = 0 ; i < 3 ; i++)
        if(cond[i]) p = i;
    void (*fp[])(Node) = {
        print_i , print_c , print_s
    };
    fp[p](node);
}

int main(void){
    List li_i = new(List);
    for(int i = 0 ; i < 10 ; i++)
        push_front(li_i , i);
    map(li_i , print_i);puts("");
    map(li_i , addOne);
    map(li_i , print_i);puts("");

    List li_c = List();
    for(char c = 'a' ; c < 'z' ; c++)
        push_front(li_c , c);
    map(li_c , print_c);puts("");
    map(li_c , toUpper);
    map(li_c , print_c);puts("");

    List li_s = List("list" , "in" , "c");
    map(li_s , print_s);puts("");

    /*literal in int and char should use LIT */
    /* BUT! literal char will store as int ! */
    List li_mix = List(LITN(0) , LITN('1') , "2");
    map(li_mix , print_mix);puts("");

    char ch = '1';
    List li_expect = List(LITN(0) , LITC('1') , "2");
    map(li_expect , print_mix);puts("");

    List cdrls = cdrL(li_expect);
    map(cdrls , print_mix);puts("");

    delete(li_i);
    delete(li_c);
    delete(li_s);
    delete(li_mix);
    delete(li_expect);
    delete(cdrls);
    return 0;
}
