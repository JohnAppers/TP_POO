#ifndef CARRO_H
#define CARRO_H

#include <string>
using namespace std;

class Carro
{
	string marca, modelo;
	char nome;
	float energiaMax, energia;
	int velocidadeMax, velocidade;
	bool acelerador = false, travao = false, emergencia = false, condutor = false, dano = false;

public:
	//construtor com valor de modelo por defini��o
	Carro(string marca, float energia, float energiaMax, int velocidadeMax, string modelo = "modelo base");

	//fun��es get
	char getNome() const { return nome; }
	int getVelocidade() const { return velocidade; };
	const bool getEmergengia() { return emergencia; };
	//fun��es de controlo do carro
	void acelera();
	void para_acelera();
	void trava();
	void para_trava();
	void carrega(float n);
	void movimento();
	void setEmergencia();
	const string &getAsString() const;
};
#endif