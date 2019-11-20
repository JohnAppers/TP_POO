#ifndef PISTA_H 
#define PISTA_H
#include<vector>
#include"Carro.h"

#define MAX_CARROS 10

class Pista{
    int max_carros;
    const int comprimento;
    vector<Carro*> carros;
    Carro **lugares;
public:
    Pista(int max_carros);
};

#endif 