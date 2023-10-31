#ifndef TABLERO_H
#define TABLERO_H
#include <string>
#include <iostream>
using namespace std;

class tablero{
private:
    int n,posiciones_verticales,posiciones_horizontales,posiciones_diagonales;
    int **matriz=new int*[n];
public:
    tablero(int dimension);
    void valores_iniciales_matriz();
    void liberar_memoria_heap();
    void impimir_tablero();
    void imprimir_posibles_jugadas();
    void reiniciar_valores_posiciones();
    void analizar_posiciones_horizontales(int jugador); //int jugador será 1 o 2 segun sea el turno. IMPLEMENTACION CODIGO FALTA
};

#endif // TABLERO_H
