#ifndef IMAGE_H
#define IMAGE_H

#include "Dimension.h"
#include <iostream>
using namespace std;

class Image
{
	protected:
		int 	id;
		string 	nom;
		Dimension dimension;
	public:
		Image(void);
		Image(int i,const string n);
		Image(int i,const string n,const Dimension& d);
		Image(const Image& p);
		Image(const string n);
		
		virtual ~Image();

		void setId(int i);
		void setNom(const string n);
		virtual void setDimension(const Dimension& d);

		int getId() const;
		const string getNom() const;
		Dimension getDimension() const;
		virtual string getType() const = 0;

		virtual void Affiche() const = 0;
		virtual void Dessine() = 0;
		virtual void exportToFile(const string fichier, const string format) = 0;

		void Save(ofstream & fichier) const;
		void Load(ifstream & fichier);
};

#endif