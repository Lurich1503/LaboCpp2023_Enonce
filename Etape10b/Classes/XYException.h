#ifndef XYEXCEPTION_H
#define XYEXCEPTION_H

#include "Exception.h"
#include <iostream>
using namespace std;

class XYException : public Exception
{
	private:
		char coordonnee;
	public:
		XYException(void);
		XYException(char c, const char* m);
		XYException(const XYException& e);

		~XYException();

		void setCoordonnee(const char c);

		char getCoordonnee() const;
};

#endif

