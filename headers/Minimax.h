#pragma once

#include "Nodo.h"
#include "Tablero.h"


class Minimax {
public:
    int minimax(Nodo* nodo, bool maximizando, int alpha, int beta);
    pair<int, int> mejorMovimiento(const vector<vector<char>>& tablero, char jugador);
};