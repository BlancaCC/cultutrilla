/** 


 * @file fechahistorica.cpp
 * @author Blanca Cano Camarero
 * @date primeros de octubre 2018
 * @brief Fichero implementación del TDA fecha historica
 **/

#include <iostream>
#include <vector>
#include <string>
#include "fechahistorica.h"

using namespace std;

//constructor por defecto
Fecha_historica::Fecha_historica()
{
  _fecha = 0;
  _eventos = NULL;
}

//constructor por copia
Fecha_historica::Fecha_historica(int fecha , char ** eventos)
{
  _fecha = fecha;
  _eventos = eventos;
}

//constructor por co
