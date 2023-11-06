#include <iostream>
#include "juego.h"
using namespace std;

int main()
{
    int eleccion=0;
    cout<<"-BIENVENIDO(A) A OTHELLO-\n\nQue desea hacer?\n\n\t1.Iniciar nueva partida\n\t2.Ver historial del juego\n\nIngrese su eleccion:";
    cin>>eleccion;
    while(eleccion!=1 &&eleccion!=2){
        cout<<"*El valor ingresado no corresponde a una opción*\n Ingrese nuevamente su eleccion: ";
         cin>>eleccion;
    }
    if(eleccion==1){
        juego juego1;
        juego1.iniciar_partida();
        tablero tablero_juego=juego1.getTablero1();
        tablero_juego.liberar_memoria_heap();
    }
    else{
        historico historial;
        historial.mostrarHistorico();
    }
    return 0;
}
