#ifndef ADT_H
#define ADT_H

typedef void *Object;


#define new(ADT) ADT ## _new()

#define delete(ADT) _Generic((ADT), \
    List: List_delete \
    )(ADT)

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

#define LIT(x) (typeof(x)){x}

#define newElt(val) \
    memcpy( \
            malloc(sizeof(val)) , \
            &(val) , \
            sizeof(val) \
            )
#endif
