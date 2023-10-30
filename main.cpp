#include <iostream>
#include "tablero.h"
using namespace std;

int main()
{
    tablero tablero1(8);
    tablero1.impimir_tablero();
    tablero1.liberar_memoria_heap();

    return 0;
}
