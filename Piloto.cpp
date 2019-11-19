#include "Piloto.h"
#include <iostream>
#include <string>
using namespace std;

Piloto::Piloto(string nome_p) {
	static int nome_count = 0, dup_count = 1;		//dup_count para adicionar a nomes duplicados
	static string lista_nomes[30];
	bool dup = false;								//bool para existência de duplicado
	if (nome_count < 30) {							//se a lista de nomes não estiver cheia
		for (int i = 0; i < 30; i++) {				//percorrer a lista de nomes comparando duplicados
			if (nome_p == lista_nomes[i]) {			
				dup = true;
			}
		}
		if (dup) {
			nome = nome_p + to_string(dup_count);
			lista_nomes[nome_count] = nome_p;
			nome_count++;
			dup_count++;
			dup = false;
		}
		else {
			nome = nome_p;
			lista_nomes[nome_count] = nome_p;
			nome_count++;
		}
	}
	else {
		cout << "Número máximo de pilotos atingido.";
	}
}