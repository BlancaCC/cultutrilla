## Conversión de datos 
Conversión de tipos`static_cast<dataTypeName>(expresión) ` `static_cast<double>(25)`

## I/O Sream and Standard I/O Device
### Input y output



 Función                                | Utilidad                                       |Ejemplo    
  ---                                   | ---                                            | ---
 `istreamVar.get(varChar) `              | Lee un carácter                                | `cin.get(ch) `                         
 `istreamVar.ignore(intExp , chEx)`      | intExp: número de carácteres a ignorar <br>  chExp: caráceter a partir del cual deja <br> de ignorar.  Prevalece chExp    | `cin.ignore(100, '\n' ) `           
`istreamVar.putback(ch)`                | Incluye último carárcter                       |   
`ch = istreamVar.peek()`                | Devuelve el siguiente carácter sin quitarlo    |    
 `istreamVar.clear();`                  | Cuando hay un error de lectura, el<br>sitema ignora todos, esta función lo resaura    	 |`cin.clear()`                          
 ` getline(istreamVar , strVar) ` 	| Permite leer string que contengan espacios   	 | ` getline( cin , miString )`
 
[Código de ejemplo](https://github.com/BlancaCC/cultutrilla/blob/master/cpp_aprendizaje/ejemplosBasicos/input_output.cpp)

#### File input/output
Lee y escribe en fichero. Pasos a segir:
1. Include en la cabecera la biblioteca `#include<fstream>`
2. Declara las variables que contendrán al fichero y su dirección `ifstream inData` si es de entrada y `oftream outData` si es de escritura
3. Abre los ficheros `filestreamVariable.open("sourceName")` ejemplo:` inData.open("disk:\\fichero.txt")`
4. Lee y escribe en los ficheros con los operadores `<<`(escritura) y `>>` (lectura).
5. Cierra los ficheros `nombre.close()`

[Ejemplo de trabajo con fichero y de getline](https://github.com/BlancaCC/cultutrilla/blob/master/cpp_aprendizaje/ejemplosBasicos/fstream.cpp)

### Output and formating output


 Función                                | Utilidad						 |Ejemplo    
  ---                                   | ---                                           	 | ---
  `setprecition(<integer>)`		| número de decimales a utilizar, requiere *iomanip* 	 | `#include<iomanip> [omito código] cout<<setprecision(2)`
  fixed 				| vuelve al estandar  		  	   		 | `cout.unsetf(ios::fixed)`
 scientific 				| números decimales en formato científico 		 | ---
  showpoint				| supone que la perte decimal es cero, y así la muestra  | `cout << showpoint`
 setw 					| fija un tamaño específico de columnas	     		 | `cout << setw(5) << x << endl `
 flush 					| permite que todos los caracteres de un buffer se <br> escriban y limpia el buffer <br> hace lo mismo que endl pero sin saltar de línea	| ` cout << "holaaaa " << flush ; `
 `setfill(<character>)			| sustituye los espacios 	      	 	   	| `cout << setfill(#); `
 `ostreamVar << left ` or right		| alinea hacia la izquierda o hacia la derecha		|  `cout << left `
 `cout.unsetf(manipulador) 		| Desactiva un manipulador    	       			| `ostreamVar.unsetf(ios::left)`
 `getline(istreamVar , strVar )`	| Lee hasta que encuentra un salto de línea 		| `getline( cin , linea )`

[Código de ejemplo para output](https://github.com/BlancaCC/cultutrilla/blob/master/cpp_aprendizaje/ejemplosBasicos/output.cpp)


## Bibliografía

 Libro								| Autor		| Apreciaciones
 --- 								| --- 		| ---
 *C++ programing: Program desing including data structures* 	| D.S. Malik 	| Bien ejemplificado, nivel muy básico
