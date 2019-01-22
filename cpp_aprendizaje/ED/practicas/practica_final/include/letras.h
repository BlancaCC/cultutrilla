/**
   @file letras.h
   @brief TDA para gestionar las letras del diccionario 
   Este TDA lee de un fichero diccionario sus palabras, realiza un conteo de sus letras, obteniedo su frecuencia absoluta y relativa. 
   Además en la salida genera la siguiende estructura: 
   # Letra Frecuencia_absoluta Frecuencia_relativa 
   a
   b
   c 
 */

#ifndef __LETRAS_H__
#define  __LETRAS_H__

#include "diccionario.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

/**
   @brief Estructura auxiliar que contiene las propiedases de una letra
   Contiene los siguientes argumentos: 
   fa: Frecuencia ab

 */
struct Letra
{
  //char letra; //< letra en cuestión 
  int fa;     //< frecuencia absoluta
  float fr;   //< frecuencia relative
  int puntos; //< puntos asociados

  /**
     @brief contruccutor por defecto de Letra
  */
  Letra();
  
  /**
     @brief constructor por referencia 
   */
  Letra(  int a, float r, int pnts);
  
  /**
     @brief Algoritmo diseñado para generar los puntos de cada letra
     (quizás debiera como método privadodo de la clase más generar )
   */
  void generaPuntos();
  
};

/**
   @brief TDA conjunto de letras 
Estructura sobre la que se apoya las letras del scrabble y cuyo objetivo es: 
 
- Almacena las letras válidas y las contabiliza a partir de un diccionario o archivo ya leído. 
- Les asigna una puntuación, a partir de un algoritmo ya diseñado
- Genera fichero con los datos leídos. 
- Dado un número devuelve de manera aleatoria y en función de su frecuencia un conjunto con tal número de letras. 
 */

class conjuntoLetras
{

 private:
  map <Letra> letras;
  long int letras_contabilizadas;
  string validas; 

 public:
  /**
     @brief constructor por defecto, es caso de no pasarle un archivo de letras válidas, tomará aquellas que estén en este conjunto: abcdefghijklmnopqrstwyz
   */
  conjuntoLetras();

  /**
     @brief construcctor a partir de archivo con letras :D
   */

  /**
     @brief cosntructor a partid de archivo con diccionario ya analizado 
   */

  /**
     @brief Dado un diccionario del TDA diccionario, 
calcula el número de aparicciones de cada una de las letras, 
así como su frecuencia relativa
   */
  void   analizarDiccioanario( cosnt Diccioanario & d);

  /**
     @brief incremeneta en uno la frecuencia absoluta de un caracter
inctroducido si es válido 
   */

  void incrementa( char c); 
  
}; 

#endif //  __LETRAS_H__



