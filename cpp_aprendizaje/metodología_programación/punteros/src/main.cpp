#include<iostream>
#include<cstdlib>
#include<ctime>

#include "punteros.h"

using namespace std;

int main()
{
  /// tamaño máximo y mínimo de los vecotres a declarar
  const int tam_max = 100;
  const tam_min  = 3;
  
  srand( time(NULL));
  int tam_vector = rand()%(tam_max - tan_min + 1) + tan_min +1;

  //creo vectores del tamaño ya calculado
  int *c = new int [ tam_vector]; //vector que contendrá los datos en cuestión
  int *p = new int *[ tam_vector]; //vector de punteros

  //les doy valores
  completa_aleatorio( p , tam_max);

  cout<< "Procedo al mostrar el vector sin ordenar: \n";
  
  delete [] c;
  delete [] p;

  c = NULL;
  p = NULL; 
}
