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
	int taille;

public:
	Case tab[][];
	Map(int taille):taille(taille)
	{

	}
	virtual ~Map();
};

#endif /* MAP_H_ */
