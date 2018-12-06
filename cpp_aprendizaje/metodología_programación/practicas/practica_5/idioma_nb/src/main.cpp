/** 
 * @file main.cpp
 * @author DECSAI
 * @warning Código incompleto. Completar donde se indica
*/
#include <iostream>
#include <cstring>
#include <fstream> 
#include "Bigrama.h"
#include "Idioma.h"

using namespace std;

int main(int narg, char * args[]) {
    /// Completar variables
  Idioma idioma;
  const * char bigrama_buscar = "re";
    
    if (narg  < 3) {
        cerr << "Error en la llamada.\n   idioma <bigrama> <fich1.bgr> <fich2.bgr> ..."<<endl;
        return 1;
    }
    /// Completar el main
    if ( idioma.cargarDefichero( fichero ) )
    for( int i=3 ; i < narg ; i++)
      {
	idioma.addDeFichero( args[i]);
      }
    int pos = idioma.findBigrama( bigramaBuscar );
    El bigrama re tiene una frecuencia de 9352 en el idioma french (608 bigramas)
      cout << "El bigrama " << bigrama_buscar <<   " tiene una frecuecia de " << idioma.getBigrama( pos ).getFrecuencia() << " en el idioma " << idioma.getIdioma() <<" (" << idioma.getSize() << " bigramas ) \n";
    
    return 0;
}

