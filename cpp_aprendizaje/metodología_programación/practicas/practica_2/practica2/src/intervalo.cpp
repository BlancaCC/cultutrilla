/** 
@file intervalor.cpp
@brief Implementación de la clase intervalo
@author Blanca Cano Camarero
 */


#include <iostream>
#include <assert.h>
#include "intervalo.h"

using namespace std;


Intervalo::Intervalo()
{
  
  cotaInf = 0;
  cotaSup = 0;
  cerradoInf = false;
  cerradoSup = false;
}

Intervalo::Intervalo(double cinf,double csup)
{
  assert (validar(cinf,csup, true, true));
  cotaInf = cinf;
  cotaSup = csup;
  cerradoInf = true;
  cerradoSup = true;
}

Intervalo::Intervalo( double cinf , double csup , bool ceinf , bool cesup )
{
  assert (validar(cinf,csup, ceinf, cesup));
  cotaInf = cinf;
  cotaSup = csup;
  cerradoInf = ceinf;
  cerradoSup = cesup;
}

double Intervalo::getCotaInf()const
{
  return cotaInf;
}
double Intervalo::getCotaSup()const
{
  return cotaSup;
}

bool Intervalo::  esCerradoInf()const
{
  return cerradoInf;
}

bool Intervalo::esCerradoSup()const
{
  return cerradoSup;
}

bool Intervalo::esVacio()const
{
  return ( cotaSup == cotaInf && ( cerradoInf == false || cerradoSup == false ) )? true : false;
}

bool Intervalo::estaDentro( double n ) const
{
  bool salida = false ;
  
  if ( cotaInf < n && cotaSup > n )
    salida = true;
  else
    if (cotaInf == n && cerradoInf == true)
      salida = true;
    else
      if(cotaSup == n && cerradoSup == true)
      salida = true;
  
  return salida;
}

bool Intervalo::validar( double cotaInf , double cotaSup , bool cerIzq , bool cerDer)
{
  bool salida = true;

  if ( cotaInf > cotaSup)
    salida = false;
  else
    if (cotaInf == cotaSup && (!cerIzq || !cerDer)  )
      salida = false;

  return salida;
}

Intervalo interseccion(const Intervalo & i1 , const Intervalo & i2)
{
  double cotaInf , cotaSup;
  bool cerrInf, cerrSup;
  
  double cota1 = i1.getCotaInf();
  double cota2 = i2.getCotaInf();
  
  ///cota inferior de la interseción
  if(  cota1 < cota2 )
    {
      cotaInf = cota2;
      cerrInf = i2.esCerradoInf();
    }
  else
    {
      if(cota1 > cota2)
	{
	  cotaInf = cota1;
	  cerrInf = i1.esCerradoInf();

	}
      else
	{
	  
	  cotaInf = cota2;
	  cerrInf = ( i1.esCerradoInf() &&  i2.esCerradoInf()) ;
	}
    }

   ///cota superior del intervalo    
   cota1 = i1.getCotaSup();
   cota2 = i2.getCotaSup();

  if(  cota1 > cota2 )
    {
      cotaSup = cota2;
      cerrSup = i2.esCerradoSup();
    }
  else
    {
      if(cota1 < cota2)
	{
	  cotaSup = cota1;
	  cerrSup = i1.esCerradoSup();

	}
      else
	{
	  cotaSup = cota2;
	  cerrSup = (i1.esCerradoSup() &&  i2.esCerradoSup() )  ;
	  
	}
    }
  
  Intervalo i;
  if( i.validar( cotaInf , cotaSup , cerrInf , cerrSup) )
      return Intervalo (cotaInf , cotaSup , cerrInf , cerrSup); ///NO ME GUSTA QUE HAYA DOS RETURN

 
  return i;
}

/// Funciones auxiliares, no son métodos de la clase
void escribir( const Intervalo &i)
{
  char cerInf, cerSup;
  cerInf = (i.esCerradoInf() )? '[' : '(';
  cerSup = (i.esCerradoSup())? ']' : ')';

  cout << cerInf << i.getCotaInf() << ',' << i.getCotaSup() << cerSup << " ";
  
}

void leer(Intervalo &i ) //lee los valores de un intervalo según los valores indicados en el guión
{
  char cerInf , cerSup , nul;
  double cotaInf , cotaSup;
  cin >> cerInf >> cotaInf >> nul >> cotaSup >> cerSup ;

  bool cerradoInf , cerradoSup;
  cerradoInf = (cerInf == '[')? true : false;
  cerradoSup = (cerSup == ')')? true : false;

  i = Intervalo( cotaInf , cotaSup , cerradoInf , cerradoSup );
}

  

