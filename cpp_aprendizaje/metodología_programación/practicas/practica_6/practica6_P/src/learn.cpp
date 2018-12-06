/** 
 * @file learn.cpp
 * @author DECSAI
*/

#include <iostream>
#include <cstring>
#include "ContadorBigramas.h"
#include "Idioma.h"
#include "Bigrama.h"
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Imprime mensaje de ayuda
*/
void pinta_mensaje() {
    cout << "Formato:" << endl;
    cout << "learn {-c|-a} [-l nombreIdioma] [-f ficheroSalida] texto1.txt texto2.txt texto3.txt .... " << endl;
    cout << "           aprende el codigo para el lenguaje nombreIdioma a partir de los ficheros texto1.txt texto2.txt texto3.txt ..." << endl;
    cout << endl;
    cout << "Parámetros:" << endl;
    cout << "-c|-a: operación crear fichero de idioma (-c) o añadir a fichero de idioma (-a)" << endl;
    cout << "-l nombreIdioma: idioma (unknown por defecto)" << endl;
    cout << "-f ficheroSalida:  nombre del fichero de salida (salida.bgx por defecto)" << endl;
    cout << "texto1.txt texto2.txt texto3.txt ....: nombres de los ficheros de entrada (debe haber al menos 1)" << endl;
}

int main(int argc, char *argv[]) {
	/// Cadena de caracteres válidos de ISO8859-1 para múltiples idiomas
    string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";    
    string crear="-c", aniadir="-a", nombrei="-l", nombrei2="unkown", nombref="-f", nombref2="out.bgr";
    vector<string> ficheros;
    Idioma id;
    ContadorBigramas cb(valid);
    bool error = false;
    
    if (argc >= 3){
        if (argv[1] == crear){
            if (argv[2] == nombrei){
                nombrei2 = argv[3];
                if (argv[4] == nombref){
                    nombref2 = argv[5];
                    if(argc > 6){
                        for (int i=6; i<argc; i++){
                            ficheros.push_back(argv[i]);
                        }
                    }
                    else
                        error = true;
                }
                else if(argc > 4) {
                    for (int i=4; i<argc; i++){
                        ficheros.push_back(argv[i]);
                        
                    }
                }
                else
                    error = true;
            }
            else if (argv[2] == nombref){
                nombref2 = argv[3];
                if(argc > 4){
                    for (int i=4; i<argc; i++){
                        ficheros.push_back(argv[i]);
                    }
                }
                else
                    error = true;
            }
            else if (argc > 2){
                for (int i=2; i<argc; i++){
                    ficheros.push_back(argv[i]);
                }
            }
            else
                error = true;
            
            if(!error){
                for (int i=0; i<ficheros.size(); i++){
                    cb.calcularFrecuenciasBigramas(ficheros[i].c_str());
                }
            
                id = cb.toIdioma();
                id.setIdioma(nombrei2);
                id.ordenar();
                id.salvarAFichero(nombref2.c_str());
            }
            else
                pinta_mensaje();
        }
        else if (argv[1] == aniadir){
            if (argv[2] == nombrei){
                nombrei2 = argv[3];
                if (argv[4] == nombref){
                    nombref2 = argv[5];
                    if(argc > 6){
                        for (int i=6; i<argc; i++){
                            ficheros.push_back(argv[i]);
                        }
                    }
                }
                else if(argc > 4){
                    for (int i=4; i<argc; i++){
                        ficheros.push_back(argv[i]);
                    }
                }
                else
                    error = true;
            }
            else if (argv[2] == nombref){
                nombref2 = argv[3];
                if(argc > 4){
                    for (int i=4; i<argc; i++){
                        ficheros.push_back(argv[i]);
                    }
                }
            }
            else if (argc > 2){
                for (int i=2; i<argc; i++){
                    ficheros.push_back(argv[i]);
                }
            }
            else
                error = true;
            
            if (!error){
                if (id.cargarDeFichero(nombref2.c_str())){
                    if (id.getIdioma() == nombrei2){
                        cb.fromIdioma(id);
            
                        for (int i=0; i<ficheros.size(); i++){
                            cb.calcularFrecuenciasBigramas(ficheros[i].c_str());
                        }
            
                        id = cb.toIdioma();
                        id.setIdioma(nombrei2);
                        id.ordenar();
                        id.salvarAFichero(nombref2.c_str());
                    }
                    else
                        pinta_mensaje();
                }
                else
                    pinta_mensaje();
            }
            else
                pinta_mensaje();
        }
        else
            pinta_mensaje();
    }
    else
        pinta_mensaje();
    
    return 0;
}
