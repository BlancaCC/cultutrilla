#Makefile rápidillo
all:
	g++ -o bin/positividad src/main.cpp src/celdas.cpp -I./include
clean:
	@sudo rm -rf obj/* bin/*  src/*~ data/*~ include/*~ *~
test:
	valgrind --leak-check=full ./bin/positividad
exe:
	./bin/positividad






# CC=g++
# CPPFLAGS=-Wall -I./includes #AQUÍ SE AÑADE LA CARPETA DE LOS INCLUDES

# DIR_BIN=./bin/
# DIR_OBJ=./obj/
# DIR_SCR=./src/
# DIR_H=./includes

# EXE=$(DIR_BIN)celdas_positivas
# _SRC=main.cpp celdas.cpp
# _OBJ=$(_SRC:.cpp=.o)
# _H=celdas.h

# SRC=$(DIR_SCR)$(_SRC)
# OBJ=$(DIR_OBJ)$(_OBJ)
# H=$(DIR_H)$(_H)

# .o : .cpp .h
# 	$(CC) -c $< -o $@ $(CPPFLAGS)





# # $(EXE): $(OBJ)
# # 	echo $(OBJ)
# # 	$(CC) $^ -o $@

# # #$^  hace refenrencia a todos los objetos de los que depende la regla

# # $(OBJ): $(SRC) $()
# # 	echo $(OBJ)
# # 	echo $(_OBJ)
# # 	echo $(SRC)
# # 	$(CC) -c  $(CPPFLAGS)  $< -o  $@ #$< hace referencia al primer elemento del que depende la regla
# # 	$(CC) -c $(OBJ) $(CPPFLAGS)
# # clean:
# # 	sudo rm -rf obj/* bin/* include/*~ src/*~

