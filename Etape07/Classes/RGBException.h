#ifndef RGBEXCEPTION_H
#define RGBEXCEPTION_H

#include "Exception.h"
#include <iostream>
using namespace std;

class RGBException : public Exception
{
	private:
		int valeur;
	public:
		RGBException(void);
		RGBException(int v, const char* m);
		RGBException(const RGBException& e);

		~RGBException();

		void setValeur(int v);

		int getValeur() const;
};

#endif