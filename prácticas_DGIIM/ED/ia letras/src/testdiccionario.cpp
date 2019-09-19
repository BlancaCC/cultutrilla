/**
   @brief Ejemplo de uso y test de diccionario.cpp
   @author Blanca Cano Camarero
   @date dicembre 2018

 */



#include <iostream>

#include "diccionario.h"
using namespace std; 

int main()
{
  //construcctor por defecto
  Diccionario D("amarillo");

  //añadir palabra al diccionario
  D.agregarPalabra( "tomate");
  D.agregarPalabra("riquirdi");

  //tamaño del diccionario, función size :D
  cout << "El diccionario tiene : " << D.size() << " palabras \n";

  //palabrasLongitud, devuelve vector con palabras.
  int longitud = 6; 
  cout << "La primera palabra de tamaño " << longitud << " es " << D.palabrasLongitud(longitud)[0] << endl;

  // test de si una palabra está en el diccionario
  string palabra = "tomate";
  cout << palabra;
  if( D.esta( palabra))
    cout << " Está en el diccionario" << endl;
  else
    cout << " NO está en el diccionario " << endl;

  palabra = "rojo";
  cout << palabra;
  if( D.esta( palabra))
    cout << " Está en el diccionario" << endl;
  else
    cout << " NO está en el diccionario " << endl;

  
  //prueba de los iteradores
  cout << "Prueba de iteradores: \n"; 
  for ( auto cit= D.cbegin(); cit != D.cend(); cit++)
    {
      cout << (*cit) << endl;
    }
   
  cout << "fin de la prueba de los iteradores " << endl; 
    
  // sobrecarga de operadores
  //entrada
  cin >> D;
  
 // salida

  cout << " El diccionario cargado es:\n" << D;
  
  
}
