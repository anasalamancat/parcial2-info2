#ifndef JUEGO_H
#define JUEGO_H
#include"tablero.h"
#include "historico.h"

class juego
{
private:
    string jugador1;
    string jugador2;
    int cantidad_fichas_ganador;
    tablero tablero1;
    historico historico_partida;
public:
    void iniciar_partida();
    int elegir_columna_turno();
    int elegir_fila_turno();
    void menu_opciones_dimension();
    void menu_nombres_jugadores();
    int cambiar_turno(int turno_actual);
    void juego_terminado();
    int menu_principal();
    juego();
    tablero getTablero1() const;
};

#endif // JUEGO_H
