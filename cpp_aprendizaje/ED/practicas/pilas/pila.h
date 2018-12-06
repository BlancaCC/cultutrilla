/**
  * @file pila_max.h
  * @brief Fichero cabecera del TDA Pila_max
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  *
  */

#ifndef __Pila_max_H__
#define __Pila_max_H__

#include <cassert>

/**
 *  @brief T.D.A. Pila_max
 *
 *
 * Una instancia @e v del tipo de datos abstracto Pila_max sobre el tipo @c T es 
 * una lista de elementos del mismo con un funcionamiento @e LIFO (Last In, 
 * First Out). En una pila, las operaciones de inserción y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila de longitud
 * @e n la denotamos

 * - [a1,a2,a3,..,an>

 * donde @e ai es el elemento de la posición i-ésima.

 * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es decir, 
 * a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hará sobre éste. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila está vacía.

 * El espacio requerido para el almacenamiento es O(2n). Donde 2n es el número de
 * elementos de la Pila acompañado de su máximo 
 *
 * @author Blanca Cano Camarero
 * @date Noviembre de 2018
 */
template <class T>
class Pila_max{
  private:
    struct Celda {
      T elemento;        ///< Elemento de información.
      T maximo;          ///< Elemento máximo de los que hay por debajo
      Celda * siguiente; ///< Puntero al siguiente nodo.

      /**
       * @brief Constructor por defecto
       */
      Celda() : siguiente(0){
      }
      /**
       * @brief Constructor con parámetros
       * @param elem Elemento de información.
       * @param sig Puntero al siguiente nodo.
       */
    Celda(const T & elem, const T & maximillo, Celda * sig): elemento(elem), siguiente(sig), maximo(maximillo){
      }
    };

    Celda * primera; ///< Puntero al primer nodo de la lista.
    int num_elem;    ///< Número de elementos de la pila.

  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Pila_max(): primera(0), num_elem(0){
    }
    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se hará la copia.
     */
    Pila_max(const Pila_max<T> & otra);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila_max();
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param otra La pila que se va a asignar.
     */
    Pila_max& operator= (const Pila_max<T>& otra);
    /**
     * @brief Comprueba si la pila está vacía
     */
    bool vacia() const{
      return (primera==0);
    }
    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    T& tope (){
      assert(primera!=0);       //Si la pila está vacía, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }
        /**
     * @brief Devuelve el elemento máximo del tope de una pila
     */
    T & tope_maximo(){
      assert(primera!=0);       //Si la pila está vacía, abortar
      return primera->maximo; //Devuelve el elemento del tope de la pila
    }
    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const T & tope () const{
      assert(primera!=0);       //Si la pila está vacía, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }
    /**
     * @brief Devuelve el elemento máximo del tope de una pila constante
     */
    const T & tope_maximo() const{
      assert(primera!=0);       //Si la pila está vacía, abortar
      return primera->maximo; //Devuelve el elemento del tope de la pila
    }
    /**
     * @brief Añade un elemento "encima" del tope de la pila
     * @param elem Elemento que se va a añadir.
     */
    void poner(const T & elem);
    /**
     * @brief Quita el elemento del tope de la pila
     */
    void quitar();
    /**
     * @brief Devuelve el número de elementos de la pila
     */
    int num_elementos() const{
      return num_elem;
    }

    /**
Imprime en pantalla la representaciín de la pila :D
     */
    void representa() const;
};

#include <pila.cpp>

#endif // __Pila_max_H__
