.SILENT:
CLASSES=./Classes/
COMP=g++ -I $(CLASSES) -Wall -D DEBUG

Test1:	Test1.cpp $(CLASSES)ImageNG.o
	echo Creation de Test1
	$(COMP) Test1.cpp $(CLASSES)ImageNG.o -o Test1

$(CLASSES)ImageNG.o:	$(CLASSES)ImageNG.cpp $(CLASSES)ImageNG.h
	echo Creation de ImageNG.o
	$(COMP) $(CLASSES)ImageNG.cpp -c -o $(CLASSES)ImageNG.o

clean:
		echo Suppression des fichiers objets
	rm -f $(CLASSES)*.o core

clobber:	clean
	        echo Suppression de Test1
	rm -f Test1