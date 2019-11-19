#ifndef CARRO_H
#define CARRO_H

#include <iostream>
#include <string>
using namespace std;

class Carro {
	//Contador
	static char id;
	string marca, modelo;
	char nome;
	float energiaMax, energia;
	int velocidadeMax, velocidade;
	bool acelerador = false, travao = false, emergencia = false, condutor = false, dano = false;
public:
	//construtor com valor de modelo por defini��o
	Carro(string marca, float energia, float energiaMax, int velocidadeMax, string modelo = "modelo base");

	//fun��es get
	char getNome()const { return nome; }
	//fun��es de controlo do carro
	void acelera();
	void trava();
	void carrega(float n);
	void movimento();
	void setEmergencia();
};
#endif