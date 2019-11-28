#include "Autodromo.h"
#include <sstream>
Autodromo::Autodromo(int max_carros, int comprimento, string nome) : pista(max_carros, comprimento)
{
    this->nome = nome;
}

Autodromo::~Autodromo()
{
    
}

const string &Autodromo::getAsString() const
{
    ostringstream os;
    static string s;
    os << "Nome:" << nome << endl
       << pista.getAsString() << endl;
    s = os.str();
    return s;
}

const string &Autodromo::getNome() const { return nome; }
