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
#include <set>

#include <math.h> //trunc

#include <iomanip> //setw
#include <fstream> //open , close file
#include <assert.h>




using namespace std;

/**
   @brief Estructura auxiliar que contiene las propiedades de una letra
   Contiene los siguientes argumentos: 
   fa: Frecuencia ab

 */
struct Letra
{
  // variables obtenidas de analizar el diccionario
  int fa;     ///< frecuencia absoluta
  float fr;   ///< frecuencia relative

  //variables para la partida
  int cantidad;  ///< cantidad de fichas máxima que se dispone para repartir 
  int puntos; ///< puntos asociados

  /**
     @brief contruccutor por defecto de Letra
  */
  Letra();
  

  /**
     @brief constructor por referencia 
   */
  Letra( int pnts, int canti, int a=0, float r=0);
  
  /**
     @brief Algoritmo diseñado para generar los puntos de cada letra
     (quizás debiera como método privadodo de la clase más generar )
   */
  void generaPuntos();
  
};
// #################### TDA CONJUTNO LETRAS ##################

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
  map <char, Letra> letras;
  long int letras_contabilizadas; //letras totales en leídas
  string validas;
  bool estadistica_actualizada; //con el objetivo de ahorrarno cálculos
  bool cargado_de_diccionario; //si procede cargado de diccionario 
  int total_cantidad; ///< cantidad total de letras posibles


  // Funciones privada para el cálculo 
  /**
     @brief Genera resultados a partir de las fa leídas, 
     *- modifica la freciencia relativa 
     *- y la puntuación asociada a esa palabra.
     *- en este método se encuentra el algoritmo para calcular la puntuación de cada letra. 
   */

  void calculaEstadisticas();
  
 public:
  /**
     @brief constructor por defecto, es caso de no pasarle un archivo de letras válidas, tomará aquellas que estén en este conjunto: abcdefghijklmnopqrstwyz
   */
  conjuntoLetras();

  /**
     @brief construcctor a partir de archivo con letras :D
     La estructura del fichero debe ser:

     #Letra Cantidad Puntos  
     Donde: 
     *- letra es la letra en cuentión  
     *- Cantidad: a la hora de repartir número máximo a dar
     *- Puntuación: Si se juega en la modalidad de puntos, puntuaciónes que pesan sobre cada letra. 

   */

  conjuntoLetras( string fichero_letras);  
  /**
     @brief Dado un diccionario del TDA diccionario, 
calcula el número de aparicciones de cada una de las letras, 
así como su frecuencia relativa
   */
  void   analizarDiccionario( const Diccionario & d);

  /**
     @brief incremeneta en uno la frecuencia absoluta de un caracter
inctroducido si es válido 
   */

  void incrementa( char c);



  /**
     @brief Genera un fichero con la estadística obtenidas de: 
     *- Frecuencia absoluta 
     *- Frecuencia relativa
     @param fsalida : nombre del fichero de salida 
   */
  void generaFicheroEstadistica(string fsalida); // const ;

  /**
     @brief Devuelve  @n n número de letras, generadas aleatoriamente pero teniendo en cuenta su cantidad; 
y en fúnción de su cantidad 
@param n, número de letras a devolver 
   */

  string sacaLetras( int n );

  /**
     @brief Devuelve la puntuación de una palabra dada
     @param palabra
     @return entero con la puntuacion 
   */

  int puntuacionAsociada( string palabra);

    /**
     @brief Devuelve la puntuación de una palabra dada
     @param palabra
     @return entero con la puntuacion 
   */

  int puntuacionAsociada( const multiset<char> & palabra); 
    
  ///###################### funciones amigas ################
  /**
     @brief Sobrecarga del operador salida, muestra estadística
   */

  friend ostream & operator<<( ostream & os, conjuntoLetras & C ); 
  
}; 

#endif //  __LETRAS_H__



