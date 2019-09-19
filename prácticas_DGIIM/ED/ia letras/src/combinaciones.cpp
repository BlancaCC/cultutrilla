/**
   @brief Implementación del TDA combinaciones, 
esta estructura se encuentra definida en combinaciones.h
   @file combinacion.cpp 
   @author Blanca Cano Camarero 
   @date Enero 2019
 */

#include "combinaciones.h"

Combinaciones::Combinaciones( string elementos)
{
  multiset<char> aux;
  for( auto c = elementos.cbegin();  c != elementos.cend(); c++)
    aux.insert( *c );

  set< multiset<char> > aux2;
  aux2.insert( aux);
  
  arbol_combinaciones.push_back( aux2 );
  
} // ~~~ fin combinaciones 



// ¡ CON ESTE ALGORITMO SE PRODUCEN REPETICIONES!
bool Combinaciones::GeneracionSiguiente()
{
  // tomamos longitud mínima de la descendencia de 2, ya que no consideramos palabras a simpletes de letras
  // para ello leemos el primer string del último conjunto del vector
  //que se corresponde a la última generaciín creada
  
  int longitud = (* (arbol_combinaciones.back()).begin() ).size();
  if ( longitud > 2)
    {
      set< multiset<char> > descendientes;
      /// Utilizaremos set para evitar repeticiones, ( ejemplo ABBA )
      //recorremos cada combinación del conjunto
      
      for( auto padre = arbol_combinaciones.back().cbegin() ; padre !=  arbol_combinaciones.back().cend(); padre++  )
	{
	  // de cada combinación exploramos las siguientes
	  for( auto letra_quitar= padre->begin(); letra_quitar !=  padre->end() ; letra_quitar++)
	    {

	      
	      //formamos nueva combinación obviando una letra
	      multiset< char> nuevo_elemento = *padre;
	      //se hace con un find y no con un erase *letra_quitar porque de la segunda forma borraría toda las incidencias
	      //como suponemos que no se repetiran muchas letras no tiene porqué ser un defecto muy grande en la eficiencia
	      nuevo_elemento.erase( nuevo_elemento.find(*letra_quitar)) ; 
	      

	      descendientes.insert( nuevo_elemento); 
	      //cout << nuevo_elemento << endl;
	      
	    } // FIN for combinaciones letras
	  
	} // FIN for cada uno de las combinaciones padre

      //insertamos el nuevo conjunto al final
      arbol_combinaciones.push_back( descendientes);

      //devolvemos true en señal de que ha sido creaod con éxito 
      return true; 
    }

  return false; //si longitud <= 1 
  
} //~~~~~~ fin generación siguiente 


