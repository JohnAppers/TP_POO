#ifndef CARRO_H
#define CARRO_H

#include <iostream>
#include <string>
using namespace std;

class Carro {
	string marca, modelo;
	char nome;
	float energiaMax, energia;
	int velocidadeMax, velocidade;
	bool acelerador = false, travao = false, emergencia = false, condutor = false, dano = false;
public:
	//construtor com valor de modelo por definição
	Carro(string marca, float energia, float energiaMax, int velocidadeMax, string modelo = "modelo base");

	//funções get
	char getNome()const { return nome; }
	int getVelocidade()const { return velocidade; };
	//funções de controlo do carro
	void acelera();
	void para_acelera();
	void trava();
	void para_trava();
	void carrega(float n);
	void movimento();
	void setEmergencia();
};
#endif