#include "list.h"
#include <assert.h>

#define implFunc(ADT , func) (ADT ## _ ## func)
#define bindFunc(ADT , func) \
    .func = implFunc(ADT , func)

struct List{
    unsigned int len;
    Node head , tail;
};


/* access functions */
int empty(List self){
    return self->head == NULL;
}

Object head(List self){
/*    assert(!empty(self) && "calling head on an empty list"); */
    return getObj(self->head);
}

Object last(List self){
/*    assert(!empty(self) && "calling last on an empty list"); */
    return getObj(self->tail);
}

unsigned int length(List self){
    return self->len;
}

/* manipulation prcedure
 *
 * */

List _cons(List self , Object elt ,
        const char* type , size_t size){
    self->len = self->len + 1;
    self->head = _Node_new(elt , self->head , type , size);
    if(!self->tail) self->tail = self->head;
    return self;
}

List _push(List self , Object elt ,
        const char* type , size_t size){
    self->len = self->len + 1;
    *(empty(self) ? &self->tail : getNextPtr(self->tail)) =
        self->tail = _Node_new(elt , NULL , type , size);
    if(!self->head) self->head = self->tail;
    return self;
}

List pop(List self , int idx){
    if(idx < 0) idx += self->len;
    assert(idx < self->len);
    assert(self->len != 0);
    self->len = self->len - 1;
    Node *ppn = &self->head;
    while(idx--)
        ppn = getNextPtr(*ppn);
    Node del = (*ppn);
    (*ppn) = getNext(del);
    if(self->len == 0)
        self->head = self->tail = NULL;
    free(getObj(del)) , free(del);
    return self;
}

List map(List self , void (*fp)(Node node)){
    Node iter = self->head;
    while(iter) fp(iter) , iter = getNext(iter);
    return self;
}

const struct List klass = {
    .len = 0 ,
    .head = NULL ,
    .tail = NULL ,
};

List List_init(List self){
    return (List)memcpy(self , &klass , sizeof(klass));
}

List List_new(){
    return List_init(malloc(sizeof(klass)));
}

List List_copy(List inst){
    List copy = List_new();
    Node iter = inst->head;
    while(iter)
        _push(copy ,
                memcpy(
                    malloc(getSize(iter)) ,
                    getObj(iter) ,
                    getSize(iter)) ,
                getType(iter) ,
                getSize(iter)) ,
        iter = getNext(iter);
    return copy;
}

void List_clear(List self){
    unsigned int i = length(self);
    while(i--) pop(self , 0);
    self->head = self->tail = NULL;
}

void List_delete(List self){
    List_clear(self);
    free(self);
}
