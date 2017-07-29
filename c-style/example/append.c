#include <stdio.h>
#include "../list.h"

void print_s(Node node){
    printf("%s " , arr(char , node));
}

List appened(List self , List app){
    if(empty(self)) return copy(app);
    else{ /* O(N) */
        List cdrRef = cdr(self);
        List rtn = cons(appened(cdrRef , app), car(self));
        ListRef_delete(cdrRef);
        return rtn;
    }
}

List apped(List self , List p){
    List rtn = copy(self); /* O(N^2) */
    for(int i = 0 ; i < length(p) ; i++)
        snoc(rtn , nth(p , i));
    return rtn;
}

int main(void){
    List self = List("a" , "b" , "c");
    List appd = List("d" , "e" , "f");
    List rslt = appened(self , appd);
    List rt = apped(self , appd);
    map(rslt , print_s) , puts("");
    map(rt , print_s) , puts("");
    delete(self);
    delete(appd);
    delete(rslt);
    delete(rt);
    return 0;
}
