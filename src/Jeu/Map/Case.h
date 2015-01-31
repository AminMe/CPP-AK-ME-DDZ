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
public:
	int x;
	int y;
	int secteur;
	bool estOccupe;
	Pion *pionCase; //= NULL;

	Case(int posiX, int posiY, int secteurNum) {
		x=posiX;
		y=posiY;
		secteur=secteurNum;
		estOccupe=false;
		pionCase=NULL;
	}

	Case():x(-1),y(-1),secteur(-1),estOccupe(false),pionCase(NULL){};


	void setOccupe(bool caseOcupe);

	bool getEstOccupe();

	virtual ~Case();

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

};

#endif /* CASE_H_ */
