#include "Simulador.h"
#include <iostream>

int main()
{
    Simulador simu;
    simu.escolheModo(1);
    simu.carregaA("autodromos.txt");
    string s="pilotos.txt";
    simu.carregaC("carros.txt");
    simu.carregaP(s);
    cout<< simu.lista();
    simu.cria('p', "Sergio");
    simu.cria('a', 5, 100, "Auto");
    simu.cria('c', "fiat", 10, 100, 150);

    simu.apaga('p', "Sergio");
    simu.apaga('a', "Auto");
    simu.apaga('c', "C");

    // cout << simu.lista();
    // cout << simu.listaCarros();
    
    simu.entraCarro('A', "Sergio1");
    
    cout<<simu.getDGV().getPiloto("Sergio1")->getAsString();
    
    // cout << simu.lista();
    // simu.entraCarro('B', "Gil");
    // simu.saiCarro('B', "Gil");
    // cout << simu.lista();
    // cout << simu.listaCarros();
}