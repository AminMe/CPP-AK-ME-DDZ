/*
 * Zebre.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Zebre.h"

void Zebre::check(Case position)
{
	Map& map = Map::Instance();

	bool lionaualentour = false;

	int i = position.getY();
	int j = position.getX();

	pair<int, int> centre(i,j);
	pair<int, int> h(i-1,j);
	pair<int, int> g(i,j-1);
	pair<int, int> d(i,j+1);
	pair<int, int> b(i+1,j);

	if(h.first>=0 && h.second>=0 && h.first<map.getLigne() && h.second<map.getColonne() && map[h]->isEstOccupe())
	{
		lionaualentour = map[h]->getPionCase()->getName()=="Lion";
	}

	/*
	 * Faire la meme pour toutes les autres positions => à chaque fois mettre
	 * le if(lionaualentour) pour eviter de faire le test si un lion a deja ete trouve
	 */

	if(lionaualentour)
	{
		this->estCache = true;
		this->valeur=0;/*Le zebre ne rapporte plus de pion s'il est caché*/
		return;
	}

	if(g.first>=0 && g.second>=0 && g.first<map.getLigne() && g.second<map.getColonne() && map[g]->isEstOccupe())
	{
		lionaualentour = map[g]->getPionCase()->getName()=="Lion";
	}

	if(lionaualentour)
	{
		this->estCache = true;
		this->valeur=0;/*Le zebre ne rapporte plus de pion s'il est caché*/
		return;
	}

	if(b.first>=0 && b.second>=0 && b.first<map.getLigne() && b.second<map.getColonne() && map[b]->isEstOccupe())
	{
		lionaualentour = map[b]->getPionCase()->getName()=="Lion";
	}

	if(lionaualentour)
	{
		this->estCache = true;
		this->valeur=0;/*Le zebre ne rapporte plus de pion s'il est caché*/
		return;
	}

	if(d.first>=0 && d.second>=0 && d.first<map.getLigne() && d.second<map.getColonne() && map[d]->isEstOccupe())
	{
		lionaualentour = map[d]->getPionCase()->getName()=="Lion";
	}

	if(lionaualentour)
	{
		this->estCache = true;
		this->valeur=0;/*Le zebre ne rapporte plus de pion s'il est caché*/
		return;
	}

}
