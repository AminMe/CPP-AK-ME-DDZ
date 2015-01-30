/*
 * Map.h
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef MAP_H_
#define MAP_H_
#include "Case.h"
#define TAILLE 5

class Map {
private:
public:
	Case tab[TAILLE][TAILLE];

	Map();
	virtual ~Map();
};

#endif /* MAP_H_ */
