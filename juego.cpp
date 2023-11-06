#include "juego.h"
#include <string>
#include <stdlib.h>

juego::juego()
/*Constructor de la clase. Se establece la dimensión del atributo tablero, se inicializan sus valores y se muestra
el menú para ingresar los nombres de los jugadores*/
{
    tablero1.setN(8);
    tablero1.tablero_inicializacion();
    tablero1.valores_iniciales_matriz();
    tablero1.reiniciar_valores_posiciones_juego();
    menu_nombres_jugadores();
}

tablero juego::getTablero1() const
//Retorna el atributo tablero
{
    return tablero1;
}

void juego::iniciar_partida()
/*Método en donde se lleva a cabo la partida. En este se utilizan métodos de tablero y de sí mismo.
Se imprime el tablero, las jugadas posibles según el jugador en turno, se implementan las respectivas
validaciones,se cambian los valores de las fichas en el tablero,se  verifica que haya jugadas y si está
o no lleno el tablero. En caso de que el juego haya terminado, se llama al método juego_terminado*/
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
                cout<<"\nTURNO DEL JUGADOR #"<<turno<<" - POSIBLES JUGADAS: "<<endl;
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
                    cout<<"\n*SE AGOTARON LAS JUGADAS POSIBLES PARA AMBOS JUGADORES. EL JUEGO HA TERMINADO*\n";
                    ban=false;
                }
            }
            turno=cambiar_turno(turno);
            system("cls");
        }
        else{
            cout<<"\n\t*EL TABLERO ESTA COMPLETAMENTE LLENO. EL JUEGO HA TERMINADO*\n";
            ban=false;
        }
    }
    juego_terminado();
}


int juego::elegir_columna_turno()
/*Método para la elección de la columna en que se va a jugar.El jugador ingresa un string y se hace
el respectivo cambio para poder retornar su equivalente en entero. Ejemplo: La columna identificada con
la letra 'A' en la matriz del tablero, es la columna en la posición 0(cero).
*/
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
/*Método para le eleccion de la fila, El número que se ingrese se le debe restar 1 para que coincida
con el manejo de las matrices (ya que las posiciones van de 0 a 7 y no de 1 a 8)
*/
{
    int fila_elegida=0;
    cout<<"Ingrese numero de fila:";
    cin>>fila_elegida;
    fila_elegida--;
    return fila_elegida;
}

void juego::menu_opciones_dimension()
//Método para que el jugador elija la dimensión del tablero (en este caso no es implementada)
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
//Método para ingresar los nombres de los jugadores para darles valor en los atributos de la clase
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
//Método para intercambiar el turno
{
    int turno;
    if(turno_actual==1){turno=2;}
    if(turno_actual==2){turno=1;}
    return turno;
}

void juego::juego_terminado()
/*En este método se cuentan las fichas de cada jugador para establecer el ganador, Se imprime por consola
el recuento y se guarda la información de la partida con el método de la clase histórico.
*/
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
    cout<<"\nFELICIDADES "<<jugadorganador<<"!!! Fuiste el ganador con "<<cantidad_fichas_ganador<<" fichas.\n\n";
}


