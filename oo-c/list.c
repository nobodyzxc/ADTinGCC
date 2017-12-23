#include "list.h"
#include <assert.h>

struct List{
    unsigned int len;
    Node head , tail;
};


/* access functions */
int empty(List self){
    return self->head == NULL;
}

Node car(List self){
    assert(!empty(self) && "calling car on an empty list");
    return self->head;
}

Node rac(List self){
    assert(!empty(self) && "calling last on an empty list");
    return self->tail;
}

List cdr(List self){
    List rtn = List_new();
    if(empty(self)) return rtn;
    rtn->len = self->len - 1;
    rtn->head = getNext(self->head);
    rtn->tail = rtn->head ? self->tail : NULL;
    return rtn;
}

Object nth(int idx , List self){
    if(idx < 0) idx += self->len;
    assert(idx < self->len);
    assert(self->len != 0);
    Node iter = self->head;
    while(idx--)
        iter = getNext(iter);
    return iter;
}

unsigned int length(List self){
    return self->len;
}

/* manipulation prcedure
 * */

List _push_front(List self , Object elt ,
        const char* type , size_t size){
    self->len = self->len + 1;
    self->head = _Node_new(elt , self->head , type , size);
    if(!self->tail) self->tail = self->head;
    return self;
}

List _push_back(List self , Object elt ,
        const char* type , size_t size){
    self->len = self->len + 1;
    *(empty(self) ? &self->tail : getPtrOfNext(self->tail)) =
        self->tail = _Node_new(elt , NULL , type , size);
    if(!self->head) self->head = self->tail;
    return self;
}

/* will copy a new one and cons it */
List cons(Node inst , List self){
    self->len = self->len + 1;
    self->head = copy(inst , self->head);
    if(!self->tail) self->tail = self->head;
    return self;
}

List snoc(Node inst , List self){
    self->len = self->len + 1;
    *(empty(self) ? &self->tail : getPtrOfNext(self->tail)) =
        self->tail = copy(inst , NULL);
    if(!self->head) self->head = self->tail;
    return self;
}

List pop(List self , int idx){
    if(idx < 0) idx += self->len;
    assert(idx < self->len);
    assert(self->len != 0);
    self->len -= 1;
    Node *ppn = &self->head;
    while(idx--)
        ppn = getPtrOfNext(*ppn);
    Node del = (*ppn);
    (*ppn) = getNext(del);
    if(self->len == 0)
        self->head = self->tail = NULL;
    free(getObj(del));
    free(del);
    return self;
}

List map(void (*fp)(Node node) , List self){
    Node iter = self->head;
    while(iter) fp(iter) , iter = getNext(iter);
    return self;
}

Object foldl(void (*fp)(Node node , Object acc) ,
        Object acc , List self){
    Node iter = self->head;
    while(iter) fp(iter , acc) , iter = getNext(iter);
    return acc;
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
        snoc(iter , copy) , iter = getNext(iter);
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

void ListRef_delete(List ref){
    free(ref);
}
