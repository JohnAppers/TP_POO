#include <sstream>
#include "Carro.h"
using namespace std;

Carro::Carro(string marca_p, float energia_p, float energiaMax_p, int velocidadeMax_p, string modelo_p)
{
	static int ascii = 65; //c�digo ASCII do nome
	marca = marca_p;
	modelo = modelo_p;
	energia = energia_p;
	energiaMax = energiaMax_p;
	velocidadeMax = velocidadeMax_p;
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
/*---Fun��es para ativar/desativar o acelerador e o trav�o---*/
void Carro::acelera()
{
	if (!travao)
	{
		acelerador = true;
	}
}
void Carro::para_acelera()
{
	if (!travao)
	{
		acelerador = false;
	}
}
void Carro::trava()
{
	if (!acelerador)
	{
		travao = true;
	}
}
void Carro::para_trava()
{
	if (!acelerador)
	{
		travao = false;
	}
}
/*---Fun��o de carregamento de energia, fornecendo n por itera��o---*/
void Carro::carrega(float n)
{
	if (energia <= (energiaMax - n))
	{
		energia += n;
	}
	else
	{
		energia = energiaMax;
	}
}
/*---Fun��o geral de movimento, acelera ou trava e reduz energia conforme velocidade---*/
void Carro::movimento()
{
	if (acelerador && velocidade < velocidadeMax)
	{
		velocidade++;
	}
	if (travao && velocidade > 0)
	{
		velocidade--;
	}
	energia -= (0.1 * velocidade);
}
/*---Fun��o para ligar/desligar sinal de emerg�ncia---*/
void Carro::setEmergencia()
{
	if (emergencia)
	{
		emergencia = false;
	}
	else
	{
		emergencia = true;
	}
}

const string &Carro::getAsString() const
{
	ostringstream os;
	static string s;

	os<<"Nome: "<<nome<<endl
		<<"Marca: "<<marca<<endl
		<<"Modelo: "<<modelo<<endl;
	s=os.str();
	return s;
}