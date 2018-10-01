# Doxygen

Doxygen es una herramienta para generar documentación de un proyecto, a traves de comentarios dentro del propio código. Soporta lenguajes como C, Objetive-C, C#, PHP, Java, Python, entre otros.

Es capaz de generar el codigo en formato LaTeX y como una página web HTML.

## Instalación

Se puede instalar en distintas distribuciones linux.

### Arch Linux (y derivadas como Antergos, Manjaro, ...)

`sudo pacman -S doxygen`

### Debian (y derivadas como Ubuntu, LMDE, ...)

`sudo apt install doxygen`

### Fedora (y derivadas)

`sudo dnf install doxygen`

## Uso

Es tan facil como usar comentarios en el codigo, de la siguiente forma para cada funcion:


    /**
    *   @brief Descripcion de la tarea de la funcion
    *   @param x1 Parametro 1 de la funcion
    *   @param x2 Parametro 2 de la funcion
    *   @pre   Precondición
    *   @return Cosas que retorna la funcion
    */


Tambien se admite poner el autor al principio:


    /**
    *   @author Antonio David Villegas Yeguas
    *
    */


Una vez realizado esto, basta con ejecutar:

`doxygen archivo`

Y te generara la documentacion tanto en LaTeX como en HTML.