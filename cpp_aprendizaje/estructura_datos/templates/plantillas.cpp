/**
@file plantillas.tpp
*/

template<class T>

Vector<T>::Vector<T>( int n=0)
{
  reservarMemoria(n);
}

vector<T>::Vector<T>( const Vector <T> & original)
{
  copiar (original);
}

///---------------- Funciones propias privadas ----------------

Vector<T>::void reservarMermoria( int n)
{
  ///comprobaciones y cosicas las cuales procedo a omitir
  assert ( n>=0);
  if( n > 0)
    datos = new T[n];
  n_elementos = n;
}
Vector<T>::void liberarMemoria()
{
  if( n_elementos > 0)
    {
      delete [] datos;
      *datos = NULL;
      n_elementos = 0;
    }
}

Vector<T>::void copiar( const Vector<T> & original)
{
  liberal_memoria(); ///QUIZÁS SERÍA MEJOR UN RESIZE
  reservarmemoria( original.n_elementos );

  for (int i=0 ; i< n_elementos ; i++)
    datos[i] = original.datos[i];
  
}
///--------------------------------------------------------------

