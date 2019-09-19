/**
   @file testnuevaia.cpp
   @author Blanca Cano Camarero
   @date Enero 2019 
   @brief Test de prueba de ia.cpp
 */

#include <iostream>
#include "ia.h"
#include "diccionario.h"
#include "letras.h"

using namespace std;


void muestraSoluciones( IA ia, conjuntoLetras & cl,  string letras)
{
  vector<string > soluciones = ia.mejorSolucion(letras, cl);

  string modo_juego = ia.modoPuntuacion() ? " puntos " : "longitud"; 
  
  cout << " -- Soluciones encontradas para   " << letras <<  " --"
       << endl  << "jugando  en modo " << modo_juego <<":" << endl ;
  
  for( auto sol= soluciones.cbegin(); sol != soluciones.cend(); sol++)
    cout << (*sol) << endl;
  
}


int main()
{
  
  Diccionario D;
  cin >> D;
  
  conjuntoLetras cl( "./data/letras.txt");

  /// Prueba del constructor
  bool modo_puntos = false; 
  IA ia_l( D, modo_puntos);


  /// Buscamos soluciones por longitud
  muestraSoluciones( ia_l, cl, "cola");
  muestraSoluciones( ia_l, cl, "yaxohnswe" );
  muestraSoluciones( ia_l, cl, "cadamentealambi");

  modo_puntos = true;  
  IA ia_p( D, modo_puntos);
 
  /// Buscamos soluciones por puntos
  muestraSoluciones( ia_p, cl, "cola");
  muestraSoluciones( ia_p, cl, "yaxohnswe" );
  muestraSoluciones( ia_p, cl, "cadamentealambi");

  
  cout << " --  Fin de la prueba IA, todo correcto (o eso parece) -- " << endl; 
  
}

