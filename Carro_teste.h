#ifndef CARRO_TESTE_H
#define CARRO_TESTE_H
using namespace std;
#include <string>

class Carro_teste
{
    string nome;

public:
    Carro_teste(string nome) { this->nome = nome; };
    const string &getNome() const { return nome; }
    void setNome(string nome) { this->nome = nome; }
};

#endif