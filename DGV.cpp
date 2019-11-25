#include "DGV.h"
#include <sstream>

void DGV::adicionaCarro(Carro carro)
{
    carros.push_back(carro);
}

void DGV::retiraCarro(Carro &carro)
{
    for (auto i = 0; i < carros.size(); i++)
    {
        if (carros[i].getNome() == carro.getNome())
        {
            carros.erase(carros.begin() + i);
        }
    }
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

void DGV::adicionaPiloto(Piloto &piloto)
{
    pilotos.push_back(piloto);
}

void DGV::retiraPiloto(Piloto &piloto)
{
    for (auto i = 0; i < carros.size(); i++)
    {
        if (pilotos[i].getNome() == piloto.getNome())
        {
            pilotos.erase(pilotos.begin() + i);
        }
    }
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

    os<<"============Carros============="<<endl
        <<this->getCarrosAsString()<<endl
        <<"=============Pilotos==========="<<endl
        <<this->getPilotosAsString()<<endl;

    s = os.str();
    return s;
}