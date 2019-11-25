#include "Simulador.h"
#include <iostream>
#include <fstream>

void Simulador::carrega(string file_name)
{
    ifstream f;
    string line;

    int capacidadeInicial, capacidadeMaxima;
    string marca, modelo;

    f.open(file_name);

    while (getline(f, line))
    {
        istringstream is(line);
        is >> capacidadeInicial >> capacidadeMaxima >> marca >> modelo;
        dgv.adicionaCarro(Carro(marca, capacidadeInicial, capacidadeMaxima, modelo));
    }
    f.close();
}

const DGV &Simulador::getDGV() const
{
    return dgv;
}