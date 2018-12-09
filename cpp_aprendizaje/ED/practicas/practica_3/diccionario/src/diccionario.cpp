/**
   @file diccionario.cpp
   @brief: implementación del tipo de dato diccionario.cpp
 */

/**
Implementación del tipo de dato anstracto diccionario 
 */

template <class T, class U>
void Diccionario<T,U>::Copiar(const Diccionario<T,U>& D)
  {
    
    datos.assign(D.datos.begin(),D.datos.end());
   
  }
template <class T, class U>		    
void Diccionario<T,U>::Borrar()
{
  this->datos.erase(datos.begin(),datos.end());
}


template <class T, class U>
Diccionario<T,U> & Diccionario<T,U>::operator=(const Diccionario<T,U> &D)
{
  if (this!=&D)
    {
      Borrar();
      Copiar(D);
    }
  return *this;
}


 /* Busca la clave p en el diccionario. Si está devuelve un iterador a
     dónde está clave. Si no está, devuelve end() y deja el iterador de salida
     apuntando al sitio dónde debería estar la clave
  */
template <class T, class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out)
  {
    
    if (datos.size()>0)
      {
				    
	typename list<data<T,U> >::iterator it;
			      
	for (it=datos.begin(); it!=datos.end() ;++it)
	  {
	    if ((*it).clave==p)
	      {
		it_out=it;
		return true;
	      }
	    else if ((*it).clave>p)
	      {
		it_out=it;
		return false;
	      }	  
					   
	  }
			      
	it_out=it;
	return false;
      }
    else
      {	
	it_out=datos.end();
	return false;
      }	    
  }

template <class T, class U>
void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info)
  {
    
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(clave,it))
      {
	data<T,U> p;
	p.clave = clave;
	p.info_asoci=info;
	
	datos.insert(it,p);
      
      }
    
  }
		 
template <class T, class U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s ,const T &p)
  {
    typename list<data<T,U> >::iterator it;
			   
    if (!Esta_Clave(p,it))
      {
	datos.insert(it,p);
      }	    
			   
    //Insertamos el siginificado al final
    (*it).info_asoci.insert((*it).info_asoci.end(),s);
  }

template <class T, class U>
list<U>  Diccionario<T,U>::getInfo_Asoc(const T & p)
    {
      typename list<data<T,U> >::iterator it;
      
      if (!Esta_Clave(p,it))
	{
	  return list<U>();
	}
      else
	{
	  return (*it).info_asoci;
	}
    }			   
				
			   

 
		 
  /*
//Funciones begin y end asociadas al diccionario
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
  */

template <class T, class U>
void Diccionario<T,U>::imprime()
  {
   
    typename list<data<T,U> >::iterator it;
    for( it = datos.begin(); it != datos.end(); it++)
      {
	cout << "______ " << (*it).clave << "_____, su contenido: " << endl;
	typename list<U>:: iterator its;

	for( its = (*it).info_asoci.begin(); its != (*it).info_asoci.end(); its++ )
	  {
	    cout << (*its) << endl;
	  }

	
      }
  }

//############# implementación de mis funciones ########

template<class T, class U>
bool Diccionario<T,U>::removeDic( const T & c)
{
  typename list<data<T,U>>::iterator it; 
  if( Esta_Clave( c, it ) )
    {
      
      datos.erase(it ); //borramos el elemento 
      return true; 
    }
  else
    {
      return false;
    }
}

// ~~fin removedic


template<class T, class U>
bool Diccionario<T,U>::removeDic( const T & c_inicial, const T & c_final  )
{
  typename list<data<T,U>>::iterator it, it2; 
  if( Esta_Clave( c_inicial, it ) && Esta_Clave(c_final , it2) )
    {
      cout << "Se ha encontrado " << (*it).clave << (*it2).clave<< endl;
      advance(it2,1); // movemos en uno para borra el último también
      datos.erase(it, it2 ); //borramos el elemento 
      return true; 
    }
  else
    {
      cout << "No se ha encontrado " << c_inicial << " o "
	   << c_final << endl; 
      return false;
    }
}
	  
//---------- removeDic
	  

template<class T, class U>
bool Diccionario<T,U>::removeUntil( const T & c_inicial, const T & c_final  )
{
  typename list<data<T,U>>::iterator it, it2; 
  if( Esta_Clave( c_inicial, it ) && Esta_Clave(c_final , it2) )
    { 
      datos.erase(it, it2 ); //borramos el elemento 
      return true; 
    }
  else
    {
      return false;
    }
}

// ~~~~~~~~ fin remove until


template<class T, class U >
void Diccionario<T,U>::addDiccionario( const Diccionario<T,U> & D )
{
  //recorremos el diccionario sobre el que se quieren añadir los termnminos

  typename list<data<T,U>>::iterator it, itc;
  typename list<U>::iterator it_info; 
  for(it= D.datos.begin(); it != D.datos.end(); it++)
    {
      //si la clave ya se encuentra en el diccionario
      //actualizamos su contenido 
      if( Esta_Clave( (*it).clave, itc ) )
	{
	  for( it_info = (*it).info_asoci.begin();  it_info != (*it).info_asoci.end(); it_info++ )
	    {
	      if( !binary_search( (*itc).info_asoci.begin(), (*itc).info_asoci.end(),  (*it_info) ) )
		{
		  //si no se ha encontrado añadimos tal contenido
		  (*itc).info_asoci.insert( (*itc).info_asoci.end(), (*it_info) ); 
		  
		} //if
	
	    }
	}
      else
	{
	  //si no está la clave la insetamos donde debería estar
	  datos.insert( itc, (*it) );
	}
    }
}
