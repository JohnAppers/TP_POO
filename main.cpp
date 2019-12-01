#include <iostream>
#include <sstream>
#include "Consola.h"
#include "Simulador.h"
using namespace std;

void gotoxy(int x, int y) {
	Consola::gotoxy(x, y);
}

void start_screen() {
	Consola::setTextColor(Consola::VERMELHO);
	Consola::setTextSize(15, 15);
	Consola::setScreenSize(30, 120);
	gotoxy(45, 14);
	cout << "Simulador de corridas de carros";
	gotoxy(48, 15);
	cout << "Trabalho pratico de POO";
}

void menu_screen() {
	Consola::clrscr();
	gotoxy(47, 13);
	cout << "Escolha o modo pretendido:";
	gotoxy(49, 14);
	cout << "1 - Editor de classes";
	gotoxy(47, 15);
	cout << "2 - Campeonato de corridas";
}

void editor() {

	Consola::clrscr();
	gotoxy(55, 9);
	cout << "Comandos:";
	gotoxy(47, 10);
	cout << "carregaP <nomeFicheiro>";
	gotoxy(47, 11);
	cout << "carregaC <nomeFicheiro>";
	gotoxy(47, 12);
	cout << "carregaA <nomeFicheiro>";
	gotoxy(42, 13);
	cout << "cria <letraTipo> <dados do objeto>";
	gotoxy(42, 14);
	cout << "apaga <letraTipo> <identificador>";
	gotoxy(40, 15);
	cout << "entranocarro <letraCarro> <nomePiloto>";
	gotoxy(47, 16);
	cout << "saidocarro <letraCarro>";
	gotoxy(56, 17);
	cout << "lista";
	gotoxy(0, 28);
}
void print_pista(int comp, int ncarros) {
	stringstream linha_pista;
	for (int i = 0; i < comp; i++) {
		linha_pista << "-";
	}
	for (int i = 5; i <= ((ncarros * 2) + 5); i + 2) {
		gotoxy(30, i);
		cout << linha_pista.str();
	}
}
void print_carros(){}

int main() {	
	
	Simulador simu;
	Campeonato champ = simu.getCampeonato();
	bool valido = false;
	int index;
	start_screen();
	Consola::getch();
	/*
	menu_screen();
	do {
		modo = Consola::getch();
	} while (modo != '1' && modo != '2');
	//TAMANHO PARA CORRIDAS
	//Consola::setScreenSize(30, 160);
	if (modo == '1') {
	*/

	//INICIO DO MODO 1
	editor();
	do{
		istringstream comando;
		string bin, comando_str;
		gotoxy(0, 28);
		cout << "                                                  ";
		gotoxy(0, 28);
		cin >> bin;
		comando.str(bin);
		
//		while (comando.rdbuf()->in_avail() == 0) {
//			comando >> bin;
//			comando_str += bin;
//		}
		getline(comando, comando_str, ' ');
		cout << comando_str;
		if (comando_str == "carregaP") {
			comando_str = "";
			comando >> comando_str;
			if (simu.carregaP(comando_str) == nullptr) {
				gotoxy(50, 28);
				cout << "Erro ao carregar piloto.";
			}
		}
		else if(comando_str == "carregaC"){
			comando_str = "";
			comando >> comando_str;
			if (simu.carregaC(comando_str) == nullptr) {
				gotoxy(50, 28);
				cout << "Erro ao carregar carro.";
			}
		}
		else if (comando_str == "carregaA") {
			comando_str = "";
			comando >> comando_str;
			if (simu.carregaA(comando_str) == nullptr) {
				gotoxy(50, 28);
				cout << "Erro ao carregar autodromo.";
			}
		}
		else if (comando_str == "cria") {
			comando_str = "";
			comando >> comando_str;
			if (comando_str == "P" || comando_str == "p") {
				comando_str = "";
				comando >> comando_str;
				simu.cria('p', comando_str);
				gotoxy(50, 28);
				cout << "Piloto criado com sucesso.";
			}
			else if (comando_str == "C" || comando_str == "c") {
				string p1, p5;
				float p2, p3;
				int p4;
				comando >> p1 >> p2 >> p3 >> p4 >> p5;
				simu.cria('c', p1, p2, p3, p4, p5);
				gotoxy(50, 28);
				cout << "Carro criado com sucesso.";
			}
			else if (comando_str == "A" || comando_str == "a") {
				int p1, p2;
				string p3;
				comando >> p1 >> p2 >> p3;
				simu.cria('a', p1, p2, p3);
				gotoxy(50, 28);
				cout << "Autodromo criado com sucesso.";
			}
		}
		else if (comando_str == "apaga") {
			char tipo;
			string identificador;
			comando >> tipo;
			comando >> identificador;
			simu.apaga(tipo, identificador);
			gotoxy(50, 28);
			cout << "Apagado com sucesso.";
		}
		else if (comando_str == "entranocarro"){
			char id;
			string nome;
			comando >> id >> nome;
			simu.entraCarro(id, nome);
		}
		else if (comando_str == "saidocarro") {
			char id;
			string nome;
			comando >> id >> nome;
			simu.saiCarro(id, nome);
		}
		else if (comando_str == "lista") {
		//POR COMPLETAR
		}
		else if (comando_str == "campeonato") {
			comando_str = "";
			comando >> comando_str;
			for (int i = 0; i < (int)champ.getAutodromo().size(); i++) {
				if (champ.getAutodromo()[i].getNome() == comando_str) { 
					valido = true;
					index = i;
				}
			}
			if (!valido) {
				gotoxy(50, 28);
				cout << "                                 ";
				gotoxy(50, 28);
				cout << "Autodromo invalido.";
			}
		}
		else {
			gotoxy(50, 28);
			cout << "                           ";
			gotoxy(50, 28);
			cout << comando_str;
			cout << " l ";
			//cout << "Comando invalido.";
			comando.str() = "";
			comando_str = "";
		}
		
	} while (!valido);
	//INICIO DO MODO 2
	do {
		print_pista(champ.getAutodromo()[index].getPista().getComprimento(), simu.getDGV().getNumCarros());
		Consola::getch();
	} while (true);
}

