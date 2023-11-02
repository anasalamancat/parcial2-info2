#include "juego.h"
#include <string>
#include <stdlib.h>
void juego::iniciar_partida()
{
    int turno=1,fila_juego,columna_juego,continua_juego=0;
    bool ban=true;
    bool jugada_ingresada_correctamente=false;
    while (ban==true){
        tablero1.impimir_tablero();
        tablero1.posiciones_posibles(turno);
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
                ban=false;
            }
        }
        turno= cambiar_turno(turno);
        system("cls");
    }
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
    cout<<"\nIngrese numero de fila:";
    cin>>fila_elegida;
    fila_elegida--;
    return fila_elegida;
}

void juego::menu_opciones_dimension()
{
    int decision=0;
    cout<<"\nOpciones dimension del tablero:\n\n1.Tradicional(8x8)\n2.Otra\nIngrese su eleccion:";
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

juego::juego()
{
    cout<<"--------BIENVENIDO A OTHELLO---------\n";
    menu_opciones_dimension();
    menu_nombres_jugadores();
    tablero1.tablero_inicializacion();
    tablero1.valores_iniciales_matriz();
    tablero1.reiniciar_valores_posiciones_juego();
}
