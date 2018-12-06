/** 
 * @file Bigrama.cpp
 * @author DECSAI
*/

#include <cstring>
#include <iostream>
#include "Bigrama.h"

using namespace std;


//----------------------------- clase bigrama -----------------------------------------------------------------------
Bigrama::Bigrama() {
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

Bigrama & Bigrama::operator=(const Bigrama & orig)
{
 
  strcpy( _bigrama , orig.getBigrama());
  _frecuencia = orig.getFrecuencia();
  return *this;
}

const char* Bigrama::getBigrama() const
{
  return _bigrama; 
}

int Bigrama::getFrecuencia() const 
{
  return _frecuencia;
}

void Bigrama::setBigrama( const char cadena[])
{
  //entiendo por validación a que los dos primeros caracteres no sean de fin de linea
  if ( cadena[0] != '\0' && cadena[1] != '\0')
    {
      strcpy(_bigrama , cadena );
    }
  
}

void Bigrama::setFrecuencia( int frec)
{
  _frecuencia = frec; 
}

// ---------------------------------------------- fin de la clase ------------------------------------------------------
void imprimeBigramas(const Bigrama *v, int n)  {
    cout << "Lista de " << n << " bigramas:" <<endl;
    for (int i=0; i<n; i++)
       cout << v[i].getBigrama() << "-" << v[i].getFrecuencia()<< ", "; // << endl;
      
}

void ordenaAscFrec( Bigrama *v , int n)
{
  int pos;
  int frec;
  Bigrama memoria;
  
  for( int i = 0; i < n ; i++)
    {
       pos = i;
       frec = v[i].getFrecuencia();
       for( int j=i+1 ; j < n ; j++)
	{
	  if(frec > v[j].getFrecuencia())
	    {
	      frec =  v[j].getFrecuencia();
	      pos = j;
	    }

	}
      if( pos != i)
	{
	  memoria.setBigrama( v[pos].getBigrama() );
	  memoria.setFrecuencia( v[pos].getFrecuencia() );

	  v[pos].setBigrama( v[i].getBigrama() );
	  v[pos].setFrecuencia( v[i].getFrecuencia() );

	  v[i].setBigrama( memoria.getBigrama() );
	  v[i].setFrecuencia( memoria.getFrecuencia() );
	}
    }
}
void ordenaDesFrec( Bigrama *v , int n)
{
  int pos;
  int frec;
  Bigrama memoria;
  
  for( int i = 0; i < n ; i++)
    {
       pos = i;
       frec = v[i].getFrecuencia();
       for( int j=i+1 ; j < n ; j++)
	{
	  if(frec < v[j].getFrecuencia())
	    {
	      frec =  v[j].getFrecuencia();
	      pos = j;
	    }

	}
      if( pos != i)
	{
	  memoria.setBigrama( v[pos].getBigrama() );
	  memoria.setFrecuencia( v[pos].getFrecuencia() );

	  v[pos].setBigrama( v[i].getBigrama() );
	  v[pos].setFrecuencia( v[i].getFrecuencia() );

	  v[i].setBigrama( memoria.getBigrama() );
	  v[i].setFrecuencia( memoria.getFrecuencia() );
	}
    }
}

void ordenaAscBigr(Bigrama *v, int n)
{
  Bigrama memoria;
  char b0,b1;
  int pos;
  for( int i= 0; i<n ; i++)
    {
      b0 = v[i].getBigrama()[0];
      pos = i;
      
      for(int j = 1+i; j < n ; j++)
	{
	  if( b0 > v[j].getBigrama()[0] || ( b0 == v[j].getBigrama()[0] && v[pos].getBigrama()[1] > v[j].getBigrama()[1]) )
	    {
	      pos = j;
	      b0 = v[j].getBigrama()[0];
	    }
	}
      if(pos != i ) //procedemos a intercambiar
	{
	  memoria.setBigrama( v[pos].getBigrama() );
	  memoria.setFrecuencia( v[pos].getFrecuencia() );

	  v[pos].setBigrama( v[i].getBigrama() );
	  v[pos].setFrecuencia( v[i].getFrecuencia() );

	  v[i].setBigrama( memoria.getBigrama() );
	  v[i].setFrecuencia( memoria.getFrecuencia() );

	  
	}
    }
}

void sumaBigramas(const Bigrama *v1, int nv1, const Bigrama *v2, int nv2, Bigrama *& res, int & nres)
{
  for( int i = 0; i < nv1 ; i++)
    {
      
      res[i].setBigrama( v1[i].getBigrama() );
      res[i].setFrecuencia( v1[i].getFrecuencia() + v2[i].getFrecuencia() );      
    }
  nres = nv1; 
  
}



