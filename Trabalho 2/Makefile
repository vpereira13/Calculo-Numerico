main_newton: funcoes newton simpson
	gcc main_newton.c -o main_newton funcoes.o newton.o simpson.o -I . -lm

main_simpson: funcoes newton simpson
	gcc main_simpson.c -o main_simpson funcoes.o newton.o simpson.o -I . -lm

funcoes:
	gcc -c funcoes.c -I .

newton:
	gcc -c newton.c -I .

simpson:
	gcc -c simpson.c -I .

run_newton:
	@./main_newton

run_simpson:
	@./main_simpson

clean:
	rm -f *.o main_simpson main_newton
