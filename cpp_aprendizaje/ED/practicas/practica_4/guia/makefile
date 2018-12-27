MAIN=usoguia
TDA=guiatlf
OBJ=./obj/
INCLUDE=./include/
FLAGS=-g -I$(INCLUDE)
DATA=./data/
BIN=./bin/
SRC=./src/

$(BIN)$(MAIN).out:  $(SRC)$(MAIN).cpp  $(OBJ)$(TDA).o
	g++ $(FLAGS) -o $@ $^

$(OBJ)$(TDA).o: $(SRC)$(TDA).cpp $(INCLUDE)$(TDA).h
	g++ -I$(INCLUDE) -c -o $@ $<
clear:
	@rm $(BIN)* $(OBJ)* $(SRC)*~ $(INCLUDE)*~ *~

valgrind:
	valgrind --leak-check=yes $(BIN)$(MAIN).out #< data.txt
test:
	$(BIN)$(MAIN).out  < $(DATA)guia2.txt



# MAKEFILE QUE NOS DIERON: 
# INCLUDE = .

# usoguia : usoguia.cpp 
# 	g++  -o usoguia -I$(INCLUDE) usoguia.cpp 

