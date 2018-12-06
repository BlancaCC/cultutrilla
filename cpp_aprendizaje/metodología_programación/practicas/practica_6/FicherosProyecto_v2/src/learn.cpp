/** 
 * @file learn.cpp
 * @author DECSAI
*/

#include <iostream>
#include <cstring>

#include "ContadorBigramas.h"
#include "Bigrama.h"
#include "Idioma.h"


using namespace std;

/**
   @brief Modifica el idioam y el nombre de fichero si este ha sido añadido
 */
void configuracion ( string & i , int & cnt , string & fichero ,  char * argv [] ); 

/**
 * @brief Imprime mensaje de ayuda
*/
void pinta_mensaje() {
    cout << "Formato:" << endl;
    cout << "learn {-c|-a} [-l nombreIdioma] [-f ficheroSalida] texto1.txt texto2.txt texto3.txt .... " << endl;
    cout << "           aprende el codigo para el lenguaje nombreIdioma a partir de los ficheros texto1.txt texto2.txt texto3.txt ..." << endl;
    cout << endl;
    cout << "Parámetros:" << endl;
    cout << "-c|-a: operación crear fichero de idioma (-c) o añadir a fichero de idioma (-a)" << endl;
    cout << "-l nombreIdioma: idioma (unknown por defecto)" << endl;
    cout << "-f ficheroSalida:  nombre del fichero de salida (salida.bgx por defecto)" << endl;
    cout << "texto1.txt texto2.txt texto3.txt ....: nombres de los ficheros de entrada (debe haber al menos 1)" << endl;
}
int main(int argc, char *argv[]) {
	/// Cadena de caracteres válidos de ISO8859-1 para múltiples idiomas
    string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; 

    
    int cnt=2;
    string fichero,idioma;
    idioma = "unknown";
    fichero="out.bgr";
    ContadorBigramas cntb ( valid);
    if ( argc > 2)
    if( strcmp( "-c" , argv[1]) == 0 ) // crea nuevo fichero de bigramas
      {
        configuracion( idioma , cnt , fichero , argv );

	while ( cnt < argc)
	  {
	    if(! cntb.calcularFrecuenciasBigramas( argv[cnt++]))
	      cerr << "No ha sido posible cargar correctamente" << argv[cnt -1] << endl;
	  }
	Idioma i ( cntb.toIdioma());
	i.setIdioma(idioma);
	if( !i.salvarAFichero(fichero.c_str() ) )
	  cerr <<"No ha sido posible guardar los datos en el fichero " << fichero << endl;
	
	
      }
    else if ( strcmp( "-a" , argv[1]) == 0 ) ///añade los nuevos bigramas al fichero
      {
        configuracion( idioma , cnt , fichero , argv );
	Idioma i;
	if ( ! i.cargarDeFichero( fichero.c_str() ) ) 
	  {
	    cerr << "No se ha podido cargar el fichero " << fichero << endl;
	  }
	else
	  {
	    cntb.fromIdioma (i);
	    while ( cnt < argc)
	  {
    	    if(! cntb.calcularFrecuenciasBigramas( argv[cnt++]))
	      cerr << "No ha sido posible cargar correctamente el fichero  " << argv[cnt -1] << " para añadir la frecuencia de sus bigramas" << endl;
	  }
	    i =  cntb.toIdioma( );
	    i.setIdioma(idioma);
	    if( !i.salvarAFichero(fichero.c_str() ) )
	      cerr <<"No ha sido posible guardar los datos en el fichero " << fichero << endl;
	    
	  }
      }
    else
      {
	cerr << "Ha introducido mal los primeros parámetros,de opción, a continuación le musestro el mensaje de ayuda" << endl;
	pinta_mensaje();
	
      }
    else
      {
	cerr << "No hay los suficientes datos, a continuación le muestro el mensaje de ayuda" << endl;
	pinta_mensaje();
      }
   return 0;
}

void configuracion ( string & i , int & cnt , string & fichero , char * argv [] )
{
   if( strcmp( "-l" , argv[cnt]) == 0 )
     {
       i =  argv[++cnt];
       cnt++;
     }
    if( strcmp( "-f" , argv[ cnt]) == 0 )
     {
       fichero = argv[++cnt];
       cnt++;
     }
}
