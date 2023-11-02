#include "tablero.h"

tablero::tablero(int dimension)
/*
 Función del constructor
 Inicializa las matrices dinámicas y establece la dimensión del
 tablero(n) según se ingrese en la ejecución.
 */
{
    n=dimension;
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
 parámetros: Número entero (1 o 2) que hace referencia al jugador en turno.
 Return: Vacía. Cambia valores de la matriz booleana internamente sin necesidad de retorno

 La función recorre la matriz que tiene almacenada la distribución de las fichas, por cada
 posición, analiza las 8 casillas/posiciones vecinas a ella. Si en esa posición vecina
 está almacenado el valor del oponente, analiza la posición siguiente a esta hasta encontrar un
 espacio vacío (representado por un 0). Cuando se encuetre la posición que almacena el numero 0,
 se cambiará esa misma posición en la matriz booleana asignando un valor True que indica que esa
 poscición en una jugada posible.

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
                    if(matriz[pos_filas][pos_columnas]==contrario){
                        pos_vacia=false;
                        while(pos_vacia==false){
                        pos_filas+=proximas[cont][0];
                        pos_columnas+=proximas[cont][1];
                        if(matriz[pos_filas][pos_columnas]==0){
                            posiciones_juego[pos_filas][pos_columnas]=true;
                            pos_vacia=true;
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
    cout<<"\n-----POSIBLES JUGADAS----\n";
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
/*return: dato tipo Bool.  retorna true si encuentra alguna posicion con valor true,
 de lo contrario, retorna false
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

void tablero::valores_iniciales_matriz()
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
    cout<<"JUGADOR 1 -> o\nJUGADOR 2 -> +\n\n";
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
void tablero::liberar_memoria_heap()
{
    for(int i=0;i<n;i++){
        delete [] matriz[i];
        delete [] posiciones_juego[i];
    }
    delete[] matriz;
    delete[] posiciones_juego;
}



