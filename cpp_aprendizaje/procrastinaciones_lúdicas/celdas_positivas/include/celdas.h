/**
@file celdas.h
@author Doña Blanca
 **/


#ifndef _CELDAS_H
#define _CELDAS_H
#include <string>

class Mensaje
{
 private:
  char  mensaje [101];
  int positividad;

 public:
  ///construcctures
  Mensaje()
    {
      Mensaje("");
    }
  Mensaje( char mensaje[]);
  Mensaje( char mensaje[] , int positividad );
  
  ///modificadores
  void set_positividad( int n);
  void set_mensaje(  char  mensaje [] );

  /// informantes
  int get_positividad() const ;
  void show_mensaje() const;
  char * get_mensaje();
  
};

struct  Celda
{
  Mensaje mensaje;
  Celda *sig=NULL;

};

//funciones para trabajar con celdas 
void insertar_celda( Celda* &lista , Mensaje ms );
void recorrer_celda( Celda* lista );
void destruir_celda( Celda* &lista );





#endif
