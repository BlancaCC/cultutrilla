/** 
 * @file   intervalo.cpp
 * @author decsai.ugr.es
 *
 */


#include <iostream>
#include <assert.h>
using namespace std;

class Intervalo{
private:
    bool cerradoInf;
    bool cerradoSup;
    double cotaInf;
    double cotaSup;

    /**
     * @brief comprueba que los argumentos definen un intervalo correcto
     * @param cotaInferior
     * @param cotaSuperior
     * @param cerradoInferior
     * @param cerradoSuperior
     * @pre cotaInferior < cotaSuperior 
     * @pre cotaInferior == cotaSuperior && cerradoInferior == cerradoSuperior 
     * @return @retval true si correcto @retval false en otro caso
     */
    bool validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
public:
    /** 
     *  @brief Crea un intervalo vacio 
     */
    Intervalo();
    /** 
     * @brief Crea un Intervalo cerrado 
     * @param cotaInferior
     * @param cotaSuperior
     * @pre El intervalo es válido
     */
    Intervalo(double cotaInferior, double cotaSuperior);
    /** 
     * @brief Crea un intervalo cualquiera 
     * @param cotaInferior
     * @param cotaSuperior
     * @param cerradoInferior
     * @param cerradoSuperior
     * @pre El intervalo es válido
     */
    Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior);
    /** 
     * @brief Devuelve la cota inferior del intervalo
     * @return El valor de la cota
     */
    double getCotaInf()const ;
    /** 
     * @brief Devuelve la cota superior del intervalo
     * @return El valor de la cota
     */
    double getCotaSup()const ;
    /** 
     * @brief Consulta si el intervalo es cerrado en su cota inferior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool esCerradoInf()const ;
    /** 
     * @brief Consulta si el intervalo es cerrado en su cota superior
     * @return @retval true si es cerrado @retval false si es cerrado
     */
    bool esCerradoSup()const ;
    /** 
     * @brief Consulta si el intervalo almacenado es vacío o no
     * @return @retval true si es un intervalo vacío, @retval false en otro caso 
     */
    bool esVacio()const ;
    /** 
     * @brief Consulta si un determinado valor está dentro del intervalo
     * @param n El valor consultado
     * @return @retval true si el valor @p n pertenece al intervalo, @retval false en otro caso 
     */
    bool estaDentro(double n)const ;


};

/** 
* @brief Imprime los valores de un intervalo de forma visual según lo indicado en el guión
* @param i El intervalo
*/
void escribir(const Intervalo &i);

/** 
* @brief Lee los valores del intervalo según el formato indicado en el guión
* @param i El intervalo
*/
void leer(Intervalo &i);

Intervalo::Intervalo(double cinf,double csup){
	assert (validar(cinf,csup, true, true));
	cotaInf = cinf;
	cotaSup = csup;
	cerradoInf = true;
	cerradoSup = true;
}



int main(){
	int nintervalos;
	Intervalo vacio;
	Intervalo punto(1,1);
	Intervalo interv[10];

	// Lectura de datos 
	cout << endl<< "Cuantos intervalos se van a introducir? (max 10):";
	do{
		cin >> nintervalos;
	} while (nintervalos >10);

	cout << endl << "Introduce [ o ( cotaInferior, cotaSuperior ) o ]";
	for(int i=0; i < nintervalos; i++)
		leer(interv[i]);

	// Comprobaciones
	cout << endl << "Comprobando intervalo vacio"<< endl;
	escribir(vacio);
	if (vacio.esVacio())
		cout << " Es vacío " << endl;
	else
		cout << " No es vacío " << endl;
	escribir(punto);
	if (punto.esVacio())
		cout << " Es vacío " << endl;
	else
		cout << " No es vacío " << endl;

	// Dado un conjunto de valores −1, −0.001, 0, 5.7, 9.6, 10
	double v[]= {-1, -0.001, 0, 5.7, 9.6, 10};
	int numvalores = 6;
	cout << endl;
	for(int i=0; i < nintervalos; i++){
		escribir(interv[i]);
		cout << endl << "Valores dentro del intervalo:";
		for (int j= 0; j < numvalores; j++){
			if (interv[i].estaDentro(v[j]))
				cout << v[j] <<" ";
		}
		cout << endl << "Valores fuera del intervalo:";
		for (int j= 0; j < numvalores; j++){
			if (!interv[i].estaDentro(v[j]))
				cout << v[j] <<" ";
		}
		cout << endl;
	}
	return 0; 
}
