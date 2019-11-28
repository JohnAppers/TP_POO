#include "Campeonato.h"


void Campeonato::adiciona(Autodromo autodromo)
{
    autodromos.push_back(autodromo);
}

void Campeonato::retira(string nome)
{
    for (int i = 0; i < autodromos.size(); i++)

        if (autodromos[i].getNome() == nome);

            //autodromos.erase(autodromos.begin() + i);
}

vector<Autodromo> &Campeonato::getAutodromo()
{
    return autodromos;
}
