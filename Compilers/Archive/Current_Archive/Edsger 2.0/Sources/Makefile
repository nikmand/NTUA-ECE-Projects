.PHONY: clean distclean count

# OS type: Linux/Win DJGPP
ifdef OS
   EXE=.exe
else
   EXE=
endif

#-ansi -pedantic
CFLAGS=-Wall  -g 
CC=gcc
CPP = g++

#must find appropriate llvm-config -- llok your /usr/bin/ directory ()
LLVMCONFIG = llvm-config-3.8
CPPFLAGS = `$(LLVMCONFIG) --cxxflags`
LDFLAGS = `$(LLVMCONFIG) --ldflags`
#-lpthread -ldl -lz -lncurses -rdynamic
LIBS = `$(LLVMCONFIG) --system-libs` `$(LLVMCONFIG) --libs`
SEM_OBJ   = sem_lexer.o sem_parser.o sem_symbol.o sem_error.o sem_general.o
IR_OBJ = ir_parser.o ir_lexer.o ir_symbol.o ir_error.o ir_general.o

#Edsger-x: main.cpp ir_full.o
#	$(CPP) $(CPPFLAGS) -lfl $(LDFLAGS) $(LIBS) main.cpp final.o $(IR_OBJ) -o $@

final.o: sem_full.o ir_full.o
	$(CPP) sem_full.o ir_full.o -o final.o
ir_full.o:   $(IR_OBJ)
	$(CPP)  -o $@ sem_full.o $(IR_OBJ) -lfl $(LDFLAGS) $(LIBS)
#	objcopy --prefix-symbols sem  sem_full.o sem_full.o
#	objcopy --redefine-sym sem_Semantics=Semantics sem_full.o sem_full.o
	

ir_lexer.cpp: ir_lexer.l ir_parser.hpp ir_symbol.o
	flex -o ir_lexer.cpp ir_lexer.l ir_parser.hpp
ir_parser.cpp ir_parser.hpp: ir_parser.y  ir_symbol.o
	bison -dv -o ir_parser.cpp ir_parser.y
ir_parser.o: ir_parser.cpp
	$(CPP)  -c $(CPPFLAGS) -o ir_parser.o ir_parser.cpp
ir_lexer.o: ir_lexer.cpp
	$(CPP)  -c $(CPPFLAGS) -o ir_lexer.o ir_lexer.cpp
ir_general.o: ir_general.cpp ir_general.h ir_error.h
	$(CPP)  -c $(CPPFLAGS) -o ir_general.o ir_general.cpp
ir_error.o: ir_error.cpp ir_general.h ir_error.h
	$(CPP)  -c $(CPPFLAGS) -o ir_error.o ir_error.cpp
ir_symbol.o: ir_symbol.cpp ir_symbol.h ir_general.o ir_error.o
	$(CPP)  -c $(CPPFLAGS) -o ir_symbol.o ir_symbol.cpp


sem_full.o: $(SEM_OBJ)
	$(CPP) $(LDFLAGS) $(LIBS) -lfl $(SEM_OBJ)  -o sem_full.o
sem_lexer.cpp: sem_lexer.l  sem_parser.hpp sem_symbol.o
	flex -o sem_lexer.cpp sem_lexer.l sem_parser.hpp
sem_parser.cpp sem_parser.hpp: sem_parser.y  sem_symbol.o
	bison -dv -o sem_parser.cpp sem_parser.y
sem_lexer.o: sem_lexer.cpp
	$(CPP)  -c $(CPPFLAGS) -o sem_lexer.o sem_lexer.cpp
sem_general.o: sem_general.cpp sem_general.h sem_error.h
	$(CPP)  -c $(CPPFLAGS) -o sem_general.o sem_general.cpp
sem_error.o: sem_error.cpp sem_general.h sem_error.h
	$(CPP)  -c $(CPPFLAGS) -o sem_error.o sem_error.cpp
sem_symbol.o: sem_symbol.cpp sem_symbol.h sem_general.o sem_error.o
	$(CPP)  -c $(CPPFLAGS) -o sem_symbol.o sem_symbol.cpp

count:
	wc -l -c Makefile $(SRCFILES)
bonus.zip: distclean
	zip bonus.zip Makefile $(SRCFILES)
bonus.tgz:
	tar cvfzh bonus.tgz Makefile $(SRCFILES)
clean:
	$(RM) sem_lexer.cpp sem_parser.cpp sem_parser.hpp sem_parser.output ir_lexer.cpp ir_parser.cpp ir_parser.hpp ir_parser.output *.o *~
distclean: clean
	$(RM) simple
