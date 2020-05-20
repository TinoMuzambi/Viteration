# Tinotenda Muzambi
# MZMTIN002

default:
	@g++ -I /Eigen/Dense main.cpp -o viterate

main.run: main.o viterate.o
	g++ main.run main.o viterate.o

clean:
	@rm -f ./viterate *.o

run:
	@./viterate
