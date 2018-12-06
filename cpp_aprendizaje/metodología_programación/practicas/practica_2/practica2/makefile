
# Definición de macros para definir las carpetas de trabajo
BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
LIB=./lib
ZIP=./zip
DOC=./doc
# Opciones de compilación
# -Wall muestra todas las advertencias
# -g compila en modo "depuración"
OPT=-Wall
# Nombre de la práctica
PRJ=practica2



bin/intervalo :$(OBJ)/intervalo.o $(OBJ)/main.o # para construir inervalo necesitas ...archivos de los que depende
	g++ -o $(BIN)/intervalo $(OBJ)/main.o $(OBJ)/intervalo.o
$(OBJ)/intervalo.o: $(SRC)/intervalo.cpp $(INC)/intervalo.h
	g++ -c $(SRC)/intervalo.cpp -o $(OBJ)/intervalo.o -I$(INC)
$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/intervalo.h
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -Iinclude

clean: 
	@echo "Limpiando ... "
	rm -rf $(OBJ)/*.o $(BIN)/* $(LIB)/* $(ZIP)/* $(DOC)/latex $(DOC)/html

zip: clean
	@echo "Generando ZIP del proyecto " $(PRJ)
	zip -r $(ZIP)/$(PRJ).zip *

doxy:
	doxygen doc/intervalo.doxy










#APUNTE DE MAKEFILE TOMADOS EN CLASE
#bin/intervalo : obj/intervalo.o obj/main.o # para construir inervalo necesitas ...archivos de los que depende
#	g++ -o bin/intervalo obj/main.o obj/intervalo.o
#obj/intervalo.o: src/intervalo.cpp include/intervalo.h
#	g++ -c src/intervalo.cpp -o obj/intervalo.o -Iinclude
#obj/main.o: src/main.cpp include/intervalo.h
#	g++ -c src/main.cpp -o obj/main.o -Iinclude

#clean: #al ir vacío siempre se ejecuta SIEMPRE LLEVAR ESTA ORDEN
#	rm -rf doc/html	doc/latex obj/* bin/*

#otras regla adicionales
#doxy:
#	doxygen doc/intervalo.doxy
#	firefox doc/html/index.html

#zip: clean # empaquetame todo, pero antes me lo limpias DEBE DE EXISTIR FICHERO ZIP SI NO TE DA ERROR
#	zip -r zip/practica2.zip * 
