/**
   @file central.cpp
   @brief Implementación del programa principal
   @author MP-DGIM - Grupo A
**/
#include <iostream>
#include "punto.h"
#include "circulo.h"
using namespace std;

int main()
{
    Circulo c1,c2;

    cout << "Introduzca un circulo en formato radio-(x,y): ";
    c1.leer();
    c1.escribir();
    cout << "Introduzca otro circulo: ";
    c2.leer();
    c2.escribir();	

    Circulo res;

    res.set(puntoMedio(c1.getCentro(),c2.getCentro()),
                     distancia(c1.getCentro(),c2.getCentro())/2);
    cout << "La distancia entre los círculos es: " << distancia(c1,c2) << " y el círculo que pasa por los dos centros es: ";
    res.escribir();
    cout << endl;
    return 0;
}

