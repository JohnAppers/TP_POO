#include "Campeonato.h"
#include <sstream>

void Campeonato::adiciona(Autodromo autodromo)
{
    autodromos.push_back(autodromo);
}

void Campeonato::retira(string nome)
{
    for (int i = 0; i < autodromos.size();)

        if (autodromos[i].getNome() == nome)
            autodromos.erase(autodromos.begin() + i);
        else
            i++;
}

const string &Campeonato::getAsString() const
{
    ostringstream os;
    static string s;

    for (const auto &a : autodromos)
        os << a.getAsString() << endl;

    s = os.str();
    return s;
}

vector<Autodromo> &Campeonato::getAutodromo()
{
    return autodromos;
}
