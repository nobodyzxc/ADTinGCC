#include "node.h"

struct Node{
    Object elt;
    Node next;
    const char* eltType;
    size_t eltSize;
};

Object getObj(Node self){
    return self->elt;
}

Node getNext(Node self){
    return self->next;
}

Node *getNextPtr(Node next){
    return &(next->next);
}

const char* getType(Node self){
    return self->eltType;
}

size_t getSize(Node self){
    return self->eltSize;
}

Node _Node_new(Object elt , Node next ,
        const char* type , size_t size){
    Node node = malloc(sizeof(struct Node));
    node->elt = elt , node->next = next;
    node->eltType = type , node->eltSize = size;
    return node;
}

void Node_clear(Node self){
    free(self->elt);
}

void Node_delete(Node self){
    Node_clear(self);
    free(self);
}
