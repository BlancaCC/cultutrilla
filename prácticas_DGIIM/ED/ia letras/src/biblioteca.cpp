/**
   @file biblioteca.cpp 
   @author Blanca Cano Camarero 
   @brief Implementación de inteligencia artificial para jugar al scrabble 
   @date enero de 2019
 */


#include "biblioteca.h"

//string por defecto "abcdefghijklmnopqrstuwxyz"
Biblioteca::Biblioteca( Diccionario & soluciones, string validas)
{
  
  asignaPrimos(validas);
  traduceDiccionario(soluciones);
  
} //~~~~~~~~~~ fin constructor 


//string Bliblioteca::devuelveSoluciones()
  
// ################# funciones privadas ##############

void Biblioteca::asignaPrimos( string validas)
{
  const string fichero_primos = "./data/primos"; 
  int primos_necesarios = validas.length();

  //abrimos con capacidad de lectura y escritura
  ifstream f_primos (fichero_primos);
  
  
  if(! f_primos.is_open() )
    {
      cout << "No se ha podido abrir el archivo con los primos " << endl; 
      assert(f_primos);
    }
  
  int indice = 0;
  int num_primo;
  
  while ( indice < primos_necesarios && f_primos >> num_primo)
    {
      // cout << validas[ indice] << " : " << num_primo << endl;
      primos[ validas[ indice] ] = num_primo; 
      indice++; 
    }
  
  //si el fichero contiene menos primos de los necersarios,
  // procedo a calcularlos y añadirlos al fichero
  f_primos.close();
  
  ofstream out_primos ( fichero_primos, ios::app);
  while( indice < primos_necesarios)
    {
      num_primo+= 2; 
      bool es_primo = true;
      for( int i = 0; es_primo && i < indice ; i++)
	{
	  if (num_primo % primos[ validas[i] ] == 0)
	    es_primo = false;
	}
      if( es_primo)
	{
	  //cout << validas[ indice] << " : " << num_primo<< " (ha sido primo de repesca)"<< endl;
	   primos[ validas[ indice] ] = num_primo; 
	   indice++;
	   out_primos << num_primo << endl; 
	}
    }
    out_primos.close(); 
} //~~~~~~~ fin asigna primos


void Biblioteca::traduceDiccionario( Diccionario & soluciones)
{
  for( auto cit = soluciones.cbegin(); cit != soluciones.cend(); cit++)
    {

      
      ///< calculamos la entrada de la tabla hash correspondiente
      unsigned long int entrada = traduce((*cit)); 
      traduccion_diccionario[ entrada ].push_back( (*cit));
    }
}  //~~~~~~~ traduceDiccionario 

///< OJO para mejorar la eficiencia algo no se comprueba que el caracter esté registrado en el diccionario de los primos 
unsigned long int Biblioteca::traduce ( string validas)
{
  
  unsigned long int indice = 1; 
  for( int i=0; i< validas.length(); i++)
    indice *= primos[ validas[i] ];

  return indice; 
} // traudce 


///< OJO para mejorar la eficiencia algo no se comprueba que el caracter esté registrado en el diccionario de los primos 
unsigned long int Biblioteca::traduce ( multiset<char> validas)
{
  
  unsigned long int indice = 1; 
  for( auto c = validas.cbegin(); c != validas.cend(); c++ )
    indice *= primos[*c ];

  return indice; 
} // traudce 


Biblioteca & Biblioteca::operator=( const Biblioteca  & B) 
{
  primos = B.primos;
  traduccion_diccionario = B.traduccion_diccionario;
  
} //~~~ sobrecarga del operador igual


