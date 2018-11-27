/*
  Mañana tengo un examencillo de la STL y aquí estoy yo repasando un poquitillo :D
  Granada 4/X/18
  Blanca
 */

#include <iostream>
#include <set>
#include <stdlib.h>
using namespace std;

//############################## mis declaraciones ##############################
// estructura para funtor de orde inverso :D
struct classcmp
{
  bool operator()(const int& i, const int& d ) const
  {
    return i>d;
  }
};

// utiles
int*  elementos( int tam, int max=10); //devuelve un puntero de tal tamañio
set <int> conjuntoAleatorio( int tam, int max=10); //devuelve un conjutno de enteros elementos aleatorios
ostream& operator<<( ostream& os ,const set<int>& a ); //sobre carga del operador mostrar
void imprime_reves( const set<int, classcmp>& a); //imprime_reves con clase no escalar
//operaciones
set <int> intersection ( const set<int>& a, const set<int>& b);

//uniones
set<int> unioncilla( const set<int>& a , const set<int>& b);
set<int>operator+(const set<int>& a, const set<int>& b );

//complemetarios
set<int>complementa( const set<int>& a, const set<int>& b );
set<int>operator-( const set<int>& a, const set<int>& b );


//############################ main ################################
int main()
{
  srand( time( NULL));

  set<int> A = conjuntoAleatorio(6);
  set<int> B = conjuntoAleatorio(3,10);
  set<int, classcmp> C( A.begin(), A.end());
  cout << "Conjunto A: " <<A << "Conjunto B: " << B;
  cout << "Conjunto C del revés: "; imprime_reves(C); //imprimimos del reves el conjunto 
  cout << "intersection A y B: " << intersection(A, B);
  cout << "union A y B: " << A + B;
  cout << "El complementario es: " <<  A-B ;
  cout << "El tamaño de A es " << A.size() << ", su tamaño máximo " << A.max_size()<< endl;
  while( !A.empty())
    {
      cout << "A no está vacio :( \n";
      A.clear();
    }
  cout << "A está vacio  JO JO JO>:) \n";
  A.swap(B);
  cout << "Tras ejecutar la A.swap(B) resulta que A se queda así: "<< A;

  pair< set<int>::iterator, set<int>::iterator > ret;
  ret=A.equal_range(5);
  cout << "Limite inferior de A en 5: " << *ret.first << endl; //si se encuentra devuelve el elemento encontrado
  cout << "Límite superior A en 5: " << *ret.second << endl; //el máximo que tenga por encima,10);

  //si el el último devuelve el primer elemento
  //si no lo encuentra devuelve un rango de 0, es decir el mismo elemento del set

  set<int>::iterator itlow, itup;
  itlow = A.lower_bound(2); //mayor o igual
  itup = A.upper_bound(2);  //menor o igual

  cout << "A lower_bound(2): " << *itlow <<endl;
  cout << "A upper_bound(2): " << *itup<<endl;

  itlow = C.lower_bound(5); //mayor o igual
  itup = C.upper_bound(5);  //mayor estricto

  //recordemos que el conjunto C está definido del revés, por tanto ahora será:
  cout << "C lower_bound(5): " << *itlow <<endl; //menor o igual 
  cout << "C upper_bound(5): " << *itup<<endl;   //menor estricto
  
  return 0;
}


//####################### implementaciones #####################################
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COMPLEMENTARIO   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
set<int>complementa( const set<int>& a, const set<int>& b )
{
  set<int> c = a;
  set<int>::iterator it;

  for( it=b.begin(); it != b.end(); it++)
    {
      c.erase( *it); //puede ser que no funciones
    }
  return c;
}

set<int>operator-( const set<int>& a, const set<int>& b )
{
  set<int> c = complementa(a,b);
  return c;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UNIONES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
set<int>operator+(const set<int>& a , const set<int>& b )
{
  set<int> u= unioncilla(a,b);
  return u;

}
//unión
set<int> unioncilla( const set<int>& a , const set<int>& b)
{
  set<int> u = b;
  set<int>::iterator it;

  for( it=a.begin(); it != a.end(); it++)
  {
    u.insert(*it);
  }
  return u;
}

//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ itersección  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
set <int> intersection ( const set<int>& a, const set<int>& b)
{
  set<int> i;
  set<int>::iterator it;

  for( it = a.begin(); it != a.end(); it++ )
    {
      if( b.find(*it) != b.end() )
	{
	  i.insert(*it);
	}
    }
  return i;
}


//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UTILES  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ostream& operator<<( ostream& os ,const set<int>& a )
{
  set<int>::iterator it;

  for( it = a.begin() ; it != a.end(); it++)
  {
    os << *it << " " ;
  }
  os << endl;
  return os;
}
void imprime_reves( const set<int, classcmp>& a )
{
  set<int, classcmp>::reverse_iterator it;

  for( it = a.rbegin() ; it != a.rend(); it++)
  {
    cout << *it << " " ;
  }
  cout << endl;
  
}
//devuelve conjuto de enteros de como máximo el tamaño dado
// (es como máximo porque al haber un random una no se puede asegurar de su totalidad )
set <int> conjuntoAleatorio( int tam , int max)
{
   int *p;
  p = elementos(tam, max);
  set<int>conjuntillo( p, p+tam );

  delete []p;
  p = NULL;

  return  conjuntillo;
}


int*  elementos( int tam, int max)
{

  int* n = new int[tam];

  for( int i=0; i<tam; i++ )
    {
      n[i] = rand()%max;
    }
  return n;
}
