/** 
 * @file fechahistorica.h
 * @author Blanca Cano Camarero
 * @date primeros de octubre 2018
 * @brief Fichero cabecera del TDA fecha historica
 **/

#ifndef FECHAHISTORICA_H
#define FECHAHISTORICA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @class Fecha_historica
 * @brief Implementación del T.D.A Fecha histórica
 *  Una instancia de @c Fecha_historica es un objeto del conjunto de acontecimientos históricos, compuesto por un entero,símbolo del año; 
 * y un vector de string que almacenará los eventos. 
 *
 * Un ejemplo de su uso se encuentra en: @include fechahistorica.cpp
 *
 *
 **/

class Fecha_historica
{
 private:
  /**
  * @page repConjunto Rep del TDA Fecha historica
  *
  * @section invConjunto Invariante de la representación
  *
  * Un año lleva asociado una serie de acontecimientos
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA fecha historica
  *
  * (rep.fecha,rep. acontecimientos)
  *
  */
  int _fecha; /**< Año de los determinados eventos*/
  char ** _eventos; /**< Sucesivos acontecimientos*/

 public:

  /**
   * @brief construcctor por defecto, año 0, y sin acontecimientos
   */
  Fecha_historica();

  /**
  * @brief Constructor de la clase
  * @param fecha año de la fecha histórica a construir
  * @param eventos, sere de acontecimientos de la fecha histórica a construir
  * @return Crea la fecha histórcia 
  * @pre NADA EN CONCRETO
  */
  Fecha_historica(int fecha, char * eventos[]);  
};



#endif


