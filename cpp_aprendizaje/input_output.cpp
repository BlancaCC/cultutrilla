/**
  EJEMPLOS DE INPUT/OUTPUT
  @Author: Blanca Cano Camarero
  @Date: 4/10/17
 */
#include<iostream>

using namespace std;

// Funciones que aparecen:
int clearVg();
int peek_putbackVg();

int main()
{
//clearVg();
peek_putbackVg();

  return 0;
}

// ############### FUNCIONES ##################
/**
   EJEMPLO DE CLEAR Y DE IGNORE
 */
int clearVg()
{
  int a = -1 , b = -1;
  cout << "Enter a number followed by a character: ";
  cin >> a >> b;
  cout << endl << "a = " << a << " , b = " << b << endl;

  cin.clear();   // Restaura el flujo de carácteres, si no ponemos esto se saltaría el siguiente cin

  cin.ignore();  // Limpia el buffer, si no se hace, cogería los valores siguientes introducidos, en su defecto 0

  cout << "Enter two number: ";
  cin >> a >> b ;
  cout << endl << "a = " << a << ", b = " << b << endl;

  return 0;
}

/**
   EJEMPLOS DE GET, PUTBACK Y PEEK
 */

int peek_putbackVg()
{
char ch;
cout << "Enter a string: ";
cin.get(ch);
cout << endl;
cout << "Primer caráceter: " << ch << endl;

cin.get(ch);
cout<< "Segundo carácter" << ch << endl;

cin.putback(ch);
cin.get(ch);
cout  << "Segundo carácter" << ch << endl;

ch = cin.peek();
cout << "Tercer carácter" << ch << endl;

cin.get(ch);
cout << "Tercer carácter" << ch << endl;

return 0;
}
