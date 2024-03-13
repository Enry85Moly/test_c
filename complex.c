#include "complex.h"

struct Complesso
{
    float real;
    float imm;
};

// funzioni pubbliche (definizioni)

Complesso* Crea_Complesso(const float r, const float i)
{
    Complesso* pun = (Complesso*)malloc( sizeof(Complesso) );
    pun->real = r;
    pun->imm  = i;
    return pun;
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