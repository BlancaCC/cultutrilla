/** 
 * @file main.cpp
 * @author DECSAI
 * @warning Código incompleto
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"

using namespace std;

int main() {
  char s[60]; s[2] = '\0';
    int frec, nv1, nv2, nv3;
    Bigrama *v1=NULL, *v2=NULL, *v3=NULL;
    
    // Lee número de elementos del primer vector
    // Lee el primer vector
    cin >> nv1;
    v1 = new Bigrama [nv1];
    for ( int i = 0; i< nv1 ; i++)
      {
	cin >> s[0] >> s[1] >> frec;
	v1[i].setBigrama( s );
	v1[i].setFrecuencia( frec);
	
      }
    
   
    // Lee número de elementos del segundo vector
    // Lee el segundo vector
    cin >> nv2;
    v2 = new Bigrama [nv2];
    for ( int i = 0; i< nv2 ; i++)
      {
	cin >> s[0] >> s[1] >> frec;

	v2[i].setBigrama( s );
	v2[i].setFrecuencia( frec);
      }
    
    cout << endl <<"Contenido de v1" << endl; imprimeBigramas(v1, nv1);
    cout << endl <<"Contenido de v2" << endl; imprimeBigramas(v2, nv2);
   
    // Posibles operaciones intermedias sobre v1 o v2

    ordenaAscBigr(v1 , nv1 );
    ordenaAscBigr(v2 , nv2 );

    nv3 = nv1;
    v3 = new Bigrama [nv3];
    
    // ---
    sumaBigramas(v1, nv1, v1, nv1, v3, nv3);
    ordenaAscFrec(v3, nv3);
    cout << endl <<"Contenido de v3" << endl;  imprimeBigramas(v3, nv3);

    // Limpieza de memoria
    delete [] v1;
    v1 = NULL;

    delete [] v2;
    v2 = NULL;

    delete [] v3;
    v3 = NULL;

    
    return 0;
}

