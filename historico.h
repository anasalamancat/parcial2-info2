#ifndef HISTORICO_H
#define HISTORICO_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctime> //contiene las funcones para capturar la fecha y hora del sistema
using namespace std;

class historico
{
private:
    ofstream historicoEscritura; //objeto para escribir en el archivo
    ifstream historicoLectura; //obketo para leer la info del archivo
    string fecha; //guarda la fecha actual del sistema
    string hora; //guarda la hora actual del sistema
public:
    historico(); //construtor de la clase
    void guardarDatosPartida(string _jugador1, string _jugador2, string _ganador, int _puntajeGanador, int _totalPuntos);  //recoje los info de la partida para guardarla en el archivo
    void mostrarHistorico(); //imprime en consola el historico de las partidas
    string fechaHoraActual(); //toma la fecha y hora actual del sistema
};

#endif // HISTORICO_H
