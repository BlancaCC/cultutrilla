/**
   @brief programa de prueba de combinaciones.h combinaciones.cpp
   @author Blanca Cano Camarero 
   @date Enero 2019
 */

#include "combinaciones.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
   @brief Muestra en pantalla la última generación creada de Combinacioness
   @param C estructura de combinaciones que mostrar en pantalla 
 */
void muestraGeneracion( const Combinaciones & C)
{
  for( auto  conjunto  = (C.arbol_combinaciones.back()).cbegin();
       conjunto  != (C.arbol_combinaciones.back()).cend();
       conjunto++ )
    {
      for( auto c = conjunto->cbegin(); c != conjunto->cend(); c++)
	cout << (*c) ;
      cout << "  "; 
    }
  cout << endl; 
}

// ~~~~~~~~~~~~~~


int main( int argc, char * argv [])
{
  //string letras = "01234";
  vector<string> letras ={"01234", "ABBAB"} ;

  for( int i= 0; i< letras.size(); i++)
    {
      cout << " COMBINACIONES DE " << letras[i] << endl; 
      Combinaciones C (letras[i]);
      vector<string> nulo;
      cout << "=========== otra generación ===========" << endl; 
      muestraGeneracion( C); 

      while( C.GeneracionSiguiente())
	{
	  cout << "=========== otra generación ===========" << endl; 
	  muestraGeneracion( C); 

	}
    }
}
