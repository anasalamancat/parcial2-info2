#include "auxiliares.h"

int numero_menor(int num1, int num2)
{
    int menor=0;
    if(num1<num2){menor=num1;}
    if(num2<num1){menor=num2;}
    return menor;
}

int numero_mayor(int num1, int num2)
{
    int mayor=0;
    if(num1>num2){mayor=num1;}
    if(num2>num1){mayor=num2;}
    return mayor;
}
