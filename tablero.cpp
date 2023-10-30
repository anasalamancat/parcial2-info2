#include "tablero.h"

tablero::tablero(int dimension)
{
    n=dimension;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==n/2 || i==(n+1)/2){
                if(i==j){matriz[i][j]=1;}
                if(j==i+1||j==i-1){matriz[i][j]=2;}
                else{
                    matriz[i][j]=0;
                }
            }
        }
    }
}


void tablero::liberar_memoria_heap()
{
    for(int i=0;i<n;i++){
        delete [] matriz[i];
    }
    delete[] matriz;
    //delete[] posiciones_diagonales;
    //delete[] posiciones_horizontales;
    //delete[] posiciones_verticales;
}

void tablero::impimir_tablero()
{
    string nombres_columnas="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int k=0;k<n;k++){
        cout<<"\t"<<nombres_columnas[k];
    }
    for(int i=0;i<n;i++){
        cout<<"i\t";
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


