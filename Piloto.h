#ifndef PILOTO_H
#define PILOTO_H

#include <iostream>
#include <string>
using namespace std;

class Piloto {
	string nome;
	bool conduzir = false;
public:
	Piloto(string nome);
	string getNome() { return nome; }
};
#endif
