.SILENT:
CLASSES=./Classes
COMP=g++ -I $(CLASSES) -Wall -D DEBUG
OBJS=$(CLASSES)/ImageNG.o $(CLASSES)/Dimension.o
PROGRAMS=Test2

all:	$(PROGRAMS)

Test2:	Test2.cpp $(OBJS)
	echo Creation de Test2
	$(COMP) Test2.cpp $(OBJS) -o Test2

$(CLASSES)ImageNG.o:	$(CLASSES)/ImageNG.cpp -I $(CLASSES)/ImageNG.h
	$(COMP) $(CLASSES)ImageNG.cpp -c -o $(CLASSES)/ImageNG.o

$(CLASSES)Dimension.o:	$(CLASSES)/Dimension.cpp -I $(CLASSES)/Dimension.h
	$(COMP) $(CLASSES)Dimension.cpp -c -o $(CLASSES)/Dimension.o

clean:
		echo Suppression des fichiers objets
	rm -f $(OBJS) core

clobber:	clean
	        echo Suppression de Test2
	rm -f $(PROGRAMS)