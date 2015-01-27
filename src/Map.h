/*
 * Map.h
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef MAP_H_
#define MAP_H_
#include "Case.h"

class Map {
private:
	int tailleX=5;
public:
	Case tab[tailleX][tailleX];

	Map()
	{

	}
	virtual ~Map();
};

#endif /* MAP_H_ */
