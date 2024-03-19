// #pragma once

#ifndef __complex_h__

#define __complex_h__
// dichiarazione "opaca" della struct Complesso (ovvero senza i campi interni)
typedef struct Complesso Complesso;

/*
dichiarazione chiara, NON opaca, che consentirebbe pun->campi_interni, nel main
typedef struct Complesso
{
    float real;
    float imm;
} Complesso;
*/

// funzioni pubbliche (prototipi)
Complesso* Crea_Complesso(const float, const float);
void Distruggi_Complesso(const Complesso* const);
void SetReal(Complesso* const, const float);
void SetImm(Complesso* const, const float);
float GetReal(const Complesso* const);
float GetImm(const Complesso* const);
void somma_complessa__modo1
(
    Complesso* const, const Complesso* const, const Complesso* const
);
Complesso* somma_complessa__modo2
(
    const Complesso* const add1, const Complesso* const add2
);

#endif