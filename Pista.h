#ifndef PISTA_H
#define PISTA_H
#include <vector>
#include "Carro_teste.h"

#define DEF_COMP 100

class Pista
{

    int max_carros, n_carros = 0;
    const int comprimento;
    Carro_teste **lugares = nullptr;
    bool a_correr = false;

public:
    Pista(int max_carros, const int comprimento);
    Pista(const Pista &);
    const int getMaxCarros() const;
    const int getNCarros() const;
    const int getComprimento() const;
    const Carro_teste *const *getLugares() const;
    const bool getACorrer() const;
    const string &getAsString() const;
    void adicionaCarro( Carro_teste &);
    void eliminaCarro( Carro_teste &);
    //void inserePiloto(const Piloto&, const Carro&);
    const void iniciaCorrida() const;
    void avancar( int tempo);
    const void terminaCorrida() const;

    //inline const int getComprimento() const{return this->comprimento;};
};

#endif