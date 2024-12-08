#pragma once
#include "Tablero.h"


#include <vector> 
#include <iostream>
#include <limits>

using namespace std;

class Nodo {
public: 
    Tablero tablero;
    char jugador;
    vector <Nodo*> hijos;
    int valor;

    Nodo(Tablero t, char c);

    ~Nodo();
    void generarHijos();

};