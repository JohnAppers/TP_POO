#ifndef AUTODROMO_H
#define AUTODROMO_H


#include <string>
#include"Pista.h"
#include"Carro.h"

class Piloto;

class Autodromo
{
private:
    string nome;
    Pista pista;
    Carro **garagem;
    
public:
    Autodromo(Pista pista);
    ~Autodromo();
};

#endif