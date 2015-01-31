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
	//Pion pionCase;
	/* une case à un pion ?*/


	Case (int posiX, int posiY, int secteurNum);

	Case():secteur(-1),estOccupe(false){};

	void setOccupe(bool caseOcupe);

	bool getEstOccupe();

	virtual ~Case();

	//Case(int secteur,bool estOccupe):secteur(secteur),estOccupe(estOccupe){}

	void affiche();

	Case& operator = (const Case&& other) // copy assignment
	{
	    return *this;
	}

	void setPion(Pion &p){
		/*if(p!=NULL){
		pionCase = p;*/
		estOccupe=true;
		//}
	}

};

#endif /* CASE_H_ */
