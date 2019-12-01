#include "Simulador.h"
#include <sstream>
#include <fstream>

void Simulador::escolheModo(int i)
{
    modoCampeonato = i;
}
void *Simulador::carregaC(string file_name)
{

    ifstream f;
    string line, marca, modelo;
    int capacidadeInicial, capacidadeMaxima, velocidadeMax;

    if (modoCampeonato == 2)
        return nullptr;

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
    string line, nome;

    if (modoCampeonato == 2)
        return nullptr;

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

    if (modoCampeonato == 2)
        return nullptr;

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

void *Simulador::cria(char tipo, string marca, int capacidadeInicial, int capacidadeMaxima, int velocidadeMax, string modelo)
{
    if (tipo == 'c' && modoCampeonato == 1)
        if (modelo.compare("-1") != 0)
            dgv.adiciona(Carro(marca, capacidadeInicial, capacidadeMaxima, velocidadeMax, modelo));
        else
            dgv.adiciona(Carro(marca, capacidadeInicial, capacidadeMaxima, velocidadeMax));

    else
        return nullptr;
}

void *Simulador::cria(char tipo, string nome)
{
    if (tipo == 'p' && modoCampeonato == 1)
        dgv.adiciona(Piloto(nome));
    else
        return nullptr;
}

void *Simulador::cria(char tipo, int max_carros, int comprimento, string nome)
{
    if (tipo == 'a' && modoCampeonato == 1)
        campeonato.adiciona(Autodromo(max_carros, comprimento, nome));
    else
        return nullptr;
}

void *Simulador::apaga(char tipo, string id)
{
    if (modoCampeonato == 2)
        return nullptr;
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
        return nullptr;
    }
}

const string &Simulador::lista() const
{
    ostringstream os;
    static string s;

    if (modoCampeonato == 1)
        os << dgv.getAsString() << endl
           << campeonato.getAsString() << endl;

    s = os.str();
    return s;
}

const string &Simulador::listaCarros() const
{
    return dgv.getCarrosAsString();
}

bool Simulador::carregaBat(char id, float Q)
{
    if (modoCampeonato == 2){
        dgv.getCarro(id)->carrega(Q);
        return true;
    }else
    
        return false;
    
    
}

void Simulador::entraCarro(char id, string nome)
{
    dgv.getPiloto(nome)->conduz(dgv.getCarro(id));
}

void Simulador::saiCarro(char id, string nome)
{
    dgv.getPiloto(nome)->conduz(nullptr);
}

DGV &Simulador::getDGV()
{
    return dgv;
}

Campeonato &Simulador::getCampeonato()
{
    return campeonato;
}