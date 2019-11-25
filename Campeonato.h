#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include<vector>
#include"Autodromo.h"


class Campeonato
{

    int n_corridas;
    vector<Autodromo> Autodromos;
    
public:
    void adicionaAutodromo();
    void retiraAutodromo();
};


#endif