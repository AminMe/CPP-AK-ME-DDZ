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

	if(h.first>=1 && h.second>=1 && h.first<map.getLigne()-1 && h.second<map.getColonne()-1 && map[h]->isEstOccupe())
	{
		if(map[h]->getPionCase()->getName()==animalRecherche && map[h]->getPionCase())
			resultat.push_back(map[h]);
	}

	if(g.first>=1 && g.second>=1 && g.first<map.getLigne()-1 && g.second<map.getColonne()-1 && map[g]->isEstOccupe())
	{
		if(map[g]->getPionCase()->getName()==animalRecherche)
			resultat.push_back(map[g]);
	}

	if(b.first>=1 && b.second>=1 && b.first<map.getLigne()-1 && b.second<map.getColonne()-1 && map[b]->isEstOccupe())
	{
		if(map[b]->getPionCase()->getName()==animalRecherche)
			resultat.push_back(map[b]);
	}

	if(d.first>=1 && d.second>=1 && d.first<map.getLigne()-1 && d.second<map.getColonne()-1 && map[d]->isEstOccupe())
	{
		if(map[d]->getPionCase()->getName()==animalRecherche)
			resultat.push_back(map[d]);
	}


	return resultat;
}

void Animal::switchPosition(Case *first, Case*second)
{
	Pion * animal1 = first->getPionCase();
	Pion * animal2 = second->getPionCase();

	animal2->setC(first);

	second->setPion(NULL);
	second->setPion(animal1);
	first->setPion(NULL);
	first->setPion(animal2);
}
