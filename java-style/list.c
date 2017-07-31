#include "list.h"
#include <assert.h>

#define implFunc(ADT , func) (ADT ## _ ## func)
#define bindFunc(ADT , func) \
    .func = implFunc(ADT , func)

#define assnk(TYPE , des , org) \
    memcpy((TYPE *)&des , &(TYPE){org} , sizeof(TYPE))

struct Node{
    ListElt elt;
    pNode next;
};

/* access functions */
int List_empty(List self){
    return self->head == NULL;
}

ListElt List_front(List self){
    return self->head->elt;
}

ListElt List_back(List self){
    return self->tail->elt;
}

unsigned int List_length(List self){
    return self->len;
}

/* manipulation prcedure */
List List_push_front(List self , ListElt elt){
    assnk(unsigned int , self->len , self->len + 1);
    pNode node = malloc(sizeof(struct Node));
    node->elt = elt , node->next = self->head;
    assnk(pNode , self->head , node);
    if(!self->tail)
        assnk(pNode , self->tail , self->head);
    return self;
}

List List_push_back(List self , ListElt elt){
    assnk(unsigned int , self->len , self->len + 1);
    self->tail->next = malloc(sizeof(struct Node));
    assnk(pNode , self->tail , self->tail->next);
    self->tail->elt = elt , self->tail->next = NULL;
    if(!self->head)
        assnk(pNode , self->head , self->tail);
    return self;
}

List List_pop_front(List self){
    assert(self->len != 0);
    pNode del = self->head;
    assnk(pNode , self->head , self->head->next);
    if(self->head->next == NULL)
        assnk(pNode , self->tail , NULL);
    free(del);
    assnk(unsigned int , self->len , self->len - 1);
    return self;
}

List List_pop_back(List self){
    assert(self->len != 0);
    pNode del = self->head;
    assnk(pNode , self->head , self->head->next);
    if(self->head->next == NULL)
        assnk(pNode , self->tail , NULL);
    free(del);
    assnk(unsigned int , self->len , self->len - 1);
}

const struct List klass = {
    .len = 0 ,
    .head = NULL ,
    .tail = NULL ,
    /* access functions */
    bindFunc(List , empty) ,
    bindFunc(List , front) ,
    bindFunc(List , back) ,
    bindFunc(List , length) ,
    /* manipulation prcedure */
    bindFunc(List , push_front) ,
    bindFunc(List , push_back) ,
    bindFunc(List , pop_front) ,
    bindFunc(List , pop_back) ,
};

List List_init(List self){
    return (List)memcpy(self , &klass , sizeof(klass));
}

List List_new(){
    return List_init(malloc(sizeof(klass)));
}
