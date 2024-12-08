#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Tablero {
public:
    vector<vector<char>> tablero;

    Tablero();

    void imprimir();
    bool estaLleno();
    int evaluar();
    bool esMovimientoValido(int fila, int colummna);
    void hacerMovimiento(int fila, int columna, char jugador);
};