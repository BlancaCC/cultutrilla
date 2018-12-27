/**
   @brief: implementación del TDA guiaTlf
   @file: guiatlf.cpp
   @author: Blanca Cano Camararo
   @date: diciembre 2018
 */
#include <iostream>
#include <map>
#include <string> // string and npos
#include <utility> //para lincluir a pair

#include "guiatlf.h"

using namespace  std; 

Guia_Tlf::Guia_Tlf( const Guia_Tlf & gt)
{
  datos = gt.datos; 
}

string & Guia_Tlf::operator[](const string &nombre)
{
  return datos[nombre];
}

string Guia_Tlf::gettelefono( const string & nombre)
{
  string resultado = "";
  map<string, string>::iterator it = datos.find(nombre); 
  for(int i = 0; i< datos.count( nombre); i++ )
    {
      resultado += (*it).second;
      resultado += "\t";
      it++; 
    }
  return resultado; 
}


//~~~~ fin gettelefono

pair<map<string,string>::iterator,bool> Guia_Tlf:: insert(string nombre, string tlf)
    {
      pair<string,string> p (nombre,tlf);
      pair< map<string,string> ::iterator,bool> ret;

      ret=datos.insert(p); 
      return ret;     					
    }

//~~~~~ fin insert


void Guia_Tlf::borrar(const string &nombre)
{
  //Se supone que la clave es única
  //Por consiguiente sólo se necesita un iterador para borrar
  map<string,string>::iterator it = datos.find( nombre);
  //si el elemnto que se desea borrar se encuentra
  if( it != datos.end() )
    datos.erase( it); 
}

// ~~~~~~~ fin borrar  por clave

void Guia_Tlf::borrar(const string &nombre,const string &tlf)
{
  map<string,string>::iterator it = datos.find( nombre);
  
  if( it != datos.end() && tlf == (*it).second )
    datos.erase( it); 
}
// ~~~~~ fin de borrar por clave y teléfono 


Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g)
{
  Guia_Tlf aux (g);

  map<string,string>::const_iterator cit;
  for( cit = datos.cbegin() ; cit != datos.cend() ; cit++)
    aux.insert(cit->first, cit->second);

  return aux; 
  
  
}

// ~~~~~~ fin de la sobrecarga del operador unión 

Guia_Tlf  Guia_Tlf:: operator-(const Guia_Tlf & g)
  {
    Guia_Tlf aux (*this);
    map<string, string>::const_iterator cit;

    for( cit = g.datos.begin(); cit != g.datos.end() ; cit++)
      aux.borrar( cit->first , cit->second);

    return aux;
  }

//~~~ fin de la sobrecarga del operador diferencia

ostream & operator<< (ostream & os, Guia_Tlf & g)
{
    map<string,string>::iterator it;
    for (it=g.datos.begin(); it!=g.datos.end();++it)
      {
	os<<it->first<<"\t"<<it->second<<endl;
      }
    return os;
}


// ~~~~~~~ fin de la sobrecarga del operador <<


 istream & operator>>(istream & is, Guia_Tlf & g)
  {
    pair<string,string> p;
    Guia_Tlf aux;
    string DELIMITADOR = "fin";

    bool dentro = true;
    string clave, numero; 
    while (dentro)
      {
	//clave de la guía, el nombre de la persona
	getline( is, clave, '\t'); //lee hasta tabulador
	if( clave == DELIMITADOR)
	  dentro = false;
	else
	  {
	    getline(is, numero);
	    g.datos[clave] = numero; 
	  }
      }

    return is;
  }


//~~~~~~~ fin de la sobrecarga del operador >> 


// ############## comienzo de mis implementaciones ##########

string Guia_Tlf::clavesIniciales( const string & inicio) const
{
  string salida = "";
  int len = inicio.size(); 

  //comenzamos a recorrer todos los elementos
  map<string,string>::const_iterator cit;
  for( cit = datos.cbegin(); cit != datos.cend(); cit++)
    {
      if( cit->first.substr(0,len) == inicio)
	{
	  salida += cit->first + "\t" + cit->second + "\n"; 
	}
    }
  
  return salida; 
}

//~~~~~~~~ fin clavesIniciales


string Guia_Tlf::buscaClaves( const string & str) const
{
  string salida = "";
  
  //comenzamos a recorrer todos los elementos
  map<string,string>::const_iterator cit;
  for( cit = datos.cbegin(); cit != datos.cend(); cit++)
    {
      if( cit->first.find(str) != string::npos) //si se ha encontrado
	{
	  salida += cit->first + "\t" + cit->second + "\n"; 
	}
    }
  
  return salida;
}
//~~~~~ fin buscaClaves

string Guia_Tlf::clave( const string & telefono )const
{
  string salida = "NADIE CON TAL TELÉFONO";
  bool encontrado = false; 
 map<string,string>::const_iterator cit;
  for( cit = datos.cbegin(); cit != datos.cend() && !encontrado; cit++)
    {
      if( cit->second == telefono) //si se ha encontrado
	{
	  salida = cit->first;
	  encontrado = true; 
	}
    }
  return salida; 
}

//~~~~~~~~ fin clave 

void Guia_Tlf::asignaTelefono( const string & usuario, const string & telefono)
 {
   datos[usuario] = telefono; 
 }

//~~~ fin asignTeléfono 
