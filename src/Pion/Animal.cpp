/*
 * Animal.cpp
 *
 *  Created on: 20 janv. 2015
 *      Author: firminrabefiringa
 */

#include "Animal.h"

int Animal::idGen = 0;

vector<Case*> Animal::checkAlentour(Case position, string animalRecherche)
{
	Map& map = Map::Instance();
	int i = position.getX();
	int j = position.getY();

	pair<int, int> centre(i,j);
	pair<int, int> h(i-1,j);
	pair<int, int> g(i,j-1);
	pair<int, int> d(i,j+1);
	pair<int, int> b(i+1,j);

	vector<Case*> resultat;

	if(h.first>=0 && h.second>=0 && h.first<map.getLigne() && h.second<map.getColonne() && map[h]->isEstOccupe())
	{
		if(map[h]->getPionCase()->getName()==animalRecherche)
			resultat.push_back(map[h]);
	}

	if(g.first>=0 && g.second>=0 && g.first<map.getLigne() && g.second<map.getColonne() && map[g]->isEstOccupe())
	{
		if(map[g]->getPionCase()->getName()==animalRecherche)
			resultat.push_back(map[g]);
	}

	if(b.first>=0 && b.second>=0 && b.first<map.getLigne() && b.second<map.getColonne() && map[b]->isEstOccupe())
	{
		if(map[b]->getPionCase()->getName()==animalRecherche)
			resultat.push_back(map[b]);
	}

	if(d.first>=0 && d.second>=0 && d.first<map.getLigne() && d.second<map.getColonne() && map[d]->isEstOccupe())
	{
		if(map[d]->getPionCase()->getName()==animalRecherche)
			resultat.push_back(map[d]);
	}


	return resultat;
}

void Animal::switchPosition(Animal *first, Animal*second)
{
	Case *firstC(first->getC());

	Case *secondC(second->getC());

	second->setC(firstC);
	first->setC(secondC);
}
