#include "../headers/Minimax.h"
#include "../headers/Nodo.h"
#include "../headers/Tablero.h"

#include "Nodo.cpp"
#include "Tablero.cpp"
#include "Minimax.cpp"


int main() {
    Tablero tablero;
    Minimax ia;
    char jugadorHumano = 'O';
    char jugadorIA = 'X';
    bool turnoHumano = true;

    cout << "----Juego del Gato ----\n";
    tablero.imprimir();

    while (true) {
        if (turnoHumano) {
            int fila, columna;
            cout << "Tu turno (O). Ingresa fila (1-3) y columna (1-3): ";
            cin >> fila >> columna;
            fila--; columna--;

            if (tablero.esMovimientoValido(fila, columna)) {
                tablero.hacerMovimiento(fila, columna, jugadorHumano);
            } else {
                cout << "Movimiento inválido. Intenta de nuevo.\n";
                continue;
            }
        } else {
            cout << "Turno de la IA...\n";
            pair<int, int> movimiento = ia.mejorMovimiento(tablero.tablero, jugadorIA);
            tablero.hacerMovimiento(movimiento.first, movimiento.second, jugadorIA);
        }

        tablero.imprimir();
        int evaluacion = tablero.evaluar();
        if (evaluacion == 10) {
            cout << "La IA gana (X)!\n";
            break;
        } else if (evaluacion == -10) {
            cout << "¡Ganaste (O)!\n";
            break;
        } else if (tablero.estaLleno()) {
            cout << "¡Es un empate!\n";
            break;
        }

        turnoHumano = !turnoHumano;
    }

    return 0;
}