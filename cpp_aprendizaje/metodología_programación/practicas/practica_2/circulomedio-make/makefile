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
OPT=-Wall -g
# Nombre de la práctica
PRJ=practica2

# Las macros se usan en las reglas del makefile como si fuesen variables
# que se sustituyen por su valor definido anteriormente
all : $(BIN)/circulomedio 
$(BIN)/circulomedio : $(OBJ)/central.o lib/libformas.a
	g++ -o $(BIN)/circulomedio $(OBJ)/central.o -lformas -L$(LIB)

$(OBJ)/punto.o : $(SRC)/punto.cpp $(INC)/punto.h
	g++ $(OPT) -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -I$(INC) 
	
$(OBJ)/circulo.o : $(SRC)/circulo.cpp $(INC)/circulo.h $(INC)/punto.h
	g++ $(OPT) -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -I$(INC) 
	
$(OBJ)/central.o : $(SRC)/central.cpp $(INC)/punto.h $(INC)/circulo.h
	g++ $(OPT) -c $(SRC)/central.cpp -o $(OBJ)/central.o -I$(INC) 

$(LIB)/libformas.a : $(OBJ)/punto.o $(OBJ)/circulo.o
	ar -rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

