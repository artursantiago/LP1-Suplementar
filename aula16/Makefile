GCC = g++
GCC_FLAGS = -I include -std=c++11 -g
PROGRAMA = empresa

all: $(PROGRAMA)

clean:
	rm -f *.o
	rm empresa

$(PROGRAMA): main.o Empresa.o Funcionario.o
	$(GCC) $(GCC_FLAGS) -o empresa *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Empresa.o: src/Empresa.cpp
	$(GCC) $(GCC_FLAGS) -c src/Empresa.cpp

Funcionario.o: src/Funcionario.cpp
	$(GCC) $(GCC_FLAGS) -c src/Funcionario.cpp

# Arquivos que não existem no disco
.PHONY: all