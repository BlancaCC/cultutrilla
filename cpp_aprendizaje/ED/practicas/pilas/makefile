INCLUDE = .
FLAGS = -g # flag de depuración
EXE = usopilas.out

$(EXE) : usopilas.cpp pila.cpp pila.h
	g++ -I$(INCLUDE) -o $(EXE) $(FLAGS) usopilas.cpp

valgrind:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./$(EXE)
