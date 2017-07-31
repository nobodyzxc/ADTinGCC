#include <stdio.h>
#include "../list.h"

void print_s(Node node){
    printf("%s " , arr(char , node));
}

List rec_appened(List self , List app){
    if(empty(self)) return copy(app);
    else{ /* O(N) */
        List cdrRef = cdr(self);

        List nth_appn =
            cons(car(self) , rec_appened(cdrRef , app));

        ListRef_delete(cdrRef);
        return nth_appn;
    }
}

List nth_appened(List self , List p){
    List nth_appn = copy(self); /* O(N^2) */
    for(int i = 0 ; i < length(p) ; i++)
        snoc(nth(i , p) , nth_appn);
    return nth_appn;
}

int main(void){
    List self = List("a" , "b" , "c");
    List appd = List("d" , "e" , "f");

    List rec_app = rec_appened(self , appd);
    List nth_app = nth_appened(self , appd);
    List fold_app =
        foldl((void(*)(Node , Object))snoc ,
    /* cast a fp is UB :P (rock!)
     * https://stackoverflow.com/questions/559581/
     * casting-a-function-pointer-to-another-type
     * */
                copy(self) , appd);

    map(print_s , rec_app) , puts("");
    map(print_s , nth_app) , puts("");
    map(print_s , fold_app) , puts("");

    delete(self , appd , rec_app , nth_app , fold_app);
    return 0;
}
