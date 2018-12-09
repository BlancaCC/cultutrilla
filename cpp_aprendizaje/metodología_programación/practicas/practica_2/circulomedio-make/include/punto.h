/**
   @file punto.h
   @brief Definción de la clase @p Punto
   @author MP-DGIM - Grupo A
**/
#ifndef _PUNTO_H
#define _PUNTO_H

/// Clase Punto
class Punto {
private:
    double x; ///< coordenada x del punto
    double y; ///< coordenada y del punto};
public:
    Punto(){x=0;y=0;} ///< constructor. Pone a 0 las dos coordenadas
    Punto(double x, double y){this->x=x;this->y=y;}///< constructor. Inicializa un punto con dos valores x y
    double getX() const {return x;} ///< Devuelve la coordenada x del punto
    double getY() const {return y;} ///< Devuelve la coordenada y del punto
    void setX(double nuevoX); ///< Asigna el valor nuevoX a la coordenada x del punto
    void setY(double nuevoY); ///< Asigna el valor nuevoY a la coordenada y del punto
    void escribir() const; ///<  Escribe un punto en formato (x,y)
    void leer(); ///< // Lee un punto en el formato (x,y)
};

double distancia(Punto p1, Punto p2);
Punto puntoMedio(Punto p1, Punto p2);
#endif
