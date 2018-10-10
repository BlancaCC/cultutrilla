/**
@file: templates_uso.cpp
@brief: ejemplo de uso de las templates
las templates permiten la abstración por la generalización
 */

#ifndef __PLANTILLAS_T_H__
#define __PLANTILLAS_T_H__

#include <cassert> //salidas correctas

/**
   @brief:pseudo vector dinámico casero
   @param datos , n_elementos: punteros de elementos y tamaño del array 
 */
template<class T>
class Vector
{
 private :
  T* datos;
  int n_elememtos;

  ///Funciones propias para hacerme más facililla la vida 
  void reservar_memoria( int n);
  void liberar_memoria( );
  void copiar(const Vector <T> & original);

 public:

  Vector<T>( int n=0); ///contructor por defecto
  Vector<T>(const Vector<T> & original); /// constructor por copia
  ~Vector<T>(); /// Destructor

  int size() const; ///devuelve tamaño de vector
  T& operator[] ( int i) const; /// sobrecarga del operador []
  void resize( int n); /// Reajuste del tamaño del vector
  Vector<T>& operator=( const Vector<T>& original); ///Sobrecarga del operador =

};


#include "plantillas.tpp" ///IMPLIMENTACIÓN DE LAS DEFINICIONES, tal extensión para facilitad su compresión 
#endif __PLANTILLAS_T_H__
