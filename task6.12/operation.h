#ifndef OPERATION_H
#define OPERATION_H

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*operation)(int, int);

struct Operation {
    char operator;
    operation op;
};

struct Operation* load_operation() ;
int isOperation(char symb);
int getOp(char op, int a, int b); 

#define SIZE_OP (sizeof(*operations) / sizeof(struct Operation))

#endif //OPERATION_H