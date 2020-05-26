# Tinotenda Muzambi
# MZMTIN002

default:
	@g++ main.cpp v_iteration.cpp -o viterate

main.run: main.o v_iteration.o
	g++ main.run main.o v_iteration.o
main.o: main.cpp v_iteration.h
	g++ -c -o main.o main.cpp
v_iteration.o: v_iteration.cpp v_iteration.h
	g++ -c -o v_iteration.o v_iteration.cpp

clean:
	@rm -f ./v_iteration *.o

run:
	@./viterate
