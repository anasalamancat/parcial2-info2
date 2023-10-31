#include "tablero.h"

tablero::tablero(int dimension)
{
    n=dimension;
    for(int i=0;i<n;i++){
        matriz[i]=new int[n];
    }
    posiciones_diagonales=0;
    posiciones_horizontales=0;
    posiciones_verticales=0;
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

void tablero::imprimir_posibles_jugadas()
{
    posiciones_diagonales=12345670;
    posiciones_horizontales=56345621;

    int analizar=0;
    string nombres_columnas="ABCDEFGHIJLKLMNOPQRSTUVWXYZ";
    if(posiciones_diagonales==0 && posiciones_horizontales==0 && posiciones_verticales==0){
        cout<<"\n*NO TIENE POSIBILIDAD DE JUEGO EN ESTE TURNO*";
    }
    else{
        cout<<"JUGADAS POBIBLES:\n";
        while(posiciones_diagonales!=0){
            analizar=posiciones_diagonales%10;
            cout<<endl<<nombres_columnas[analizar];
            posiciones_diagonales=posiciones_diagonales/10;
            cout<<posiciones_diagonales%10;
            posiciones_diagonales=posiciones_diagonales/10;
        }
        while(posiciones_verticales!=0){
            analizar=posiciones_verticales%10;
            cout<<endl<<nombres_columnas[analizar];
            posiciones_verticales=posiciones_verticales/10;
            cout<<posiciones_verticales%10;
            posiciones_verticales=posiciones_verticales/10;
        }
        while(posiciones_horizontales!=0){
            analizar=posiciones_horizontales%10;
            cout<<endl<<nombres_columnas[analizar];
            posiciones_horizontales=posiciones_horizontales/10;
            cout<<posiciones_horizontales%10;
            posiciones_horizontales=posiciones_horizontales/10;
        }
        cout<<endl;
    }

}

void tablero::reiniciar_valores_posiciones()
{
    posiciones_diagonales=0;
    posiciones_horizontales=0;
    posiciones_verticales=0;
}


