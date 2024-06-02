//
//  Pelicula.cpp
//  clase episodio y clase video
//
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 22/05/2024
*/

#include "Pelicula.h"

//Constructores: vacío y con parámetros
Pelicula::Pelicula():Video(){ //Llama a, metodo constructor de la clase base
    oscares = 100;
}

Pelicula::Pelicula(string _iD, string _titulo,
         int _duracion,
         string _genero,
                   double _calificacion, int _oscares):Video(_iD, _titulo, _duracion, _genero, _calificacion){
    oscares = _oscares;
    
}


// Método modificador - set
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}


//Método de acceso
int Pelicula::getOscares(){
    return oscares;
}


//Otros métodos
string Pelicula::str(){
    //Tenemos acceso directo a los atributos de la clase padre porque son protected
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' +
    genero + ' ' + to_string(calificacion) + ' ' + to_string(oscares);
}
