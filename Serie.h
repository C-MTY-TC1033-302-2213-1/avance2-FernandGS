//
//  Serie.h
//  clase episodio y clase video
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 22/05/2024
¿Qué aprendí en el desarrollo de esta clase? (solo en el .h responde a esta pregunta)
Aprendí acerca de la herencia y de la composición ya que la la clase serie tiene las propiedades de la clase
video(asi se demuestra la herencia), y al mismo tiempo esta clase se compone de otra clase, la clase episodio(aqui
se demuestra la composición).
*/

#ifndef Serie_h
#define Serie_h

#include <stdio.h>

//Para herencia
#include "Video.h"
//Para composicion
#include "Episodio.h"

#include <string>

using namespace std;



class Serie: public Video{
private:
    Episodio episodios[5];
    int cantidad;
public:
    //método constructor
    Serie();
    Serie(string _iD, string _titulo,
             int _duracion,
             string _genero,
          double _calificacion);
    
    //Métodos Modificadores - setters
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);
    
    
    //Métodos de acceso - getters
    Episodio getEpisodio(int posicion);
    int getCantidad();
    
    //Otros métodos
    
    double calculaPromedio();
    
    string str();
    
    void agregaEpisodio (Episodio episodio);
    
    void calculaDuracion (Episodio episodio);
        
};

#endif /* Serie_h */
