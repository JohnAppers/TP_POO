
#include "Pista.h"
#include <sstream>
#include <iostream>

Pista::Pista(int max_carros, int comprimento) : comprimento(comprimento >= 0 ? comprimento : DEF_COMP), max_carros(max_carros) {}

Pista::Pista(const Pista &pista) : comprimento(pista.comprimento), max_carros(pista.max_carros) {}

const int Pista::getMaxCarros() const { return max_carros; }

const int Pista::getNCarros() const { return n_carros; }

const int Pista::getComprimento() const { return comprimento; }

const bool Pista::getACorrer() const { return a_correr; }

const Carro_teste* const * Pista::getLugares() const { return lugares; }

const string &Pista::getAsString() const
{
    ostringstream os;
    static string s;

    os << "N maximo de carros: " << max_carros << endl
       << "Comprimento: " << comprimento << endl
       << "A correr: " << a_correr << endl;

    if (lugares != nullptr)
    {
        os << "Carros: " << endl;
        for (int i = 0; i < n_carros; i++)
            os << "[" << i + 1 << "]:" << lugares[i]->getNome() << endl;
        
    }
    s = os.str();
    return s;
}

void Pista::adicionaCarro( Carro_teste &carro)
{

    Carro_teste **temp = nullptr;
    temp = new Carro_teste *[++n_carros];
    int i=0;
    while (i<n_carros)
    {
        if(i==n_carros-1){
            temp[i] = &carro;
        }
        else{
            temp[i] = lugares[i];
        }
        i++;
    }
    
    

    if (temp != lugares)
        delete[] lugares;


    lugares = temp;
}

void Pista::eliminaCarro( Carro_teste &carro){
    Carro_teste **temp=nullptr;
    temp= new Carro_teste*[n_carros-1];

    for(int i=0, j=0;i<n_carros;i++)
        if(lugares[i]->getNome()!=carro.getNome()){
            temp[j]=lugares[i];
            j++;
        }
    
    --n_carros;
    delete[]lugares;
    lugares=temp;
}