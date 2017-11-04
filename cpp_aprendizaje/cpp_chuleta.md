## Conversión de datos 
Conversión de tipos`static_cast<dataTypeName>(expresión) ` `static_cast<double>(25)`
Función **get** , lee datos de tipo carácter, cin puede acceder a ella: 

## I/O Sream and Standard I/O Device
### Input y output



 Función                                | Utilidad                                       |Ejemplo                                
 `isreamVar.get(varChar) `              | Lee un carácter                                | `cin.get(ch) `                         
 `istreaVar.ignore(intExp , chEx)`      | intExp: número de carácteres a ignorar <br>  chExp: caráceter a partir del cual deja <br> de ignorar.  Prevalece chExp    | `cin.ignore(100, '\n' ) `           
`istreamVar.putback(ch)`                | Incluye último carárcter                       |   ---
`ch = istreamVar.peek()`                | Devuelve el siguiente carácter sin quitarlo    |    --- 
 `istreamVar.clear();`                  | Cuando hay un error de lectura, el     	 |`cin.clear()`                          
|                                       |sitema ignora todos, esta función lo resaura    |  ---

(Código de ejemplo)[]