.SILENT:

ApplicPhotoShop:	moc_mainwindowphotoshop.o mainwindowphotoshop.o main.o
	echo Creation de ApplicPhotoShop...
	g++ -o ApplicPhotoShop moc_mainwindowphotoshop.o mainwindowphotoshop.o main.o /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread

moc_mainwindowphotoshop.o:	moc_mainwindowphotoshop.cpp mainwindowphotoshop.h
	echo Creation de moc_mainwindowphotoshop.o...
	g++ -c -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o moc_mainwindowphotoshop.o moc_mainwindowphotoshop.cpp

mainwindowphotoshop.o:	mainwindowphotoshop.cpp mainwindowphotoshop.h ui_mainwindowphotoshop.h 	
	echo Creation de mainwindowphotoshop.o...
	g++ -c -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o mainwindowphotoshop.o mainwindowphotoshop.cpp

main.o:	main.cpp
	echo Creation de main.o...
	g++ -c -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o main.o main.cpp

