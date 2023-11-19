#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
using namespace std;

class Exception
{
	protected:
		char message[100];
	public:
		Exception(void);
		Exception(const char* m);
		Exception(const Exception& e);

		virtual ~Exception();

		void setErreur(const char* m);

		const char* getMessageErreur() const;
};

#endif