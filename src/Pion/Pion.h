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
<<<<<<< HEAD

protected:
	string name;
	Case c;

=======
protected:
	string name;
	Case c;
>>>>>>> refs/remotes/origin/master
public:
	Pion();
	Pion(int x, int y, Map map)
	{
		//return tab[x][y]
		pair<int, int> index(x,y);
		c = map[index];
	}
<<<<<<< HEAD

	Pion(Case c):c(c){}

=======
	Pion(Case c):c(c){}
>>>>>>> refs/remotes/origin/master
	virtual ~Pion();

	void poser(int x,int y)
	{

	}
};

#endif /* SRC_PION_H_ */
