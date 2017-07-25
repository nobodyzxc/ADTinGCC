#include "adt.h"
#include "list.h"
#include <stdio.h>

void print_p(Node node){
    for(int i = 0 ; i < 4 ; i++)
        printf("%d " , elt(int* , node)[i]);
    puts("");
}

void print(Node node){
    printf("%s" , "type is a ");
    printf(getType(node));
    if(isChar(node)){
//        if(isPointer(node))
            puts(arr(char , node));
//        else if(isArray(node))
//            puts(arr(char , node));
//        else
//            printf("%c \n" , elt(char , node));
    }
    else if(isInt(node))
        printf("%d \n" , elt(int , node));
    else
        printf("%p \n" , getObj(node));
}

int main(void){
    int a[10] = {1 , 2 , 3};
    char ch = 'a';
    List ls = new(List);
//    append(ls , p);
    append(ls , a);
    append(ls , LIT("asdf"));
    printf("len is %d\n" , length(ls));

    map(ls , print);
    puts("fuck");
    return 0;
}
