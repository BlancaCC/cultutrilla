/**
   @brief: Ejemplo de uso del TDA guiatlf
   @file usoguia.cpp
   @author Blanca Cano Camarero
   @date: diciembre 2018
*/

#include <iostream>
#include "guiatlf.h"

using namespace std;

int main()
{
  // Ejemplo de creación

  Guia_Tlf A;
  A["Antonia Morales"] = "123456789";
  A["Paquito De Los Palotes"] = "987654321";
  A.insert("Yo", "12123432");
  A["a"]="1";

  //Probamos constructor de copia
  Guia_Tlf B (A);
  B.borrar("Yo");
  A.borrar("a","1");

  cout << "El núemero de elementos de la guía es B " << B.size()
       << " en A hay : " << A.size() << endl;

  cout << "Los resultado de buscar yo: " << A.gettelefono("Yo") << endl;

  //probamso clear 
  B.clear();
  B["Clear"]="666";

  //probamos el operador de unión 
  Guia_Tlf C ( A+B);

  cout << "C contiene " << C.size() << " elementos" << endl;
  //probamos operador de intersección 
  cout << "El tamaño de B es igual a " << (C-A).size() << endl;

  //prueba del operador << 
  cout << "El contenido de la guía C es " << endl
       << C ;

  //prueba de la sobrecarga de entrada
  cout << "Introduzca Nombre, tabule  núemero enter" << endl
       << "Para finalizar escriba fin tabuladore enter" << endl;

  B.clear();
  cin >> B;

  cout << "_________El resutuldado ha sido________" << endl;
  cout << B;

  //prueba clavesIniciales
  string BUSCA = "F";
  cout << "_______Veamos las ocurrencias que empiecen por"<< BUSCA<<" ______"<< endl;
  cout << B.clavesIniciales(BUSCA);

 
 //pruena de buscaClaves
 string DENTRO="an";
 cout << "________ Veamos las ocurrencia que contienen a  " << DENTRO << endl;
 cout <<B.buscaClaves(DENTRO);

 //prueba clave
 string TELEFONO = "111111111"; 
 cout << "El dueño del teléfono " << TELEFONO << " es " << endl;
 cout << B.clave(TELEFONO); 
	
}
