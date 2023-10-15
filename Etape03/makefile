CLASSES = ./Classes/

Test3: Test3.cpp $(CLASSES)MyQT.o $(CLASSES)Dimension.o $(CLASSES)ImageNG.o
	g++ Test3.cpp -o Test3 $(CLASSES)MyQT.o $(CLASSES)ImageNG.o $(CLASSES)Dimension.o -I $(CLASSES) -lSDL -lpthread -Wl,-O1 -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I /usr/lib64/qt5/mkspecs/linux-g++ /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so

$(CLASSES)ImageNG.o:	$(CLASSES)ImageNG.cpp $(CLASSES)ImageNG.h
	g++ $(CLASSES)ImageNG.cpp -c -I Classes -o $(CLASSES)ImageNG.o -D DEBUG

$(CLASSES)Dimension.o:	$(CLASSES)Dimension.cpp $(CLASSES)Dimension.h
	g++ $(CLASSES)Dimension.cpp -c -I Classes -o $(CLASSES)Dimension.o -D DEBUG

$(CLASSES)MyQT.o:	$(CLASSES)MyQT.cpp $(CLASSES)MyQT.h
	g++ -c $(CLASSES)MyQT.cpp -o $(CLASSES)MyQT.o -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I /usr/lib64/qt5/mkspecs/linux-g++
clean:	
	rm -f $(CLASSES)*.o core

clobber:	clean
	rm -f Test3