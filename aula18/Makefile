GCC = g++
GCC_FLAGS = -I include -std=c++11 -g
PROGRAMA = conta

all: $(PROGRAMA)

clean:
	rm -f *.o
	rm conta

$(PROGRAMA): main.o Conta.o Cliente.o ClientePF.o ClientePJ.o Agencia.o  Fila.o Funcionario.o Gerente.o Seguranca.o Caixa.o
	$(GCC) $(GCC_FLAGS) -o conta *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp
	$(GCC) $(GCC_FLAGS) -c src/Conta.cpp

Cliente.o: src/Cliente.cpp
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

ClientePF.o: src/ClientePF.cpp
	$(GCC) $(GCC_FLAGS) -c src/ClientePF.cpp

ClientePJ.o: src/ClientePJ.cpp include/ClientePJ.h
	$(GCC) $(GCC_FLAGS) -c src/ClientePJ.cpp

Agencia.o: src/Agencia.cpp
	$(GCC) $(GCC_FLAGS) -c src/Agencia.cpp

Fila.o: src/Fila.cpp include/Fila.h
	$(GCC) $(GCC_FLAGS) -c src/Fila.cpp

Funcionario.o: src/Funcionario.cpp include/Funcionario.h
	$(GCC) $(GCC_FLAGS) -c src/Funcionario.cpp

Gerente.o: src/Gerente.cpp include/Gerente.h
	$(GCC) $(GCC_FLAGS) -c src/Gerente.cpp

Seguranca.o: src/Seguranca.cpp include/Seguranca.h
	$(GCC) $(GCC_FLAGS) -c src/Seguranca.cpp

Caixa.o: src/Caixa.cpp include/Caixa.h
	$(GCC) $(GCC_FLAGS) -c src/Caixa.cpp

# Arquivos que não existem no disco
.PHONY: all