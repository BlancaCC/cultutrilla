/**
PUNTOS DENTRO DE UNA CIRCUNFERENCIA
Blanca Cano Camarero
13/12/17
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


struct Punto
{
  double x; // coordenada de x
  double y; //coordenada y
};

double distancia( Punto p , Punto q)
{
  double x = (p.x-q.x);
  double y = (p.y-q.x);
  return sqrt(x*x + y*y );
}

Punto leer_punto()
{
  cout << "Introduzca las coordenadas del punto, son necesarios dos números: ";

  Punto punto;
  cin >> punto.x >> punto.y;

  return punto;
}

double leer_positivo()
{
  double num = -1;

  do
    {
      cout << "Introduzce un valor  positivo: ";
      cin >> num;
    }while( num <= 0);
  
  return num;
}



class Circulo
{
  Punto centro;
  double radio;

public:
  /**
     @brief costructor de círculo 
  */
 Circulo( Punto punto, double r )
  {
    centro = punto;
    radio = r;
  };
  
/**
   @brief: recibe como parámetro punto y dice si está dentro
 */
  bool interior( Punto p ) const 
  {
    double dist = distancia ( centro , p );
    
    return ( dist*dist < radio*radio )? true : false; 
  }

  /**
     @consultora del radio
   */
  Punto devuelve_centro() const 
  {
    return centro;
  }

  double devuelve_radio() const 
  {
    return radio;
  }
};

/**
   @brief devuelve un objeto de la clase objeto
 */
Circulo escribir_circulo()
{
  return  Circulo ( leer_punto() , leer_positivo());
}


/**
   @brief vector de puntos
 */
vector<Punto> puntos ()
{
  vector<Punto> vp;
  Punto p;
  while ( p != )
    {
    }
  return vp;
}


int main()
{
  Circulo circulo =  escribir_circulo(); //constructor por copia
  vector<Punto> vp = puntos();
  return 0;
}
