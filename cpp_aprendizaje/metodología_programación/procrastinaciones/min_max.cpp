/**
   Escribe un vector de 100 elementos y devuelve un puntero apuntando a cada uno de ellos
   Blanca Cano Camarero
   Granada 31 / I / 18
 */

#include <iostream>
using namespace std;

int * vector ( int tam = 100 , int min = -100 , int max = 100 )
{
  static int array[ 100];
  int *ptr = &array[0];
  int rango = max - min + 1;

  for ( int i = 0; i < tam ; i++ )
    {
      do
	{
	  *ptr = rand()% rango + min;
	}while( *ptr == NULL);
      ptr++;
    }
  ptr -= tam;

  return ptr;
}

void imprime( int * ptr )
{
  int * aux = ptr;
  while ( *aux != NULL)
    {
      cout << *aux << "  ";
      aux++;
    }
  cout << endl;
}


int main()
{
  int *ptr = vector( 11 );
  int *ptr_min , *ptr_max = ptr;
  
  imprime(ptr);

  while (*ptr != NULL)
    {
      if( *ptr > *ptr_max)
	ptr_max = ptr;
      else
	if( *ptr < *ptr_min )
	  ptr_min = ptr;
      ptr++;
      
    }
  

  cout << endl << "Mínimo: " << *ptr_min
       << endl << "Máximo: " << *ptr_max
       << endl;
}
