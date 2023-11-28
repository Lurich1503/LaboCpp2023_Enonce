#ifndef ARRAYLISTEXCEPTION_H
#define ARRAYLISTEXCEPTION_H

#include "Exception.h"
#include <iostream>
using namespace std;

class ARRAYLISTException : public Exception
{
	private:
		int valeur;
	public:
		ARRAYLISTException(void);
		ARRAYLISTException(int v, const char* m);
		ARRAYLISTException(const ARRAYLISTException& e);

		~ARRAYLISTException();

		void setValeur(int v);

		int getValeur() const;
};

#endif
