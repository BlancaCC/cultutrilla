/*
Lee un número N,como máximo de 100 , tal será el número de elementos de nuestro array
Los va pidiendo  e introduciendo en el array  
Otra función devuelve el mínimo de estos  

Granada 21 / II / 18
Blanca Cano Camarero

Ejemplo de ejecución:

Número de elementos: 4
Elemento 0 : 1
Elemento 1 : 2
Elemento 2 : 3
Elemento 3 : 0
Array leído: 1 2 3 0 
Mínimo: 0

 
 */


#include <iostream>

using namespace std;

void imprimir_array( const int v[] , int tam); // Imprime la función
void introducir_elementos( int v[] , int tam ); // Pide tam elementos para introducirlos en v
int min_array( const int v[] , int tam); // Devuelve el valor mínimo de un array de enteros

int main ()
{
  int tam_max = 100;
  int v[tam_max];
  
  int tam;
  cout << "Número de elementos: ";
  cin >> tam;

  introducir_elementos( v , tam );
  
  cout << "Array leído: ";
  imprimir_array( v , tam );

  cout << "Mínimo: " <<  min_array( v , tam ) << endl;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imprimir_array( const int v[] , int tam)
{
  for ( int i = 0 ; i < tam ; i++)
    cout << v[i] << " ";
  cout << endl;
}

void introducir_elementos( int v[] , int tam )
{
  int n;
  for( int i = 0 ; i < tam ; i++)
    {
      cout << "Elemento " << i << " : " ;
      cin >> n;
      v[i] = n;

    }
}

int min_array( const int  v[] , int tam)
{
  int min = v[0];

  for ( int i = 1 ; i < tam ; i++)
    if (min > v[i])
      min = v[i];
	
  return min;
}
    
