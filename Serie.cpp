//
//  Serie.cpp
//  clase episodio y clase video
//
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 22/05/2024
*/

#include "Serie.h"

//método constructor
Serie::Serie():Video(){
    //Solo se inicializa la cantidad
    cantidad = 0;
}

Serie::Serie(string _iD, string _titulo,
         int _duracion,
         string _genero,
         double _calificacion)
:Video(_iD, _titulo, _duracion, _genero, _calificacion){
    
}

//Métodos Modificadores - setters
void Serie::setEpisodio(int posicion, Episodio episodio){
    // primero validar que exista ese episodio
    if (posicion >= 0 && posicion < cantidad){
        episodios[posicion] = episodio;
    }
}

//Cambiar el valor del atributo cantidad con el nuevo valor recibido _cantidad
void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}


//Métodos de acceso - getters
Episodio Serie::getEpisodio(int posicion){
    //Crea un objeto de tipo episodio y lo incializa con el contructor default
    Episodio epi;
    
    //Validar primero que exista el  episodio solicitado (posicion)
    if (posicion >= 0 && posicion < cantidad){
        return episodios[posicion];
    }
    
    //Si no existe se retorna un episodio default
    return epi;
    
}

//Retorna el valor del atributo cantidad
int Serie::getCantidad(){
    return cantidad;
}


//Otros métodos
double Serie::calculaPromedio(){
    double acumulado = 0;
    
    for (int index = 0; index < cantidad; index++){
        acumulado = acumulado + episodios[index].getCalificacionE();
    }
    
    if (cantidad > 0 ) {
        return acumulado / cantidad;
    }
    else {
        return 0;
    }
}
//Se hace el overwriting del método str() en la clase base
string Serie::str(){
    string resultado=(iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' +
    genero + ' ' + to_string(calculaPromedio()) + ' ' + to_string(cantidad) + "\n");
    if (cantidad > 0){
        for (int index = 0; index < cantidad; index++){
            resultado += episodios[index].str() + '\n';
    }
    return resultado;
    }
    else {
        return resultado;
    }

}
// agraga un Episodio solo si existe espacio
void Serie::agregaEpisodio (Episodio episodio){
    if (cantidad < 5){
        episodios[cantidad++] = episodio;
    }
}
void Serie::calculaDuracion (Episodio episodio){
    int DuracionCalculada = 0;
    for  (int index = 0; index < cantidad; index++){
        DuracionCalculada += episodios[index].getTemporadaE();
    }
}
