bin/intervalo : obj/intervalo.o obj/main.o # para construir inervalo necesitas ...archivos de los que depende
	g++ -o bin/intervalo obj/main.o obj/intervalo.o
obj/intervalo.o: src/intervalo.cpp include/intervalo.h
	g++ -c src/intervalo.cpp -o obj/intervalo.o -Iinclude
obj/main.o: src/main.cpp include/intervalo.h
	g++ -c src/main.cpp -o obj/main.o -Iinclude

clean: #al ir vacío siempre se ejecuta SIEMPRE LLEVAR ESTA ORDEN
	rm -rf doc/html	doc/latex obj/* bin/*

#otras regla adicionales
doxy:
	doxygen doc/intervalo.doxy
	firefox doc/html/index.html

zip: clean # empaquetame todo, pero antes me lo limpias DEBE DE EXISTIR FICHERO ZIP SI NO TE DA ERROR
	zip -r zip/practica2.zip * 
#para crear una biblioteca, la ventaja es que a la hora de enlazar solo te introduce lo que utilice
# ar rvs lib/libintervalo.a obj/intervalo.o

# orden de enlazado
# g++ obj/main.o -lintervalo -Llib

# tener la libreriia en usr/local/lib
# el .h /usr/local/inlcude 
