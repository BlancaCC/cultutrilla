#include <iostream>

using namespace std;

int main()
{
  cout << "bbb"<< endl;
}
/** 

DIR_SRC=src/
DIR_OBJ=obj/
DIR_BIN=bin/

SRC=`ls src`
OBJ=$(SRC.cpp=.o)
EXE=positivo

$(DIR_BIN)$(EXE):obj/main2.o #$(DIR_OBJ)$(OBJ)
	$(CC) $^ -o $@ #$^  hace refenrencia a todos los objetos de los que depende la regla
obj/main2.o : src/main2.cpp #$(DIR_OBJ)$(OBJ): $(DIR_SRC)$(SRC)
	$(CC) $(CPPFLAGS) $< -o $@ #$< hace referencia al primer elemento del que depende la regla
clean:
	sudo rm -rf obj/* bin/* include/*~ src/*~

 **/
