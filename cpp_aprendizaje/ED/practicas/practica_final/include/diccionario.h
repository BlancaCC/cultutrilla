/**
   Cabecera del  TDA diccionario 
   @author Blanca Cano Camarero
   @file diccionario.h 
 */

#ifndef __Diccionario_h__
#define __Diccionario_h__

#include <iostream>
using namespace std;

#include <set>
#include <vector>
#include <string>


class Diccionario
{
 private:
  set<string> datos;

   public:
  /**
     @brief Añade una palabra al diccionario 
     @param Palabra a añadir
   */
  void agregarPalabra( string palabra);
    


  /**
     @brief Construye un diccionario vacío
   */

  Diccionario(); 

  /**
     @brief Constructor a partir de una palabra  
     @param Palabra con la que commentzar el diccionario 
   */
  Diccionario(string palabra ); 
  
  /**
     @brief Devuelbe el número de palabras del diccionario
   */

  int size() const;

   /**
     @brief Obtine todas las palabras en el diccionario de una longitud dada  
     @param longitud: la longitud de las palabras de salida  
     @return un vector con las palabra de la longitud específica del parámetro de entrada 
   */

  vector<string> palabrasLongitud( int longitud );

  /**
     @brief Indica si una palabra está en el diccionario o no
     @param palabra: la palabra que se quiere buscar
     @return true si la palabra está en el diccionario, false en caso contrario
   */

  bool esta(string palabra) const ;

  //#################### iteradores ########################

  /**
     @brief iteradores cbegin() y cend()  de diccionario
   */
  /**
  set<string>::iterator begin();
  set<string>::iterator end();
  */
  set<string>::const_iterator cbegin() const ;
  set<string>::const_iterator cend()  const ;

};


  /**
     @brief Escribe en un flujo de salida un diccionario
     @param os: flujo de salida
     @param D: el objeto diond ese realiza la escritura
     @return el flujo de salida     
   */
//< Gracias a los iteredores constanstes no es necesario declarar amiga esta función 
 ostream & operator <<( ostream & os, const Diccionario & D);

  /**
     @brief Lee de un flujo de entrada un diccionario (cada palabra en una línea)
     @param is: Flujo de entrada 
     @param D: el objeton donde se realiza la lectura
     @return el flujo de entrada
   */
//< gracias a la función pública agregarPalabra no es necesario declarar esta función friend
 istream & operator >> (istream & is, Diccionario &D);


#endif // __Diccionario_h__

