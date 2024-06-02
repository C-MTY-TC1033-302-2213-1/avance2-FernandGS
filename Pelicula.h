//
//  Pelicula.h
//  clase episodio y clase video
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 22/05/2024
¿Qué aprendí en el desarrollo de esta clase? (solo en el .h responde a esta pregunta)
Aprendí acerca de la herencia, ya que esta clase recibe las propiedades de la clase base video
y las reutiliza para generar su propia clase
*/

#ifndef Pelicula_h
#define Pelicula_h

#include <stdio.h>
#include <string>
#include "Video.h"

using namespace std;


// Clase película es derivada de Video
class Pelicula : public Video{

    private:
    int oscares;
    
    public:
    //Constructores: vacío y con parámetros
    Pelicula();
    Pelicula(string _iD, string _titulo,
             int _duracion,
             string _genero,
             double _calificacion, int _oscares);
    
    // Método modificador - set
    void setOscares(int _oscares);
    
    //Método de acceso
    int getOscares();
    
    //Otros métodos
    string str();
    
    
};

#endif /* Pelicula_h */
