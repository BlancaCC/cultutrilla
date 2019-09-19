############################################################
#         Makefile para el proyecto scrabble jugador
#
# author: Blanca Cano Camarero
# date: enero 2019
# 
# instrucciones básicas:
#  make           para construir todo el proyecto
#  make clear     limpiar archivos no necesarios
#  make exe       ejecutar juego
#  make doxy      genera la documentación
#  make test      ejecuta todos los test 
#
############################################################



########## construcción programa y test de prueba ########

OBJ=./obj/
INCLUDE=./include/
FLAGS=-g -I$(INCLUDE)
DATA=./data/
BIN=./bin/
SRC=./src/

all:  $(BIN)testdiccionario.out $(BIN)testletras.out $(BIN)testbiblioteca.out  $(BIN)testcombinaciones.out $  $(BIN)testia.out

## ~~~~~~~~~~ binarios de los test ~~~~~~~~~~
$(BIN)testdiccionario.out: $(OBJ)testdiccionario.o $(OBJ)diccionario.o
	g++ $^ -o $@

$(BIN)testletras.out: $(OBJ)testletras.o $(OBJ)letras.o $(OBJ)diccionario.o
	g++ $^ -o $@


$(BIN)testbiblioteca.out: $(OBJ)testbiblioteca.o $(OBJ)biblioteca.o  $(OBJ)diccionario.o
	g++ -g $^ -o $@

$(BIN)testcombinaciones.out: $(OBJ)testcombinaciones.o $(OBJ)combinaciones.o 
	g++ -g $^ -o $@

$(BIN)testia.out: $(OBJ)testia.o $(OBJ)ia.o $(OBJ)biblioteca.o $(OBJ)combinaciones.o  $(OBJ)diccionario.o $(OBJ)letras.o
	g++ -g $^ -o $@



## ~~~~~~~~ objetos de los test ~~~~~~~~~~
$(OBJ)testdiccionario.o: $(SRC)testdiccionario.cpp  $(OBJ)diccionario.o
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)testletras.o: $(SRC)testletras.cpp $(OBJ)letras.o
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)testbiblioteca.o: $(SRC)testbiblioteca.cpp  $(OBJ)biblioteca.o 
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)testia.o: $(SRC)testia.cpp $(OBJ)ia.o $(OBJ)letras.o
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)testcombinaciones.o: $(SRC)testcombinaciones.cpp $(OBJ)combinaciones.o
	g++ -c $< -o $@ -I$(INCLUDE)


## ~~~~~~~~~~ objetos esenciales ~~~~~~~~~~ 
$(OBJ)diccionario.o: $(SRC)diccionario.cpp $(INCLUDE)diccionario.h
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)letras.o: $(SRC)letras.cpp $(INCLUDE)letras.h
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)biblioteca.o: $(SRC)biblioteca.cpp $(INCLUDE)biblioteca.h
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)combinaciones.o: $(SRC)combinaciones.cpp $(INCLUDE)combinaciones.h
	g++ -c $< -o $@ -I$(INCLUDE)

$(OBJ)ia.o: $(SRC)ia.cpp $(INCLUDE)ia.h
	g++ -c $< -o $@ -I$(INCLUDE)	


################### utilidades ##################
doxygen:
	doxygen ./doc/configure.doxy 
	firefox ./doc/html/annotated.html &
clear:
	find . -name "*~" -delete
	@rm -r $(OBJ)* $(BIN)* ./doc/html ./doc/latex 

#########    comando para ejecutar test    ##########

testall:
	@echo "TEST DE PRUEBA DE TODOS LOS MÓDULOS"
	@echo "Realizado por Blanca Cano Camararo "
	@echo "Enero de 2019    (con mucho amor)"
	@echo ""

	@echo "============================================="
	@echo " 		   test diccionario "
	@echo "============================================="
	 $(BIN)testdiccionario.out < $(DATA)diccionario1000.txt

	@echo "============================================="
	@echo " 		      test letras "
	@echo "============================================="
	$(BIN)testletras.out ./data/estadisticas.txt ./data/letras.txt < $(DATA)diccionario1000.txt

	@echo "============================================="
	@echo " 		    test biblioteca "
	@echo "============================================="
	valgrind --leak-check=yes $(BIN)testbiblioteca.out  <  $(DATA)diccionario1000.txt	



valgrind:
	valgrind --leak-check=yes $(BIN)testcombinaciones.out

testdiccionario:
	$(BIN)$testdiccionario.out < $(DATA)diccionario1000.txt

testletras:
	$(BIN)$@.out ./data/estadisticas.txt ./data/letras.txt < $(DATA)diccionario1000.txt


testcombinaciones:
	$(BIN)$@.out

testbiblioteca:
	$(BIN)$@.out <  $(DATA)diccionario1000.txt

testia:
	$(BIN)$@.out <  $(DATA)diccionario1000.txt


