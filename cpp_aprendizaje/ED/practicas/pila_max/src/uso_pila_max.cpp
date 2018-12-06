/**
   @brief Ejemplo de uso del TDA pila_max
   @author Blanca Cano Camarero
   @date Noviembre 2018
 */

#include <iostream>

#include "pila_max.h"

#include <stdlib.h> 
#include <time.h>
#include <math.h>

using namespace std;

void representa(  Pila_max & q )
{
  while( !q.vacia())
    {
      cout << q.tope() << " " << q.tope_maximo() << endl;
      q.quitar();
    }
}

int main()
{
  //poner , num_elementos, quitar, tope,  tope_maximo

  Pila_max q;
  int j;

  //llenamo q
  for ( j=0; j<10 ; j++) 
    q.poner(j/10.0+1 * pow( -1, j) );
  
  // constructor por copia
   cout << "El número de elementos de q es " << q.num_elementos() << endl;
  Pila_max p (q);
  cout << " P " << ( (p.vacia())?"SÍ":"NO") << " está vacía \n";
   cout << "El número de elementos de p es " << p.num_elementos() << endl;
   
  cout << "Los valores de p son: \n";
  representa(p);
  cout << " P " << ( (p.vacia())?"SÍ":"NO") << " está vacía \n";
  
  float z = q.tope();
  float z_max = q.tope_maximo();
  cout << "El tope de q es: \n";
  cout << z << " " << z_max<< endl;

  
  // operador de igualdad
  p = q;
  //tamaño de p
  cout << "El número de elementos de p es " << p.num_elementos() << endl;
     


  return 0;
}
