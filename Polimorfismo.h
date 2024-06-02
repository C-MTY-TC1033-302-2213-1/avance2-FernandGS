//
//  Polimorfismo.hpp
//  clase episodio y clase video
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 26/05/2024
¿Qué aprendí en el desarrollo de esta clase? (solo en el .h responde a esta pregunta)
Aprendí acerca de la herencia y de la composición ya que la la clase serie tiene las propiedades de la clase
video(asi se demuestra la herencia), y al mismo tiempo esta clase se compone de otra clase, la clase episodio(aqui
se demuestra la composición).
*/

#ifndef Polimorfismo_h
#define Polimorfismo_h

#include <stdio.h>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include "Video.h"
const int MAX_VIDEOS = 100;

class Polimorfismo{
    private:
        Video *arrPtrVideos[MAX_VIDEOS];
        int cantidad;
    public:
        //Constructor vacío 
        Polimorfismo();

        void leerArchivo(string nombre );


        //Metodos modificadores - setters
        void setPtrVideo(int index, Video *video);
        void setCantidad(int _cantidad);

        //Metodos de acceso - getters
        Video* getPtrVideo(int index);
        int getCantidad();

        //Otros métodos
        void reporteInventario();
        void reporteCalificacion(double _calificacion);
        void reporteGenero(string _genero);
        void reportePeliculas();
        void reporteSeries();
};


#endif /* Polimorfismo_h */
