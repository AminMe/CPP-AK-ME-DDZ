/*
 * Pion.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_PION_H_
#define SRC_PION_H_

#include <iostream>
#include <string>
#include <utility>

#include "../Jeu/Map/Case.h"
#include "../Jeu/Map/Map.h"

class Map;

using namespace std;

class Pion {

protected:
	string name;
	Case* c;
public:

	Pion():name("PionErreur"),c(new Case(-1,-1,-1)){}

	Pion(const Pion* copie):name(copie->name),c(copie->c){}

	Pion(string name, int x, int y):name(name)
	{
		//return tab[x][y]
		Map& map = Map::Instance();
		pair<int, int> index(x,y);
		if(x>=0 && y>=0 && !map[index]->isEstOccupe())
		{
			/*c = *map[index];*/
			c = map[index];
		}
	}

	Pion(Case* c):c(c){}

	virtual ~Pion(){}

	void poser(int x,int y)
	{

	}

	string getName() const {
		return this->name;
	}

	void setName(const string& name) {
		this->name = name;
	}

	virtual void affiche();

	Case* getC() {
		/*return &c;*/
		return c;
	}

	void setC(Case* c) {
		if(c==NULL) return;
		/*this->c = *c;*/
		this->c = c;
	}
};

#endif /* SRC_PION_H_ */
