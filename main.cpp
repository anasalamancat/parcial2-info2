#include <iostream>
#include "tablero.h"
using namespace std;

int main()
{
    int dimension=8;
    tablero tablero1(dimension);
    tablero1.valores_iniciales_matriz();
    tablero1.impimir_tablero();
    tablero1.imprimir_posibles_jugadas();
    tablero1.liberar_memoria_heap();

    return 0;
}
