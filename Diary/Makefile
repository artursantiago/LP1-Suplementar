GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = diary
MATRICULA = 20190042017

all: $(PROGRAMA) zip

zip: src/* include/* resources/*
	zip $(MATRICULA).zip src/* include/* resources/*

$(PROGRAMA): main.o App.o Diary.o Message.o Date.o Time.o Util.o
	$(GCC) $(GCC_FLAGS) -o diary *.o

main.o: src/main.cpp 
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Message.o: src/Message.cpp include/Message.h
	$(GCC) $(GCC_FLAGS) -c src/Message.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

Time.o: src/Time.cpp include/Time.h
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp

Util.o: src/Util.cpp include/Util.h
	$(GCC) $(GCC_FLAGS) -c src/Util.cpp

# Arquivos que não existem no disco
.PHONY: all zip