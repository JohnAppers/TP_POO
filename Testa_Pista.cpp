#include "Simulador.h"
#include <iostream>

int main()
{
    Simulador simu;
    simu.escolheModo(1);
    simu.carregaA("autodromos.txt");
    simu.carregaC("carros.txt");
    simu.carregaP("pilotos.txt");

    cout << simu.cria('p', "Sergio");
    simu.cria('a', 5, 100, "Auto");
    simu.cria('c', "fiat", 10, 100, 150);

    cout << simu.getDGV().getAsString();
    cout << simu.getCampeonato().getAsString();
    simu.apaga('p', "Sergio");
    simu.apaga('a', "Auto");
    simu.apaga('c', "C");

    cout << simu.getDGV().getAsString();
    cout << simu.getCampeonato().getAsString();
}