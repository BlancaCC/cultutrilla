/** 
 * @file Bigrama.cpp
 * @author Paula Villanueva Nuñez
*/

#include <cstring>
#include <iostream>
#include "Bigrama.h"

using namespace std;

Bigrama::Bigrama(){
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

const char* Bigrama::getBigrama() const{
    return _bigrama;
}

int Bigrama::getFrecuencia() const{
    return _frecuencia;
}

void Bigrama::setBigrama(const char cadena[]){
    bool longitud = false;
    
    if (cadena[2] == '\0')
        longitud = true;
    
    if (longitud){
        for (int i=0; i<2; i++){
            _bigrama[i] = cadena[i];
        }
        _bigrama[2] = '\0';
    }
}

void Bigrama::setFrecuencia(int frec){
    _frecuencia = frec;
}

void ordenaAscFrec(Bigrama *v, int n){
    Bigrama aux;
    
    for (int i=0; i<n; i++){
        for (int j=0 ; j<n-1; j++){
            if (v[j].getFrecuencia() > v[j+1].getFrecuencia()){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void ordenaAscBigr(Bigrama *v, int n){
    Bigrama aux;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (strcmp(v[j].getBigrama(), v[i].getBigrama()) > 0){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void imprimeBigramas(const Bigrama *v, int n)  {
    cout << "Lista de " << n << " bigramas:" <<endl;
    for (int i=0; i<n; i++)
        cout << v[i].getBigrama() << "-" << v[i].getFrecuencia()<< ", "; // << endl;
}