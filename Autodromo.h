#ifndef AUTODROMO_H
#define AUTODROMO_H

#include <string>
#include "Pista.h"
#include "Carro.h"

class Piloto;

class Autodromo
{
private:
    string nome;
    Pista pista;
    vector<Carro*> garagem;

public:
    Autodromo(int max_carros, int comprimento, string nome);
    ~Autodromo();
    const string &getAsString() const;
    const string &getNome() const;

    //redefinição do operador =
    Autodromo& operator=(const Autodromo& autodromo);
};

#endif