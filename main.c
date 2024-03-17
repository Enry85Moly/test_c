#include <stdio.h>
#include "complex.h"

// esempio
void main(void)
{
    Complesso* c1 = Crea_Complesso(3.4, -0.8); // costruttore nello heap
    SetReal(c1, 2.9);
    SetImm(c1, 3.7);
    printf("numero complesso = (%f, %f)\n", GetReal(c1), GetImm(c1)); // printf = implementazione NON rientrante (not "thread-safe")
    // c1->real; not allowed
    while(1);
}