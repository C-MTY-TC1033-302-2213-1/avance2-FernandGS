//
//  Episodio.h
//  clase episodio y clase video
//
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 22/05/2024
¿Qué aprendí en el desarrollo de esta clase? (solo en el .h responde a esta pregunta)
Aprendí sobre la herencia ya que esta clase toma los atributos de la clase video.
De la misma forma encontré la relación que se crearía entre esta clase y la clase serie
haciendo así uso de la composición.
*/
//

#ifndef Episodio_h
#define Episodio_h

#include <stdio.h>
#include <string>

using namespace std;

class Episodio{

//Atributos
protected:
        string tituloE;
        int temporadaE;
        int calificacionE;

//Métodos
public:
        //Constructores
        Episodio();
        Episodio(string _tituloE,
              int _temporadaE,
              int _calificacionE);
    // Metodos modificadores (Set)
    void setNombreE(string _tituloE);
    void setTemporadaE(int _temporadaE);
    void setCalificacionE(int _calificacionE);
    
    //Metodos de acceso (get)
    string getNombreE();
    int getTemporadaE();
    int getCalificacionE();
    
    //Otros metodos
    string str();
};

#endif /* Episodio_h */
