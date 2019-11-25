#ifndef CARRO_H
#define CARRO_H

#include <string>
#include "Piloto.h"
#include <sstream>

using namespace std;

class Carro
{
	string marca, modelo;
	char nome;
	float energiaMax, energia;
	int velocidadeMax, velocidade;
	bool acelerador = false, travao = false, emergencia = false, condutor = false, dano = false;

	//atribuir piloto
	Piloto *piloto;

public:
	//construtor com valor de modelo por defini��o
	//Carro(string marca, float energia, float energiaMax, int velocidadeMax, string modelo = "modelo base");

	//fun��es get
	char getNome() const { return nome; }
	int getVelocidade() const { return velocidade; };

	//fun��es de controlo do carro
	void acelera();
	void para_acelera();
	void trava();
	void para_trava();
	void carrega(float n);
	void movimento();
	void setEmergencia();

	//========================================================================
	//Atribuir piloto
	void atribuiPiloto(Piloto &piloto)
	{
		this->piloto = &piloto;
	}

	const string &getAsString() const
	{
		ostringstream os;
		static string s;

		os << "Nome: " << nome << endl
		   << "Marco: " << marca << endl
		   << "Modelo: " << modelo << endl
		   << "Energia: " << energia << endl
		   << "Energia maxima: " << energiaMax << endl;
		s = os.str();
		return s;
	}

	Carro(string marca_p, float energia_p, float energiaMax_p, string modelo_p)
	{
		static int ascii = 65; //c�digo ASCII do nome
		marca = marca_p;
		modelo = modelo_p;
		energia = energia_p;
		energiaMax = energiaMax_p;
		nome = (char)ascii;
		if (ascii < 90)
		{
			ascii++; //o pr�ximo carro ter� a letra seguinte
		}
		else
		{
			ascii = 63; //se a letra anterior for z, define como '?'
		}
	}
};
#endif