#include <iostream>
#include <pila.h>

//gnerar número aleatorios
#include <stdlib.h> 
#include <time.h>
#include <math.h> //para pow en la pila float 

using namespace std;

int main(){

  //inicializamos semilla del random
  srand( time(NULL));
  
  Pila_max <int> p;
  int i;

  for ( i=0; i<10 ; i++) 
    p.poner(rand()%10);
   
  int x = p.tope();
  int x_max = p.tope_maximo();
  cout << x << " " << x_max<< endl;
     
  p.quitar();

  cout << "La pila de número entros es: " << endl;
  p.representa();

  int y = p.tope();
  int y_max = p.tope_maximo();
  cout << y << " " << y_max<< endl;
     

  Pila_max <float> q;
  int j;
  
  for ( j=0; j<10 ; j++) 
    q.poner(j/10.0 * pow( -1, j) );
  cout <<  "La pila de flotates es: \n" ;
  q.representa();
   
  float z = q.tope();
  float z_max = q.tope_maximo();
  cout << z << " " << z_max<< endl;
     
  q.quitar();

  float w = q.tope();
  float w_max = q.tope_maximo();
  cout << w << " " << w_max<< endl;;

  Pila_max <char> pc;
  char k;

  for ( k='a'; k<='z' ; k++) 
    pc.poner(k);

  char zz = pc.tope();
  char zz_max = pc.tope_maximo();
  cout << zz << " " << zz_max<< endl;

  pc.quitar();

  char ww = pc.tope();
  cout << ww << endl;
  
  cout << pc.num_elementos() << endl;

  return 0;
}
