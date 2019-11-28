#ifndef DGV_H
#define DGV_H

#include <vector>
#include "Carro.h"

class DGV
{
    vector<Carro> carros;
    vector<Piloto> pilotos;

public:
    void adiciona(Carro carro);
    void adiciona(Piloto piloto);
    //retira carro
    void retira(char id);
    //retira piloto
    void retira(string nome);

    //Devolve carro com o mesmo id que "id"
    Carro *getCarro(char id);
    //devolve o piloto com o mesmo nome que "nome"
    Piloto *getPiloto(string nome);

    const string &getCarrosAsString() const;
    const string &getPilotosAsString() const;
    const string &getAsString() const;
};

#endif