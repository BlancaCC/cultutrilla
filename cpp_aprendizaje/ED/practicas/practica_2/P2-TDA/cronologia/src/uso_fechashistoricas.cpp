/** 
 * @file uso_fechahistoricas.cpp
 * @author Blanca Cano Camarero
 * @date primeros de octubre 2018
 * @brief Fichero de ejemplode uso del TDA fecha historica
 **/

#include <iostream>
#include "fechahistorica.h"

using namespace std;

int main(int argc , char * argv[])
{
  int fecha = atoi(argv[1]);
  char **evento;
  evento = new char *[argc-2];
  
  for( int i=2; i<argc ; i++)
    evento[i-2] = argv[i];
  cout << "Copiado con éxito" <<endl;
  
  Fecha_historica eventos (fecha ,  evento) ;

  for( int i=0; i<argc-2 ; i++)
    delete [] evento[i];
  delete [] evento;

  
}
