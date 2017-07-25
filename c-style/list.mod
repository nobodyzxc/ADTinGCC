#ifndef LIST_H
#define LIST_H
//http://en.cppreference.com/w/c/language/generic
//https://gcc.gnu.org/onlinedocs/gcc-5.3.0/gcc/Typeof.html
//http://tigcc.ticalc.org/doc/keywords.html

/* compiler requirements
 * gnu(typeof)
 * c11(_Generic)
 * */

#include <stdlib.h>
#include <string.h>

#define isArray(x) ((void*)&(x) == (void*)(x))

#define new(ADT) ADT ## _new()

#define delete(ADT) _Generic((ADT), \
    List: List_delete \
    )(ADT)

#define simple_adt_header(fname , type) \
    type* fname ## _new(type lit);

simple_adt_header(char , char);
simple_adt_header(int , int);
simple_adt_header(long_int , long int);
simple_adt_header(long_long_int , long long int);
simple_adt_header(unsigned_int , unsigned int);
simple_adt_header(unsigned_long_int , unsigned long int);
simple_adt_header(unsigned_long_long_int , unsigned long long int);
simple_adt_header(float , float);
simple_adt_header(double , double);
#define complex_adt_new(x) \
    memcpy(malloc(sizeof(x)) , &(x) , sizeof(x))

#define simple_adt_select(x) _Generic((x) , \
        char: char_new , \
        int: int_new , \
        long int: long_int_new , \
        long long int: long_long_int_new , \
        unsigned int: unsigned_int_new , \
        unsigned long int: unsigned_long_int_new , \
        unsigned long long int: unsigned_long_long_int_new , \
        float: float_new , \
        double: double_new \
        )(x)

#define newElt(x) _Generic((x), \
       char: \
        simple_adt_select(x) , \
       int: \
        simple_adt_select(x) , \
       long int: \
        simple_adt_select(x) , \
       long long int: \
        simple_adt_select(x) , \
       unsigned int: \
        simple_adt_select(x) , \
       unsigned long int: \
        simple_adt_select(x) , \
       unsigned long long int: \
        simple_adt_select(x) , \
       float: \
        simple_adt_select(x) , \
       double: \
        simple_adt_select(x) , \
        default: complex_adt_new(x) \
        )

#define typename(x) _Generic((x), \
        char: "char" , \
        int: "int" , \
        long int: "long int" , \
        long long int: "long long int" , \
        unsigned int: "unsigned int" , \
        unsigned long int: "unsigned long int" , \
        unsigned long long int: "unsigned long long int" , \
        float: "float" , \
        double: "double" , \
        int*: (isArray(x) ? "int[]" : "int*") , \
        default: "unknown" \
        )

char _typeisa[25];
#define typeisa(x) strcat(strcpy(_typeisa , #x " is a ") , typename(x))
    


typedef void *ListElt;
typedef struct List *List;
typedef struct Node *pNode;

/* constructor */
List List_new();
/* destructor */
void List_delete();
/* access functions */
int empty(List self);
ListElt front(List self);
ListElt back(List self);
unsigned int length(List self);
/* manipulation prcedure */
List cons(List self , ListElt elt);
#define cons(self , elt) \
    cons(self , newElt(elt))
List append(List self , ListElt elt);
#define append(self ,elt) \
    append(self , newElt(elt))
List pop(List self , int idx);
List map(List self , void (*fp)(void *elt));

#endif
