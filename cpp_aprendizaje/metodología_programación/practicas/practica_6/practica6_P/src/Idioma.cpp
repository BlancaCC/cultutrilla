/**
 * @file Idioma.cpp
 * @author Paula Villanueva Nuñez
 */

#include <cstring>
#include <iostream>
#include <fstream>
#include "Idioma.h"
#include <string>
#include "Bigrama.h"

using namespace std;

Idioma::Idioma(){
    _nBigramas = 0;
    _conjunto = NULL;
    _idioma = "NULL";
}

Idioma::Idioma(int nbg){
    _idioma = "NULL";
    _conjunto = NULL;
    reservarMemoria(nbg);
}

Idioma::Idioma(const Idioma& orig){
    this->_idioma = orig._idioma;
    reservarMemoria(orig._nBigramas);

    for (int i=0; i<_nBigramas; i++){
      this->_conjunto[i] = orig._conjunto[i];
    }
}

Idioma::~Idioma(){
    liberarMemoria();
}

Idioma& Idioma::operator=(const Idioma& orig){
    copiar(orig);
    return *this;
}

void Idioma::reservarMemoria(int n){
    if (_conjunto != NULL)
        liberarMemoria();

    if(n > 0){
        _nBigramas = n;
        _conjunto = new Bigrama[n];
    }
}


void Idioma::liberarMemoria(){
    delete[] _conjunto;
    _conjunto = NULL;
    _nBigramas = 0;
}

string Idioma::getIdioma() const{
    return _idioma;
}

void Idioma::setIdioma(const string& id){
    _idioma = id;
}

Bigrama Idioma::getPosicion(int p) const{
    return _conjunto[p];
}

void Idioma::setPosicion(int p, const Bigrama& bg){
    if (p >= 0 && p < _nBigramas)
        _conjunto[p] = bg;
}

int Idioma::findBigrama(const string& bg) const{
    int posicion = -1;

    for (int i=0; i<getSize(); i++){
        if (strcmp(getPosicion(i).getBigrama(), bg.c_str()) == 0)
            posicion = i;
    }

    return posicion;
}

void Idioma::ordenar(){
    ordenaAscFrec(_conjunto, _nBigramas);
    Bigrama aux;
    
    for (int i=0; i<getSize()/2; i++){
        aux = _conjunto[i];
        _conjunto[i] = _conjunto[getSize()-1-i];
        _conjunto[getSize()-1-i] = aux;
    }
}

ostream & operator<<(ostream & os, const Idioma & i){
    os << "MP-BIGRAMAS_IDIOMA-T-1.0\n" << i.getIdioma() << "\n" << i.getSize() << "\n";
    
    for (int j=0; j<i.getSize(); j++){
        os << i._conjunto[j].getBigrama() <<  " " << i._conjunto[j].getFrecuencia() << "\n";
    }
    
    return os;
}

istream & operator>>(istream & is, Idioma & i){
    string identificador, id, cad;
    int tam, frec;
    Bigrama bg;
    
    is >> identificador >> id >> tam;
    
    Idioma aux(tam);
    aux.setIdioma(id);
    
    for (int j=0; j<aux.getSize(); j++){
        is >> cad >> frec;
        bg.setBigrama(cad.c_str());
        bg.setFrecuencia(frec);
        aux.setPosicion(j, bg);
    }
    
    i.copiar(aux);
    
    return is;
}

bool Idioma::salvarAFichero(const char *fichero) const{
    bool salvado = false;
    ofstream fo;
    
    fo.open(fichero);
    
    if(fo){
        fo << *this;
        
        if(fo){
            salvado = true;
        }
    }
    
    return salvado;
}

bool Idioma::cargarDeFichero(const char* fichero){
    bool cargado = false;
    ifstream fentrada;

    fentrada.open(fichero);
    
    if(fentrada){
        fentrada >> *this;
        
        if (fentrada)
            cargado = true;
        
        fentrada.close();
    }
    
    return cargado;
}

void Idioma::copiar(const Idioma& otro){
    if(&otro!=this){
        if (this != NULL)
            liberarMemoria();
        if (otro._conjunto != NULL){
            this->_idioma = otro._idioma;
            this->_nBigramas = otro._nBigramas;
            this->_conjunto = new Bigrama[_nBigramas];

            for (int i=0; i<_nBigramas; i++){
                this->_conjunto[i] = otro._conjunto[i];
            }
        }
    }
}