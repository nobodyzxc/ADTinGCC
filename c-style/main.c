#include "adt.h"
#include "list.h"
#include "macro.h"
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
        printf("Object @ %p \n" , *(long*)getObj(node));
}

int main(void){
    int a[10] = {1 , 2 , 3 , 4 , 5};
    char ch = 'c';
    List ls = NULL;
    ls = List(LIT(1) , LIT('b') , ch , "cdef" , a);
    push(ls , ls);

    printf("ls's address is %p\n" , ls);
    map(ls , print);
    printf("ls's len is %d\n" , length(ls));
    puts("\npushed self's test");
    List pushed = back(List , ls);
    //List cp = *(List*)last(ls);
    map(pushed , print);
    //map(back(List , ls) , print);

    puts("\npop ls @ -2\n");
    pop(ls , -2);
    puts("ls remap print");
    map(ls , print);
    puts("");
    puts("pushed self remap print");
    map(back(List , ls) , print);

    puts("\ncopy list test");
    List cp = copy(ls);
    map(cp , print);
    printf("cp's len is %d\n" , length(ls));
    puts("\npop ls @ -1");
    pop(ls , -1);
    puts("\napply print on ls");
    map(ls , print);
    puts("\napply print on copy");
    map(cp , print);

    puts("\nclear ls...");
    clear(ls);
    empty(ls) ? puts("ls is empty!") : puts("ls is not empty");

    puts("\napply print on copy");
    map(cp , print);
    clear(cp);

    delete(ls);
    puts("\nUB after delete\n");
    empty(ls) ? puts("ls is empty!") : puts("ls is not empty");
    printf("ls's len is %d\n" , length(ls));
    return 0;
}
