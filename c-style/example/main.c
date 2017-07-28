#include "../list.h"
#include <stdio.h>

/* higher order function for map */
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
                /* try obj macro instead of arr here you will get a warning */
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
    List ls = List(LITN(1) , LITN('b') , ch , "cdef" , a);
    snoc(ls , ls);

    printf("ls's address is %p\n" , ls);
    map(ls , print);
    printf("ls's len is %d\n" , length(ls));
    puts("\nsnoced self's test");
    List snoced = back(List , ls);
    map(snoced , print);

    puts("\npop ls @ -2\n");
    pop(ls , -2);
    puts("ls remap print");
    map(ls , print);
    puts("");
    puts("snoced self remap print");
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
