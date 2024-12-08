#include "../headers/Tablero.h"

Tablero::Tablero() : tablero(3, vector<char>(3, ' ')) {}

void Tablero::imprimir() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3;++j ) {
            cout<< tablero[i][j];
            if(j < 2) cout << " | ";
        }
        cout << "\n";
        if(i < 2) cout << "---------\n";
    }
    cout << "\n";
}

bool Tablero::estaLleno() {
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if( tablero[i][j] == ' ') return false;
        }
    }

    return true;
}

int Tablero::evaluar() {
    for(int i = 0; i < 3; ++i) {
        if(tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
           if(tablero[i][0] == 'X') return 10;
           if(tablero[i][0] == 'O') return -10;
        }
        if(tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
           if(tablero[0][i] == 'X') return 10;
           if(tablero[0][i] == 'O') return -10;
        }

    }
    if(tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        if(tablero[0][0] == 'X') return 10;
        if(tablero[0][0] == 'O') return -10;
    }
    if(tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        if (tablero[0][2] == 'X') return 10;
        if (tablero[0][2] == 'O') return -10;
    }

    return 0;
}

bool Tablero::esMovimientoValido(int fila, int col) {
    return fila >= 0 && fila < 3 && col >= 0 && col < 3 && tablero[fila][col] == ' '; 
}

void Tablero::hacerMovimiento(int fila, int col, char jugador) {
    if(esMovimientoValido(fila, col)) {
        tablero[fila][col] = jugador;
    }
}