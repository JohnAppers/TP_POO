#include <iostream>
#include "Carro.h"
using namespace std;

Carro::Carro(string marca_p, float energia_p, float energiaMax_p, int velocidadeMax_p, string modelo_p) {
	static int ascii = 65;			//código ASCII do nome
	marca = marca_p;
	modelo = modelo_p;
	energia = energia_p;
	energiaMax = energiaMax_p;
	velocidadeMax = velocidadeMax_p;
	nome = (char)ascii;
	if (ascii < 90) {
		ascii++;					//o próximo carro terá a letra seguinte
	}	
	else { 
		ascii = 63; 				//se a letra anterior for z, define como '?'
	}		
}
void Carro::acelera() {
	if (!travao) {
		acelerador = true;
	}
}
void Carro::para_acelera() {
	acelerador = false;
}
void Carro::trava() {
	if (!acelerador) {
		travao = true;
	}
}
void Carro::para_trava() {
	travao = false;
}