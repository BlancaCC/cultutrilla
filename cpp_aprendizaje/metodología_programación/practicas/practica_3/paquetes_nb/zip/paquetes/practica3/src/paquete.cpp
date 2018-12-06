/**
   @file paquete.cpp
   @author decsai.ugr.es
   @warning Código incompleto
**/
#include <iostream> 
#include "paquete.h"


Paquete::Paquete(int id, double peso, int largo, int ancho, int alto)
{
  _id = id;	
  _peso = peso;	
  _largo = largo;	
  _ancho = ancho;	
  _alto = alto;	
}

Paquete::Paquete(const Paquete & p)
{
  _id = p.getId();	
  _peso = p.getPeso();	
  _largo = p.getLargo();	
  _ancho = p.getAncho();	
  _alto = p.getAlto();
}

void Paquete::setId( int id)
{
  _id = id;
}

int Paquete::getId() const 
{
  return _id;
}

void Paquete::setPeso(int peso)
{
  _peso = peso;
}
double Paquete::getPeso() const 
{
    return _peso;
}


void Paquete::setLargo(int largo)
{
  _largo = largo;
}

int Paquete::getLargo() const 
{
  return _largo;
}



void Paquete::setAncho(int ancho)
{
  _ancho = ancho;
}

int Paquete::getAncho() const 
{
  return _ancho;
}

void Paquete::setAlto(int alto)
{
  _alto = alto;
}

int Paquete::getAlto() const 
{
  return _alto;
}


void Paquete::setPaquete(int id, int peso, int largo, int ancho, int alto)
{
  //considero que algo que sea positivo, ya es suficiente condición para que ser correcto

  if( id > 0 && peso > 0 &&  largo > 0 && ancho > 0 && alto > 0)
    {
      setId( id);
      setPeso(peso);
      setLargo(largo);
      setAncho(ancho);
      setAlto(alto);
    }
}

double Paquete::getVolumen() const
{
  double volumen = getAlto()*getAncho() * getLargo();
  return volumen;
}

double Paquete::calculaPesoVolumetrico() const
{
  double peso_volumetrico = getVolumen() / _FACTORVOLUMETRICO;
  double peso = getPeso();
  return ( peso_volumetrico < peso)? peso : peso_volumetrico;
}

double Paquete::getFactura() const
{
  double factura;
  double volumen = calculaPesoVolumetrico();
  if( volumen < _RANGO1)
    factura = _TARIFA1 * (1 + _IVA);
  else
    {
      if( volumen < _RANGO2)
	factura = _TARIFA2* (1 + _IVA);
      else
        factura =_TARIFA3* (1 + _IVA); 
      //supongo que no sobrepasa de los 15 kg como nos indica el ejercicio
    }

  return factura;
}
