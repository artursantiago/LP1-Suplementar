GCC = g++
GCC_FLAGS = -I include -std=c++11 -g
PROGRAMA = supermercado
MATRICULA = 20190042017

all: $(PROGRAMA)

zip: src/* include/* 
	zip $(MATRICULA).zip src/* include/* Makefile README.md .gitignore estoque.csv

$(PROGRAMA): main.o App.o Fornecedor.o Estabelecimento.o Produto.o Cliente.o Config.o Util.o VectorSupermercado.o
	$(GCC) $(GCC_FLAGS) -o supermercado *.o 

main.o: src/main.cpp 
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Fornecedor.o: src/Fornecedor.cpp include/Fornecedor.h
	$(GCC) $(GCC_FLAGS) -c src/Fornecedor.cpp	

Estabelecimento.o: src/Estabelecimento.cpp include/Estabelecimento.h
	$(GCC) $(GCC_FLAGS) -c src/Estabelecimento.cpp

Produto.o: src/Produto.cpp include/Produto.h
	$(GCC) $(GCC_FLAGS) -c src/Produto.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

Config.o: src/Config.cpp include/Config.h
	$(GCC) $(GCC_FLAGS) -c src/Config.cpp

Util.o: src/Util.cpp include/Util.h
	$(GCC) $(GCC_FLAGS) -c src/Util.cpp

VectorSupermercado.o: src/VectorSupermercado.cpp include/VectorSupermercado.h
	$(GCC) $(GCC_FLAGS) -c src/VectorSupermercado.cpp

clean:
	rm -f *.o
	rm supermercado

# Arquivos que não existem no disco
.PHONY: all zip