# Introducción a latex para principiantes  
> Como ya habrá tiempo para pelearse con emacs autex y orgmode he aquí un manual basiquísimo de latex, a modo de resumen de lo que conozco de latex  
También puedes utilizar mis plantillas 
<a href="gummi.tex"> Plantilla básica <\a>

## Primeros pasos  
Las distribuciones de linux ya suelen traer instalada una distribución de latex, pero para asegurarnos de que no nos faltan paquetes y enloquecer en busca de erros sintáxticos haga usted un 
`sudo apt-get install texlive-full`

Mientras se instalan, disfrute usted de la buena lectura de esta guía básica (aunque con lo que tarda te recomiendo ir a por un té)

Al pricipio, cuando no estamos familiriacidados con la sintaxis la forma más rápida de trabajar es ver lo que se está haciendo Gnummi es una gran opción para ello:  

`sudo apt-get install gummi`  Así de simple

## Estructura de un documento latex  

La estructura mínima para un docuemnto en español 

```tex
\documentclass[a4paper , 11pt, spanish ]{article}

% Codificación e idioma, para las tildes crucial
\usepackage[utf8]{inputenc}
\usepackage[spanish]{babel}
\usepackage[T1]{fontenc}
\usepackage{textcomp}\documentclass[a4paper , 11pt, spanish ]{article}

%comenzo del cuerpo 
\begin{document}
Texto súper 
\end{document}
```

### Órdenes y macros  
Instrucciones que comienzan por el caracter \ 

Sintaxis | Significado   
--- | ---  
\title{TÍTULO} | Escribir títulos  
\date | Escribir la fecha  
\author | Para autores 

## Salto de línea y de página   

Sintaxis | Utilidad  
---  | ---
\\ | Nuevo párrafo  
\\* | Nueva línea sin párrafo  
\newpage | Para saltar a na nueva página
## Fórmulas en latex

la fórmula se de una línea se pueden escribir entre llaves, la otras entre `\[ ... ]\ ` 

 Sintaxis		        | significado
 --- 			   	| ---
 `\sum_{abajo}^{arriba}` 	| sumatoria
 `\prod_{subíndice}^{supe}` 	| productorio
 \in 				| pertenece  

## Alfabeto griego

 letra		| sintaxis
 --- 		| ---
 \alpha 	| `\alpha`
 \beta 		| `beta`

## Tipografías y estilos varios  

### Familias  
Este nombre es el que recoge una variación de fuentes de Latex 

Sintaxis  | Significado  
--- | ---  
\rmfamily | letras con remate  
\sffamily | letras sin remate  
\ttfamily | letras mecanografiadas  

## Fuentes de aprendizaje  

Página | Apreciación  
--- | --- 
[ wikibook latex ](https://es.wikibooks.org/wiki/Manual_de_LaTeX)  | Altamente recomenda: amplia, clara y con ejemplo  
[latex fácil ](http://nokyotsu.com/latex/curso.html) | Aunque un tanto anticuada, muy buena para aprender también, un blog cuidado con gran variedad de ejemplos  
[ wed muy del 200 ](http://www.personal.ceu.hu/tex/)  | Para consultas puntuales, te redirecciona a otras páginas  
