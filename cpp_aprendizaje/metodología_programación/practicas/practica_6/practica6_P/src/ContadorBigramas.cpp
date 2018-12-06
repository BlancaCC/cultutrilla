/**
 * @file ContadorBigramas.cpp
 * @author Paula Villanueva Nuñez
 */

#include <cstring>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include "ContadorBigramas.h"

using namespace std;

ContadorBigramas::ContadorBigramas(const std::string& caracteresValidos){
    _caracteresValidos = caracteresValidos;
    _bigramas = NULL;
    reservarMemoria(caracteresValidos.size());
    
    for (int i=0; i<getSize(); i++){
        for (int j=0; j<getSize(); j++){
            _bigramas[i][j] = 0;
        }
    }
}

ContadorBigramas::ContadorBigramas(const ContadorBigramas & orig){
    copiar(orig);
}

ContadorBigramas::~ContadorBigramas(){
    liberarMemoria();
}

int ContadorBigramas::getSize() const{
    return _caracteresValidos.size();
}

int ContadorBigramas::getBigramasActivos() const{
    int activo = 0;
    
    for (int i=0; i<getSize(); i++){
        for (int j=0; j<getSize(); j++){
            if (_bigramas[i][j] > 0)
                activo++;
        }
    }
    
    return activo;
}

bool ContadorBigramas::addBigrama(const char cadena[], int frecuencia){
    int fila, col;
    bool exito, encontrado, aniadido;
    
    for (int i=0; cadena[i+1]!='\0'; i++){
        encontrado = false;
        exito = false;
        
        for (int j=0; j<getSize() && !encontrado; j++){
            if (cadena[i] == _caracteresValidos[j]){
                fila = j;
                encontrado = true; 
            }
        }
        
        for (int k=0; k<getSize() && encontrado; k++){
            if (cadena[i+1] == _caracteresValidos[k]){
                col = k;
                exito = true;
            }
        }
        
        if (exito){
            if (frecuencia == 0)
                _bigramas[fila][col] = _bigramas[fila][col] + 1;
            else
                _bigramas[fila][col] = _bigramas[fila][col] + frecuencia;
            
            aniadido = true;
        }
        else
            aniadido = false;
    }
    
    return aniadido;
}

ContadorBigramas& ContadorBigramas::operator=(const ContadorBigramas& orig){
    this->_caracteresValidos = orig._caracteresValidos;
    this->_bigramas = new int*[orig.getSize()];
    
    for (int i=0; i<orig.getSize(); i++){
        this->_bigramas[i] = new int[orig.getSize()];
    }
    
    for (int i=0; i<getSize(); i++){
        for (int j=0; j<getSize(); j++){
            _bigramas[i][j] = orig._bigramas[i][j];
        }
    }
    
    return *this;
}

bool ContadorBigramas::calcularFrecuenciasBigramas(const char* nfichero){
    bool cargado = false;
    char cadena[60];
    ifstream fentrada;

    fentrada.open(nfichero);
    if(fentrada){
        cargado = true;
        
        while (!fentrada.eof()){
            fentrada >> cadena;
            
            for (int i=0; cadena[i]!='\0'; i++){
                cadena[i] = tolower(cadena[i]);
            }
            
            addBigrama(cadena);
        }
        
        fentrada.close();
    }
    
    return cargado;
}

Idioma ContadorBigramas::toIdioma() const{
    Idioma traducir(getBigramasActivos());
    int pos=0;
    Bigrama insertar;
    char cad[60];
    
    for (int i=0; i<getSize(); i++){
        for (int j=0; j<getSize(); j++){
            if (_bigramas[i][j] != 0){
                cad[0] = _caracteresValidos[i];
                cad[1] = _caracteresValidos[j];
                cad[2] = '\0';
                insertar.setBigrama(cad);
                insertar.setFrecuencia(_bigramas[i][j]);
                traducir.setPosicion(pos,insertar);
                pos++;
            }
        }
    }
    
    return traducir;
}

void ContadorBigramas::fromIdioma(const Idioma& i){
    for (int j=0; j<i.getSize(); j++){
        addBigrama(i.getPosicion(j).getBigrama(), i.getPosicion(j).getFrecuencia());
    }
}

void ContadorBigramas::reservarMemoria(int n){
    liberarMemoria();
    _bigramas = new int*[n];
    
    for (int i=0; i<n; i++){
        _bigramas[i] = new int[n];
    }
}

void ContadorBigramas::liberarMemoria(){
    if(_bigramas!=NULL){
        for(int i=0;i<getSize();++i)
            delete[] _bigramas[i];
        delete[] _bigramas;
    }
}

void ContadorBigramas::copiar(const ContadorBigramas& otro){
    this->_caracteresValidos = otro._caracteresValidos;
    reservarMemoria(otro.getSize());
    
    for (int i=0; i<getSize(); i++){
        for (int j=0; j<getSize(); j++){
            _bigramas[i][j] = otro._bigramas[i][j];
        }
    }
}