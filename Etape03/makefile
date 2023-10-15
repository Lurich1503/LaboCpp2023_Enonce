.SILENT:
CLASSES=./Classes/
COMP=g++ -I $(CLASSES) -Wall -D DEBUG

Test3: Test3.cpp $(CLASSES)MyQT.o $(CLASSES)Dimension.o $(CLASSES)ImageNG.o
	echo Creation de Test3
	$(COMP) Test3.cpp -o Test3 $(CLASSES)MyQT.o $(CLASSES)ImageNG.o $(CLASSES)Dimension.o -lSDL -lpthread -Wl,-O1 -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I /usr/lib64/qt5/mkspecs/linux-g++ /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so

$(CLASSES)ImageNG.o:	$(CLASSES)ImageNG.cpp $(CLASSES)ImageNG.h
	echo Creation de ImageNG.o
	$(COMP) $(CLASSES)ImageNG.cpp -c -o $(CLASSES)ImageNG.o

$(CLASSES)Dimension.o:	$(CLASSES)Dimension.cpp $(CLASSES)Dimension.h
	echo Creation de Dimension.o
	$(COMP) $(CLASSES)Dimension.cpp -c -o $(CLASSES)Dimension.o

$(CLASSES)MyQT.o:	$(CLASSES)MyQT.cpp $(CLASSES)MyQT.h
	echo Creation de MyQT.o
	$(COMP) $(CLASSES)MyQT.cpp -c -o $(CLASSES)MyQT.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I /usr/lib64/qt5/mkspecs/linux-g++
clean:	
	echo Suppression des fichiers objets
	rm -f $(CLASSES)*.o core

clobber:	clean
	echo Suppression de Test3
	rm -f Test3