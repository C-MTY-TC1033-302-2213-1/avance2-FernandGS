//
//  Episodio.cpp
//  clase episodio y clase video
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 22/05/2024
*/
//

#include "Episodio.h"

//Constructores
Episodio::Episodio(){
    tituloE = "Titulo provisional";
    temporadaE = 000;
    calificacionE = 000;
}
Episodio::Episodio(string _tituloE,
      int _temporadaE,
      int _calificacionE){
    tituloE = _tituloE;
    temporadaE = _temporadaE;
    calificacionE = _calificacionE;
    
}
// Metodos modificadores (set)
void Episodio::setNombreE(string _tituloE){
    tituloE = _tituloE;
}

void Episodio::setTemporadaE(int _temporadaE){
    temporadaE = _temporadaE;
}

void Episodio::setCalificacionE(int _calificacionE){
    calificacionE = _calificacionE;
}


//Metodos de acceso (get)
string Episodio::getNombreE(){
    return tituloE;
}

int Episodio::getTemporadaE(){
    return temporadaE;
}

int Episodio::getCalificacionE(){
    return calificacionE;
}

//Otros metodos
string Episodio::str(){
    return tituloE + ' ' + to_string(temporadaE) + ' '+ to_string(calificacionE);
}
