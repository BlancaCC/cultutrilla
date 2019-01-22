/**
   @brief Ejemplo de cómo se crea un iterador de una clase
   @author Blanca Cano
   @date 21 enero 2019
 */

#include <iostream>
#include<list>

using namespace std;

struct Pares
{
  int a,b;
  Pares( int x, int y):a(x),b(y){};
}; 
  
class Lista
{
private:
  list <Pares> l;

  //un par puro es aquel que ambos miembros son par o impar
  //creemos un iterador que lo recorra
public:
  Lista()
  {
    int a, b; 
    while ( cin >> a )
      {
	cin >> b; 
	l.push_back( Pares(a,b) ) ;
	
      }
  }
    
  class iterator_puro
  {
  private:
    list<Pares>::iterator it, final;

  public:
    //constructor por defecto

    iterator_puro(){}
    bool operator == ( const iterator_puro & i)
    {
      return it == i.it;  
    }
    bool operator != ( const iterator_puro & i)
    {
      return it != i.it;  
    }
    Pares &operator*()
    {
      return *it;  
    }
    iterator_puro & operator++ (int)
    {
      it++;
      bool no_encontrado = true;
      
	while ( it != final && no_encontrado )
	  {
	    if( it->a % 2 == it->b % 2)
	      no_encontrado = false;
	    else
	      it++;
	  }
      return *this; 
    }
    
    friend class Lista; 
  };

  
  iterator_puro begin()
  {
    iterator_puro i;
    i.it = l.begin();
    i.final = l.end();
    
    bool no_encontrado = true;
      
	while ( i.it != i.final && no_encontrado )
	  {
	    if( i.it->a % 2 == i.it->b % 2)
	      no_encontrado = false;
	    else
	      i.it++;
	  }
    
   

    return i; 
  }

  iterator_puro end()
  {
    iterator_puro i;
    i.it = l.end();
    i.final = l.end();

    return i; 
  }
};


int main()
{
  Lista l;

  Lista::iterator_puro it;
  cout << "proceder a representar" << endl;
  
  for( it = l.begin(); it != l.end(); it++)
    {
      cout << (*it).a << " " << (*it).b << endl; 
    }
}
