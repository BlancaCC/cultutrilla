/**
   @file circulo.cpp
   @brief Implementación de la clase @p Circulo
   @author MP-DGIM - Grupo A
**/
#include <iostream>
#include <cmath>
#include "circulo.h"

using namespace std;

Circulo::Circulo()  {
	centro.setX(0);
	centro.setY(0);
	radio = 0;
}

Circulo::Circulo(Punto centro, double radio)  {
	this->centro = centro;
	this->radio = radio;
	// set(centro,radio);
}

void Circulo::set(Punto centro, double radio)  {
	this->centro = centro;
	this->radio = radio;
}

Punto Circulo::getCentro() const  {
	return centro;
}

double Circulo::getRadio() const {
	return radio;
}

void Circulo::escribir() const{
    cout << radio << "-";
    centro.escribir();
}

void Circulo::leer(){
    // Formato de lectura del círculo: radio-(x,y)
    char car;

    cin >> radio;
    cin >> car; //Leer -
    centro.leer();
}

double Circulo::area() const{
    return M_PI*radio*radio;
}


/**
@brief Calcula la distancia entre dos circulos
@param c1 primer círculo
@param c2 segundo círculo
@return la distancia entre el círculo @a c1 y el círculo @a c2

La distancia entre dos círculos se define como la distancia entre los centros menos los dos radios.
Nótese que la distancia puede ser negativa si los círculos se intersecan
*/
double distancia (Circulo c1, Circulo c2){
    Punto centro1, centro2;
    double dist;

    centro1=c1.getCentro();
    centro2=c2.getCentro();
    dist=distancia(centro1,centro2)-c1.getRadio()-c2.getRadio();
    return dist;
}


/**
@brief Comprueba si un punto es interior a un círculo
@param p punto a comprobar
@param c circulo
@retval true si el punto @a p es interior al círculo @a c
@retval false en caso contrario
*/
bool interior (Punto p, Circulo c){
    if(distancia(p,c.getCentro())<=c.getRadio()) {
        return true;
    }
    else{
        return false;
    }
}

