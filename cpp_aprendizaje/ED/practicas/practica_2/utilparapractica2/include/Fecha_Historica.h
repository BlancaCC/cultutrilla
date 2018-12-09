/**
  * @file Fecha_Historica.h
  * @brief Fichero cabecera del TDA Fecha_Historica
  *
  */

#ifndef _FECHA_HISTORICA_
#define _FECHA_HISTORICA_

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/**
  *  @brief T.D.A. Fecha_Historica
  *
  * Una instancia @e c del tipo de datos abstracto @c Fecha_Historica es un objeto
  * con cuatro campos, tres enteros y un vector de string  
  * Uno de los enteros es la fecha base del conjunto de eventos y los otros dos son la base del   
  * vector dinamico que representamos como
  *
  * Año 
  * num_eventos 
  * evento/s:
  * *)Fecha_Historica_1
  * ...
  * ...
  * *)Fecha_Historica_N 
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Blanca Cano Camarero
  * @date 
  */

class Fecha_Historica {

 private:
/**
  * @page repConjunto Rep del TDA Fecha_Historica
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.anio > 0 && rep.anio < 9999
  *
  * Fijamos como limite que los años no sean ni negativos ni superiores a 9999.
  * Tratamos años antes o después de Cristo con un booleano
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Fecha_Historica representa al valor
  *
  * Año 
  * num_eventos 
  * evento/s:
  * *)Fecha_Historica_1
  * ...
  * ...
  * *)Fecha_Historica_N 
  *
  *
  */


  int anio;           /**< Año */
  
  int numeventos;       /**< número de Eventos Historicos almacenados para ese Año */
  
  int reservados;     /**< número de elementos reservados */
  
  string *str;        /**< vector de string de Eventos Historicos */

  void resize(int r); /**< Funcion privada para mantener el vector dinámico de string */
  
  

 public:

/**
  * @brief Constructor por defecto de la clase. Lo creamos sencillamente para evitar 
  * errores o asignaciones de basura a objetos de nuestra clase. Crea una Fecha Historica 
  * por defecto con año 0, con el vector nulo y 0 numeventos y reservados
  */

  Fecha_Historica();


/**
  * @brief Constructor de la clase
  * @param a año del evento a construir
  * @param s vector de string con el evento o eventos de ese año
  * @param n número de eventos que contienen el vector s que se pasa como parámetro
  * @return Crea el evento con año a y n eventos asociados
  * @pre a debe ser mayor o igual que 0 y menos o igual que 9999, n debe ser un número positivo
  * igual al número de eventos contenidos en el vector de string s
  */

  Fecha_Historica(int a, string *s, int n);

/**
  * @brief Constructor de copias de la clase
  * @param e objeto de la clase que se quiere copiar
  * @return Crea el evento con los datos de e
  */

  Fecha_Historica(const Fecha_Historica& e);

/**
  * @brief Destructor de la clase. Hace un delete del vector de string
  */

  ~Fecha_Historica(){
     anio=0;
     reservados=0;
     numeventos=0;
     delete[] str;
  }


/**
  * @brief Método de acceso al año de la Fecha_Historica
  * @return int con el valor del campo anio
  */

  int getAnio ();



/**
  * @brief Añade un evento
  * @param event string con evento a añadir
  */

  void aniadirevento(string& event);


/**
  * @brief Búsqueda de eventos en una Fecha_Historica dada una palabra clave s
  * @param s string con la palabra a buscar
  * @param matches nueva Fecha_Historica donde se introducen únicamente los eventos de this que contienen el string s
  * @return Devuelve true o false indicando si hay o no algún match de la cadena clave s en los eventos de this
  */


  bool buscarEventos(string s, Fecha_Historica &matches);

/**
  * @brief Salida de un Fecha_Historica a ostream
  * @param os stream de salida
  * @param e Fecha_Historica a escribir
  * @post Se muestra la Fecha_Historica en formato "año#evento1#evento2#...#eventoN" 
  */

  friend ostream& operator<< (ostream& os, const Fecha_Historica& e);

/**
  * @brief Entrada de un Fecha_Historica desde istream
  * @param is stream de entrada
  * @param e Fecha_Historica que recibe el valor
  * @retval El Fecha_Historica leído en e
  * @pre La entrada tiene el formato "año#evento1#evento2#...#eventoN
  */

  friend istream& operator>> (istream& is, Fecha_Historica& e);  

};

#endif
