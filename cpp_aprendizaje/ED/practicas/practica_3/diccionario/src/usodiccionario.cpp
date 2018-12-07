#include <iostream>
#include "diccionario.h"



/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre 
  listas de listas y otro sobre listas
*/

ostream & operator<<(ostream & os, const Diccionario<string,string> & D){
	  
  list<data<string,string> >::const_iterator it;
  int cnt = 0;
  
  //he camniado esta línes
  //PREGUNTAR LO DE ERROR
  //for (it=D.begin(); it!=D.end(); it++)
  //for (it=D.cbegin(); it!=D.cend(); it++)
  for (it=D.datos.begin(); it!=D.datos.end(); it++)
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

//estoy hata las narices del operados que me han dado, ya me lo hago yo

/*Operator >>. El formato de la entrada es:
  numero de claves en la primera linea
  clave-iésima retorno de carro
  numero de informaciones asociadas en la siguiente linea
  y en cada linea obviamente la informacion asociada
*/
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

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string>&l)
{		 
  list<string>::const_iterator it_s;
	  
  for (it_s=l.begin();it_s!=l.end();++it_s){
    cout<<*it_s<<endl;
  }
}	


/*Lee un diccioario e imprime datos asociados a una clave. 
  Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe: 
  ./usodiccionario < data.txt 
*/
int main(int argc , char * argv[])
{
  Diccionario<string,string> D;
  
  cin>>D;
  //imprime2(D);
  cout<<D;
  cout << "El número de elementos de nuestra precioso diccionario es "
       << D.numDatos() << endl; 
  cout << endl << "___________ Vamos a borrar__________" << endl;
  D.removeDic("Compilador");
  cout << D;
  //Hemos comentado para probar sólo una de las funciones 
  //D.removeDic("Programa", "Sentencia");
  D.removeUntil("Programa", "Sentencia");
  cout << D;
  if( D.estaVacia())
    cout << "Nuestro diccionario está vacio, qué pocas paralabras hay en el mundo :(" << endl;
  else
    cout << "Yupiiiiiii el diccionario no está vacio " << endl; 

  

  string a;
  
  cout<<"Introduce una palabra"<<endl;
  cin>>a;

  list<string>l=D.getInfo_Asoc(a);

  if (l.size()>0)
    EscribeSigni(l);

}

