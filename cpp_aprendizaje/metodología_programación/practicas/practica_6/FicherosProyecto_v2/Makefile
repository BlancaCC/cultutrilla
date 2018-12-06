# Esto es un precioso makefile implimentado por Blanca Cano Camarero



bin/learn: obj/learn.o obj/ContadorBigramas.o  obj/Idioma.o obj/Bigrama.o
	g++ -g $^ -o $@ 

obj/learn.o: src/learn.cpp include/ContadorBigramas.h  include/Idioma.h
	g++ -c src/learn.cpp -o $@ -I include 

obj/ContadorBigramas.o: src/ContadorBigramas.cpp include/ContadorBigramas.h 
	g++ -c src/ContadorBigramas.cpp -o $@ -I include 


obj/Idioma.o: src/Idioma.cpp  include/Idioma.h
	g++ -c src/Idioma.cpp -o $@ -I include

obj/Bigrama.o: src/Bigrama.cpp include/Bigrama.h
	g++ -c src/Bigrama.cpp -o $@ -I include
clean:
	rm -rf obj/* bin/* doc/* ZIP/ *.bgr
	find -name "*~" -delete
	@echo "Borrado con éxito :) "
testv:
	valgrind --leak-check=full --track-origins=yes ./bin/learn -c -l spanish -f spanish.bgr data/fortunata.txt
	valgrind --leak-check=full --track-origins=yes ./bin/learn -a -l spanish -f spanish.bgr  data/quijote.txt

test:

	./bin/learn -c -f unkown.bgr data/test.txt
	@echo "Las 10 primeras líneas de unkown.bgr son: "
	@head -10 unkown.bgr
	@echo "=================================================="
	@echo "=================================================="

	./bin/learn -c -l spanish -f spanish.bgr data/fortunata.txt data/quijote.txt
	@echo "Las 20 primeras líneas de spanish.bgr son: "
	@head -20 spanish.bgr
	@echo "=================================================="
	@echo "=================================================="

	
	./bin/learn -a -l spanish -f spanish.bgr data/fortunata.txt
	@echo "Las 20 primeras líneas de spanish.bgr son: "
	@head -20 spanish.bgr
	@echo "=================================================="
	@echo "=================================================="
	



zip: clean
	mkdir practica6
	cp -r bin  data  doc  include  Makefile  obj  src practica6
	zip -r practica6.zip practica6
	rm -r practica6
	@echo "Creado zip con éxito"
