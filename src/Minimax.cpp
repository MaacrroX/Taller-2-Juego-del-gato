#include "../headers/Minimax.h"
#include "../headers/Nodo.h"


int Minimax::minimax(Nodo* nodo, bool maximizando, int alpha, int beta) {
    int evaluacion = nodo->tablero.evaluar();

    if(evaluacion == 10 || evaluacion == -10 || nodo->tablero.estaLleno()) {
        return evaluacion;
    }

    if(maximizando) {
        int mejorvalor = numeric_limits<int>::min();  //Se inicia la variable en el menor valor posible para un entero
        nodo->generarHijos();
        for (Nodo* hijo : nodo->hijos){
            mejorvalor = max(mejorvalor, minimax(hijo, false, alpha, beta));
            alpha = max(alpha, mejorvalor);
            if(beta <= alpha) {
                break;
            }
        }
        return mejorvalor;
    } else {
        int mejorValor = numeric_limits<int>::max();
        nodo->generarHijos();
        for(Nodo* hijo: nodo->hijos) {
            mejorValor = min(mejorValor, minimax(hijo, true, alpha, beta));
            beta = min(beta, mejorValor);
            if(beta <= alpha) {
                break;
            }
        }
        return mejorValor;
    }
}

pair<int, int> Minimax::mejorMovimiento(const vector<vector<char>>& tablero, char jugador) {
    Tablero t;
    t.tablero = tablero;
    Nodo* raiz = new Nodo(t, jugador);
    pair<int, int> movimiento = {-1, -1}; 
    int mejorValor = numeric_limits<int>::min();

    raiz->generarHijos();

    for(Nodo* hijo: raiz->hijos) {
        int valor = minimax(hijo, false, numeric_limits<int>::min(), numeric_limits<int>::max());
        if (valor > mejorValor) {
            mejorValor = valor;
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j){
                    if(hijo->tablero.tablero[i][j] != t.tablero[i][j]) {
                        movimiento = {i,j};
                    }
                }
            }
        }
    }
    delete raiz;
    return movimiento;
}