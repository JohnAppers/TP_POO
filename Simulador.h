#ifndef SIMULADOR_H
#define SIMULADOR_H

#include"Simulador.h"
#include "DGV.h"
#include "Campeonato.h"

class Simulador
{
    DGV dgv;
    Campeonato campeonato;

public:
    void carrega(string file_name);
    const DGV &getDGV() const;
};

#endif