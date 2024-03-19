#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "complex.h"
#include "unit_test_complex.h"

/*
// Definizione di una macro personalizzata per l'assert
#define custom_assert(expression, message) \
    do { \
        if (!(expression)) { \
            fprintf(stderr, "Assertion failed: %s\n", message); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)
*/

// Definizione di una macro personalizzata per l'assert
#define custom_assert(expression, message) \
        if (!(expression)) { \
            fprintf(stderr, "Asserzione fallita: %s\n", message); \
            exit(EXIT_FAILURE); \
        } \

void test_somma(void)
{
    // testiamo la somma fra complessi con alcuni casi (anche casi limite)
    // il cui risultato atteso dovrebbe corrispondere a quello ottenuto 
    // dalla funzione under test: se il caso ottenuto diverge da quello atteso (assert),
    // allora segnaliamo l'errore a run-time

    Complesso* num1;
    Complesso* num2;
    Complesso* risult;
    


    printf("test somma normale:\n");
    num1 = Crea_Complesso(1, 3);
    num2 = Crea_Complesso(2, 1);
    risult = somma_complessa__modo2(num1, num2);
    // assert( GetReal(risult)==3 );
    // assert( GetImm(risult)==4 );

    custom_assert( GetReal(risult)==3 , "problema sulla parte reale");
    custom_assert( GetImm(risult)==4 ,  "problema sulla parte immaginaria");
    Distruggi_Complesso(num1);
    Distruggi_Complesso(num2);
    Distruggi_Complesso(risult);
    printf("OK\n");



    printf("test somma X - X:\n");
    num1 = Crea_Complesso(7, 5);
    num2 = Crea_Complesso(-7, -5);
    risult = somma_complessa__modo2(num1, num2);

    custom_assert( GetReal(risult)==0 , "problema sulla parte reale");
    custom_assert( GetImm(risult)==0 ,  "problema sulla parte immaginaria");
    Distruggi_Complesso(num1);
    Distruggi_Complesso(num2);
    Distruggi_Complesso(risult);
    printf("OK\n");


    
    printf("test somma 0 + 0:\n");
    num1 = Crea_Complesso(0, 0);
    num2 = Crea_Complesso(0, 0);
    risult = somma_complessa__modo2(num1, num2);

    custom_assert( GetReal(risult)==0 , "problema sulla parte reale");
    custom_assert( GetImm(risult)==0 ,  "problema sulla parte immaginaria");
    Distruggi_Complesso(num1);
    Distruggi_Complesso(num2);
    Distruggi_Complesso(risult);
    printf("OK\n");
}