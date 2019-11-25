#ifndef PISTA_H
#define PISTA_H
#include <vector>
#include "Carro.h"

class Pista
{
    //Maximo de carros na pista
    int max_carros,
        //numero de carros no array
        n_carros = 0;
    //comprimento da pista
    const int comprimento;
    //Ponteiro para os carros que estão na pista
    Carro **classificacao = nullptr;
    //para saber se está a decorrer uma corrida
    bool a_correr = false;

public:
    //Construtores
    Pista(int max_carros, const int comprimento);
    Pista(const Pista &);

    //funcoes get
    const int getMaxCarros() const;
    const int getNCarros() const;
    const int getComprimento() const;
    const Carro *const *getClassificacao() const;
    const bool getACorrer() const;
    const string &getAsString() const;

    //adiciona/elimina Carro ao array
    void adicionaCarro(Carro &);
    void eliminaCarro(Carro &);

    //Insere piloto num carro
    void inserePiloto(Piloto &piloto, Carro &carro);

    void iniciaCorrida() const;
    void avancar(int tempo);
    void terminaCorrida() const;

    //inline const int getComprimento() const{return this->comprimento;};
};

#endif