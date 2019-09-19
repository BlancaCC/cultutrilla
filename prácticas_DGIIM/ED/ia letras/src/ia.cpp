/**
   @file ia.cpp 
   @author Blanca Cano Camarero 
   @brief Implementación de inteligencia artificial para jugar al scrabble, su cabecera es el archivo "ia.h"
   @date enero de 2019
 */

#include "ia.h"

IA::IA(  Diccionario & D, bool modo_puntos , string validas)
{
  conocimiento = Biblioteca( D , validas); 
  modo_puntuacion = modo_puntos;
  
} //~~~~~ fin del constructor 


bool IA::modoPuntuacion() const
{
  return modo_puntuacion; 
} //~~~~~ fin modo puntuación 



vector<string> IA::mejorSolucion( string letras, conjuntoLetras & cl )
{
 
  return ( modo_puntuacion ) ?
    solucionesPuntos( letras, cl):
    solucionesLongitud( letras); 
  
} // ~~~~~~~~ mejor solucion general 


//#### MÉTODOS DE BÚSQUEDA PARTICULARES  ########

vector<string> IA::solucionesLongitud( string letras )
{

  /*
    Lo interesante que permite Combinaciones es que en longitud, 
    los "padres" del árbol van a tener estrictamente mayor puntuación.
    Por tanto, en cuanto encontremos en una "generación" una solución,
    sabremos que esa y sus hermanas serán las mejores soluciones
    y no hará falta seguir generando y explorando el árbol. 
   */
  
  Combinaciones C(letras);
  vector<string> soluciones;

  bool puedeDividirse =  true;
  bool encontrado = false;
  
  while (!encontrado &&  puedeDividirse )
    {
      set<multiset <char>> candidatos = C.arbol_combinaciones.back(); 
      for( auto candidato = candidatos.cbegin();
	   candidato != candidatos.cend(); candidato++ )
	{
	  //traducimo las letras actuales a la clave que tendría si estuviera en las posibles soluciones traduccion_diccionario 
	  unsigned long int codigo_primo = conocimiento.traduce( (*candidato) );
	  //comprobamos si se encuentra en las soluciones
	  if( conocimiento.traduccion_diccionario.count( codigo_primo))
	    {
	      vector<string> nuevas_soluciones  = conocimiento.traduccion_diccionario[codigo_primo];

	      //añadimos las nuevas soluciones al final del  vector de soluciones a devolver
	      soluciones.insert( soluciones.end(),
				 nuevas_soluciones.begin(),
				 nuevas_soluciones.end());
	      encontrado = true; 
	    } 
	} // for candidatos

      // si no se ha encontrado se genera la siguiente generación de combinaciones
      // y se guarda si es la última o no en puedeDivirse
      if ( !encontrado )
	puedeDividirse = C.GeneracionSiguiente(); 
  
    } // WHILE se puedan crear más generaciones o se encuentre

  return soluciones; 
  
} //~~~~~~ soluciones por longitud


vector<string> IA::solucionesPuntos( string letras , conjuntoLetras & cl)
{
  /*
    Aquí no podemos aplicar la idea de soluccionesLongitud,
    si embargo podemos podar el árbol de la siguiente manera:

    Cuando se haya producciodo un encuentro de una solución está tendrá una puntuación asociada, 
    se eliminarán de la lista de candidatos a seguir explorando, los que potencialmente tengan  una puntuación menor
    
    Cuando se produzca una combinación con solución,
    almacenaremos la incidencia en un diccionario cuya clave es su puntuación
    Finalmemnte devolveremos la estructura con mayor puntuación. 
   */
 
  map < int, vector<string> > puntos_soluciones;
  int puntuacion_maxima = -1; //suponemos que la puntuación no puede ser negativa

  Combinaciones C(letras);

  bool seguirExplorando = true;

  while ( seguirExplorando )
    {
      set< multiset<char> > candidatos = C.arbol_combinaciones.back();

      //recorremos los multiset
      for( auto candidato = candidatos.cbegin();
	   candidato != candidatos.cend(); candidato++ )
	{

	  // si el candidato es potencialmente de puntuación menor, directamente lo eliminamos
	  int nueva_puntuacion = cl.puntuacionAsociada(*candidato);

	  
	  if ( nueva_puntuacion < puntuacion_maxima)
	    {
	      //elimina dicho candidato, ya que por más que profundicemos no vamos a llegar a una puntuación mayor
	      (C.arbol_combinaciones.back() ).erase( *candidato );
	    }
	  else
	    {
	    
	      //traducimo las letras actuales a la clave que tendría si estuviera en las posibles soluciones traduccion_diccionario

	      unsigned long int codigo_primo = conocimiento.traduce(*candidato);
	  
	      //comprobamos si se encuentra en las soluciones
	      if(  conocimiento.traduccion_diccionario.count( codigo_primo))
		{
		  //actualizamos puntuacion_maxima
		  puntuacion_maxima = nueva_puntuacion; 
	      
		  vector<string> nuevas_soluciones =  conocimiento.traduccion_diccionario[codigo_primo];

		  //añadimos las nuevas soluciones al final del  vector de soluciones a devolver
		  puntos_soluciones[puntuacion_maxima].insert(puntos_soluciones[puntuacion_maxima].end(),
							      nuevas_soluciones.begin(),
							      nuevas_soluciones.end()); 
		  
		}
		
	    } // else potencial de puncuación mayor
	   
	} // fin for candidato
      seguirExplorando = C.GeneracionSiguiente();
    } //fin del while de buscar por el árbol

  // de esta forma el string no se queda vacío y además vemos la puntuación obtenida
  puntos_soluciones[puntuacion_maxima].push_back("puntuación obtenida: "+to_string(puntuacion_maxima) ); 

    return puntos_soluciones[ puntuacion_maxima]; 
  
} // ~~~~~~ soluciones por puntos 

