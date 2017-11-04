/*
  Resuelve ecuaciones de segundo grado o menos
  Blanca Cano Camarero
  14/10/17
 */

#include<iostream>
using namespace std;

int inicio()
{
  float a , b , c; // coeficiente de la ecuación
  cout >> "Introduzca los coeficientes de su ecuación de segundo grado: \n";
  cin << a << b << c ;  

  float solucion = resultado (a,b,c, True);
  
  return 0;
}
doble resultado(float a, float b, float c , bool primera)
{
  if (a*b*c == 0)
    {
      if(a == 0)
	{
	  if( b != 0 )
	    {
	      resultado = c / d;
	    }
	  else
	    {
	      cout << "En la actualidad, matemáticamente hablando, lo que ha escrito usted es una paradoja \n Anda pruebe suerte otra ves";
	      inicio();
	    }
	}
    }
}

int main()
{
  inicio();
  return 0;
}
