
#include "Pista.h"
#include <sstream>
#include <iostream>

//construtores
Pista::Pista(int max_carros, int comprimento) : comprimento(comprimento), max_carros(max_carros) {}

Pista::Pista(const Pista &pista) : comprimento(pista.comprimento), max_carros(pista.max_carros) {
    n_carros=pista.n_carros;
    classificacao=new Carro*[n_carros];

    for(int i = 0; i<n_carros; i++)
        classificacao[i]=pista.classificacao[i];

    a_correr=pista.a_correr;

}

//Destrutores
Pista::~Pista()
{
    for (int i = 0; i < n_carros; i++)
    {
        delete[] classificacao[i];
    }
    delete[] classificacao;
}

//funcoes get
const int Pista::getMaxCarros() const { return max_carros; }

const int Pista::getNCarros() const { return n_carros; }

const int Pista::getComprimento() const { return comprimento; }

const bool Pista::getACorrer() const { return a_correr; }

const Carro *const *Pista::getClassificacao() const { return classificacao; }

const string &Pista::getAsString() const
{
    ostringstream os;
    static string s;

    os << "N maximo de carros: " << max_carros << endl
       << "Comprimento: " << comprimento << endl
       << "A correr: " << a_correr << endl;

    if (classificacao != nullptr)
    {
        os << "Carros: " << endl;
        for (int i = 0; i < n_carros; i++)
            os << "[" << i + 1 << "]:" << classificacao[i]->getAsString() << endl;
    }
    s = os.str();
    return s;
}

//Adiciona/elimina carros
int Pista::adicionaCarro(Carro &carro)
{
    if (!a_correr)
    {
        Carro **temp = nullptr;
        temp = new Carro *[++n_carros];
        int i = 0;
        while (i < n_carros)
        {
            if (i == n_carros - 1)
            {
                temp[i] = &carro;
            }
            else
            {
                temp[i] = classificacao[i];
            }
            i++;
        }

        if (temp != classificacao)
            delete[] classificacao;

        classificacao = temp;
    }
    else
        return -1;
}

void Pista::eliminaCarro(Carro &carro)
{
    Carro **temp = nullptr;
    temp = new Carro *[n_carros - 1];

    for (int i = 0, j = 0; i < n_carros; i++)
        if (classificacao[i]->getNome() != carro.getNome())
        {
            temp[j] = classificacao[i];
            j++;
        }

    n_carros--;
    delete[] classificacao;
    classificacao = temp;
}

//insere piloto num carro
// void Pista::inserePiloto(Piloto &piloto, Carro &carro)
// {
//     /*
//     TODO atribui piloto a carro
//     */
//     //carro.atribuiPiloto(piloto);
// }

int Pista::iniciaCorrida()
{
    /*
    TODO verificar se todos os carros tem pilotos
    */
    if (n_carros >= 2)

        a_correr = true;
    else
        return -1;
}

void Pista::avanca(int tempo)
{

    if (!a_correr)
    {
        for (int i = 0; i < n_carros; i++)
        {
            /*
            TODO chamar funcao para avançar carros
            */
        }
    }
}

Carro const *Pista::verificaEmergencia()
{
}

Pista &Pista::operator=(const Pista &pista)
{
    max_carros = pista.max_carros;
    n_carros = pista.n_carros;
    comprimento=pista.comprimento;
    a_correr=pista.a_correr;
    for(int i = 0; i<n_carros;i++)
        classificacao[i]=pista.classificacao[i];
    
}
