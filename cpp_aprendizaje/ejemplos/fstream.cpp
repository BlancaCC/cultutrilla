/*
  Pograma de ejemplos para la escritura de ficheros 
  Blanca Cano Camarero
  5/11 / 17
 */

#include<fstream>

using namespace std;

int main()
{
  string contenido; // Contendrá el mensaje de los distintos ficheros
  
  // Variables que contendrán el nombre del fichero con el que voy a trabajar
  ifstream fichero_de_lectura;
  ofstream fichero_de_escritura;
  ofstream f_escritura2;

  // Asigno  a las variables declaradar un fichero
  fichero_de_lectura.open("leeme.txt"); 
  fichero_de_escritura.open("Escribeme.txt"); //si no existe el fichero lo crea
  f_escritura2.open( "ecribeme.txt" );

  fichero_de_lectura >> contenido; //lee como si de un cin se tratara, los espacios como delimitadores  y lo copio en la variable contenido;
  fichero_de_escritura << contenido; // escribo lo que que tiene la variable contenido

  getline( fichero_de_lectura , contenido ); // aquí leo una línea, hasta el enter
  f_escritura2 << contenido ;

  // cierro los ficheros
  fichero_de_lectura.close();
  fichero_de_escritura.close();
  f_escritura2.close();

  
    
}
