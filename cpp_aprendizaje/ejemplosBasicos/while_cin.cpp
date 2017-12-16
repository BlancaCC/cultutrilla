/**
   WHILE CIN
   Blanca Cano Camarero
   Granada 16/12/17

   Lee enteros hasta su defecto, basándose en un while( cin >> var) 
   Al salirse para volver a utilizar cin se ignoran los errores y se salta a la siguiente linea
   La biblioteca limits permite no tener que definir el número de caracteres máximos

   Ejemplo de ejecución:
#################################

1
2
2.71828... este número sí que mola
0

##################
  En la tercera línea abandona el while


 */

#include <iostream>
#include <limits>
using namespace std;

int main ()
{
  int num;
  while (cin >> num )
    continue; //cout << num << endl;

  cin.clear();
  cin.ignore( numeric_limits<streamsize>::max(), '\n'); //en defecto de utilizar  numeric_limits<streamsize>::max() de limits incluir un entero

  cin >> num;  // si no se hiciera un cin.clear e ignore el progrma se cortaría bruscamente aquí
  
  return 0;
}

