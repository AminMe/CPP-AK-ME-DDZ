/*
 * Case.h
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef CASE_H_
#define CASE_H_

#include <iostream>

#define RIVIERE_GAUCHE 0
#define RIVIERE_DROITE 1
#define RIVIERE_HAUT 2
#define RIVIERE_BAS 3

#define LIGNE 7
#define COLONNE 8

#include <cstdlib>
#include <string>
using namespace std;

class Pion;

class Case {
private:
	    int x;
		int y;
		int secteur;
		bool estOccupe;
		Pion *pionCase; //= NULL;
		bool tabRiviere[4];

public:
	Case(int posiX, int posiY, int secteurNum) {
		x=posiX;
		y=posiY;
		secteur=secteurNum;
		estOccupe=false;
		pionCase=NULL;
	}

	Case():x(-1),y(-1),secteur(-1),estOccupe(false),pionCase(NULL){};
	 ~Case(){}

	void affiche();
	string getAffiche();
	string getPionAffiche();

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
	void setTab(int position, bool valeur);
	/*
	void setPionCase(const Pion*& pionCase) {
		this->pionCase = pionCase;
	}
	*/

	const bool* getTabRiviere() const {
		return tabRiviere;
	}
};

#endif /* CASE_H_ */
