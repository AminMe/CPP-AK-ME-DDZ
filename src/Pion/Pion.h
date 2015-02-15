/*
 * Pion.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_PION_H_
#define SRC_PION_H_

#include <iostream>
#include <utility>

#include "../Jeu/Map/Case.h"
#include "../Jeu/Map/Map.h"

class Map;

using namespace std;

class Pion {

protected:
	string name;
	Case c;
public:

	Pion(string name, int x, int y, Map map):name(name)
	{
		//return tab[x][y]
		pair<int, int> index(x,y);
		if(x>=0 && y>=0 && !map[index].isEstOccupe())
		{
			c = map[index];
		}
	}
	Pion(Case c):c(c){}

	virtual ~Pion(){}

	void poser(int x,int y)
	{

	}
};

#endif /* SRC_PION_H_ */
