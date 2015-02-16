/*
 * Etat.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Etat.h"

#include "Map/Map.h"


bool Etat::isFinished()
{
	Map &map = Map::Instance();

	for (int i = 1; i<Map::LIGNE-1; i++)
	{
		for (int j = 1; i<Map::COLONNE-1; i++)
		{
			pair<int, int> index(i,j);
			if(!map[index].isEstOccupe())
			{
				return false;
			}
		}
	}

	return true;
}
