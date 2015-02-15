/*
 * Case.h
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef CASE_H_
#define CASE_H_

#include <cstdlib>

class Pion;

class Case {
private:
	int x;
		int y;
		int secteur;
		bool estOccupe;
		Pion *pionCase; //= NULL;
public:


	Case(int posiX, int posiY, int secteurNum) {
		x=posiX;
		y=posiY;
		secteur=secteurNum;
		estOccupe=false;
		pionCase=NULL;
	}

	Case():x(-1),y(-1),secteur(-1),estOccupe(false),pionCase(NULL){};
	virtual ~Case(){}

	void affiche();

	Case& operator = (const Case&& other) // copy assignment
	{
	    return *this;
	}

	void setPion(Pion *p){
		if(p!=NULL){
			pionCase = p;
			estOccupe=true;
		}
	}
	Pion*& getPionCase() {return pionCase;}
	bool isEstOccupe() const {return estOccupe;}
	void setEstOccupe(bool estOccupe) {this->estOccupe = estOccupe;}
	int getSecteur() const {return secteur;}
	void setSecteur(int secteur) { this->secteur = secteur;}
	int getX() const {return x;}
	void setX(int x) {this->x = x;}
	int getY() const {return y;}
	void setY(int y) {this->y = y;}
};

#endif /* CASE_H_ */
