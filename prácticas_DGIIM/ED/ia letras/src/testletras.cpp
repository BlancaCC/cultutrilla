/**
   @brief Test para probar los módulos letras.h
 */

#include <iostream>
#include "letras.h"
#include "diccionario.h"


#include <vector>
#include <set>
#include <string>

using namespace std;


int main( int argc , char* argv [])
{
  Diccionario D;
  cout << "Inctroduzca palabras, ctr-d para finalizar :D" << endl; 
  cin >> D;

  // ~~~~~~~~~~~~~ prueba de la estructura Letra ~~~~~~~~~~~~~
  Letra A; 
  A.fa = 10;
  cout << A.fa << endl;

  // ~~~~~~~~~~~ prueba de conjuntoLetras ~~~~~~~~~~~~~~~~~

  conjuntoLetras C;
  C.analizarDiccionario(D);
  
  // probamos calculaEstadisticas y sobrecarga de << 
  cout << C;

  //generamos fichero con la estadística
  cout << "Vamos a guardar los datos en " << argv[1] << endl; 
  C.generaFicheroEstadistica( argv[1]);

  //cargamos otro conjunto a partir de un fichero de letras
  // estos fichero tienen la letra, la cantidad y sus puntos

  cout << "Cargamos un conjunto de letras de " << argv[2] << endl; 
  conjuntoLetras C2 ( argv[2]);

  //veamos si se ha leído bien
  cout << "Esto es lo que se ha cargado del fichero pasado \n" << C2; 
  
  //vamos a pedirle que nos genere un par de letras
  cout << "Sus letras son " << C.sacaLetras( 8) << endl;

  //comprobemos si nos devuelve las puntuaciones de una palabra
 
  vector<string> palabras =  {"hola", "tomate", "riquirdi"};

  for( auto i= palabras.begin();  i !=palabras.end(); i++)
    {

      multiset<char> conjunto;
      for ( auto c =  i->begin(); c !=  i->end(); c++)
	conjunto.insert(*c);
      
      cout << "La puntuacion de la palabra " << *i << " es "<< endl
	   << " en string: "<< C2.puntuacionAsociada( *i ) << endl
	   << " en conjunto: "<< C2.puntuacionAsociada( conjunto) << endl
	   << endl; 
    }

  
}
