# basic makefile for c++ project

SOURCE=main.cpp 
MYINCLUDES=
MYLIBRARIES= -O2
CC=g++
all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
       $(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM) -l$(MYLIBRARIES)
#	$(CC) $(SOURCE) -o$(MYPROGRAM)

clean:
	rm -f $(MYPROGRAM)