#include "operation.h"

operation add, diff, mult, divis;
void* handle;

void getFunc(const char* lib) {
    handle = dlopen(lib, RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
}

struct Operation* load_operation() {

    getFunc("libadd.so");
    operation add = (operation)dlsym(handle, "add");

    getFunc("libdiff.so");
    operation diff = (operation)dlsym(handle, "diff");

    getFunc("libmult.so");
    operation mult = (operation)dlsym(handle, "mult");

    getFunc("libdivis.so");
    operation divis = (operation)dlsym(handle, "divis");

    struct Operation* operations = malloc(4 * sizeof(struct Operation));

    operations[0].operator = '+';
    operations[0].op = add;

    operations[1].operator = '-';
    operations[1].op = diff;

    operations[2].operator = '*';
    operations[2].op = mult;

    operations[3].operator = '/';
    operations[3].op = divis;

    return operations;
}

int isOperation(char symb) {
    if (symb == '+' || symb == '-') return 1;
    if (symb == '*' || symb == '/') return 2;
    return 0;
}

int getOp(char op, int a, int b) {
    struct Operation* operations = load_operation();
    for (unsigned int i = 0; i < 4; i++ ) {
        if (op == operations[i].operator) {
            return operations[i].op(a, b);
        }
    }

    return 0;
}