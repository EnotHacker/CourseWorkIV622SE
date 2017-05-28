# переменная CC указывает компилятор, используемый для сборки
CC=g++

# в переменной CFLAGS лежат флаги, которые передаются компилятору

CFLAGS= -I thirdparty -I src -c -Wall
#сборка программы
SOURCES = main.cpp function.cpp
EXECUTABLE = main
DIR = build/src
DUR = bin
DAR = src

#сборка тестов
SOURCES_TEST = main.cpp function_test.c validation_test.c
EXECUTABLE_TEST = test
BUT = build/test
BT = bin
DT = test


all: $(DUR)/$(EXECUTABLE) #test

$(DUR)/$(EXECUTABLE): $(DIR)/main.o $(DIR)/function.o
	@if [ ! -d $(DUR) ] ; then echo "creating $(DUR)"; mkdir bin; fi
	$(CC) $(DIR)/main.o $(DIR)/function.o -o $(DUR)/$(EXECUTABLE)

$(DIR)/main.o: $(DAR)/main.cpp
	@if [ ! -d $(DIR) ] ; then echo "creating $(DIR)"; mkdir build; mkdir build/src; fi
	$(CC) $(CFLAGS) -c $(DAR)/main.cpp -o $(DIR)/main.o

$(DIR)/function.o: $(DAR)/function.cpp
	@if [ ! -d $(DIR) ] ; then echo "creating $(DIR)"; mkdir build; mkdir build/src; fi
	$(CC) $(CFLAGS) -c $(DAR)/function.cpp -o $(DIR)/function.o

install:
	install main /bin

#test: $(BT)/$(EXECUTABLE_TEST)

#$(BUT)/main.o: $(DT)/main.cpp
	#@if [ ! -d $(BUT) ] ; then echo "creating $(BUT)"; mkdir build; mkdir build/test; fi
	#$(CC) $(CFLAGS) -c $(DT)/main.cpp -o $(BUT)/main.o

#$(BUT)/function_test.o: $(DT)/function_test.c
	#@if [ ! -d $(BUT) ] ; then echo "creating $(BUT)"; mkdir build; mkdir build/test; fi
	#$(CC) $(CFLAGS) -c $(DT)/function_test.c -o $(BUT)/function_test.o

#$(BUT)/validation_test.o: $(DT)/validation_test.c
	#@if [ ! -d $(BUT) ] ; then echo "creating $(BUT)"; mkdir build; mkdir build/test; fi
	#$(CC) $(CFLAGS) -c $(DT)/validation_test.c -o $(BUT)/validation_test.o 

#$(BT)/$(EXECUTABLE_TEST): $(BUT)/main.o $(BUT)/function_test.o $(BUT)/validation_test.o $(DIR)/function.o
	#@if [ ! -d $(BT) ] ; then echo "creating $(BT)"; mkdir bin; mkdir bin/function-calc-test; fi
	#$(CC) $(BUT)/main.o $(BUT)/function_test.o $(BUT)/validation_test.o $(DIR)/function.o -o $(BT)/$(EXECUTABLE_TEST)


.PHONY : clean #test
clean:
	rm -rf build/src/*.o build/test/*.o bin/*