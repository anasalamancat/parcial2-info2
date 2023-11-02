#include <iostream>
#include "tablero.h"
using namespace std;

int main()
{
    int dimension=8;
    tablero tablero1(dimension);
    tablero1.valores_iniciales_matriz();
    tablero1.reiniciar_valores_posiciones_juego();
    tablero1.impimir_tablero();
    tablero1.posiciones_posibles(2);
    tablero1.imprimir_jugadas_posibles();
    tablero1.liberar_memoria_heap();

    return 0;
}
