#include "../headers/Nodo.h"
#include "../headers/Tablero.h"


Nodo::Nodo(Tablero t, char c) : tablero(t), jugador(c), valor(0) {}

Nodo::~Nodo() {
    for(Nodo* hijo : hijos) {
        delete hijo;
    }
}

void Nodo::generarHijos() {
    char sgteJugador = (jugador == 'X') ? 'O' : 'X';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero.esMovimientoValido(i, j)) {
                Tablero nuevoTablero = tablero;
                nuevoTablero.hacerMovimiento(i, j, jugador);
                hijos.push_back(new Nodo(nuevoTablero, sgteJugador));
            }
        }
    }
}