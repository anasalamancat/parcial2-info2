#include "tablero.h"

void tablero::setN(int newN)
{
    n = newN;
}

void tablero::tablero_inicializacion()
/*
 Función del constructor
 Inicializa las matrices dinámicas y establece la dimensión del
 tablero(n) según se ingrese en la ejecución.
 */
{
    for(int i=0;i<n;i++){
        matriz[i]=new int[n];
    }
    for(int k=0;k<n;k++){
        posiciones_juego[k]=new bool[n];
    }
}

void tablero::reiniciar_valores_posiciones_juego()
/*establece un valor false a cada posición de la matriz booleana.
 Se usa para dar los valores iniciales y para actualizar después de cada turno*/
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            posiciones_juego[i][j]=false;
        }
    }
}

void tablero::posiciones_posibles(int turno)
/*
 Parámetros: Número entero (1 o 2) que hace referencia al jugador en turno.
 Return: Vacía. Cambia valores de la matriz booleana internamente sin necesidad de retorno

 La función recorre la matriz que tiene almacenada la distribución de las fichas, por cada
 posición, analiza las 8 casillas/posiciones vecinas. Si en esa posición vecina
 está almacenado el valor del oponente, analiza la posición siguiente a esta en la misma dirección
 hasta encontrar un espacio vacío (representado por un 0). Cuando se encuetre la posición
 que almacena el numero 0, se cambiará esa misma posición en la matriz booleana asignando un
 valor True que indica que esa poscición en una jugada posible.

 */
{
    int proximas[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    int contrario=0,cont,pos_filas,pos_columnas;
    bool pos_vacia;
    if(turno==1){contrario=2;}
    if(turno==2){contrario=1;}
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matriz[i][j]==turno){
                cont=0;
                while(cont<8){
                    pos_filas=i+proximas[cont][0];
                    pos_columnas=j+proximas[cont][1];
                    if(pos_filas>=0 && pos_columnas>=0 && pos_filas<n && pos_columnas<n){
                        if(matriz[pos_filas][pos_columnas]==contrario){
                            pos_vacia=false;
                            while(pos_vacia==false && pos_filas>0 && pos_columnas>0 && pos_filas<n && pos_columnas<n){
                            pos_filas+=proximas[cont][0];
                            pos_columnas+=proximas[cont][1];
                            if(matriz[pos_filas][pos_columnas]==0){
                                posiciones_juego[pos_filas][pos_columnas]=true;
                                pos_vacia=true;
                            }
                            else if(matriz[pos_filas][pos_columnas]==turno){
                                pos_vacia=true;
                            }
                            }
                        }
                    }
                    cont++;
                }
            }
        }
    }
}

void tablero::imprimir_jugadas_posibles()
/*Recorre la matriz booleana. Se imprimen las posiciones con valor true.
 Para las columnas se imprime la letra del abecedario que se encuentre
 en la misma posición para hacerlo más amigable y entendible para el jugador
 */
{
    string columnas="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout<<"\nPOSIBLES JUGADAS:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(posiciones_juego[i][j]==true){
                cout<<columnas[j]<<i+1<<endl;
            }
        }
    }
    cout<<"-------------------------";
}

bool tablero::verificar_existencia_jugadas()
/*return: dato tipo Bool.  retorna true si encuentra alguna posicion con valor true
 en la matriz booleana con las posiciones de juego posibles,de lo contrario, retorna false
 Si y solo si este método retorna true, se ejecuta el método "imprimir_jugadas_posibles"
*/
{
    bool existe=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(posiciones_juego[i][j]==true){
                existe=true;
            }
        }
    }
    if(existe==false){cout<<"\n*NO TIENE JUGADAS POSIBLES EN ESTE TURNO*\n";}
    return existe;
}

bool tablero::verificar_tablero_lleno()
{
    bool lleno=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matriz[i][j]==0){
                lleno=false;
            }
        }
    }
    return lleno;
}

void tablero::cambio_fichas_encierro(int fila_escogida, int columna_escogida, int jugador_en_turno)
{
    int contrario=0,pos_filas=0,pos_columnas=0,cambio_filas,cambio_columnas;
    int proximas[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    bool extremo_encierro;
    if(jugador_en_turno==1){contrario=2;}
    if(jugador_en_turno==2){contrario=1;}
    matriz[fila_escogida][columna_escogida]=jugador_en_turno;
    for(int cont=0;cont<8;cont++){
        extremo_encierro=false;
        pos_filas=fila_escogida+proximas[cont][0];
        pos_columnas=columna_escogida+proximas[cont][1];
        cambio_filas=fila_escogida,cambio_columnas=columna_escogida;
        if(pos_filas>=0 && pos_columnas>=0 && pos_filas<n && pos_columnas<n){
            if(matriz[pos_filas][pos_columnas]==contrario){
                while(extremo_encierro==false &&pos_filas>=0 && pos_columnas>=0 && pos_filas<n && pos_columnas<n){
                    pos_filas+=proximas[cont][0];
                    pos_columnas+=proximas[cont][1];
                    if(matriz[pos_filas][pos_columnas]==0){
                        extremo_encierro=true;
                    }
                    else if(matriz[pos_filas][pos_columnas]==jugador_en_turno){
                        while(cambio_filas!=pos_filas || cambio_columnas!=pos_columnas){
                            matriz[cambio_filas][cambio_columnas]=jugador_en_turno;
                            cambio_filas+=proximas[cont][0];
                            cambio_columnas+=proximas[cont][1];
                        }
                        extremo_encierro=true;
                    }
                    else if(pos_filas<0 || pos_filas==n || pos_columnas<0 || pos_columnas==n){
                        extremo_encierro=true;
                    }
                }
            }
        }
    }
}

void tablero::valores_iniciales_matriz()
//Establece los valores con que empieza la partida en la matriz de enteros.
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==n/2 || i==(n-1)/2){
                if(j==i){
                    matriz[i][j]=1;
                }
                else if(j>=(n-1)/2 && j<=n/2 && j!=i){
                    matriz[i][j]=2;
                }
                else{
                    matriz[i][j]=0;
                }
            }
            else{
                matriz[i][j]=0;
            }
        }
    }
}

void tablero::impimir_tablero()
{
    string nombres_columnas="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout<<"\n\JUGADOR 1: o\nJUGADOR 2: +\n\n";
    cout<<" ";
    for(int k=0;k<n;k++){
        cout<<"  "<<nombres_columnas[k];
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" ";
        for(int j=0;j<n;j++){
        if(matriz[i][j]==0){
            cout<<" - ";
        }
        if(matriz[i][j]==1){
            cout<<" o ";
        }
        if(matriz[i][j]==2){
            cout<<" + ";
        }
        }
        cout<<endl;
    }
}

int tablero::numfichas(int jugador)
{
    int conteo=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matriz[i][j]==jugador){
                conteo++;
            }
        }
    }
    return conteo;
}


bool tablero::verificar_jugada_ingresada(int numfila, int numcolumna)
{
    bool correcta=false;
    if(posiciones_juego[numfila][numcolumna]==true){
        correcta=true;
    }
    return correcta;
}


void tablero::liberar_memoria_heap()
{
    for(int i=0;i<n;i++){
        delete [] matriz[i];
        delete [] posiciones_juego[i];
    }
    delete[] matriz;
    delete[] posiciones_juego;
}

