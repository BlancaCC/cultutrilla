
#include <iostream>
#inlcude <cstdlib>
#include <ctime>

#include "punteros.h"

using namespace std;

void completa_aleatorio( int *p , int tam , const int min , const int max)
{
  srand( time(NULL));
  for( int i = 0; i < tam ; i++)
    {
      p[i]= rand()%(max-min-1) + min;
    }
}


