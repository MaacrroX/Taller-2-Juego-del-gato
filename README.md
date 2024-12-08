Minimax es un algoritmo de búsqueda utilizado para juegos de dos jugadores de suma cero y con información perfecta, como el juego del gato. El objetivo es que un jugador (el maximizador) elija el movimiento que maximice su ganancia, mientras que el otro jugador (el minimizador) busca minimizar esa ganancia.

Funcionamiento del algoritmo:

1. Genera un árbol de juego donde cada nodo representa un estado del tablero.
2. Calcula un puntaje (heurístico) para los estados finales (hojas del árbol).
3. Propaga esos puntajes hacia arriba para que cada nodo padre obtenga el valor óptimo para el jugador correspondiente.

Poda alfa-beta optimiza Minimax reduciendo las ramas que no influyen en la decisión final. Utiliza dos valores:

1. Alpha: El mejor puntaje que el maximizador puede garantizar.
2. Beta: El mejor puntaje que el minimizador puede garantizar.

Cuando beta <= alpha, no es necesario explorar más nodos en esa rama.

Uso del programa:

1. El jugador ingresara las coordenadas,primero la fila y luego la columna.
2. La IA toma automáticamente su decisión.
3. El juego termina cuando hay un ganador o un empate.

Diagrama del arbol considerando el siguiente caso:

X | O | ▢
---+---+---
▢ | X | ▢  
---+---+---
▢ |▢ | ▢  

Raíz (Turno O)
1. Movimiento (O en [0, 2])
   X gana (Valor = +10)
   ...

2. Movimiento (O en [1, 2])
   Empate (Valor = 0)
   ...

3. Movimiento (O en [2, 2])
   X gana (Valor = +10)
   ...

El algoritmo decidirá el movimiento que minimice la pérdida para "O".



Analisis de Complejidad

1. Sin poda la complejidad es O(b^d)
2. Con poda la complejidad es O(b^(d/2))

Donde "b" es el numero posible de movimientos en cada turno y "d" es La pronfundidad del arbol(numero de turnos restantes).


