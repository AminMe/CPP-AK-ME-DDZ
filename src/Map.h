/*
 * Map.h
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef MAP_H_
#define MAP_H_
#include "Case.h"

#define TAILLE 15

class Map {
private:

	Case tab[TAILLE][TAILLE];
public:

	Map()
	{

	}
	virtual ~Map();
};

#endif /* MAP_H_ */
