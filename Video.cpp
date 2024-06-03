//
//  Video.cpp
//  clase episodio y clase video
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 22/05/2024
*/

#include "Video.h"
//Constructores

Video::Video(){
    iD = "0000";
    titulo = "Fernando Gael Hernández Salazar";
    duracion = 1000;
    genero = "masculino";
    calificacion = 100; //cambiar  calificacion
}
Video::Video(string _iD, string _titulo,
      int _duracion,
      string _genero,
             double _calificacion){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

// Metodos modificadores (set)
void Video::setId(string _iD){
    iD = _iD;
}

void Video::setNombre(string _titulo){
    titulo = _titulo;
}

void Video::setDuracion(int _duracion){
    duracion = _duracion;
}

void Video::setGenero(string _genero){
    genero = _genero;
}

void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}


//Metodos de acceso (get)
string Video::getId(){
    return iD;
}

string Video::getNombre(){
    return titulo;
}

int Video::getDuracion(){
    return duracion;
}

string Video::getGenero(){
    return genero;
}

double Video::getCalificacion(){
    return calificacion;
}

//Otros metodos
string Video::str(){
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' +
    genero + ' ' + to_string(calificacion);
}
