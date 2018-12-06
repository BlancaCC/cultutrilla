/**
  * @file conjunto_reales.h
  * @brief Fichero cabecera del TDA Conjunto_Reales
  *
  */
#ifndef _conjunto_reales_h
#define _conjunto_reales_h

#include <vector_dinamico.h>
#include <cassert>

/**
 *  @brief T.D.A. Conjunto_Reales
 *
 * Una instancia @e c del tipo de datos abstracto @c Conjunto_Reales 
 * es un conjunto de n�meros de tipo \c float.
 *
 * El n�mero de elementos del conjunto se denomina \e cardinal o \e tama�o del
 * conjunto. Un conjunto de tama�o cero se denomina vac�o.
 * Lo podemos representar como
 *
 * {e1,e2,e3...,en}
 * 
 * donde n es el n�mero de elementos del conjunto.
 * La eficiencia en espacio es @e O(n).
 *
 *
 * Un ejemplo de su uso:
 * @include ejemplo_conjunto_reales.cpp
 *
 * @author A. Garrido
 * @date Octubre-2011
 */
class Conjunto_Reales {
  private:
    /**
       * @page repConjunto_Reales Rep del TDA Conjunto_Reales
       *
       * @section invConjunto_Reales Invariante de la representaci�n
       *
       * Un objeto v�lido @e rep del TDA Conjunto_Reales debe cumplir 
       * - @c rep.v.size()>=rep.nelementos 
       * - @c rep.nelementos>= 0
       * - \c rep.v[i]<rep.v[j] para todo \e i,j tal que \e \c
 0<=i<j<rep.nelementos
       *
       * @section faConjuntoReales Funci�n de abstracci�n
       *
       * Un objeto v�lido @e rep del TDA Vector_Disperso representa al vector
       *
       * { rep.v[0],...,rep.v[rep.nelementos]}
       *
    */    
    Vector_Dinamico v; /**< Almacena los elementos del conjunto */
    int nelementos;  /**< N�mero de posiciones de \c v usadas */
    /**
     * @brief Localizador de una posici�n en @c v
     *
     * @param val valor del indice a localizar en la matriz
     * @retval pos La posici�n donde se encuentra el @a val (si est�) o
     *     la posici�n donde deber�a insertarse (si no est�)
     * @return Si el valor @a val est� en el vector
     * @note La eficiencia es logar�tmica (usa b�squeda binaria)
     */    
    bool posicion_elemento(int& pos, float val) const;
  public:
    Conjunto_Reales(): nelementos(0) {}
    // Conjunto_Reales(const Conjunto_Reales& c);
    // ~Conjunto_Reales();
    // Conjunto_Reales& operator= (const Conjunto_Reales& c);
    /**
     * @brief A�adir un elemento
     *
     * @param f valor a insertar en el conjunto.
     * @return Si el n�mero de elementos ha aumentado (false en caso
     *     de que el elemento ya estaba en el conjunto)
     */
    bool Insertar(float f);
    /**
     * @brief Eliminar un elemento
     *
     * @param f valor a eliminar del conjunto.
     * @return Si el n�mero de elementos ha disminuido (false en caso
     *     de que el elemento no estuviera en el conjunto)
     */
    bool Borrar(float f);
     /**
     * @brief Consultar la existencia de un elemento
     *
     * @param f valor a consultar en el conjunto.
     * @return Si el elemento pertenece al conjunto
     */
    bool Pertenece(float f) const { int pos; return posicion_elemento(pos,f); }
    /**
     * @brief Valor del i-�simo elemento
     *
     * @param i indica el elemento del conjunto que queremos obtener.
     * @pre 0<=i<size()
     * @return El valor del i-�simo elemento.
     */
    float Elemento(int i) const { assert(0<=i && i<v.size()); return v[i]; }
    /**
     * @brief Cardinal del conjunto
     * @return El n�mero de elementos del conjunto
     */
    int size() const { return nelementos; }
};

#endif /* _conjunto_reales_h */
