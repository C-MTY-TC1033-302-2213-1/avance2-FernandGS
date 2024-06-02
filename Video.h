//
//  Video.h
//  clase episodio y clase video
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 22/05/2024
¿Qué aprendí en el desarrollo de esta clase? (solo en el .h responde a esta pregunta)
Aprendí acerca de la creación de las clases padre o base y lo importante que es saber
que propiedades darle para que sean compartidas por las demás clases.
*/


#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>

using namespace std;

class Video{
    
//Atributos
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

//Métodos

public:
    //Constructores
    Video();
    Video(string _iD, string _titulo,
          int _duracion,
          string _genero,
          double _calificacion);
    
    // Metodos modificadores (Set)
    void setId(string _iD);
    void setNombre(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);
    
    //Metodos de acceso (get)
    string getId();
    string getNombre();
    int getDuracion();
    string getGenero();
    double getCalificacion();
    
    //Otros metodos
    virtual string str();
};
#endif /* Video_h */
