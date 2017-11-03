## 
Conversión de tipos`static_cast<dataTypeName>(expresión) ` `static_cast<double>(25)`
Función **get** , lee datos de tipo carácter, cin puede acceder a ella: 
 
## Input y output
` istreamVar.get(varChar) ` `cin.get(ch1)`
Descartar parte de la entrada `istreamVar.ignore(intExp, chExp) ``cin.ignore(100,'\n')`
intExp: número de esteros a ignorar, prevalece chExp
chExp: carácter a partir del cual deja de ignorar 
`istreamVar.putback(ch) ` permite poner los últimos caracteres 
`ch = istreamVar.peek() ` devuelve el siguiente carácter sin quitarlo
