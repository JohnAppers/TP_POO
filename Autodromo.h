#ifndef AUTODROMO_H
#define AUTODROMO_H

using namespace std;

#include <string>
#include"Garagem.h"
#include"Pista.h"

class Autodromo
{
private:
    string nome;
    Pista pista;
    Garagem garagem;
    
public:
    Autodromo();
    ~Autodromo();
};

#endif