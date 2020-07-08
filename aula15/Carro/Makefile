GCC = g++
GCC_FLAGS = -I include -std=c++11 -g
PROGRAMA = carro

all: $(PROGRAMA)

clean:
	rm -f *.o
	rm carro

$(PROGRAMA): main.o Carro.o Motor.o 
	$(GCC) $(GCC_FLAGS) -o carro *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Carro.o: src/Carro.cpp
	$(GCC) $(GCC_FLAGS) -c src/Carro.cpp

Motor.o: src/Motor.cpp
	$(GCC) $(GCC_FLAGS) -c src/Motor.cpp

# Arquivos que não existem no disco
.PHONY: all