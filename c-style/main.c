#include "adt.h"
#include "list.h"
#include <stdio.h>

void print_p(Node node){
    for(int i = 0 ; i < 4 ; i++)
        printf("%d " , elt(int* , node)[i]);
    puts("");
}

void print(Node node){
    printf("node type is a %s => " , getType(node));
    if(isChar(node)){
        if(isArray(node))
            puts(arr(char , node));
        else if(isPointer(node))
            puts(elt(char* , node));
        else
            printf("%c\n" , elt(char , node));
    }
    else if(isInt(node)){
        if(isArray(node)){
            for(int i = 0 ; i < 5 ; i++)
                printf("%d " , arr(int , node)[i]);
            puts("");
        }
        else{
            printf("%d\n" , elt(int , node));
        }
    }
    else
        printf("Object @ %p \n" , getObj(node));
}

int main(void){
    int a[10] = {1 , 2 , 3 , 4 , 5};
    char ch = 'c';
    List ls = new(List);
    printf("list's address is %p\n" , ls);
    printf("List's len is %d\n" , length(ls));
    append(ls , LIT(1));
    append(ls , LIT('b')); /* literal char treats as int */
    append(ls , ch);
    append(ls , "cdef");
    append(ls , a);
    append(ls , ls);
    map(ls , print);
    printf("List's len is %d\n" , length(ls));

    puts("\ncopyed list test");
    List cp = back(List , ls);
    //List cp = *(List*)last(ls);
    map(cp , print);
    //map(cp , back(List , ls));
    puts("end");

    puts("\nclear ls...");
    while(!empty(ls)) pop(ls , 0);

    empty(ls) ? puts("is empty!") : puts("not empty");
    delete(ls);
    puts("\nUB after delete\n");
    empty(ls) ? puts("is empty!") : puts("not empty");
    printf("List's len is %d\n" , length(ls));
    return 0;
}
