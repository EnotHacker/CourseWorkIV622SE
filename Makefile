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

all: $(DUR)/$(EXECUTABLE) 

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


.PHONY : clean
clean:
	rm -rf build/src/*.o bin/*