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
	/*---Funções get---*/
	string getNome()const { return nome; }
	/*---Função para condução de um carro---*/
	void conduz(Carro* c);
};
#endif
