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
void SetReal(Complesso* const, const float);
void SetImm(Complesso* const, const float);
float GetReal(const Complesso* const);
float GetImm(const Complesso* const);