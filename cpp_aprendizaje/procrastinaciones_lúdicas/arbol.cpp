#include <iostream>
#include <vector>

using namespace std;

class Nodo
{
  int pos;
  vector<Nodo> hijos;

public:
  Nodo ( int posicion , const vector<int> & descendencia  )
  {
    pos = posicion;
    int tam = descendencia.size();
    vector<int> des;
    for( int i = 0 ; i < tam; i++ )
      {
	for( int j = 0 ; j < tam ; j++ )
	  if( j != i)
	    des.push_back( descendencia[ j ]);
 
	hijos.push_back(Nodo( descendencia[i] , des ) );
	des.clear();
	    
      }
  }

  void imprime() const
  {
    cout << pos << "  ";
    for( int i = 0; i < hijos.size() ; i++ )
      {
	hijos[i].imprime();
      }
    cout << endl;
  }
};

int main()
{
  int cnt = 7;
  vector<int> hijos( cnt );
  for( int i = 0 ; i < cnt; i++)
    hijos[i]=i+1;

  Nodo arbol(1,hijos);
  arbol.imprime();
  
  return 0;
}
