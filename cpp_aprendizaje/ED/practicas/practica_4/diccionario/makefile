
MAIN=usodiccionario
INCLUDE=./include/
FLAGS=-g -I$(INCLUDE)
DATA=./data/
BIN=./bin/
SRC=./src/

$(BIN)$(MAIN).out:  $(SRC)$(MAIN).cpp $(INCLUDE)diccionario.h $(SRC)diccionario.cpp
	g++ $(FLAGS) -o $@ $(SRC)$(MAIN).cpp

clear:
	rm $(BIN)*

valgrind:
	valgrind --leak-check=yes $(BIN)$(MAIN).out < $(DATA)data.txt
test:
	$(BIN)$(MAIN).out < $(DATA)data.txt



