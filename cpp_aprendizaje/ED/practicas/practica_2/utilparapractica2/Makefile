INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/prueba

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/prueba : $(OBJ)/pruebacronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o 
	$(CXX) -o $(BIN)/prueba $(OBJ)/pruebacronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o

$(OBJ)/pruebacronologia.o : $(INC)/Cronologia.h $(INC)/Fecha_Historica.h $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(OBJ)/Cronologia.o : $(INC)/Cronologia.h $(INC)/Fecha_Historica.h $(SRC)/Cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp

$(OBJ)/Fecha_Historica.o : $(INC)/Fecha_Historica.h $(SRC)/Fecha_Historica.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Fecha_Historica.o $(SRC)/Fecha_Historica.cpp

# ************ Limpieza ************		
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/* doc/html/*
