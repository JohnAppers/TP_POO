#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include <vector>
#include "Autodromo.h"


class Campeonato
{

    int n_corridas;
    vector<Autodromo> autodromos;

public:
    void adiciona(Autodromo autodromo);
    void retira(string nome);
    const string&  getAsString()const;
    vector<Autodromo>& getAutodromo();
};

#endif