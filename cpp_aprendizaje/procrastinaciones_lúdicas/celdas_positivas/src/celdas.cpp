/**
@file celdas.cpp
@brief implementación de lo implemetable de la clase celda, es decir del mensaje
 **/

#include <iostream>
#include <cstring>
#include "celdas.h"

using namespace std;

Mensaje::Mensaje( char ms [])
{
  strcpy(mensaje ,ms);
  this->positividad = 7;
}

Mensaje::Mensaje( char ms [], int n)
{
  strcpy(mensaje ,ms);
  this->positividad = n;
}

void Mensaje::set_positividad( int n)
{
   this->positividad = n;
}

void Mensaje::set_mensaje(char ms [])
{
  strcpy(mensaje ,ms);
}

int Mensaje:: get_positividad() const
{
  return positividad;
}
void Mensaje::show_mensaje() const
{
  cout << mensaje << endl;
}
char* Mensaje::get_mensaje()
{
  return mensaje;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ fin método mensaje ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
void insertar_celda( Celda* &lista , Mensaje ms )
{
  Celda* aux = new Celda;
  
  aux->mensaje.set_mensaje( ms.get_mensaje());
  aux->mensaje.set_positividad(ms.get_positividad());
  aux->sig=lista;
  lista=aux;

  
}

void recorrer_celda( Celda* lista )
{
  Celda *aux = lista;

  while (aux != NULL)
    {
      aux->mensaje.show_mensaje();
      aux = aux->sig;
      
    }
}

void destruir_celda( Celda* &lista )
{
  while (lista != NULL)
    {
      Celda *aux = lista;
      lista = lista->sig;
      delete aux;
    }
}
