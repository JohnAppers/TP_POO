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
/*---Funções para ativar/desativar o acelerador e o travão---*/
void Carro::acelera() {
	if (!travao) {
		acelerador = !acelerador;
	}
}
void Carro::trava() {
	if (!acelerador) {
		travao = !travao;
	}
}
/*---Função de carregamento de energia, fornecendo n por iteração---*/
void Carro::carrega(float n) {
	if (energia <= (energiaMax - n)) {
		energia += n;
	}
	else {
		energia = energiaMax;
	}
}
/*---Função geral de movimento, acelera ou trava e reduz energia conforme velocidade---*/
void Carro::movimento() {
	if (acelerador && velocidade < velocidadeMax) {
		velocidade++;
	}
	if (travao && velocidade > 0) {
		velocidade--;
	}
	energia -= (0.1 * velocidade);
}
/*---Função para ligar/desligar sinal de emergência---*/
void Carro::setEmergencia() {
	if (emergencia) {
		emergencia = false;
	}
	else {
		emergencia = true;
	}
}