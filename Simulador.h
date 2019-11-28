#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "DGV.h"
#include "Campeonato.h"

class Simulador
{
    DGV dgv;
    Campeonato campeonato;

public:
    //Carrega lista de carros do ficheiro, retorna null em caso de erro
    void *carregaC(string file_name);
    //Carrega lista de Pilotos do ficheiro, retorna null em caso de erro
    void *carregaP(string file_name);
    //Carrega lista de Autodromos do ficheiro, retorna null em caso de erro
    void *carregaA(string file_name);

    //Cria carro
    void cria(char tipo, string marca, int capacidadeInicial, int capacidadeMaxima, int velocidadeMax, string modelo);
    //cria Piloto
    void cria(char tipo, string nome);
    //cria Autodromo
    void cria(char tipo, int max_carros, int comprimento, string nome);

    //Apaga carro/Piloto/Autodromo
    void apaga(char tipo, string id);

    //Associa um carro a um piloto
    void entraCarro(char id, string nome);
    //retira piloto de um carro
    void saiCarro(char id, string nome);

    DGV &getDGV();
    Campeonato &getCampeonato();
};

#endif