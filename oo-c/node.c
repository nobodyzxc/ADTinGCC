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

Node *getPtrOfNext(Node next){
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

Node Node_copy(Node inst , Node next){
    return _Node_new(
            _newObj(inst->elt ,
                    inst->eltSize) ,
            /* newObj is important */
            next ,
            inst->eltType ,
            inst->eltSize
            );
}

void Node_clear(Node self){
    free(self->elt);
}

void Node_delete(Node self){
    Node_clear(self);
    free(self);
}
