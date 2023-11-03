#include "juego.h"
#include <string>
#include <stdlib.h>
tablero juego::getTablero1() const
{
    return tablero1;
}

void juego::iniciar_partida()
{
    int turno=1,fila_juego=0,columna_juego=0,continua_juego=0;
    bool ban=true;
    bool jugada_ingresada_correctamente=false;
    while (ban==true){
        tablero1.impimir_tablero();
        tablero1.posiciones_posibles(turno);
        if(tablero1.verificar_tablero_lleno()==false){
            if(tablero1.verificar_existencia_jugadas()==true){
                continua_juego=0;
                cout<<"\nTURNO DEL JUGADOR #"<<turno<<endl;
                tablero1.imprimir_jugadas_posibles();
                jugada_ingresada_correctamente=false;
                while(jugada_ingresada_correctamente==false){
                    columna_juego=elegir_columna_turno();
                    fila_juego=elegir_fila_turno();
                    if(tablero1.verificar_jugada_ingresada(fila_juego,columna_juego)==true){
                        jugada_ingresada_correctamente=true;
                    }
                    else{
                        cout<<"*La posicion ingresada no corresponde a una jugada posible. Intenta nuevamente";
                    }
                }
                tablero1.cambio_fichas_encierro(fila_juego,columna_juego,turno);
                tablero1.reiniciar_valores_posiciones_juego();
            }
            else{
                continua_juego++;
                if(continua_juego==2){
                    cout<<"\n*SE AGOTARON LAS JUGADAS POSIBLES PARA AMBOS JUGADORES*";
                    ban=false;
                }
            }
            turno=cambiar_turno(turno);
            system("cls");
        }
        else{
            cout<<"\n*EL TABLERO ESTA COMPLETAMENTE LLENO*";
            ban=false;
        }
    }
    cout<<"RECUENTO DE LA PARTIDA:";

}


int juego::elegir_columna_turno()
{
    string columnas_nombres="ABCDEFGHIJKLMNO";
    string columna_elegida_str;
    string analizar;
    int columna_elegida_int=0;
    cout<<"\nIngrese nombre de columna(A,B,C,D...):";
    cin>>columna_elegida_str;
    for(int i=0;i<columnas_nombres.size();i++){
        analizar=columnas_nombres[i];
        if(analizar==columna_elegida_str){
            columna_elegida_int=i;
        }
    }
    return columna_elegida_int;
}

int juego::elegir_fila_turno()
{
    int fila_elegida=0;
    cout<<"Ingrese numero de fila:";
    cin>>fila_elegida;
    fila_elegida--;
    return fila_elegida;
}

void juego::menu_opciones_dimension()
{
    int decision=0;
    cout<<"\nOpciones dimension del tablero:\n\t1.Tradicional(8x8)\n\t2.Otra\n\nIngrese su eleccion:";
    cin>>decision;
    while(decision!=1 &&decision!=2){
        cout<<"*Valor ingresado no corresponde a una opcion*\nIngrese su eleccion:";
        cin>>decision;
    }
    if(decision==1){
        tablero1.setN(8);
    }
    if(decision==2){
        cout<<"Ingrese la dimension:";
        cin>>decision;
        tablero1.setN(decision);
    }
}

void juego::menu_nombres_jugadores()
{
    string nombre;
    cout<<"Ingrese el nombre del jugador #1:";
    cin>>nombre;
    jugador1=nombre;
    cout<<"Ingrese el nombre del jugador #2:";
    cin>>nombre;
    jugador2=nombre;
}


int juego::cambiar_turno(int turno_actual)
{
    int turno;
    if(turno_actual==1){turno=2;}
    if(turno_actual==2){turno=1;}
    return turno;
}

void juego::juego_terminado()
{
    int fichasjugador1=0,fichasjugador2=0;
    string jugadorganador,fecha;
    fichasjugador1=tablero1.numfichas(1);
    fichasjugador2=tablero1.numfichas(2);
    if(fichasjugador1>fichasjugador2){
        jugadorganador=jugador1;
        cantidad_fichas_ganador=fichasjugador1;
    }
    else{
        jugadorganador=jugador2;
        cantidad_fichas_ganador=fichasjugador2;
    }
    historico_partida.guardarDatosPartida(jugador1,jugador2,jugadorganador,cantidad_fichas_ganador,64);
}

juego::juego()
{
    tablero1.setN(8);
    tablero1.tablero_inicializacion();
    tablero1.valores_iniciales_matriz();
    tablero1.reiniciar_valores_posiciones_juego();
    // menu_opciones_dimension();
    menu_nombres_jugadores();
}
