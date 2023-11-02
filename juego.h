#ifndef JUEGO_H
#define JUEGO_H
#include"tablero.h"

class juego
{
private:
    string jugador1;
    string jugador2;
    int cantidad_fichas_ganador;
    tablero tablero1;
public:
    void iniciar_partida();
    int elegir_columna_turno();
    int elegir_fila_turno();
    void menu_opciones_dimension();
    void menu_nombres_jugadores();
    int cambiar_turno(int turno_actual);
    juego();
};

#endif // JUEGO_H
