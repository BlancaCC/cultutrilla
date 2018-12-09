#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>


using namespace std;

/*Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
  no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
  de tipo T. El diccionario está ordenado de menor a mayor clave.
*/
template <class T,class U>
  struct data
  {
    T clave;
    list<U> info_asoci;
  };

 
/*Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como
  un funtor.
*/
template <class T, class U>
  bool operator< (const data<T,U> &d1,const data <T,U>&d2)
{
  if (d1.clave<d2.clave)
    return true;
  return false;
}	   

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
  manejan listas de listas. Se añaden 2 funciones privadas que hacen más fácil la implementación
  de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
  otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
  puede hacerse usando iteradores o directamente usando la función assign.
*/
template <class T,class U>
  class Diccionario
{
 private:
		    
		  
  list<data<T,U> > datos;
		    
  void Copiar(const Diccionario<T,U>& D);
		    
  void Borrar();	      
			   
			       
 public:
  
  /* Constructor por defecto*/
 Diccionario():datos(list<data<T,U> >()){}
		 
  /* Constructor de copias*/
  Diccionario(const Diccionario &D)
    {
      Copiar(D);
    }
		 
  /* Desstructor*/
  ~Diccionario(){}
		 
  /* Operador de asignación*/
  Diccionario<T,U> & operator=(const Diccionario<T,U> &D);
  
  /* Busca la clave p en el diccionario. Si está devuelve un iterador a
     dónde está clave. Si no está, devuelve end() y deja el iterador de salida
     apuntando al sitio dónde debería estar la clave
  */
  bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out);
		 
  /* Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
     e inserta la lista con toda la información asociada a esa clave. Si el 
     diccionario no estuviera ordenado habría que usar la función sort() 
  */
  void Insertar(const T& clave,const list<U> &info);
    
		 
  /*Añade una nueva informacion asocida a una clave que está en el diccionario.
    la nueva información se inserta al final de la lista de información.
    Si no está inserta la clave y añade la informacion asociada. 
  */
  void AddSignificado_Palabra(const U & s ,const T &p);

  
		 
  /* Devuelve la información (una lista) asociada a una clave p. Podrían 
     haberse definido operator[] como
     data<T,U> & operator[](int pos){ return datos.at(pos);}
     const data<T,U> & operator[](int pos)const { return datos.at(pos);}
  */
  list<U>  getInfo_Asoc(const T & p);				
			   
		 
  /*Devuelve el tamaño del diccionario*/
  int size()const
  {
    return datos.size();
  }
  //######### mis programs añadidos ##########################
  /**
     @brief Muestra en pantalla las claves que contienen en su defición una palabra o estructura de palabra
     @param contenido a buscar 
   */

  //hacer otro de consulta y otro adivina :)

  /**
     @brief Borra una clave y su contenido a partir de una clave dada
     @param  Clave que se quiere borrar
     @return Devuelve True si se ha borrado, False si no se encontraba en la lista 
   */
  bool removeDic( const T & c );

  /**
     @brief Borra los elemtos de dadas dos claves 
     [c_inicial, c_final]
     @param c_incial, c_final son las claves a borrar 
     
   */
  bool removeDic( const T & c_inicial, const T & c_final );

  
  /**
     @brief Borra los elemtos de dadas dos claves 
     [c_inicial, c_final) NO CONFUNDIR CON EL ANTERIOR 
     @param c_incial, c_final son las claves a borrar 
     
   */
  bool removeUntil( const T & c_inicial, const T & c_final );


  /**
     @brief Comprueba si el diccionario  está vacío
     @return true si está vacía, false en el caso contrario 
   */

  bool estaVacia() const
  {
    return datos.empty(); 
  }

  /**
     @brief Devuelve el número de elemntos de nuestro diccionario
     @return Número de elemntos del diccionario
   */
  int numDatos() const
  {
    return datos.size(); 
  }

  /**
     @brief Aniadir a partir de diccionario con el siguiente resultado:
     - Si la clave ya se encuentra se añaden las definiciones si no son la misma 
     - Si no se encuentra la clace se añade :)
     @param Diccionario 
  */

  void addDiccionario ( const Diccionario & D );

  //  ############## fin de mis añadidos ##################

  
  /*Funciones begin y end asociadas al diccionario*/
  typename list<data<T,U> >::iterator & begin()
    {
      datos.begin();
    }
  typename list<data<T,U> >::iterator &end()
    {
      datos.end();
    }
		 
  typename list<data<T,U> >::const_iterator & cbegin()const
    {
      datos.begin();
    }
  typename list<data<T,U> >::const_iterator & cend()const
    {
      datos.end();
    }

   /**
     Función que imprime en pantalla, las claves 
   */
  void imprime();

  //Sobrecarga de los operadores con funciones amigas
   friend ostream & operator<<(ostream & os, const Diccionario<string,string> & D);
  // friend istream & operator>>(istream & os, Diccionario<T,U> & D);
   friend void imprime2( const Diccionario<string,string> & D);
};

#include "./../src/diccionario.cpp" //OJO SE HA PUESTO LA RUTA RELATIVA 
#endif
	 
	  

	  
