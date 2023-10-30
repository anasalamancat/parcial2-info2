#ifndef TABLERO_H
#define TABLERO_H
#include <string>
#include <iostream>
using namespace std;

class tablero{
private:
    int n,cantidad_v,cantidad_h,cantidad_d;
    int **matriz=new int*[n];
    //int *posiciones_verticales=new int[cantidad_v];
    //int *posiciones_horizontales=new int[cantidad_h];
    //int *posiciones_diagonales=new int[cantidad_d];
public:
    tablero(int dimension);
    void valores_iniciales_matriz();
    void liberar_memoria_heap();
    void impimir_tablero();
};

#endif // TABLERO_H
