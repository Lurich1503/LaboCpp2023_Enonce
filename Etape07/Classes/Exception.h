#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
using namespace std;

class Exception
{
	protected:
		string message;
	public:
		Exception(void);
		Exception(const string m);
		Exception(const Exception& e);

		virtual ~Exception();

		void setErreur(const string m);

		const string getMessageErreur() const;
};

#endif