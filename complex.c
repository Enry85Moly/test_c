#include "complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define custom_assert(expression, message) \
        if (!(expression)) { \
            fprintf(stderr, "Asserzione fallita: %s\n", message); \
            exit(EXIT_FAILURE); \
        } \

struct Complesso
{
    float real;
    float imm;
};

// funzioni pubbliche che accedono ai campi interni della struct Complesso (definizioni)

/*
Complesso* Crea_Complesso(const float r, const float i)
{
    Complesso* pun = (Complesso*)malloc( sizeof(Complesso) );
    if(pun)
    {
        // malloc è riuscita ad allocare nello heap (c'è spazio nello heap)
        pun->real = r;
        pun->imm  = i;
        return pun;
    }
    else
    {
        // malloc NON è riuscita ad allocare nello heap (NON c'è spazio nello heap)
        fprintf(stderr, "errore: %s\n", "problema di allocazione nello heap"); 
        exit(EXIT_FAILURE);
    }
}
*/

/*
Complesso* Crea_Complesso(const float r, const float i)
{
    Complesso* pun = (Complesso*)malloc( sizeof(Complesso) );
    assert(pun);
    // malloc è riuscita ad allocare nello heap (c'è spazio nello heap)
    pun->real = r;
    pun->imm  = i;
    return pun;
}
*/

Complesso* Crea_Complesso(const float r, const float i)
{
    Complesso* pun = (Complesso*)malloc( sizeof(Complesso) );
    custom_assert(pun, "problema di allocazione nello heap");
    // malloc è riuscita ad allocare nello heap (c'è spazio nello heap)
    pun->real = r;
    pun->imm  = i;
    return pun;
}

void Distruggi_Complesso(const Complesso* const num)
{
    if(num) // se c'è heap da disallocare ...
     free(num); // ... lo disallochiamo
}

void SetReal(Complesso* const c, const float r)
{
    c->real = r;
}

void SetImm(Complesso* const c, const float i)
{
    c->imm = i;
}

float GetReal(const Complesso* const c)
{
    return c->real;
}

float GetImm(const Complesso* const c)
{
    return c->imm;
}

void somma_complessa__modo1
(
    Complesso* const ris, const Complesso* const add1, const Complesso* const add2
)
{
    ris->real = add1->real + add2->real;
    ris->imm  = add1->imm  + add2->imm;
}

Complesso* somma_complessa__modo2
(
    const Complesso* const add1, const Complesso* const add2
)
{
    Complesso* pun = (Complesso*)malloc( sizeof(Complesso) );
    pun->real = add1->real + add2->real;
    pun->imm  = add1->imm  + add2->imm;
    return pun;
}