/**
   @Maneja celdas positivas 
   @author: Doña Blanca 
 **/

#include <iostream>
#include <fstream>
#include "celdas.h"

using namespace std;

int main()
{
  ifstream fichero;
  char ms [100];
  fichero.open("./data/mensajes.txt");
  Celda * lista;
  lista = NULL;

  Mensaje mensaje;
  
  if (fichero)
    {
      do
	{
	  
	  fichero.getline( ms , 100 );
	  mensaje.set_mensaje(ms);
	  // mensaje.show_mensaje();
	  insertar_celda( lista , mensaje);
	  
	  
	  
	}while( !fichero.eof());
      
      fichero.close();
    }
  else
    cerr << "Fichero no encontrado" << endl;
  
  recorrer_celda( lista );
  destruir_celda( lista);
  

  return 0;
}
