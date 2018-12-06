#include <iostream>
#include <cstring>
#include <fstream>

#include "Idioma.h"
#include "Bigrama.h"


using namespace std;

//------------------------- MÉTODOS DE LA CLASE -------------------------
// ..... construcctores destructor .... 
Idioma::Idioma()
{
  _idioma = "unknown";
  _conjunto = NULL;
  _nBigramas = 0;
}

Idioma::Idioma( int nbg)
{
  _idioma = "unknown";
  _conjunto = NULL;
  reservarMemoria( nbg);
}

Idioma::Idioma(const Idioma& orig)
{
  copiar( orig);
}

Idioma::~Idioma()
{
  liberarMemoria();
}

// .... Sobrecarga de operadores ....
Idioma& Idioma::operator=(const Idioma& orig)
{
  liberarMemoria();
  copiar( orig);
  return *this;
}

//.... método clase idioma ....

// Idioma 
string Idioma::getIdioma() const
{
  return _idioma;
}

void Idioma::setIdioma( const string & id)
{
  _idioma = id;
}
//aray bigramas
Bigrama Idioma::getPosicion( int p) const
{
  return _conjunto[p];
}

void Idioma::setPosicion(int p, const Bigrama & bg)
{
  _conjunto[p]=bg;
}

// Búsqueda y orden
int Idioma::findBigrama( const string & bg) const
{
  int pos = -1;
  int i= 0;
  while ( pos == -1 && i < _nBigramas )
    {
      if ( strcmp( bg.c_str() , _conjunto[i].getBigrama()) == 0)
	pos = i;
      i++;
    }

  return pos;
}

void Idioma::ordenar()
{
  ordenaDesFrec( _conjunto , _nBigramas );  ///ordena por frecuenca, obtenido en clase bigrama  
}

//.... entrada y salida ficheros ....

bool Idioma::salvarAFichero( const char* fichero) const
{
  bool salida = true; /// operación efectuada con éxito

  ofstream os ( fichero);
  if(os)
    {
      os << *this;
      os.close();
    }
  else
    {
      //cerr << "No se ha podido abrir el fichero " << fichero << endl;
      salida = false;
    }
  
  return salida;
  
}

bool Idioma::cargarDeFichero( const char *fichero )
{
  bool salida = true;
  ifstream is( fichero);

  if(!is)
    {
      salida = false;
      cerr << "El fichero" << fichero <<" no se ha podido abrir correctamente \n";
    }
  else
    {
            
      is >> *this;
      is.close();
  
    }
  

  return salida;
}
  
//.... sobrecarga de operadores << y >> ....
ostream & operator<<(std::ostream & os, const Idioma & id)
{
  os << "MP-BIGRAMAS_IDIOMA-T-1.0"<< endl;
  os << id._idioma << endl;
  os << id._nBigramas << endl;

  for(int i=0 ; i < id._nBigramas ; i++)
    {
      os << id._conjunto[i].getBigrama() << " " << id._conjunto[i].getFrecuencia() << endl;
	  
    }
  return os;
}


istream & operator>>(std::istream & is, Idioma & id)
{
  string mensaje;
  char bgr[2];
  int f;
  
  getline( is , mensaje); // mensaje basura;
  getline( is , id._idioma);
  is >> f; /// número de bigramas
  id.liberarMemoria(); //método para prevenir y volver a cargarlos
  id.reservarMemoria( f); /// modifica el número de bigramas de manero ipsofasta
  
  int i=0;
  Bigrama aux;
 
  while ( i < id._nBigramas  && ! is.eof())
    {
      is >> bgr >> f ; /// lectura del bigrama y su respectiva frecuencia
      aux.setFrecuencia(f);
      aux.setBigrama(bgr);
      id._conjunto[i++] = aux;
      
    }
  if (i < id._nBigramas)
    {
      cerr << "El número de bigramas especificado es mayor que el que contiene el fichero en cuestión " << endl;
    }
  return is;
}


// ------------------------- FUNCIONES PRIVADAS ------------------------------
void Idioma::reservarMemoria( int n )
{
  _nBigramas = n;
  _conjunto = new Bigrama [n];
}

void Idioma::liberarMemoria()
{
  _nBigramas = 0;
  delete [] _conjunto;
  _conjunto = NULL;
}

void Idioma::copiar(const Idioma& otro )
{
  if( &otro != this )
    {
      if( this != NULL)
	liberarMemoria();
      
      _idioma = otro.getIdioma();
      _nBigramas = otro.getSize();

      reservarMemoria( _nBigramas);
      
      for( int i= 0; i< _nBigramas ; i++)
	{
	  _conjunto[i]= otro.getPosicion(i);
	}
    }
}



