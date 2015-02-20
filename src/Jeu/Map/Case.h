/*
 * Case.h
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef CASE_H_
#define CASE_H_

#include <iostream>

class Pion;



#define RIVIERE_GAUCHE 0
#define RIVIERE_DROITE 1
#define RIVIERE_HAUT 2
#define RIVIERE_BAS 3


#include <cstdlib>
#include <string>
using namespace std;

class Case {
private:
	    int x;
		int y;
		int secteur;
		bool estOccupe;
		Pion *pionCase; //= NULL;
		bool tabRiviere[4];

public:

	Case(Case * const c):x(c->x),y(c->y),secteur(c->secteur),estOccupe(c->estOccupe)
	{
		//pionCase(new Pion(c->getPionCase()))
		Pion *copie(c->getPionCase());
		pionCase = copie;
		for(int i =0;i<4;i++)
		{
			tabRiviere[i] = c->tabRiviere[i];
		}
	}

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

	void setPion(Pion *p);
	Pion* getPionCase() const;

	bool isEstOccupe() const {return estOccupe;}
	void setEstOccupe(bool estOccupe) {this->estOccupe = estOccupe;}
	int getSecteur() const {return secteur;}
	void setSecteur(int secteur) { this->secteur = secteur;}
	int getX() const {return x;}
	void setX(int x) {this->x = x;}
	int getY() const {return y;}
	void setY(int y) {this->y = y;}
	int getI() const {return x;}
	int getJ() const {return y;}
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
