SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) 
SOURCES = fechahistorica.cpp uso_fechashistoricas.cpp
_DEPS = fechahistorica.h

EXE = uso_fecha

#all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************\
documentacion:\
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************


DEPS = $(patsubst %,$(INC)/%,$(_DEPS))
SRCS = $(patsubst %,$(SRC)/%,$(SOURCES))
OBJECTS = $(SOURCES:.cpp=.o)
OBJS = $(patsubst %,$(OBJ)/%,$(OBJECTS))

$(OBJ)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(BIN)/$(EXE): $(OBJS)
	$(CXX)  $(CPPFLAGS) -o $@ $^

#otras regla adicionales
doxy:
	doxygen doc/intervalo.doxy
	firefox doc/html/index.html

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
exe:
	./$(BIN)/$(EXE)
