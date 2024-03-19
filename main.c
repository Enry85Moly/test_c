#include <stdio.h>
#include "complex.h"
#include "unit_test_complex.h"

// esempio
void main(void)
{
    Complesso* c0 = Crea_Complesso(3.4, -0.8); // costruttore nello heap
    SetReal(c0, 2.9);
    SetImm(c0, 3.7);
    printf("numero complesso = (%f, %f)\n", GetReal(c0), GetImm(c0)); // printf = implementazione NON rientrante (not "thread-safe")
    // c0->real; not allowed
    Distruggi_Complesso(c0);
    //-------------------------------------------------------------------------------
    Complesso* c1 = Crea_Complesso(0, 0);
    Complesso* c2 = Crea_Complesso(2, 1);
    Complesso* c3 = Crea_Complesso(5, 8);
    somma_complessa__modo1(c1, c2, c3);
    printf("somma complessa c1 = (%f, %f)\n", GetReal(c1), GetImm(c1));
    Complesso* c4 = somma_complessa__modo2(c2, c3);
    printf("somma complessa c4 = (%f, %f)\n", GetReal(c4), GetImm(c4));
    Distruggi_Complesso(c1);
    Distruggi_Complesso(c2);
    Distruggi_Complesso(c3);
    Distruggi_Complesso(c4);
    //-------------------------------------------------------------------------------
    test_somma();
    while(1);
}