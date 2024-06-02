//
//  Polimorfismo.cpp
//  clase episodio y clase video
/*
Nombre: Fernando Gael Hernández Salazar
Matricula: A01029264
Carrera: ITC
Fecha: 26/05/2024
*/

#include "Polimorfismo.h"

using namespace std;

Polimorfismo::Polimorfismo(){
 for (int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }
    //Se inicializa la cantidad de videos
    cantidad = 0;
}

void Polimorfismo::leerArchivo(string nombre ){
    // todas las declaraciones se hacen abajo del encabezado estandar c++ ITESM
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];            // row – arreglo de 7 elementos de strings, para almacenar los datos de la línea del archivo ya separados
    string line, word;        // line – almacena la línea y word la palabra que se saca de line
    int cantidadPeliculas = 0; // contadores de peliculas y series, inicialmente son 0
    int cantidadSeries = 0;
    int iR = 0, index;
    int MAX_VIDEOS = 100;
    double promedio;
    
    entrada.open(nombre, ios::in);        // Abrir archivo de entrada
    
   
    while ( getline(entrada, line)) {  // Lee una línea del archivo y la almacena en line
        stringstream s(line);            // usada para separar las palabras split()
        iR = 0;                            // Cada vez que inicia una nueva línea inicializar iR = 0
        
        // Ciclo que extrae caracteres de s y los almacena en word hasta que encuentra el delimitador ','
        while (getline(s, word, ',')) {   // añade word al arreglo row e incrementa iR p/la proxima palabra
            row[iR++] = word;
        }
        
        // Determinar si la línea es P=Pelicula, S=Serie, E=Episodio
        if (row[0] == "P"){
            // se crea un apuntador usando el operador new, se llama al constructor con parámetros y se guarda en el arrPtrPeliculas
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula( row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            // cout << "Pelicula" << arrPeliculas[cantidadPeliculas]->str() << endl;
            cantidadPeliculas++; //inc la cantidad de peliculas
        }
        else if (row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie( row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            // cout << "Serie" << arrSeries[cantidadSeries]->str() << endl;
            cantidadSeries++;
        }
        else if (row[0] == "E"){
            // Calcular la serie a la que pertenece el episodio
            index = stoi(row[1]) - 500;
            // Se agrega el episodio usando el método agregaEpisodio()
            // Se crea el apuntador y se convierte a obj usando el operador de indireccion
            arrPtrSeries[index]->agregaEpisodio(*(new Episodio( row[2], stoi(row[3]), stoi(row[4]))));
            // cout << "Episodio" << arrSeries[index]->str() << endl;
        }
    }
    
    // fuera del ciclo
    // Se termina de leer todo el archivo ahora se guardan 
    // todos los apuntadores de Pelicula y Serie en el arrPtrVideo
    // copiar todos los apuntadores del arreglo de Series al arreglo de apuntadores de Video calculando su calificacionPromedio
    // ya que tienen todos los episodios
    
    for(int index = 0; index < cantidadSeries; index++){
        
        promedio = arrPtrSeries[index]->calculaPromedio(); // calcula la calificación de la Serie
        arrPtrSeries[index]->setCalificacion(promedio); // cambia la calificación de la Serie
        // añade el calcular la duración de la serie
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }
    
    // copia todos los apuntadores del arreglo de Peliculas al arreglo de apuntadores de Video
    for(int index = 0; index < cantidadPeliculas; index++){
        
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }
    
    /* Desplegar todo el contenido del arreglo de apuntadores de la clase Video (Base)
     se ejecuta el método str() que corresponde al tipo del apuntador almacenado,
     no el correspondiente al tipo del arreglo.
    */
    entrada.close();{
        
    }// cerrar el archivo
}


      //Metodos modificadores - setters
    void Polimorfismo::setPtrVideo(int index, Video *video){
        //Validar index - >= 0 && < cantidad
        if( index >=  0 && index < cantidad) {
            //cambiar el apuntador
            arrPtrVideos[index] = video;
        }
    }

    // cambia el valor del atributo cantidad
    //cantidad debe ser entre 0 .. MAX_VIDEOS -1, de lo contrario NO se modifica el valor
    void Polimorfismo::setCantidad(int _cantidad){
        //Validar el valor de _cantidad
        if (cantidad >= 0 && _cantidad < MAX_VIDEOS){
            cantidad = _cantidad;
        }
    }

    //Metodos de acceso - getters
    Video* Polimorfismo::getPtrVideo(int index){
        //Validar que exista el index
        if (index >= 0 && index < cantidad){
            return arrPtrVideos[index];
    }
    //si no existe
    return nullptr;
    }
    int Polimorfismo::getCantidad(){
        return cantidad;
    }

    //Otros métodos
    void Polimorfismo::reporteInventario(){
        //Declaración de contadores
        int contadorPeliculas, contadorSeries;

        //Inicializar
        contadorPeliculas = 0;
        contadorSeries = 0;

        //Recorrer todo el arreglo de ptr usando un for
        for (int index = 0; index < cantidad; index++){
            
            cout << arrPtrVideos[index] -> str() << endl;

            // *indirección (ptr) genera el objeto
            if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
                contadorPeliculas++;
            }
            else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
                contadorSeries++;
            }
        }
        //fuera del for - desplegar los totales
        cout << "Peliculas = " << contadorPeliculas << endl;
        cout << "Series = " << contadorSeries << endl;
    }
    void Polimorfismo::reporteCalificacion(double _calificacion){
    //Contador total
    int total;

    //Inicializar el contador
    total = 0;
        for(int index = 0; index < cantidad; index++){
            //Verificar si tiene la calificacion == _calificacion
            //si es un apuntador se usa la notación flecha
            if (arrPtrVideos[index] ->getCalificacion() == _calificacion){
                cout << arrPtrVideos[index] ->str() << endl;
                total++; 
            }
    }
        //Desplegar el total fuera de for

        cout << "Total = " << total << endl;
    }
    void Polimorfismo::reporteGenero(string _genero){
    //Contador total
    int total;

    //Inicializar el contador
    total = 0;
        for(int index = 0; index < cantidad; index++){
            //Verificar si tiene el género
            //si es un apuntador se usa la notación flecha
            if (arrPtrVideos[index] ->getGenero() == _genero){
                cout << arrPtrVideos[index] ->str() << endl;
                total++; 
            }
    }
        //Desplegar el total fuera de for

        cout << "Total = " << total << endl;    
    }
    void Polimorfismo::reportePeliculas(){
    //Contador total
    int totalP;

    //Inicializar el contador
    totalP = 0;
        for(int index = 0; index < cantidad; index++){
            //Verificar si es de tipo película
            //si es un apuntador se usa la notación flecha
            if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
                cout << arrPtrVideos[index] ->str() << endl;
                totalP++; 
            }
    }
    if (totalP != 0){
        //Desplegar el total fuera de for
        cout << "Total Peliculas = " << totalP << endl;
    }
    //si no hay peliculas se imprime "no hay peliculas"
    else{
        cout << "No peliculas" << endl;
    }


    }
    void Polimorfismo::reporteSeries(){
    //Contador total
    int totalS;

    //Inicializar el contador
    totalS = 0;
        for(int index = 0; index < cantidad; index++){
            //Verificar si es de tipo serie
            //si es un apuntador se usa la notación flecha
            if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
                cout << arrPtrVideos[index] ->str() << endl;
                totalS++; 
            }
    }
    if (totalS != 0){
        //Desplegar el total fuera de for
        cout << "Total Series = " << totalS << endl;
    }
    //si no hay series se imprime "no hay series"
    else{
        cout << "No series" << endl;
    }
        
    }
    
    

