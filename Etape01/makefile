.SILENT:
CLASSES=./Classes
COMP=g++ -I $(CLASSES) -Wall -D DEBUG
OBJS=$(CLASSES)/ImageNG.o
PROGRAMS=Test1

all:	$(PROGRAMS)

Test1:	Test1.cpp $(OBJS)
	echo Creation de Test1
	$(COMP) Test1.cpp $(OBJS) -o Test1

$(CLASSES)ImageNG.o:	$(CLASSES)/ImageNG.cpp -I $(CLASSES)/ImageNG.h
	$(COMP) $(CLASSES)ImageNG.cpp -c -o $(CLASSES)/ImageNG.o

clean:
		echo Suppression des fichiers objets
	rm -f $(OBJS) core

clobber:	clean
	        echo Suppression de Test1
	rm -f $(PROGRAMS)