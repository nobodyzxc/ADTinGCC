#ifndef ADT_H
#define ADT_H

#include <stddef.h> /* for size_t */
#include <stdlib.h> /* for malloc */
#include <string.h> /* for strstr */

typedef void *Object;

#define new(ADT) ADT ## _new()

#define copy(ADT , ...) _Generic((ADT), \
    Node: Node_copy , \
    List: List_copy \
    /* default: copy  \ */ \
    )(ADT , ##__VA_ARGS__)
/* define you own copy */

/* va args delete */
#define delete(...) \
    MAP_LIST(_delete , __VA_ARGS__)

/* single arg delete */
#define _delete(ADT) _Generic((ADT), \
    List: List_delete \
    /* default: delete  \ */ \
    )(ADT)
/* define you own delete */

#define clear(ADT) _Generic((ADT), \
    List: List_clear \
    /* default: clear  \ */ \
    )(ADT)
/* define you own clear */


/* accept var only */
#define isVarAnArray(x) ((void*)(long)&(x) == (void*)(long)(x))

/* accept var only */
/* pay attention on char literal ,
 * its type is int in C
 * */
#define typename(x) _Generic((x), \
        _Bool: "bool" , \
        _Bool*: (isVarAnArray(x) ? "bool[]" : "bool*") , \
        char: "char" , \
        char*: \
                                         \
        (isVarAnArray(x) ? "char[]" : "char*") , \
        int: "int" , \
        long int: "long int" , \
        long long int: "long long int" , \
        unsigned int: "unsigned int" , \
        unsigned long int: "unsigned long int" , \
        unsigned long long int: "unsigned long long int" , \
        int*: (isVarAnArray(x) ? "int[]" : "int*") , \
        float: "float" , \
        float*: (isVarAnArray(x) ? "float[]" : "float*") , \
        double: "double" , \
        double*: (isVarAnArray(x) ? "double[]" : "double*") , \
        Node: "Node" , \
        Node*: (isVarAnArray(x) ? "Node[]" : "Node*") , \
        List: "List" , \
        List*: (isVarAnArray(x) ? "List[]" : "List*") , \
        default: (isVarAnArray(x) ? "type[]" : "type*") \
        )

char _typeisa[25];
#define typeisa(x) strcat( \
                    strcpy(_typeisa , #x " is a ") , \
                    typename(x))

/* literal of number */
#define LITN(x) (typeof(x)){x}
/* literal of character */
#define LITC(x) (char){x}

#define newObj(e) \
    memcpy( \
            malloc(sizeof(e)) , \
            &(e) , \
            sizeof(e) \
            )

#define _newObj(p , size) \
    memcpy( \
            malloc(size) , \
            p , \
            size \
          )

/* objArgs :
 * Object obj , const char* type , size_t size
 * (new entity , entity datatype , entity datasize)
 * */

#define objArgs(x) \
    newObj(x) , typename(x) , sizeof(x)

#endif
