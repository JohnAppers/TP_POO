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
    int comprimento;
    //Ponteiro para os carros que estão na pista
    Carro **classificacao = nullptr;
    //para saber se está a decorrer uma corrida
    bool a_correr = false;

public:
    //Construtores
    Pista(int max_carros, const int comprimento);
    Pista(const Pista &);

    //Destrutores
    ~Pista();

    //funcoes get
    const int getMaxCarros() const;
    const int getNCarros() const;
    const int getComprimento() const;
    const Carro *const *getClassificacao() const;
    const bool getACorrer() const;
    const string &getAsString() const;

    //funcoes set
    void setMaxCarros(int max_carros);
    void setComprimento(int comprimento);

    //adiciona Carro ao array
    //retorna -1 em caso não seja possivel adicionar
    int adicionaCarro(Carro &);
    //Elimina Carro do array
    void eliminaCarro(Carro &);

    //Insere piloto num carro
    // void inserePiloto(Piloto &piloto, Carro &carro);

    int iniciaCorrida();
    void avanca(int tempo);
    //retorna nullptr caso nenhum carro tenha ligado o sinal de emergencia
    //retorna o carro
    Carro const *verificaEmergencia();
    void terminaCorrida() const;
    Pista &operator=(const Pista &pista);
    //inline const int getComprimento() const{return this->comprimento;};
};

#endif