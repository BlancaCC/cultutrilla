#include<iostream>

using std::cout;


namespace funciones
{
  int mcd(int a , int b);
  
}

using namespace funciones;

int main()
{
  cout << "El mcd (123321 , 12312) es " << mcd(123321 , 12312) << std::endl;
  return 0;
}
int funciones::mcd( int a , int b)
{
  return !b ? a : funciones::mcd( b , a%b);
}
