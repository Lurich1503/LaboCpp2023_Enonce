.SILENT:
CLASSES=./Classes/
COMP=g++ -I $(CLASSES) -Wall -D DEBUG

Test2:	Test2.cpp $(CLASSES)ImageNG.o $(CLASSES)Dimension.o
	echo Creation de Test2
	$(COMP) Test2.cpp $(CLASSES)ImageNG.o $(CLASSES)Dimension.o -o Test2

$(CLASSES)ImageNG.o:	$(CLASSES)ImageNG.cpp $(CLASSES)ImageNG.h
	echo Creation de ImageNG.o
	$(COMP) $(CLASSES)ImageNG.cpp -c -o $(CLASSES)ImageNG.o

$(CLASSES)Dimension.o:	$(CLASSES)Dimension.cpp $(CLASSES)Dimension.h
	echo Creation de Dimension.o
	$(COMP) $(CLASSES)Dimension.cpp -c -o $(CLASSES)Dimension.o

clean:
		echo Suppression des fichiers objets
	rm -f $(CLASSES)*.o core

clobber:	clean
	        echo Suppression de Test2
	rm -f Test2