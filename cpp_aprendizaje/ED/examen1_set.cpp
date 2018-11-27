/**
   @brief examen de laboratorio tipo SET
   @author Blanca Cano Camarero
   @file puntuable1.cpp
 */
#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

// ############################ mis funciones ###################### 

/**
   @brief Devuelve la unión de dos conjuntos de enteros
   @param: a,b conjuntos de enteros
   @return Devuelve la unión de dos conjuntos de enteros
 */
set<int> union2( const set<int>& a,const set<int>& b)
{
  set<int> u = a;
  set<int>::iterator it;
  for(it = b.begin(); it != b.end(); it++)
    {
      u.insert(*it);
    }
  return u;
  
}
/**
   @brief Devuelve la unión de tres conjuntos de enteros
   @param: a,b,c confuntos de enteros
   @return Devuelve la unión de tres conjuntos de enteros
 */
set<int> union3( const set<int>& a,const set<int>& b,const set<int>& c)
{
  return union2( union2(a,b),c);
}

/**
   @brief Devuelve la intersección de dos conjuntos de enteros
   @param: a,b conjuntos de enteros
   @return Devuelve la intersección de dos conjuntos de enteros
 */
set<int> interseccion2( const set<int>& a,const set<int>& b)
{
  set<int> i;
  set<int>::iterator it;
  for(it = b.begin(); it != b.end(); it++)
    {
      if( a.find(*it) != a.end())
	{
	  i.insert( *it);
	}
    }
  return i;
  
}
/**
   @brief Complemento de b-a
   @param: a,b conjuntos de enteros
   @return Devuelve b-a de dos conjuntos de enteros

 */
set<int> complemento( const set<int>& b,const set<int>& a)
{
  set<int> i;
  set<int>::iterator it;
  for(it = b.begin(); it != b.end(); it++)
    {
      if( a.find(*it) == a.end())
	{
	  i.insert( *it);
	}
    }
  return i;
  
}

/**
   @brief intersección disjunta de tres elementos
   @param: a,b,c confuntos de enteros
   @return intersección disjunta de tres conjuntos A, B y C formada por los elementos de A y B que no está, en C uniíon con los de B y C que no están en A unión con los de C y A que no están en B
 */
set<int>interseccion_disjunta( const set<int>& a,const set<int>& b,const set<int>& c)
{
  return union3( complemento( interseccion2(a,b), c) , complemento( interseccion2(a,c), b) , complemento( interseccion2(c,b), a) );
}

// ######################### fin de mis funciones #########################
/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */

template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;
  
  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}
int main(){

  //Ejemplo dado en el enunciado
  int A[]={1,2,4,5,8}; set<int> a(A,A+5);
  int B[] = {4,5,6,9}; set<int> b(B,B+4);
  int C[] ={3,4,7,8,9}; set<int> c(C,C+5);
  /*set<int> c, a, b;
  
  InicializarSemilla();
  
  for (int i=0;i<3;i++)
    {
      c.insert(generaEntero(1,10)); //inserta un entero generado aleatoriamente en el rango 1-100
      a.insert(generaEntero(1,10));
      b.insert(generaEntero(1,10));
    }
  */
  cout << "Los conjuntos son:";
  cout<<endl<< "C: "<<c << endl  <<"a: "<< a << endl <<"b: "<< b << endl;
  cout << "La unión de los tres es: " << union3(a,b,c) << endl;
  cout << "La intersección disjunta es: " << interseccion_disjunta(a,b,c) << endl;
}  
  
