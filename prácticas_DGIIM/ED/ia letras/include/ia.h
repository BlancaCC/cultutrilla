/**
   @file ia.h
   @author Blanca Cano Camarero 
   @brief TDA de inteligencia artificial para jugar al scrabble 
   @date enero de 2019
 */

#ifndef _IA_H_
#define _IA_H_

#include<iostream>
#include "combinaciones.h"
#include "biblioteca.h"
#include "diccionario.h"
#include "letras.h"

#include <map> 

using namespace std; 


class IA
{
 private:

  
  Biblioteca conocimiento;  /// Creación de la trabla hash
  /**
     @ brief modo de juego 
     Indicado por variable booleana:
         *- false : busca las palabras más largas
	 *- true  : busca las palabras de mayor longitud 
   */
  bool modo_puntuacion;      /// Modo de juego, si es puntos 


  // ~~~~~~~~~ métodos búsqueda mejor solución 
  /**
     @brief Soluciones por longitud
     @param letras: total de letras que se puede combinar
     @return vector con soluciones
   */
  vector<string> solucionesLongitud( string letras);

  /**
     @brief Solucioens por puntuación
     @param letras: total de letras que se puede combinar
     @return vector con soluciones
   */
  vector<string> solucionesPuntos( string letras, conjuntoLetras & cl); 
  

 public:

  /**
     @brief Constructor de la IA
     @param Diccionario de referencia con el que jugar
     @param Modo de juego con el que jugar 
   */
  //El diccionario se podría poner constante CReO
  IA ( Diccionario & D, bool modo_puntos, string validas = "abcdefghijklmnopqrstuvwxyz");

  /**
     @brief devuelve las mejores soluciones 
     @param letras con las que jugar 
     @param conuntoLetras utilizada para consultas puntuaciones
     @return mejores soluciones encontradas 
     ( si el vector está vacío significa que no ha encontrado ninguna solución)
   */

  vector<string> mejorSolucion( string letras, conjuntoLetras & cl);   


  /**
     @return Devuelve true si se encuentra en modo puntuación,
     false en el contrario 
  */
  bool modoPuntuacion() const;

  
};


#endif //_IA_H

