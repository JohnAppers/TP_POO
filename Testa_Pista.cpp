#include "Pista.h"
#include <iostream>

int main()
{
    Carro_teste carro("Carro1");
    Carro_teste carro2("Carro2");
    cout << carro.getNome() << endl;
    Pista p1(10, 100);
    cout << p1.getAsString() << endl; 
    Pista p2 = p1;
    cout << p2.getAsString() << endl;

    p1.adicionaCarro(carro);
     //p1.getLugares()[0]->setNome("Sergio");
    cout << p1.getAsString() << endl;
    p1.adicionaCarro(carro2);
    cout << p1.getAsString() << endl;
    
    cout<<"A terminar"<<endl;
}