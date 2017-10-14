## COMANDO APARIENCIA SHELL 

- C-l limpiar terminal
- clear limpiar terminal

## APLICACIONES DESDE TERMINAL

- <programa> &  lo ejecuta en "backgraund" dejando disponible la terminal
- xdg-open <archivo> abre ese archivo con el programa predeterminado
 
## Comados relacionados con archivos y direcctorios

- **ls**

- **cd**

- **pwd** Imprime el camino absulo del direcctorio actual

- **mkdir** Y **rmdir** rmdir -r borra si tienes también archivos dentro

- **cat**

- **cd <archivo1> <archivo2>**

- **mv**

- **file** muestra el tipo de archivo.

- **more** **pager**  **pg**  visualiza un archivo fraccionándolo en la pantalla cada vez.

- **rm**

- **touch** modifica fecha y hora de un archivo, si no los crea

- **clear** borra el contenido de la terminal actual

- **tail** -<entero> <archivo> muestra las líneas finales de un fichero

- **head** -<entero> <archivo> muestras las "numero de líneas iniciales de un fichero.

- **sort** <archivo> ordena bajo un critero elegido las líneas de un archivo.

- **wc** cuenta el número de algo de un fichero

-**echo** escribe un mensaje en termminal

- **printf ** muestra en el bash lo que se especifique

- secuencia de escape

  - \b espacio atrás 

  - \n nueva línea

  - \t \'  \\  \0n

- código de formato

  - %d número con signo

  - %f  número en coma flotante

  - %q entrecomilla una cadena

  - %s muestra una cadena sin entrecomillar

  - %x núemro en hexadecimal

  - %o número en octal




## Modificación de los permisos de un archivo

- **chmod** [u,g,o,a][-+][r,w,x]

## Metacaracteres

- ** < nombre ** redirecciona la entrada de una orden para que la tenga el ficero nombre

- ** > nombre ** redirige la salida de una orede, si existe lo sobreescribe

- ** &> nomre** la salida estándar y la de error

- ** >> nombre** igual que la simple pero escribe al final de fichero nombre

- ** &>> nombre**

- ** | ** crea un cauce entre varias órdes, la salida de una es la entrada de la otra

- ** |& ** crea un cauce pero con los errores también

- ** ;** separador de órdenes que se ejecutan secuencialmente

- () aislar órdenes

- && separador de órdenes en el que uno se ejecuta solo si la orden primera es exitosa

- || separador de órdenes donde la segunda solo se ejecuta si falla la primera


## Variables especiales

- $BASH contiene la ruta de acceso del terminal

- $HOME alamacena el directorio raís de la carpeta home

- $PATH guarda el camino local de las órdenes

- $? contiene el código de retorno hacia la última orden o guión

- export <variable> para que la variable no sea local 

## Alias

- **alias** para crear una orden predetermina o cambiar el nombre a una orden

- **unalias** para bprrar el nombre de una orden

## find y grep

- **find** para buscar por la estructura de directorios los archivos quebcumplan con criterios especificados

- **grep** permite buscar cadena en archivos

  - -x línea que coincidan totalmente

  - -v línea que no contengan dicho patrón

  - -c recuento de las línea que cumplen con dicho patrón

  - -i ignora la distinción entre mayúscula sy minúsculas

  - -n añade el número de líneas en el fichero fuente

  - -l selecciona solo los nombre de los fichero con la coincidencia

  - -e especial para el uso de patrones múltiples

