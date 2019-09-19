/**
   @file biblioteca.h
   @author Blanca Cano Camarero 
   @brief TDA que crea una tabla hash indexada con producto de primos
   Con las palabras del diccionario pasado :D
   @date enero de 2019
 */


#ifndef _BIBLIOTECA_H_
#define _BIBLIOTECA_H_

#include<iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

#include "diccionario.h"

#include <fstream>
#include <assert.h>

using namespace std; 

/**
   @brief TDA IA Jugador del scrabble

 */
//class IA
class  Biblioteca 
{
 private:
  /**
     @brief Diccionario, a cada letra válida le asocia un primo 
   */
  map< char, int> primos;
  
  /**
     @brief A cada caracter válido le asocia un número primo diferente
   */
  void asignaPrimos(string validas);
  
 public: 
  // ~~~~~~~~~~~~ variables y métodos de carga ~~~~~~~~~~~
  
  map< unsigned  long int, vector<string> > traduccion_diccionario;


  /**
     @brief traduce las palabras de un diccionario a un primo, 
     Crea map donde a cada uno de los anteriores primos le asocia una palabra :D
   */
  void traduceDiccionario( Diccionario & soluciones);

  /**
     @brief Devuelve el primo asociado a una combinación 
     @param validad combinacio de letras 

   */
  unsigned long int traduce( string validas);


   /**
     @brief Devuelve el primo asociado a una combinación 
     @param validad combinacio de letras 

   */
  unsigned long int traduce( multiset<char> validas); 

 
 public:

  ///< CONSTRUCTOR POR DEFECTO
  Biblioteca()
    {
      map< char, int> null;
      primos = null;
      map< unsigned  long int, vector<string> > null2 ; 
      traduccion_diccionario =  null2; 
    }
  
  /**
     @brief constructor de la Biblioteca
     @param dicccionario, vocabulario del que dispondrá nuestra IA
     @param letras válidas x
   */
  Biblioteca( Diccionario & soluciones, string validas = "abcdefghijklmnopqrstuvwxyz" );


  /**
     @brief Sobrecarga del operador igual 
     @param Diciccionario que se va a copiar 
   */
  Biblioteca & operator=(  const Biblioteca  & B); 
  
};



#endif // _BIBLIOTECA_H_
