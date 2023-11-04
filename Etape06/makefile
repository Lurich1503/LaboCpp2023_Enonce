.SILENT:
CLASSES=./Classes/
COMP=g++ -I $(CLASSES) -Wall -D DEBUG

Test6: Test6.cpp $(CLASSES)MyQT.o $(CLASSES)Dimension.o $(CLASSES)ImageNG.o $(CLASSES)Image.o $(CLASSES)Couleur.o $(CLASSES)ImageRGB.o $(CLASSES)ImageB.o $(CLASSES)Exception.o $(CLASSES)RGBException.o $(CLASSES)XYException.o
	echo Creation de Test6
	$(COMP) Test6.cpp -o Test6 $(CLASSES)MyQT.o $(CLASSES)ImageNG.o $(CLASSES)Dimension.o $(CLASSES)Image.o $(CLASSES)Couleur.o $(CLASSES)ImageRGB.o $(CLASSES)ImageB.o $(CLASSES)Exception.o $(CLASSES)RGBException.o $(CLASSES)XYException.o -lSDL -lpthread -Wl,-O1 -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I /usr/lib64/qt5/mkspecs/linux-g++ /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so

$(CLASSES)ImageNG.o:	$(CLASSES)ImageNG.cpp $(CLASSES)ImageNG.h
	echo Creation de ImageNG.o
	$(COMP) $(CLASSES)ImageNG.cpp -c -o $(CLASSES)ImageNG.o

$(CLASSES)Image.o:	$(CLASSES)Image.cpp $(CLASSES)Image.h
	echo Creation de Image.o
	$(COMP) $(CLASSES)Image.cpp -c -o $(CLASSES)Image.o

$(CLASSES)ImageRGB.o:	$(CLASSES)ImageRGB.cpp $(CLASSES)ImageRGB.h
	echo Creation de ImageRGB.o
	$(COMP) $(CLASSES)ImageRGB.cpp -c -o $(CLASSES)ImageRGB.o

$(CLASSES)ImageB.o:	$(CLASSES)ImageB.cpp $(CLASSES)ImageB.h
	echo Creation de ImageB.o
	$(COMP) $(CLASSES)ImageB.cpp -c -o $(CLASSES)ImageB.o

$(CLASSES)Dimension.o:	$(CLASSES)Dimension.cpp $(CLASSES)Dimension.h
	echo Creation de Dimension.o
	$(COMP) $(CLASSES)Dimension.cpp -c -o $(CLASSES)Dimension.o

$(CLASSES)Couleur.o:	$(CLASSES)Couleur.cpp $(CLASSES)Couleur.h
	echo Creation de Couleur.o
	$(COMP) $(CLASSES)Couleur.cpp -c -o $(CLASSES)Couleur.o

$(CLASSES)Exception.o:	$(CLASSES)Exception.cpp $(CLASSES)Exception.h
	echo Creation de Exception.o
	$(COMP) $(CLASSES)Exception.cpp -c -o $(CLASSES)Exception.o

$(CLASSES)RGBException.o:	$(CLASSES)RGBException.cpp $(CLASSES)RGBException.h
	echo Creation de RGBException.o
	$(COMP) $(CLASSES)RGBException.cpp -c -o $(CLASSES)RGBException.o

$(CLASSES)XYException.o:	$(CLASSES)XYException.cpp $(CLASSES)XYException.h
	echo Creation de XYException.o
	$(COMP) $(CLASSES)XYException.cpp -c -o $(CLASSES)XYException.o

$(CLASSES)MyQT.o:	$(CLASSES)MyQT.cpp $(CLASSES)MyQT.h
	echo Creation de MyQT.o
	$(COMP) $(CLASSES)MyQT.cpp -c -o $(CLASSES)MyQT.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I /usr/lib64/qt5/mkspecs/linux-g++
clean:	
	echo Suppression des fichiers objets
	rm -f $(CLASSES)*.o core

clobber:	clean
	echo Suppression de Test6
	rm -f Test6