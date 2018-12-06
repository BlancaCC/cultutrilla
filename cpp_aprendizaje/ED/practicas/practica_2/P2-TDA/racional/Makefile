INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c 

$(BIN)/usoRacional : $(OBJ)/usoRacional.o $(LIB)/libracional.a
	$(CXX) -o $(BIN)/usoRacional $(OBJ)/usoRacional.o -I$(INCLUDE) -L$(LIB) -lracional

$(LIB)/libracional.a : $(OBJ)/Racional.o
	ar rvs $(LIB)/libracional.a $(OBJ)/Racional.o

$(OBJ)/Racional.o : $(SRC)/Racional.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Racional.o $(SRC)/Racional.cpp -I$(INCLUDE)

$(OBJ)/usoRacional.o : $(SRC)/usoRacional.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usoRacional.o $(SRC)/usoRacional.cpp -I$(INCLUDE)
 #************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
