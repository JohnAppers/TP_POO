#include <iostream>
#include <sstream>
#include <stdio.h>
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
	ncarros = (ncarros * 2) + 5;
	for (int i = 5; i <= ncarros; i += 2) {
		gotoxy(30, i);
		cout << linha_pista.str();
	}
}
void print_carros(int ncarros, int dist){
	ncarros = (ncarros * 2) + 5;
	for (int j = 0, i = 6; i < ncarros; i += 2) {
		gotoxy(30 + dist, i);
		cout << (char)(65 + j);
		j++;
	}
}
int main() {	
	string comando, bin, delimiter = " ";
	Simulador simu;
	Campeonato champ = simu.getCampeonato();
	bool valido = false;
	int index, dist=0;
	start_screen();
	Consola::getch();
	//INICIO DO MODO 1
	simu.escolheModo(1);
	editor();
	do{
		gotoxy(0, 28);
		cout << "                                                  ";
		gotoxy(0, 28);
		getline(cin, bin);
		comando = bin.substr(0, bin.find(delimiter));
		bin.erase(0, bin.find(delimiter) + delimiter.size());
		if (comando == "carregaP") {
			comando.clear();
			comando = bin.substr(0, bin.find(delimiter));
			if (simu.carregaP(comando) == nullptr) {
				gotoxy(50, 28);
				cout << "Erro ao carregar piloto.";
			}
			else {
				gotoxy(50, 28); 
				cout << "Piloto carregado com sucesso.";
			}
		}
		else if(comando == "carregaC"){
			comando.clear();
			comando = bin.substr(0, bin.find(delimiter));
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			if (simu.carregaC(comando) == nullptr) {
				gotoxy(50, 28);
				cout << "                                    ";
				gotoxy(50, 28);
				cout << "Erro ao carregar carro.";
			}
			else {
				gotoxy(50, 28);
				cout << "Carro carregado com sucesso.";
			}
		}
		else if (comando == "carregaA") {
			comando.clear();
			comando = bin.substr(0, bin.find(delimiter));
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			if (simu.carregaA(comando) == nullptr) {
				gotoxy(50, 28);
				cout << "Erro ao carregar autodromo.";
			}
			else {
				gotoxy(50, 28);
				cout << "Autodromo carregado com sucesso.";
			}
		}
		else if (comando == "cria") {
			comando.clear();
			comando = bin.substr(0, bin.find(delimiter));
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			if (comando == "P" || comando == "p") {
				comando.clear();
				comando = bin.substr(0, bin.find(delimiter));
				bin.erase(0, bin.find(delimiter) + delimiter.size());
				simu.cria('p', comando);
				gotoxy(50, 28);
				cout << "Piloto criado com sucesso.";
			}
			else if (comando == "C" || comando == "c") {
				string p1, p5;
				float p2, p3;
				int p4;
				p1 = bin.substr(0, bin.find(delimiter));
				bin.erase(0, bin.find(delimiter) + delimiter.size());
				p2 = stof(bin.substr(0, bin.find(delimiter)));
				bin.erase(0, bin.find(delimiter) + delimiter.size());
				p3 = stof(bin.substr(0, bin.find(delimiter)));
				bin.erase(0, bin.find(delimiter) + delimiter.size());
				p4 = stoi(bin.substr(0, bin.find(delimiter)));
				bin.erase(0, bin.find(delimiter) + delimiter.size());
				p5 = bin.substr(0, bin.find(delimiter));
				bin.erase(0, bin.find(delimiter) + delimiter.size());
				simu.cria('c', p1, p2, p3, p4, p5);
				gotoxy(50, 28);
				cout << "Carro criado com sucesso.";
			}
			else if (comando == "A" || comando == "a") {
				int p1, p2;
				string p3;
				p1 = stoi(bin.substr(0, bin.find(delimiter)));
				bin.erase(0, bin.find(delimiter) + delimiter.size());
				p2 = stoi(bin.substr(0, bin.find(delimiter)));
				bin.erase(0, bin.find(delimiter) + delimiter.size());
				p3 = bin.substr(0, bin.find(delimiter));
				bin.erase(0, bin.find(delimiter) + delimiter.size());
				simu.cria('a', p1, p2, p3);
				gotoxy(50, 28);
				cout << "Autodromo criado com sucesso.";
			}
		}
		else if (comando == "apaga") {
			char tipo;
			string identificador;
			tipo = bin.substr(0, bin.find(delimiter)).at(0);
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			identificador = bin.substr(0, bin.find(delimiter));
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			simu.apaga(tipo, identificador);
			gotoxy(50, 28);
			cout << "Apagado com sucesso.";
		}
		else if (comando == "entranocarro"){
			char id;
			string nome;
			id = bin.substr(0, bin.find(delimiter)).at(0);
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			nome = bin.substr(0, bin.find(delimiter));
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			simu.entraCarro(id, nome);
		}
		else if (comando == "saidocarro") {
			char id;
			string nome;
			id = bin.substr(0, bin.find(delimiter)).at(0);
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			nome = bin.substr(0, bin.find(delimiter));
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			simu.saiCarro(id, nome);
		}
		else if (comando == "lista") {
		Consola::clrscr();	
			gotoxy(10, 3);
			cout << simu.lista();
			Consola::getch();
			Consola::clrscr();
			editor();
		}
		else if (comando == "campeonato") {
			comando.clear();
			comando = bin.substr(0, bin.find(delimiter));
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			for (int i = 0; i < (int)simu.getCampeonato().getAutodromo().size(); i++) {
				if (simu.getCampeonato().getAutodromo()[i].getNome() == comando) {
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
			cout << "Comando invalido.";
		}
		comando.clear();
		bin.clear();
	} while (!valido);

	//INICIO DO MODO 2
	simu.escolheModo(2);
	int comprimento = simu.getCampeonato().getAutodromo()[index].getPista().getComprimento();
	do {
		
		Consola::clrscr();
		print_pista(comprimento, simu.getDGV().getNumCarros());
		print_carros(simu.getDGV().getNumCarros(), dist);
		gotoxy(0, 28);
		cout << "                   ";
		gotoxy(0, 28);
		getline(cin, bin);
		comando = bin.substr(0, bin.find(delimiter));
		bin.erase(0, bin.find(delimiter) + delimiter.size());
		if (comando == "passatempo") {
			comando.clear();
			comando = bin.substr(0, bin.find(delimiter));
			bin.erase(0, bin.find(delimiter) + delimiter.size());
			if ((dist + stoi(comando)) <= comprimento) {
				dist += stoi(comando);
			}
			else {
				dist = comprimento;
			}
		}
		else {
			gotoxy(40, 28);
			cout << "                       ";
			gotoxy(40, 28);
			cout << "Comando inv�lido.";
		}
		bin.clear();
		comando.clear();
	} while (dist < comprimento);
	Consola::clrscr();
	gotoxy(45, 14);
	cout << "Todos os carros ganharam!";
	Consola::getch();
}

