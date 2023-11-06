#include "historico.h"
using namespace std;

historico::historico(){ //contructor, abre los archivos
    historicoEscritura.open("historico.txt", ios::app); //abre el archivo en modo escritura, el "ios::app" anade la info al final del archivo
    historicoLectura.open("historico.txt"); //abre el archivo en modo lectura

    if(!historicoEscritura.is_open() || !historicoLectura.is_open()){
        cerr << "Error al abrir el archivo." << endl; //si no es posible abrir el archivo el programa se cierra y muestra el mensaje en consola
    }
}

void historico::guardarDatosPartida(string _jugador1, string _jugador2, string _ganador, int _puntajeGanador, int _totalpuntos){
    /*metodo que tiene como parametros ls datos de la partida
    (jugadores, ganador, total de puntos) guarda esots datos en un archivo llamado historico.txt
    los datos se guardan asi: fecha y hora; jugadores; ganador; puntaje*/
    historicoEscritura << fechaHoraActual() << "; " << _jugador1 << " y " << _jugador2 << "; " << _ganador << "; " << _puntajeGanador << '/' << _totalpuntos << ";" << endl; //el formato en que se guarda la info es el siguiente: fecha, jugadores, ganador y puntaje
    historicoEscritura.close(); //cerramos el archivo para evitar posibles daños en el archivo
}

void historico::mostrarHistorico(){
    /*metodo que se encarga de abrir el archivo que contiene el historico de las partidas
    se crea una estructura para el manejo de los datos, se instancia la clase stringstream para un mejor manejo de datos
    los datos se muestran en forma de una tabla: primero la fecha y hora, los jugadores, el ganador y el puntaje*/
    struct datosPartida{
        string fecha;
        string jugadores;
        string ganador;
        string puntaje;
    };

    string line;
    while(getline(historicoLectura, line)){
        stringstream flujo(line);
        datosPartida partida;

        getline(flujo, partida.fecha, ';');
        getline(flujo, partida.jugadores, ';');
        getline(flujo, partida.ganador, ';');
        getline(flujo, partida.puntaje, ';');
        cout << "\n________________________________\nFecha y hora: " << partida.fecha << "\nJugadores:\t" << partida.jugadores << "\nGanador:\t" << partida.ganador << "\nPuntaje:\t" << partida.puntaje << "\n________________________________\n" << endl;
    }
    historicoLectura.close();//cerramos el archivo para evitar posibles daños en el archivo
}
string historico::fechaHoraActual(){//funcion para capturar la fecha y la hora actuales del sistema
    time_t actual = time(nullptr); //calcula el tiempo actual en segundos desde el 01/01/1970 la epoca Unix, time(nullptr) obtien la hora actual como un valor de time_t
    tm* local = localtime(&actual); //"localtime" convierte la info de actual en una estrutura "tm", local es un puntero que apunta hacia la estructura

    fecha = to_string(local ->tm_mday) + '/' + to_string(local ->tm_mon + 1) + '/' + to_string(local ->tm_year + 1900); /*string que contien la fecha: "tm_mday" dia del mes(1,31),
        "tm_mon" mes (0: enero, 11:diciembre) se le suma 1 para que sea en un formato mas amigable, "tm_year" almacena los años transxurridos desde 1900 se le suma este valor para que sea un formato mas amigable*/
        hora = to_string(local ->tm_hour) + ':' + to_string(local ->tm_min) + ':' + to_string(local ->tm_sec); /*string que contiene la hora: "tm_hour" hora del sitema (formato militar),
        "tm_min" minutos actuales del sistema (00, 59), "tm_sec" segundo actuales del sistema (00, 59)*/
    fecha = fecha + " " + hora; //se almacenan los datos en un solo string para ser retornados por al funcion
    return fecha; //retorno de la funcion
}
