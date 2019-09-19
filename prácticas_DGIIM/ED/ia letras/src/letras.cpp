
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
  cantidad = 0; 
  
}

//~~~~~ constructor por defecto
//recordar que por defecto a=0 y r=0
Letra::Letra( int pnts , int canti, int a, float r)
{
  fa = a;
  fr = r;
  puntos = pnts;
  cantidad = canti; 
}

//~~~~~~~~~ constructor por referencia



//################## conjunto letras ############

// ~~~~~~~~~~~ constructores ~~~~~~~~~~~~~~~~~~~

conjuntoLetras::conjuntoLetras()
{
  letras_contabilizadas = 0;
  
  validas = "abcdefghijklmnopqrstwyz";
  unsigned int len = validas.length();

  //inicializamos cada entidad del vector con un de las letras anteriores
  for( int i= 0; i< len; i++)
    letras[ validas[i] ]  = Letra();

  estadistica_actualizada = true;
  cargado_de_diccionario = true; ///esto indica que no es un fichero anterior con otros datos  
  total_cantidad = 0; 
} //~~~~ constructor por defecto


conjuntoLetras::conjuntoLetras( string fichero_letras)
{
  // intentar abrir archivo
  ifstream fentrada;
  fentrada.open( fichero_letras);

  //si no se ha podido encontrar el archivo aborta el programa
  //quizás sea muy maleducado, pero más maleducado es engañar en el nombre del fichero :D
  assert( fentrada); 

  //cargado_de_diccionario = false; 
  // obviamos la primera fila
  string nulo;
  getline( fentrada, nulo);

  char caracter;
  int cantidad,puntos;
  total_cantidad = 0; 
 
  /*
  // con el fin de evitar que se la dos veces la última línea, saco una lectura fuera, supongo que el fichero tiene al menos una línea
  fentrada >> caracter >> cantidad >> puntos ;
  cout << " se ha leído " <<  "caracter " << caracter << " cantidad " <<  cantidad << " puntos "<< puntos << " "<< fentrada.eof() << endl;
  */
  while(  fentrada.eof() == 0  )
    {
      
      fentrada >> caracter >> cantidad >> puntos ;
      
      //si no se ha añadido de antes 
      if( validas.find( caracter) == string::npos )
	{
	   
	  validas.push_back( caracter );
	  letras[ caracter] = Letra(puntos, cantidad);
	  total_cantidad += cantidad;

	}
    }
 
  
  fentrada.close();

  ///<  con el objetivo de que no me machaque las cantidades ni puntos
  cargado_de_diccionario = false; 
} //~~~~~ constructor a partir de fichero

//se ha omitido el const 
void conjuntoLetras::generaFicheroEstadistica( string fsalida) 
{
  ofstream fout;
  fout.open( fsalida);

  fout << right << setw (7) << "Letras "
       << right << setw( 21) << "Frecuencia absoluta"
       << right << setw( 22) << "Frecuencia relativa"
       << endl;

  for( int i = 0; i< validas.length(); i++)
    {
      fout << right << setw(7)<<  validas[i]
	   << right << setw( 21) <<  letras[  validas[i] ].fa
	   << right << setw( 22) <<  letras[  validas[i] ].fr
	   << endl;
    }
  fout.close(); 

}//~~~~~~ generaFicheroEstadistica

//~~~~~~~~~~~~~~~~~~~ miembros ~~~~~~~~~~~~~~~~~~~~~

void conjuntoLetras::analizarDiccionario( const Diccionario & d)
{
  cargado_de_diccionario = true; 
  //leemos palabra a palabra
  for( auto cit = d.cbegin() ; cit != d.cend() ; cit++)
    {
      for( int i = 0; i< (*cit).length(); i++)
	{
	  incrementa( (*cit)[i]); 
	}
	
    }
} //~~~~~~ analizar diccionario 


void conjuntoLetras::incrementa( char c )
{
  auto it = validas.find(c); 
  if ( it  != string::npos)
    {
      letras[c].fa++;
      letras_contabilizadas++;
      
      estadistica_actualizada = false; 
    }
} //~~~~~ incrementa



void conjuntoLetras::calculaEstadisticas()
{
  if(cargado_de_diccionario == true && estadistica_actualizada == false)
    {
      int maximo = 0;
      const short int minimo_cantidad = 2; ///< Cantidad mínima de piezas
      const short int incr_cantidad_vocal = 0;  ///< Incremento de la cantidad de piezas con prioridad para que haya más probabilidad de q
      string prioridad = "aeiou";

      
      total_cantidad = 0; //procedemos a recalcula la cantidad 
      
      for ( int i= 0; i < validas.length(); i++)
	{
	  letras[validas[i]].fr = (letras[validas[i]].fa*0.1) / letras_contabilizadas;
	  //algoritmo de cálulo de puntuación
	  //la puntuación viene asociada al número de veces que aparece
	  letras[validas[i]].puntos = trunc(letras[validas[i]].fr *1000);
	  //algorirmo de la cantidad de piezas 
	  letras[validas[i]].cantidad = trunc(letras[validas[i]].puntos/minimo_cantidad) + minimo_cantidad;
	  
	  //si la letra es además una vocal, incrementaremos la prokbabilidad de que salga
	  if ( prioridad.find( validas[i]) != string::npos)
	    {
	      letras[validas[i]].cantidad += incr_cantidad_vocal;
	    }

	  total_cantidad += letras[validas[i]].cantidad;
	  
	  //vemos la puntuación máxima obtenida  
	  if( maximo < letras[validas[i]].puntos)
	    {
	      maximo = letras[validas[i]].puntos; 
	    }
	}

      // cuando menos salga, más puntuación 
      for ( int i= 0; i < validas.length(); i++)
	{
	  letras[validas[i]].puntos = 1+ maximo - letras[validas[i]].puntos; 
	}
      estadistica_actualizada = true; 
    }
}//~~~~~~~~ calculaEstadisticas 


string conjuntoLetras::sacaLetras( int num_letras)
{
  //default_random_engine generator;
  //uniform_int_distribution<int>distribution(1, total_cantidad); 
  srand((unsigned)time(NULL));
  
  string salida = "";
  int posicion;
  for( int i = 0; i< num_letras; i++)
    {
      int posicion = rand() % total_cantidad +1; //distribution( generator);
      int j = 0; 
      for( j; posicion > 0 && j < validas.length(); j++)
	{
	  posicion -= letras[ validas[j]].cantidad;
	}
      salida.push_back( validas[j-1]) ; 
    }
  return salida; 
} //~~~~~ sacaLetras


int conjuntoLetras::puntuacionAsociada( string palabra)
{
  int puntuacion = 0;

  for( int i= 0; i< palabra.length(); i++)
    {
      puntuacion += letras[ palabra[i] ].puntos; 
    }

  return puntuacion;
  
} //  ~~~~ puntuaciónAsociada


int conjuntoLetras::puntuacionAsociada( const multiset<char>  & palabra)
{
  int puntuacion = 0;

  for( auto i=palabra.cbegin(); i != palabra.cend(); i++)
    {
      puntuacion += letras[ *i ].puntos; 
    }

  return puntuacion;
  
} //  ~~~~ puntuaciónAsociada, versión multiset

//################# sobrecarga de operadores  #################

ostream & operator<<( ostream & os, conjuntoLetras & C)
{
  // actualizamos las estadísticas por si no lo estuvieran 
  C.calculaEstadisticas();

  //procedemos a mostrar en pantalla los resultados 
  os << right << setw(7)   << "Letra"
     << right << setw( 15) << "Cantidad"
     << right << setw( 15) << "Puntuación"
    // << right << setw( 21) << "Frecuencia absoluta"
    // << right << setw( 22) << "Frecuencia relativa"
     << endl;

  for( int i = 0; i< C.validas.length(); i++)
    {
      os << right << setw(7)<< C.validas[i]
	 << right << setw( 15) << C.letras[ C.validas[i] ].cantidad
	 << right << setw( 15) << C.letras[ C.validas[i] ].puntos
	// << right << setw( 21) << C.letras[ C.validas[i] ].fa
	// << right << setw( 22) << C.letras[ C.validas[i] ].fr
	 << endl;
    }

  return os; 
} //~~~~~~~ operator <<



