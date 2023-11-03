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
    void tablero_inicializacion();
    void reiniciar_valores_posiciones_juego();
    void valores_iniciales_matriz();
    void impimir_tablero();
    void posiciones_posibles(int turno);
    void imprimir_jugadas_posibles();
    bool verificar_existencia_jugadas();
    bool verificar_tablero_lleno();
    void cambio_fichas_encierro(int fila_escogida,int columna_escogida,int jugador_en_turno);
    void liberar_memoria_heap();
    bool verificar_jugada_ingresada(int numfila,int numcolumna);
    int numfichas(int jugador);
    void setN(int newN);
};

#endif // TABLERO_H
