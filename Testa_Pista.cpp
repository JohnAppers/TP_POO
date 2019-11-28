#include "Simulador.h"
#include <iostream>

int main()
{
    Simulador sim;
    

    // sim.carregaC("carros.txt");
    // Carro carro("Fiat", 30, 100);
    // Carro carro2("Punto", 20, 110);
    // sim.getDGV().adiciona(carro);
    // sim.getDGV().adiciona(carro2);
    // sim.getDGV().retira(carro);
    // sim.carregaP("pilotos.txt");
    // Piloto piloto("Jose");
    // Piloto piloto2("toino");
    // sim.getDGV().adiciona(piloto);
    // sim.getDGV().adiciona(piloto2);
    // sim.getDGV().retira(piloto);
    // cout<<sim.getDGV().getAsString();
    sim.carregaA("autodromos.txt");
    
    for(const auto& a : sim.getCampeonato().getAutodromo()){
        cout<< a.getAsString();
    }


    // cout<<sim.getDGV().getAsString();
    // cout<<"A terminar"<<endl;
}