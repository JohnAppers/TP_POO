#ifndef PILOTO_H
#define PILOTO_H
#include "Carro.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Piloto {
	static int dup_count;		//dup_count para adicionar a nomes duplicados
	static vector<string> lista_nomes;
	string nome;
	bool conduzir = false;
	Carro* atual;
public:
	/*---Construtor---*/
	Piloto(string nome);
	/*---Fun��es get---*/
	string getNome()const { return nome; }
	/*---Fun��o para condu��o de um carro---*/
	void conduz(Carro* c);
	const string& getAsString()const;
};
#endif
