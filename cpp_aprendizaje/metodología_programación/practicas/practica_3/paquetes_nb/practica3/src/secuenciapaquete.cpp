/**
   @file secuenciapaquete.cpp
   @author decsai.ugr.es
   @warning Código incompleto
**/
#include <iostream>
#include "secuenciapaquete.h"
#include "paquete.h"


void cleanSecuenciaPaq( Paquete  s[] , int until )
{
  Paquete vacio;
  for(int i= 0 ; i < until ; i++)
    s[i]= vacio;
}

bool addSecuenciaPaq(Paquete s[] , int & until , Paquete p)
{
  bool anadido = true;
  if( until < MAXPAQ) //esta condición está repetida en el main
  {
    s[until] = p;
    until++;
  }
  
  else
    anadido = false;
  return anadido;
}

double getTotalSecuenciaPaq(const Paquete s[], int util)
{
  double precio = 0;
  for( int i=0 ; i < util ; i++ )
    precio += s[i].getFactura();
  return precio;
}

Paquete paqueteMayorSecuenciaPaq(const Paquete s[], int util)
{
  double volumen = s[0].getVolumen();
  int pos = 0;

  for( int i=1 ; i < util ; i++ )
    {
      if( volumen < s[i].getVolumen())
	{
	  pos = i;
	  volumen = s[i].getVolumen();
	}
    }
  return s[pos];
}

double getMediaSecuenciaPaq( const Paquete s[],  int util)
{
  double precio = getTotalSecuenciaPaq( s , util );
  precio = precio / util;
  return precio; 
}

int numPaqueteAltosSecuenciaPaq( const Paquete s[],  int util, int altura)
{
  int mayores = 0;
  for( int i= 0; i < util ; i++ )
    if ( s[i].getAlto() > altura)
      mayores++;
  return mayores;
  
}

int numPaquetesSuperiorSecuenciaPaq( const Paquete s[], int util)
{
  int cantidad = 0;
  double media = getMediaSecuenciaPaq( s , util);
  for( int i= 0; i< util ; i++)
    {
      if ( s[i].getFactura() > media)
	cantidad++;

    }
  return cantidad;
}
