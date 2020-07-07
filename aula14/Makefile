GCC = g++
GCC_FLAGS = -I include -std=c++11 -g
PROGRAMA = conta

all: $(PROGRAMA)

clean:
	rm -f *.o
	rm conta

$(PROGRAMA): main.o Conta.o Cliente.o Agencia.o
	$(GCC) $(GCC_FLAGS) -o conta *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp
	$(GCC) $(GCC_FLAGS) -c src/Conta.cpp

Cliente.o: src/Cliente.cpp
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

Agencia.o: src/Agencia.cpp
	$(GCC) $(GCC_FLAGS) -c src/Agencia.cpp

# Arquivos que não existem no disco
.PHONY: all