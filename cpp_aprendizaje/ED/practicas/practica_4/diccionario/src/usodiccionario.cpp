#include <iostream>
#include <list>
#include "diccionario.h"


int main(int argc , char * argv[])
{
  Diccionario<string,string> D,G;

  list<string> mi_lista;
  mi_lista.push_back("El cálculo lambda es un sistema formal diseñado para investigar la definición de función, la noción de aplicación de funciones y la recursión. "); 
  G.Insertar("Cálculo lambda", mi_lista); 
  cin>>D;
  //imprime2(D);
  cout<<D;
  cout << "El número de elementos de nuestra precioso diccionario es "
       << D.numDatos() << endl; 
  cout << endl << "___________ Vamos a borrar__________" << endl;
  D.removeDic("Compilador");
  cout << D;
  
  //Hemos comentado para probar sólo una de las funciones 
  //D.removeDic("Programa", "Sentencia");
  D.removeUntil("Programa", "Sentencia");
  cout << D;
  if( D.estaVacia())
    cout << "Nuestro diccionario está vacio, qué pocas paralabras hay en el mundo :(" << endl;
  else
    cout << "Yupiiiiiii el diccionario no está vacio " << endl; 

  

  string a;
  
  cout<<"Introduce una palabra"<<endl;
  cin>>a;

  list<string>l=D.getInfo_Asoc(a);

  if (l.size()>0)
    EscribeSigni(l);

  // Ejempllo de sonbrecarga del operador +
  cout << "____ Ejemplo del operador suma ____ " << endl;
  cout << G+D;  

}

