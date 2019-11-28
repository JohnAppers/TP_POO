#include "Campeonato.h"

void Campeonato::adiciona(Autodromo autodromo)
{
    autodromos.push_back(autodromo);
}

// void Campeonato::retira(Autodromo &autodromo)
// {
//     for (auto i = 0; i < autodromos.size(); i++)
//     {
//         if (autodromos[i].getNome() == autodromo.getNome())
//         {
//             autodromos.erase(autodromos.begin() + i);
//         }
//     }
// }

 vector<Autodromo>& Campeonato::getAutodromo(){
     return autodromos;
 }

 