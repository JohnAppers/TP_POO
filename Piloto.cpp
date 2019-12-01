#include "Piloto.h"
#include "Carro.h"
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int Piloto::dup_count = 1;
vector<string> Piloto::lista_nomes;
Piloto::Piloto(string nome_p)
{

	bool dup = false; //bool para exist�ncia de duplicado
	/*---Algoritmo de configura��o de nome---*/
	for (int i = 0; i < lista_nomes.size(); i++)
	{ //percorrer a lista de nomes comparando duplicados
		if (nome_p == lista_nomes.at(i))
		{
			dup = true;
			break;
		}
	}
	if (dup)
	{
		nome = nome_p + to_string(dup_count);
		lista_nomes.push_back(nome);
		dup_count++;
		dup = false;
	}
	else
	{
		nome = nome_p;
		lista_nomes.push_back(nome_p);
	}
}

void Piloto::conduz(Carro *c)
{
	if (atual == nullptr)
	{
		atual = c;
	}
}

const string &Piloto::getAsString() const
{
	ostringstream os;
	static string s;

	os << "Nome: " << nome << endl;
	  
	s = os.str();
	return s;
}