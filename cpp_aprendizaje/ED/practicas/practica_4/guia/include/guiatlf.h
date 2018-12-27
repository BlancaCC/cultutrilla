/**
   @brief TDA guia de teléfono 
   @author Blanca Cano Camarero 
   @file guiatlf.h 

 */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H

#include <map>
#include <iostream>
#include <string>

using namespace std;



class Guia_Tlf
{
 private:
  //se trabajará con map :) 
  
  map< string, string > datos;

 public:

  /// Constructor por defecto
  Guia_Tlf(){}
  ///contructor por copia
  Guia_Tlf( const Guia_Tlf & gt);
  ///destructores
  ~Guia_Tlf(){};

  /**
     @brief Acceso a un elemento
     @param nombre: nombre del elemento  elemento acceder
     @return devuelve el valor asociado a un nombre, es decir el teléfono
  */
  string & operator[](const string &nombre);
  

/**
   @brief Dando un nombre devuelve teléfonos asociados
   @param nombre: nombre a buscar número 
   @return  String con todos los teléfonos encontrados
 */
string  gettelefono(const string & nombre) ;

/**
   @brief Inserta un nuevo telefono 
   @param nombre: nombre clave del nuevo telefono
   @param tlf: numero de telefono
   @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
*/
 pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf);

 		    
  /**
     @brief Borrar un telefono
     @param nombre: nombre que se quiere borrar
     @note: en caso de que fuese un multimap borraria todos con ese nombre
  */
 void borrar(const string &nombre);

 
 /**
    @brief Borrar un telefono
    @param nombre: nombre que se quiere borrar y telefono asociado
    @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
 */
 void borrar(const string &nombre,const string &tlf);


 /**
    @brief  Numero de telefonos 
    @return el numero de telefonos asociados
 */
 int size()const
 {
   return datos.size();
 }


 /**
    @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
    @param nombre: nombre sobre el que queremos consultar
    @return numero de telefonos asociados a un nombre
		      
 */
 //al ser un map debe de ser 0 o 1. Si fuese un multimap podríamos tener mas de uno
 unsigned int contabiliza(const string &nombre)
 {
   return datos.count(nombre);
 }

 /**
    @brief Limpia la guia
 */
 void clear()
 {
   datos.clear();
 }


 /**
    @brief Unión de guías de telefonos
    @param g: guia que se une
    @return: una nueva guia resultado de unir el objeto al que apunta this y g
 */
 Guia_Tlf operator+(const Guia_Tlf & g);

   /**
     @brief Diferencia de guias de telefonos
     @param g: guia que se une
     @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
  */
 Guia_Tlf operator-(const Guia_Tlf & g);

 		    
 /**
    @brief Escritura de la guía de teléfonos
    @param os: flujo de salida. Es MODIFICADO
    @param g: guía de teléfonos que se escribe
    @return el flujo de salida
 */ 
		      
		    
 friend ostream & operator<<(ostream & os, Guia_Tlf & g);


 		    
  /**
     @brief Lectura de  la guía de telefonos
     Para salir de aquí se deberá escribir fin<tabulador>
     @param is: flujo de entrada. ES MODIFICADO
     @param g: guia de telefonos. ES MODIFICADO
     @return el flujo de entrada
  */
		    
 friend istream & operator>>(istream & is, Guia_Tlf & g);


 // ~~~~~~~~~ comienzo de mis implementaciones ~~~~~~~~~

 /**
    @brief Encuentra todas las ocurrencias  que empiecen por el parámetro buscado
    @param inicio: Comimienzos 
    @return Devuelve string con las claves coincidentes iniciales y su número
  */

 string clavesIniciales( const string & inicio) const; 


 /**
    @brief Encuentra todas las ocurrencias que contengan 
    ciertos caracteres
    @param str: secuencia a encontrar
    @return Devuelve todad las ocuerrencias que contengan esa cadena
  */

 string buscaClaves( const string & str) const;

 /**
    @brief Dado un teléfono busca si es de alguien
    @param Secuencia a encontrar
    @return Nombre del número o NADIE CON TAL TELÉFONO en su defecto
  */
 string clave( const string & telefono) const; 

 /**
    @brief Cambia o crea un número de teléfono dado un nombre
    @param nombre: nombre del usuario al qeu cambiar el teléfono
    
  */
 void asignaTelefono( const string & usuario, const string & telefono); 
};
//Al no haber templates no es necesario llamar así a la función 
//#include "./../src/guiatlf.cpp"

#endif
