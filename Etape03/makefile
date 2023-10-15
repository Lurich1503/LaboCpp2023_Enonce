.SILENT:
CLASSES=./Classes
COMP=g++ -I $(CLASSES) -Wall -D DEBUG
OBJS=$(CLASSES)/ImageNG.o $(CLASSES)/Dimension.o $(CLASSES)/MyQT.o
PROGRAMS=Test3

all:	$(PROGRAMS)

Test3:	Test3.cpp $(OBJS)
	echo Creation de Test3
	$(COMP) Test3.cpp -o Test3 $(OBJS) -lSDL -lpthread -Wl,-O1 -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so

$(CLASSES)ImageNG.o:	$(CLASSES)/ImageNG.cpp -I $(CLASSES)/ImageNG.h
	echo compilation de ImageNG.o
	$(COMP) $(CLASSES)ImageNG.cpp -c -o $(CLASSES)/ImageNG.o

$(CLASSES)Dimension.o:	$(CLASSES)/Dimension.cpp -I $(CLASSES)/Dimension.h
	echo compilation de Dimension.o
	$(COMP) $(CLASSES)Dimension.cpp -c -o $(CLASSES)/Dimension.o

$(CLASSES)MyQT.o:	$(CLASSES)/MyQT.cpp -I $(CLASSES)/MyQT.h
	echo compilation de MyQT.o
	$(COMP) $(CLASSES)MyQT.cpp -c -o $(CLASSES)/MyQT.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++




clean:
		echo Suppression des fichiers objets
	rm -f $(OBJS) core

clobber:	clean
	        echo Suppression de Test3
	rm -f $(PROGRAMS)