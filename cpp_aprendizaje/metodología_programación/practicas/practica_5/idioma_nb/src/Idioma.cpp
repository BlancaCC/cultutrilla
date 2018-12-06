/** 
 * @file Idioma.cpp
 * @author Blanca Cano Camarero 
*/


#include "Bigrama.h"
#include "Idioma.h"



Idioma::Idioma()
{
  _idioma = "Babilónico";
  _conjunto = NULL;
  _nBigramas = 0;
}

Idioma::Idioma( int nbg )
{
  _idioma = "Babilónico";
  _conjunto = new Bigrama [nbg];
  _nBigramas = nbg;
}
 
void Idioma::reservarMemoria( int nbg )
{
  if( _conjunto != 0 ) // ¿DEBERÍA UTILIZAR LIBERAR MEMEORIA?
    delete [] _conjunto;
  
  _conjunto = new Bigrama [nbg];
}

 void Idioma::ampliarMemoria( int n ) 
{
  Bigrama *aux;
  // int nbg ;
  
  aux = new Bigrama[ _nBigramas + n];

  for( int i=0 ; i < _nBigramas && i < _nBigramas+n; i++) //doble condición por si se reduce la memoria
    aux[i] = _conjunto[i];

  liberarMemoria();
  _conjunto = aux;
  _nBigramas +=  n; // modifico aquí el nbg
}

void Idioma::liberarMemoria()
{
  delete [] _conjunto;
}

std::string Idioma::getIdioma() const
{
  return _idioma;
}


void Idioma::setIdioma( const std::string& id)
{
  _idioma = id;
}

Bigrama Idioma::getPosicion(int p) const
{
  return _conjunto[p];
}

void Idioma::setPosicion(int p, const Bigrama & bg)
{
  _conjunto[p] = bg;
}


int Idioma::findBigrama(const std::string bg) const
{
  int pos = -1;
  int cnt=0;
  
  while ( pos <0 && cnt < getSize() )
    if( bg == _conjunto[cnt].getBigrama() )
      pos = cnt;
    else
      cnt++;
  
  return pos;
      
}
 
void Idioma::addBigrama(const Bigrama & bg)
{
  int pos = findBigrama( bg.getBigrama() );

  if( pos < 0) // no se encuentra en el fichero
    {
      ampliarMemoria(1);
      setPosicion( getSize()-1 , bg);  
    }
  else
    {
      _conjunto[pos].setFrecuencia(_conjunto[pos].getFrecuencia() + bg.getFrecuencia() );
    }
  
}

bool Idioma::cargarDeFichero(const char *fichero_nombre)
{
  bool salida = true;
  std::fstream fichero;
  
  std::cout << "Abriendo fichero " << fichero_nombre  << endl;
  fichero.open(fichero_nombre);  //args[i]);
  
  if(fichero)
    {
      int n, tam , cnt;
      string bigrama , idioma;
      
      fichero >> bigrama; ///mensaje inservible
      fichero >> _idioma;
	    
      std::cout << "Idioma detectado: " << _idioma << endl;
	    
      fichero >> tam; /// número de bigramas a representar
      std::cout << "Leyendo " << tam << " bigramas." << endl;
      
      reservarMemoria(tam);
	    
      while ( fichero && cnt < tam )
	{
	  fichero >> bigrama;
	  addBigrama( bigrama );
	  
	}
	    
      if ( cnt < tam )
	std::cerr << "ERROR cargando datos del fichero \n" ; 
      
    }
  else
    {
      std::cerr << "Error de apertura del fichero \n";
      salida = false;
    }
  
  if (salida)
    cout << "OK \n";
  
  return salida;
}

bool Idioma::addDeFichero(const char *fichero)
{
  bool salida = true;
  std::cout << "Abriendo fichero " << fichero_nombre  << endl;
  fichero.open(fichero_nombre);  //args[i]);
  
  if(fichero)
    {
      int n, tam , cnt;
      string bigrama , idioma;
      
      fichero >> bigrama; ///mensaje inservible
      fichero >> idioma;
	    
      std::cout << "Idioma detectado: " << idioma << endl;
      if (getIdioma() != idioma )
	{
	  std::cerr << "Error, idioma no compatible con " << getIdioma() << endl;
	  salida = false;
	}
      if( salida )
	{
	  fichero >> tam; /// número de bigramas a representar
	  std::cout << "Leyendo " << tam << " bigramas." << endl;
	  
	  while ( fichero && cnt < tam )
	    {
	      fichero >> bigrama;
	      addBigrama( bigrama );
	      
	    }
	}
	    
      if ( cnt < tam )
	std::cerr << "ERROR cargando datos del fichero \n" ; 
      
    }
  else
    {
      std::cerr << "Error de apertura del fichero \n";
      salida = false;
    }
  
   if (salida)
    cout << "OK \n";
  
  return salida;
}
   
