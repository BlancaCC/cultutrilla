/**
  * @file pila_max.h
  * @brief Fichero cabecera del TDA Pila_max
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
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
 * First Out). En una pila, las operaciones de inserci�n y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila de longitud
 * @e n la denotamos

 * - [a1,a2,a3,..,an>

 * donde @e ai es el elemento de la posici�n i-�sima.

 * En esta pila, tendremos acceso �nicamente al elemento del @e Tope, es decir, 
 * a @e an. El borrado o consulta de un elemento ser� sobre  @e an, y la
 * inserci�n de un nuevo elemento se har� sobre �ste. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila est� vac�a.

 * El espacio requerido para el almacenamiento es O(2n). Donde 2n es el n�mero de
 * elementos de la Pila acompa�ado de su m�ximo 
 *
 * @author Blanca Cano Camarero
 * @date Noviembre de 2018
 */
template <class T>
class Pila_max{
  private:
    struct Celda {
      T elemento;        ///< Elemento de informaci�n.
      T maximo;          ///< Elemento m�ximo de los que hay por debajo
      Celda * siguiente; ///< Puntero al siguiente nodo.

      /**
       * @brief Constructor por defecto
       */
      Celda() : siguiente(0){
      }
      /**
       * @brief Constructor con par�metros
       * @param elem Elemento de informaci�n.
       * @param sig Puntero al siguiente nodo.
       */
    Celda(const T & elem, const T & maximillo, Celda * sig): elemento(elem), siguiente(sig), maximo(maximillo){
      }
    };

    Celda * primera; ///< Puntero al primer nodo de la lista.
    int num_elem;    ///< N�mero de elementos de la pila.

  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Pila_max(): primera(0), num_elem(0){
    }
    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se har� la copia.
     */
    Pila_max(const Pila_max<T> & otra);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila_max();
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignaci�n
     * @param otra La pila que se va a asignar.
     */
    Pila_max& operator= (const Pila_max<T>& otra);
    /**
     * @brief Comprueba si la pila est� vac�a
     */
    bool vacia() const{
      return (primera==0);
    }
    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    T& tope (){
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }
        /**
     * @brief Devuelve el elemento m�ximo del tope de una pila
     */
    T & tope_maximo(){
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->maximo; //Devuelve el elemento del tope de la pila
    }
    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const T & tope () const{
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }
    /**
     * @brief Devuelve el elemento m�ximo del tope de una pila constante
     */
    const T & tope_maximo() const{
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->maximo; //Devuelve el elemento del tope de la pila
    }
    /**
     * @brief A�ade un elemento "encima" del tope de la pila
     * @param elem Elemento que se va a a�adir.
     */
    void poner(const T & elem);
    /**
     * @brief Quita el elemento del tope de la pila
     */
    void quitar();
    /**
     * @brief Devuelve el n�mero de elementos de la pila
     */
    int num_elementos() const{
      return num_elem;
    }

    /**
Imprime en pantalla la representaci�n de la pila :D
     */
    void representa() const;
};

#include <pila.cpp>

#endif // __Pila_max_H__
