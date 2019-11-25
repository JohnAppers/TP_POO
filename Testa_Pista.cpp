#include "Simulador.h"
#include <iostream>

int main()
{
    Simulador sim;

    sim.carrega("carros.txt");
    cout<<sim.getDGV().getCarrosAsString();
    // DGV dgv;

    // Carro carro("Fiat", 30, 100, 50);
    // Carro carro2("Punto", 20, 110, 40);
    // Piloto piloto("Sergio");
    // Piloto piloto2("Gil");
    

    // dgv.adicionaCarro(carro);
    // dgv.adicionaCarro(carro2);
    //cout<<dgv.getAsString();
    //dgv.retiraCarro(carro);
    //cout<<dgv.getAsString();

    // dgv.adicionaPiloto(piloto);
    // dgv.adicionaPiloto(piloto2);
    //cout<<dgv.getAsString();
    //dgv.retiraPiloto(piloto);
    // cout<<dgv.getAsString();

    // Pista p1(10, 100);
    // cout << p1.getAsString() << endl; 
    // Pista p2 = p1;
    // cout << p2.getAsString() << endl;

    // p1.adicionaCarro(carro);
    // //p1.getLugares()[0]->setNome("Sergio");
    // cout << p1.getAsString() << endl;
    // p1.adicionaCarro(carro2);
    // cout << p1.getAsString() << endl;
    // p1.eliminaCarro(carro);
    // cout << p1.getAsString() << endl;

    cout<<"A terminar"<<endl;
}