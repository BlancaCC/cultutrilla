/**
   @brief TDA combinaciones con repetición y sin orden
   @file combinaciones.h 
   @author Blanca Cano Camarero 
   @date enero 2019
 */


//honestamente creo que esto es una joyita :D

#ifndef _COMBINACIONES_H_
#define _COMBINACIONES_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std; 


/**
   @brief La idea de este TDA es tener una estructura 
paramanejar conjuntos de combinaciones donde no importa el orden
No es más que un árbol camuflado que crea combinaciones de letras. 
   Los elementos son string que se almacenan en un vector<map <string>> . 
Cada entrada del vector apunta al conjunto de todas las combinaciones posibles de una misma generación. 
Ejemplo visual: 

posición del vector:      0   | 1               | 2 
contenido del conjunto:  abcd | abc,abd,acd,bcd | ab, ac, ad, bc,bd, cd. 

Ademas gracias a GeneracionSiguiente() no será necesario crearlas todas del tirón, si no que se irá creando una nueva tras cada ejecución del anterior. 
 
 */
struct Combinaciones
{
  /**
     @brief Vector cDevuelve vector con la última generación creadaon todas las combinaciones
  */
  vector< set < multiset<char> > > arbol_combinaciones;

  /**
     @brief constructor de copia
     @param string sobre el que se quieren calcular las combinaciones sin orden y sin repetición de elementos 
   */
  Combinaciones( string elementos);

  /**
     @brief amplia la siguiente generación, añadiéndola al final de arbol_combinaciones
     @return  true si se ha podido generar, false en caso contrario 
   */
  bool GeneracionSiguiente();

}; 

#endif  //_COMBINACIONES_H_
