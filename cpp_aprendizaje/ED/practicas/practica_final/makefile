MAIN=testdiccionario
TDA=diccionario
OBJ=./obj/
INCLUDE=./include/
FLAGS=-g -I$(INCLUDE)
DATA=./data/
BIN=./bin/
SRC=./src/

all:  $(BIN)$(MAIN).out  $(BIN)testletras.out

 $(BIN)$(MAIN).out: $(SRC)$(MAIN).cpp $(SRC)$(TDA).cpp $(INCLUDE)$(TDA).h
	g++ $(FLAGS) -o $@  $(SRC)$(MAIN).cpp $(SRC)$(TDA).cpp

 $(BIN)testletras.out: $(SRC)testletras.cpp $(SRC)letras.cpp $(INCLUDE)letras.h  $(INCLUDE)$(TDA).h
	g++ $(FLAGS) -o $@  $(SRC)testletras.cpp $(SRC)letras.cpp  $(SRC)$(TDA).cpp


doxygen:
	doxygen configure.doxy
	firefox ./doc/html/annotated.html
clear:
	rm -r $(OBJ)* $(BIN)* ./doc/html
	find . -name "*~" -delete

# VERSIÓN 1 

# $(BIN)$(MAIN).out:  $(OBJ)$(MAIN).o  $(OBJ)$(TDA).o
# 	g++ -g -o $@  $(OBJ)$(MAIN).o $(OBJ)$(TDA).o -I$(INCLUDE)

# $(OBJ)$(MAIN).o: $(SRC)$(MAIN).cpp
# 	g++ $(FLAGS) $^ -o $@

# $(OBJ)$(TDA).o: $(SRC)$(TDA).cpp $(INCLUDE)$(TDA).h
# 	g++ $(FLAGS) $< -o $@

# VERSIÓN 2

# $(BIN)$(MAIN).out:  $(SRC)$(MAIN).cpp  $(OBJ)$(TDA).o
# 	g++ $(FLAGS) -o $@  $(OBJ)$(TDA).o

# $(OBJ)$(TDA).o: $(SRC)$(TDA).cpp $(INCLUDE)$(TDA).h
# 	g++ -I$(INCLUDE) -c -o $@ $<
# clear:
# 	@rm $(BIN)* $(OBJ)* $(SRC)*~ $(INCLUDE)*~ *~


valgrind:
	valgrind --leak-check=yes $(BIN)$(MAIN).out < $(DATA)diccionario2.txt

testdiccionario:
	$(BIN)$(MAIN).out < $(DATA)diccionario1000.txt

testletras:
	$(BIN)$@.out 


