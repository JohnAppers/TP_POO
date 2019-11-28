#include "Simulador.h"
#include <iostream>
#include <fstream>

void *Simulador::carregaC(string file_name)
{
    ifstream f;
    string line;
    
    int capacidadeInicial, capacidadeMaxima, velocidadeMax;
    string marca, modelo;

    f.open(file_name);

    while (getline(f, line))
    {
        istringstream is(line);
        if (!(is >> capacidadeInicial >> capacidadeMaxima >> velocidadeMax >> marca >> modelo))
            return nullptr;

        dgv.adiciona(Carro(marca, capacidadeInicial, capacidadeMaxima, velocidadeMax, modelo));
    }
    f.close();
}

void *Simulador::carregaP(string file_name)
{
    ifstream f;
    string line;
    
    string nome;

    f.open(file_name);

    while (getline(f, line))
    {
        istringstream is(line);
        if (!(is >> nome))
            return nullptr;
        dgv.adiciona(Piloto(nome));
    }
    f.close();
}

void *Simulador::carregaA(string file_name)
{
    ifstream f;
    string line;
    
    int max_carros, comprimento;
    string nome;

    f.open(file_name);

    while (getline(f, line))
    {
        istringstream is(line);
        if (!(is >> max_carros >> comprimento >> nome))
            return nullptr;

        campeonato.adiciona(Autodromo(max_carros, comprimento, nome));
    }
    f.close();
}

void Simulador::cria(char tipo, string marca, int capacidadeInicial, int capacidadeMaxima, int velocidadeMax, string modelo)
{
    if (tipo == 'c')
        dgv.adiciona(Carro(marca, capacidadeInicial, capacidadeMaxima, velocidadeMax, modelo));
}

void Simulador::cria(char tipo, string nome)
{
    if (tipo == 'p')
        dgv.adiciona(Piloto(nome));
}

void Simulador::cria(char tipo, int max_carros, int comprimento, string nome)
{
    if (tipo == 'a')
        campeonato.adiciona(Autodromo(max_carros, comprimento, nome));
}

void Simulador::apaga(char tipo, string id)
{

    switch (tipo)
    {
    case 'c':
        if (id.length() == 1)
        {
            dgv.retira(id[0]);
        }
        break;
    case 'p':
        dgv.retira(id);
        break;
    case 'a':
        campeonato.retira(id);
    default:
        /*
        !Opcao invalida
        */
        break;
    }
}

void Simulador::entraCarro(char id, string nome)
{
    dgv.getCarro(id)->atribuiPiloto(dgv.getPiloto(nome));
}

void Simulador::saiCarro(char id, string nome)
{
}
DGV &Simulador::getDGV()
{
    return dgv;
}

Campeonato &Simulador::getCampeonato()
{
    return campeonato;
}