#include "DGV.h"
#include <sstream>

void DGV::adiciona(Carro carro)
{
    carros.push_back(carro);
}

void DGV::adiciona(Piloto piloto)
{
    pilotos.push_back(piloto);
}

void DGV::retira(char id)
{
    for (int i = 0; i < carros.size(); i++)
        if (carros[i].getNome() == id)
        {
            carros.erase(carros.begin() + i);
        }
}

void DGV::retira(string nome)
{
    for (int i = 0; i < pilotos.size(); i++)
    
        if (pilotos[i].getNome() == nome)
            pilotos.erase(pilotos.begin() + i);
}

const string &DGV::getCarrosAsString() const
{
    ostringstream os;
    static string s;

    for (const auto &c : carros)
        os << c.getAsString() << endl;

    s = os.str();
    return s;
}

Carro *DGV::getCarro(char id)
{
    for (int i = 0; i < carros.size(); i++)
        if (carros[i].getNome() == id)
            return &(carros[i]);
        else
            return nullptr;
}

Piloto *DGV::getPiloto(string nome)
{
    for (int i = 0; i < pilotos.size(); i++)
        if (pilotos[i].getNome() == nome)
            return &(pilotos[i]);
        else
            return nullptr;
}
const string &DGV::getPilotosAsString() const
{
    ostringstream os;
    static string s;

    for (const auto &p : pilotos)
        os << p.getAsString() << endl;

    s = os.str();
    return s;
}

const string &DGV::getAsString() const
{
    ostringstream os;
    static string s;

    os << "============Carros=============" << endl
       << this->getCarrosAsString() << endl
       << "=============Pilotos===========" << endl
       << this->getPilotosAsString() << endl;

    s = os.str();
    return s;
}