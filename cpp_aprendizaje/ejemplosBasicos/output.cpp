/* EJEMPLOS DE OUTPUT 
   - setprecision
   - fixed
   - showpoint 
   - 
   Âutora: Blanca Cano Camarero
   última modificación: 5 / 11 /17
 */

#include<iostream>
#include<iomanip> //biblioteca para setprecision

using namespace std;

int main()
{

  double a = 3.1415926534;
  double b = 2006.0;
  double c = 1.0e-10;

  std::cout.precision(5);

  std::cout << "default:\n";
  std::cout << a << '\n' << b << '\n' << c << '\n';

  std::cout << '\n';

  std::cout << "fixed:\n" << std::fixed;
  std::cout << a << '\n' << b << '\n' << c << '\n';

  std::cout << '\n';

  std::cout << "scientific:\n" << std::scientific;
  std::cout << a << '\n' << b << '\n' << c << '\n';

  

  std ::cout << fixed << showpoint;

  std ::cout << setprecision(20) << showpoint <<  endl << "showpoint, setprecision(20)" << endl 
       << "a = " << a << endl
       << "b = " << b << endl
       << "c = " << c << endl;

  std :: cout <<endl <<  setw(5) << "Esto es: " << setw(50) << "ejemplo de setw()" << endl;
  std :: cout << "Enter an integer: " << flush;
  return 0;
}
