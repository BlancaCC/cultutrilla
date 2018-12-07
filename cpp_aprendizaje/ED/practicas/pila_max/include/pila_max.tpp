/**
  * @file pila.cpp
  * @brief Implementación del TDA Pila_max
  * @author: Blanca Cano Camarero 
  * @date Noviembre 2018
  */

#include <cassert>
#include "vector_dinamico.h"

// ------------------- Constructores -------------------------

Pila_max::Pila_max(const Pila_max & otra)
{
  if( otra.num_elem != 0) //si no está vacía el vector al que copiamos
    {
      elemento = otra.elemento;
      maximo = otra.maximo;
      num_elem = otra.num_elem;
    }
  else
    {
      num_elem = 0;
    }
}


Pila_max & Pila_max::operator= (const Pila_max& otra)
{
  elemento = otra.elemento;
  maximo = otra.maximo;
  num_elem = otra.num_elem;
  return *this;
}



void Pila_max::poner( const float & elem)
{
  //aumentamos tamaño del vector
  num_elem++;
  elemento.resize(num_elem);
  elemento[num_elem-1]= elem;
  maximo.resize(num_elem);
  
  if( num_elem > 1 && maximo[num_elem-2] > elem )
    maximo[num_elem-1] = maximo[num_elem-2];
  else
    maximo[num_elem-1]= elem; 
    
}


void Pila_max::quitar()
{
  elemento.resize(--num_elem);
}




