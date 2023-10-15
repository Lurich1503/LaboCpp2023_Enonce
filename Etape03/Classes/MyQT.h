#ifndef MYQT_H
#define MYQT_H

#include "ImageNG.h"
/*
#include "ImageRGB.h"
#include "ImageB.h"
*/

class MyQT
{
  public:
    // Pour les ImageNG
    static void ViewImage(const ImageNG & image);
    static void ImportFromFile(ImageNG & image,const char* fichier);
    static void ExportToFile(const ImageNG & image, const char* fichier,const char* format);

    // Pour les ImageRGB
    /*
    static void ViewImage(const ImageRGB & image);
    static void ImportFromFile(ImageRGB & image,const char* fichier);
    static void ExportToFile(const ImageRGB & image, const char* fichier,const char* format);

    // Pour les ImageB
    static void ViewImage(const ImageB & image);
    static void ExportToFile(const ImageB & image, const char* fichier,const char* format);
    */
};

#endif
