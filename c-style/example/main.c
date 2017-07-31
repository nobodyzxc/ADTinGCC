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
    push_back(ls , ls);

    printf("ls's address is %p\n" , ls);
    map(print , ls);
    printf("ls's len is %d\n" , length(ls));
    puts("\nsnoced self's test");
    List snoced = back(List , ls);
    map(print , snoced);

    puts("\npop ls @ -2\n");
    pop(ls , -2);
    puts("ls remap print");
    map(print , ls);
    puts("");
    puts("snoced self remap print");
    map(print , back(List , ls));

    puts("\ncopy list test");
    List cp = copy(ls);
    map(print , cp);
    printf("cp's len is %d\n" , length(ls));
    puts("\npop ls @ -1");
    pop(ls , -1);
    puts("\napply print on ls");
    map(print , ls);
    puts("\napply print on copy");
    map(print , cp);

    puts("\nclear ls...");
    clear(ls);
    empty(ls) ? puts("ls is empty!") : puts("ls is not empty");

    puts("\napply print on copy");
    map(print , cp);
    clear(cp);

    delete(ls , snoced , cp);
    puts("\nUB after delete\n");
    empty(ls) ? puts("ls is empty!") : puts("ls is not empty");
    printf("ls's len is %d\n" , length(ls));
    return 0;
}
