/**
   @file diccionario.cpp
   @brief: implementación del tipo de dato diccioneario
   @author Blanca Cano Camarero
   
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
      //  cout << "Se ha encontrado " << (*it).clave << (*it2).clave<< endl;
      advance(it2,1); // movemos en uno para borra el último también
      datos.erase(it, it2 ); //borramos el elemento 
      return true; 
    }
  else
    {
      // cout << "No se ha encontrado " << c_inicial << " o " << c_final << endl; 
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

//~~~~~ fin de removeUntil


template<class T, class U>
Diccionario<T,U>  Diccionario<T,U>::operator+( const Diccionario<T,U> &D)
{
  Diccionario<T,U> aux( *this);
  typename list<data<T,U> >::const_iterator cit;

  for( cit = D.cbegin(); cit != D.cend(); cit++)
    {
      aux.Insertar( cit->clave, cit->info_asoci ); 
    }
  return aux; 
  
}


//~~~~~ fin sobrecarga del operador + 


void imprime2( const Diccionario<string,string> & D){
	  
  list<data<string,string> >::const_iterator it;
  int cnt = 0;
  
  
  for (it=D.datos.begin(); it!=D.datos.end(); it++)
    {

      cout <<"con el elemento: " << cnt++ << endl;  
      list<string>::const_iterator it_s;
      
      cout<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
      for (it_s=(*it).info_asoci.begin(); it_s!=(*it).info_asoci.end();++it_s)
	{
	  cout<<(*it_s)<<endl;
	}
      cout<<"**************************************"<<endl;
    }
  
}
 //~~~~~~~~~ fin imprime2

ostream & operator<<(ostream & os, const Diccionario<string,string> & D)
{
	  
  list<data<string,string> >::const_iterator it;
  int cnt = 0;

  for (it=D.cbegin(); it!=D.cend(); it++)
    {
      
      cout <<"con el elemento: " << cnt++ << endl;  
      list<string>::const_iterator it_s;
      
      os<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
      for (it_s=(*it).info_asoci.begin(); it_s!=(*it).info_asoci.end();++it_s)
	{
	  os<<(*it_s)<<endl;
	}
      os<<"**************************************"<<endl;
    }
  
  return os;
}

//~~~~~~ fin sobrecargar operador <<



istream & operator >>(istream & is,Diccionario<string,string> &D)
{
  //número de claves
  int np;
  is>>np;
  is.ignore();//quitamos \n
  
  Diccionario<string,string> Daux;
  
  for (int i=0;i<np; i++)
    {
      string clave;

      getline(is,clave); 
		    
      int ns;
      is>>ns; 
      is.ignore();//quitamos \n
      
      list<string>laux; //lista auxiliar 
      for (int j=0;j<ns; j++)
	{
	  string s;
	  getline(is,s);
	
	  // cout<<"Significado leido "<<s<<endl;
	  laux.insert(laux.end(),s);
	}
      Daux.Insertar(clave,laux);		      
      
    } // fin for número claves
		      
  D=Daux;
  
  return is;
}

//~~~~~ fin sobrecarga del operador >>




void EscribeSigni(const list<string>&l)
{		 
  list<string>::const_iterator it_s;
	  
  for (it_s=l.begin();it_s!=l.end();++it_s){
    cout<<*it_s<<endl;
  }
}	

