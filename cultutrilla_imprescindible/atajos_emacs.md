## SITUACIONES DE PANTALLA
 combinación de teclas  | efecto
 --- 	      	 	| ---
 C-v			| Avanzar una pantalla completa
 M-v			| Retroceder una pantalla completa
 C-l			| El cursor arriba, abajo o en el centro

## CURSOR
 combinación de teclas  | efecto
 --- 	      	 	| ---
 C-P			| Línea anterior
 C-n 			| Línea siguiente
 C-b			| una pocición atrás
 C-f			| una posición adelante
 M-f			| una palabra alante
 M-b			| una palabra atrás
 C-a 			| retroceder al principio de una línea donde esté el cursor
 C-e 			| avanzar al final de la línea donde esté el cursor
 M-a			| retroceder al principo de una oración
 M-e			| avanzar al final de una oración
 M-<			| para moverse al comienzo del documento
 m-> 			| para moverse al final del documento
 
## COMANDOS NUMÉRICOS
 combinación            | efecto
 --- 	                | ---
 C-u <entero> <comando> | repite un atajo el entero veces ` ejemplo: C-u 6 C-f`
 M-<entero> <comando>   | igual ` M-3 M-e` este comando se utiliza menos al nos ser universal

## SI EMACS DEJA DE RESPONER

`C-g` tanto si emacs se ha quedado pillado, como para cancelar un atajo

## COMANDOS DESCATIVADOS

cuando tecle un comando desactivado se me preguntará si lo quiero ejecutar:
Espacio : para aceptar

## INSERTAR Y BORRAR

 combinación		  | efecto  
 --- 			  | ---
 C-u <entero> <caracter>  | inserta ese número de veces el caracter   
 c\-y	      		  | pega el último texto borrado
 c\<DEL> 		  | borra el carácter anterio
 c\-d			  | borra el carácter siguiente
 M-\<DEL>		  | Elimina la palabra inmediata antes del cursor  
 M\-d 			  | elimina la palabra inmediata después del cursor
 C-k			  | Elimina desde el cursor hasta el final de la línea
 M\-k			  | Elimina hasta el final de la oració
 C-SPC			  | desde el cursos hasta donde estoy para seleccionar
 c\-w			  | para borrar lo seleccionado
 M\-w			  | para copiar sin borrar

## Copiar y reemplazar
 `M% *string_a_reemplazar* <ENT> *string_nuevo* <ENT>`

Se marcarán los que cumplan la condición.
opciones dentro de copiar y reemplazar: 

 tecla 	      | utilidad
 --- 	      | ---
 `<SPC>`     | para reemplazar, otros también son 
 `<DEL> `      | obviar el siguiente
  `!	`   | reemplazarlas todas 
  ^	      | retroceder al maracado anterior
  . 	      | reemplazar el siguiente y salir del modo
  , 	      | muestra la situación actual del cursor, dejando de marcar el resto miestras se tenga pulsado
  n 	      | salir del modo  

## INSTALAR PAQUETES
### opción 1
`M-x list-packages <ENT>` abre el sistema de paquetes de emacs, 
`i`para marcarlos, 
`x `para ejecutar la instalación

### Opción 2
1- Ten e cuenta de tener `custom-set-variables` en el archivo init ( normalemente ` ~/.emacs `), si no es así copia-pega este código:
```
(require 'package)
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-archives
   (quote
    (("gnu" . "http://elpa.gnu.org/packages/")
     ("melpa-stable" . "http://stable.melpa.org/packages/")))))
(package-initialize)
```

2- Ejeuta emacs y escribe el siguiente código ` M-x package-refresh-contents `
3- Después instala un paquete cualquiera, por ejemplo: ` M-x package-install RET haskell-mode `
4- Ya está instalado, ahora solo te falta aprender haskell para disfrutar del paquete de ejemplo :)

## Abril shell
`M-x shell` este comando te abre la termianl desde emacs
`c-x b <enter> ` cierra la terminal  

## Recursos donde profuncizar  
	Nombre  | Descripción 
		--- | --- 
		[Notas sobre emacs](http://www.lapipaplena.org/emacs/) | Es maravilosa esta wed, altamente recomentdada, se agradece el trabajo bien hecho.  
		[combinaciones de teclado emacs](http://wwwae.ciemat.es/~oglez/webcms/oginfo/combinaciones_emacs.html) | Listado de combinaciones de teclado que alguien utiliza
