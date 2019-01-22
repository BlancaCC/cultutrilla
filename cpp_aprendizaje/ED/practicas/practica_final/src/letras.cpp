
/**
   @file letras.cpp
   @author Blanca Cano Camarero 
   @brief implementación de los métodos de letras  
   @date finales diciembre 2018
 */

//############### método de la estructura letra ################
#include"letras.h"

Letra::Letra()
{
  
  fa = 0;
  fr = 0;
  puntos = 0;
  
}

//~~~~~ constructro por defecto

Letra::Letra( , int a, float r , int pnts)
{
  fa = a;
  fr = r;
  puntos = pnts; 
}

//~~~~~~~~~ cosntructor por referencia



//################## conjunto letras ############

// ~~~~~~~~~~~ constructores ~~~~~~~~~~~~~~~~~~~

conjuntoLetras::conjuntoLetras()
{
  letras_contabilizadas = 0;
  
  validas = "abcdefghijklmnopqrstwyz";
  unsigned int len = validas.lenght();

  //inicializamos cada entidad del vector con un de las letras anteriores
  for( int i= 0; i< len; i++)
    letras[ validas[i] ]  = Letra(); 
  
} //~~~~ constructro por defecto


//~~~~~~~~~~~~~~~~~~~ miembros ~~~~~~~~~~~~~~~~~~~~~

void conjuntoLetras::analizarDiccionario( const Diccionario & d)
{
  //leemos palabra a palabra
  for( auto cit = d.cbegin() ; cit != cend() ; cint++)
    {
      for( int i = 0; i< (*cit).lenght(); i++)
	{
	  incrementa( (*cit)[i]); 
	}
	
    }
}


void conjuntoLetras::incrementa( char c )
{
  if ( validas.find(c) != validas.end())
    letras[c].fa++; 
}
