all: testa_pista.o simulador.o dgv.o campeonato.o autodromo.o pista.o carro.o piloto.o
	g++ testa_pista.o simulador.o dgv.o campeonato.o autodromo.o pista.o carro.o piloto.o -o Simulador

testa_Pista.o:
	g++ -c Testa_Pista.cpp

simulador.o:
	g++ -c Simulador.cpp

dgv.o:
	g++ -c DGV.cpp

campeonato.o:
	g++ -c Campeonato.cpp

autodromo.o:
	g++ -c Autodromo.cpp

pista.o:
	g++ -c Pista.cpp

carro.o:
	g++ -c Carro.cpp

piloto.o:
	g++ -c Piloto.cpp

clean:
	rm *.o 





