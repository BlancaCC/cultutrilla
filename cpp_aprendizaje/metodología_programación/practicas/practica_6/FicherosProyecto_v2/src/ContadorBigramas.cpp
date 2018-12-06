/**
@file ContadorBigramas.h 
@author Blanca Cano Camarero
 **/

#include <iostream>
#include <fstream>
#include "ContadorBigramas.h"
#include "Idioma.h"
#include "Bigrama.h"

using namespace std;

ContadorBigramas::ContadorBigramas( const string & caracteresValidos )
{
  _nc = caracteresValidos.length();
  _caracteresValidos = caracteresValidos;
  reservarMemoria(_nc);
 
}

ContadorBigramas::ContadorBigramas(const ContadorBigramas & orig)
{
  _nc = orig._nc;
  _caracteresValidos = orig._caracteresValidos;
  reservarMemoria(_nc);
  copiar( orig); 
}


ContadorBigramas::~ContadorBigramas()
{
  liberarMemoria();
}



int ContadorBigramas::getSize() const
{
  return _nc;
}

int ContadorBigramas::getBigramasActivos() const
{
  int activos = 0;
  
  for( int i = 0; i < _nc ; i++ )
    for (int j= 0 ; j < _nc ; j++)
      if (_bigramas[i][j] > 0)
	activos++;
  
  return activos;
  
}

bool ContadorBigramas::addBigrama(const char cadena[], int frecuencia)
{
  int *pos = new int [2];
  bool salida = true;
  
  if ( posiciones(cadena , pos) ) //si el bigrama se encuentra el en string válido
    {
      (frecuencia ==0)? _bigramas[ pos[0] ][ pos[1] ]++ :  _bigramas[ pos[0] ][ pos[1] ]+= frecuencia;
    }
  else
    salida = false;
  
  
  
  delete [] pos;
  pos = NULL;
  
  return salida;
}

bool ContadorBigramas::addBigrama( const int pos[] )
{
  bool valido = true;
  
  if(pos [0] > -1 && pos[1]>-1 && pos[0] < _nc && pos[1]<_nc  )
    _bigramas[pos[0]][pos[1]]++;
  else
    valido = false;
  
  return valido;
}

ContadorBigramas& ContadorBigramas::operator=(const ContadorBigramas& orig)
{
  copiar(orig);
  return *this;
}


int  ContadorBigramas::correcto ( const char a)
{
  int pos = -1;
  int cnt = 0;
  while ( pos == -1 && cnt < _nc)
    {
      if (a == _caracteresValidos[cnt])
	pos = cnt;
      else
	cnt++;
    }
  return pos;
}

bool ContadorBigramas::calcularFrecuenciasBigramas(const char* nfichero)
{
  bool cargado = true;
  ifstream lectura;
  char bg ; //un caracter de bigrama que se irá leyedo
  int pbg[2]={-1,-1}; // -1 será por defecto el incorrecto
  
  lectura.open( nfichero );
  
  if (lectura)
    {
      ///trato de leer el primer caracter
      if (lectura.get(bg))
	{
	  bg = tolower( bg); ///convierto en mayúscula
	  pbg[0] = correcto(bg);
	  while( lectura.get(bg))
	    {
	      bg = tolower(bg);
	      pbg[1] = correcto(bg);
	      
	      addBigrama( pbg); /// posible optimización si caracter no válido
	      pbg[0] = pbg[1];
	    }
	}
      lectura.close();
    }
  else
    {
      cargado = false;
      //cerr << "El fichero no se ha podido abrir \n";
    }
  
  return cargado;
}

Idioma ContadorBigramas::toIdioma() const
{
  int total , cnt , i,  j;
  total =  getBigramasActivos();
  cnt = 0;
  i = 0;

  Idioma aux ( total );
  Bigrama bg;
  char bg_car[2];

  while ( cnt < total && i < _nc )
    {
      j=0;
      while ( cnt < total && j <_nc )
	{
	  if( _bigramas[i][j] != 0)
	    {
	      ///actualización de los valores del bigrama
	      bg_car[0] = _caracteresValidos[i];
	      bg_car[1] = _caracteresValidos[j];
	      bg.setBigrama( bg_car);
	    
	      bg.setFrecuencia( _bigramas[i][j]);
	    
	      aux.setPosicion(cnt,bg);
	      cnt++;
	    }
	  j++;
	}
      i++;
    }
  aux.ordenar();
  return aux;
  
}
void ContadorBigramas::fromIdioma(const Idioma &i)
{

  for( int j=0; j< i.getSize() ; j++) //Si no funciona utilizar getSize()
    {
      addBigrama(  i.getPosicion(j).getBigrama(),  i.getPosicion(j).getFrecuencia() );

    }
}


void ContadorBigramas::reservarMemoria( int n)
{
  
  _bigramas = new int *[n];
  
  for ( int i= 0;  i < n ; i++)
    _bigramas[ i ] = new int [n];

  /// se ponen a cero todas las casillas
  for( int i = 0; i < n ; i++ )
    for (int j= 0 ; j < n ; j++)
      _bigramas[i][j] = 0;
  
}
void ContadorBigramas::liberarMemoria()
{
  if( _bigramas != NULL)
    {
      for ( int i= 0;  i < _nc ; i++)
	delete [] _bigramas[ i ];
 
      delete [] _bigramas;
      _bigramas = NULL;
    } 
}


void ContadorBigramas::copiar(const ContadorBigramas & otro)
{

  for( int i = 0; i < _nc ; i++ )
    for (int j= 0 ; j < _nc ; j++)
      {
	_bigramas[i][j] = otro._bigramas[i][j];
      }
}

bool ContadorBigramas::posiciones (const char cadena[] , int *pos)
{
  bool salida = true;
  int cnt = 0;
  
  pos[0] = -1;
  pos[1] = -1;
  
  while ( salida && (pos[0] == -1 || pos[1]== -1))
    {
      if( cadena[0] ==_caracteresValidos[cnt])
	{
	  pos[0]=cnt;
	}
      
      if( cadena[1] == _caracteresValidos[cnt])
	{
	  pos[1]=cnt;
	}
      cnt++;
      if ( _nc ==  cnt)
	salida = false;
    }
  return salida;

}
