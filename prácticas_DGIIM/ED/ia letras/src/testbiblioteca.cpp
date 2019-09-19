/**
   @brief Fichero de prueba TEST IA
   @author Blanca Cano Camarero 
   @date enero 2019
 */

#include <iostream>

#include "biblioteca.h"
#include "diccionario.h"
using namespace std; 

int main()
{
 
  
 
  Diccionario D;
  cin >> D;

  ///Prueba del constructor
  Biblioteca B ( D);

  ///Prueba de traducción por string
  string letras = "abca";
  
  cout << "La traducciona a índice primos de " << letras << " es: "<< endl;
  cout << "Por string: " << B.traduce(letras) << endl;

  multiset<char> conjuntillo;
  for( auto c= letras.cbegin(); c != letras.cend(); c++)
    conjuntillo.insert( *c);

  cout << "Por conjunto con repetición: " << B.traduce( conjuntillo) << endl
       << "(Si ha ido bien debería de haber salido lo mismo ) " << endl; 
    
}
