#include "tablero.h"

tablero::tablero(int dimension)
{
    n=dimension;
    for(int i=0;i<n;i++){
        matriz[i]=new int[n];
    }
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
    cout<<" ";
    for(int k=0;k<n;k++){
        cout<<"  "<<nombres_columnas[k];
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" ";
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


