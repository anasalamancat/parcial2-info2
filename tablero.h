#ifndef TABLERO_H
#define TABLERO_H
#include <string>
#include <iostream>
using namespace std;

class tablero{
private:
    int n;
    bool **posiciones_juego=new bool*[n];
    int **matriz=new int*[n];
public:
    tablero(int dimension);
    void reiniciar_valores_posiciones_juego();
    void valores_iniciales_matriz();
    void impimir_tablero();
    void posiciones_posibles(int turno);
    void imprimir_jugadas_posibles();
    bool verificar_existencia_jugadas();
    void liberar_memoria_heap();
};

#endif // TABLERO_H
