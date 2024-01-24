.PHONY: all calc

FLAGS=-std=c++17 -lstdc++ -Wall -Werror -Wextra 
GTEST=-lgtest -lpthread -lgtest_main
SOURCE=model/*.cc controller/*.cc
HEADERS=model/*.h controller/*.h
TESTS=tests/*_test.cc
EXECUTABLE=model.out
UNAME:=$(shell uname -s) 

ifeq ($(UNAME),Linux ) 
	GXX=g++ $(FLAGS)
	OPEN_CMD=xdg-open
	ADD_LIB=-lm -lrt -lpthread
endif
ifeq ($(UNAME),Darwin ) 
	GXX=gcc $(FLAGS)
	OPEN_CMD=open
	ADD_LIB=
endif

all: clean test

style:
	clang-format -style=google -i $(TESTS) $(SOURCE) $(HEADERS)

test: clean
	$(GXX) $(SOURCE) $(TESTS) $(FLAGS) $(ADD_LIB) -o $(EXECUTABLE) $(GTEST)
	./$(EXECUTABLE)

mem: test
ifeq ($(UNAME),Linux )
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --tool=memcheck ./$(EXECUTABLE)
else
	leaks --atExit -- ./$(EXECUTABLE)
endif

build: #clean
	mkdir build
	cd build && qmake ../calc2_0 && make

install: build
	mv build/calc2_0.app ~/Desktop

uninstall:
	rm -rf build 
	rm -rf ~/Desktop/calc2_0.app

clean:
	rm -rf *.a objects $(EXECUTABLE) *.o
	rm -rf html latex build dist

dvi:
	doxygen documentation_settings
	${OPEN_CMD} html/index.html

dist: build
	mkdir dist
	cp -R build/calc2_0.app dist
	cd dist && tar -cvzf calc2_0.tgz calc2_0.app
	rm -rf dist/calc2_0.app

open: install
	open ~/Desktop/calc2_0.app 
