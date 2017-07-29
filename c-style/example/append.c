#include "../list.h"

List appened(List self , List app){
    if(empty(self)) return copy(app);
    else{
        List cdrRef = cdr(self);
        List rtn = cons(appened(cdrRef , app), car(self));
        delete(cdrRef);
        return rtn;
    }
}

int main(void){

}
