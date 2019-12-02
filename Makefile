all: testa_pista.o simulador.o dgv.o campeonato.o autodromo.o pista.o carro.o piloto.o consola.o
	g++ Testa_Pista.o simulador.o dgv.o campeonato.o autodromo.o pista.o carro.o piloto.o consola.o -o Simulador

consola.o:
	g++ -c consola.cpp

testa_pista.o:
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





