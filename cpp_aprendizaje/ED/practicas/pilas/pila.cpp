/**
  * @file pila.cpp
  * @brief Implementación del TDA Pila_max
  * @author: Blanca Cano Camarero 
  * @date Noviembre 2018
  */
#include <cassert>

//pra la representación bonita :D
#include <iostream>
#include <iomanip> //setw
using namespace std;
// #include <pila.h>  El codigo ya se incluye en pila.h

/* _________________________________________________________________________ */

template <class T>
Pila_max<T>::Pila_max(const Pila_max<T> & otra){
  if (otra.primera!=0){            //Si la pila original no está vacía
    Celda *p = otra.primera;       //Copio el puntero al primer nodo
    Celda *nueva;
    primera = 
    nueva = new Celda(p->elemento,0); //Creamos el primer nodo
    p = p->siguiente;                 //Avanzamos el puntero
    while (p!=0){                                  //Mientras queden elementos
      nueva->siguiente = new Celda(p->elemento,0); //Creamos un nuevo nodo
      nueva = nueva->siguiente;                    //Avanzamos los punteros
      p = p->siguiente;
    }
  }
  else                              //Si la pila original está vacía
    primera = 0;
  num_elem = otra.num_elem;     //En cualquier caso, copiamos num_elem
}

/* _________________________________________________________________________ */

template <class T>
Pila_max<T>::~Pila_max(){
  Celda *aux;
  while (primera!=0){              //Mientras la pila no esté vacía,
    aux = primera;                 //Copiamos el puntero al tope de la pila
    primera = primera->siguiente;  //Avanzamos primera
    delete aux;                    //Borramos el nodo de la lista
  }
}

/* _________________________________________________________________________ */

template <class T>
Pila_max<T>& Pila_max<T>::operator=(const Pila_max<T> & otra){
  Celda * p;
  
  if (this!=&otra){    //Comprobación de rigor. Si son diferentes objetos
    while (primera!=0){    //Borramos la lista de nodos de la pila *this
      p = primera;
      primera = primera->siguiente;
      delete p;
    }
    if (otra.primera!=0){        //Si la otra pila tiene elementos
      p = otra.primera;          //Copiamos el puntero al primero nodo
      Celda *nueva;
      primera = nueva = new Celda(p->elemento,p->maximo, 0);//Reservamos el primer nodo
      p = p->siguiente;                             //Avanzamos el puntero
      while (p!=0){                                 //Mientras queden elementos
        nueva->siguiente = new Celda(p->elemento, p->maximo, 0); //Creamos un nuevo nodo
        nueva = nueva->siguiente;                   //Avanzamos nueva (auxiliar)
        p = p->siguiente;                           //Avanzamos el puntero
      }
    }
    num_elem=otra.num_elem;      //En cualquier caso, copiamos num_elem
  }
  return *this; //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}

/*_________________________________________________________________________ */

template <class T>
void Pila_max<T>::poner(const T & elem){
  if( num_elem >0 ) //si el primer elemento no es nulo 
    primera = new Celda(elem, primera->maximo > elem ? primera->maximo : elem ,primera ); //Creamos un nuevo nodo en el tope
  else
    {
       primera = new Celda(elem, elem ,primera ); //Creamos un nuevo nodo en el tope
    }
  num_elem++;                        //Actualizamos num_elem
}

/* _________________________________________________________________________ */

template <class T>
void Pila_max<T>::quitar(){
  assert(primera!=0);           //Si la pila no tiene elementos, abortar
  Celda *p = primera;           //Copiamos el puntero al tope
  primera = primera->siguiente; //Actualizamos primera
  delete p;                     //Borramos el nodo que ocupaba el tope
  num_elem--;                   //Actualizamos num_elem
}


/* _________________________________________________________________________ */

template<class T>
void Pila_max<T>::representa()const {

  cout<< setw(10) << " Elemento | Máximo \n";
  Celda * aux = primera;
  for( int i= 0 ; i< num_elem; i++)
    {
      cout<< setw(9) << aux-> elemento << " | " << aux->maximo << endl;
      aux = aux->siguiente;
    }
}


