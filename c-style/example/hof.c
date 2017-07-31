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
    map(print_i , li_i);puts("");
    map(addOne  , li_i);
    map(print_i , li_i);puts("");

    List li_c = List();
    for(char c = 'a' ; c < 'z' ; c++)
        push_front(li_c , c);
    map(print_c , li_c);puts("");
    map(toUpper , li_c);
    map(print_c , li_c);puts("");

    List li_s = List("list" , "in" , "c");
    map(print_s , li_s);puts("");

    /*literal in int and char should use LIT */
    /* BUT! literal char will store as int ! */
    List li_mix = List(LITN(0) , LITN('1') , "2");
    map(print_mix , li_mix);puts("");

    char ch = '1';
    List li_expect = List(LITN(0) , LITC('1') , "2");
    map(print_mix , li_expect);puts("");

    List cdrls = cdrL(li_expect);
    map(print_mix , cdrls);puts("");

    delete(li_i);
    delete(li_c);
    delete(li_s);
    delete(li_mix);
    delete(li_expect);
    delete(cdrls);
    return 0;
}
