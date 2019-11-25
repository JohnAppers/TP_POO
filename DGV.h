#ifndef DGV_H
#define DGV_H

#include <vector>
#include "Carro.h"

class DGV
{
    vector<Carro> carros;
    vector<Piloto> pilotos;

public:
    void adicionaCarro(Carro carro);
    void retiraCarro(Carro &carro);
    void adicionaPiloto(Piloto &piloto);
    void retiraPiloto(Piloto &piloto);

    const string &getCarrosAsString() const;
    const string &getPilotosAsString() const;
    const string &getAsString() const;
};

#endif