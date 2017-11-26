/*
OPERACIONES REALES  
Permite realizar operaciones con núemeros reales:
- suma
-resta 
-representante canónico...
Autora: Blanca Cano Camarero
Última modificación: 25/11/17
 */

#include<iostream>
#include <cmath>
using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ cabeceras ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/**
 * @brief: devueve el resultado de la suma de dos número reales  
 * @param a: sumando
 * @param b: sumando
 * @return suma de los valores introducidos
 */
inline double suma( double a , double b );

/**
 *@brief: multiplica dos números reales  
 *@param a: número real
 *@param b: número real
 *@return; a*b
 */
inline double multiplica( double a , double b);

/**
 *@brief: calcula el representante canónico  
 *@param num: número a represenat canónicamente  
 *@return void, imprime en pantalla el represetante canónico
 */
void canonico( double num );
  
/**
 *@brief: uiliza método de euclides para calcular el mcd  
 *@param a: primer entero  
 *@param b: segundo entero
 *@return mcd de a y b
 */
int mcd ( int a , int b);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
  int valor = 5;
  while (valor)
    {
      
      cout << "Qué desea hacer: \n"
	   << "\t0) Cerrar este utilísimo programa"
	   << "\n\t1) sumar"
	   << "\n\t2) multiplicar"
	   << "\n\t3) representante canónico"
	   << endl << "Intruduzca el número de la opción deseada: ";
      cin >> valor;
      
      switch( valor )
      {
	//---------- suma de reales --------------------
      case 1:
	cout << "Introduzca los números que quiere sumar separados por un enter, si es 0 se devuelve el resultado:" << endl;
	
	double num, resultado;
	resultado = 0;
	
	while (num)
	  {
	    cin >> num;
	    resultado = suma( resultado , num);
	    
	  }
	cout << "El resultado es " << resultado << endl;
	break;
	
	//----------multiplica reales  ----------
      case 2:
	cout << "Introduzca los números que quiere multiplicar separados por un enter, si es 1 devuelve el resultado:" << endl;

	double num, resultado;
	resultado = 1;
	
	while (num != 1)
	  {
	    cin >> num;
	    resultado = multiplica( resultado , num );
	    
	  }
	cout << "El resultado es " << resultado << endl;
	break;
	
	//----------representación canónica ----------
      case 3: 
	cout << "Introduzca el número a representar en su forma canónica: ";

	double num;
	cin >> num;
	canonico( num ) ;

	break;
      }
    }
  cout << "Espero que haya disfrutado de nuestros servicios \n" << "Se ha cerrado el programa para trabajar con núemeros reales" << endl;
  return 0;
 }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ funciones ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double suma ( double a , double b)
{
  return a + b;
}

double multiplica( double a , double b)
{
  return a * b;
}

void canonico ( double num )
{
  const  int precision = 100000;   // el número de 0 es el equivalente a decimales que coge
  int valor = round(num * precision); 
  int divide = mcd ( valor , precision );

  cout << "El representante canónico de " << num << " es " << valor/divide << "/" << precision/divide << endl;
}

int mcd ( int a , int b )
{
  cout << " a " << a << " b " << b << endl ; 
  return !(b)? a: mcd ( b , a%b );
}



      
