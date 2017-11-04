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

[Código de ejemplo](https://github.com/BlancaCC/cultutrilla/blob/master/cpp_aprendizaje/input_output.cpp)
