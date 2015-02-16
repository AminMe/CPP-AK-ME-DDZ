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
	pair<int, int> hg(i-1,j-1);
	pair<int, int> h(i-1,j);
	pair<int, int> hd(i-1,j-1);
	pair<int, int> g(i,j-1);
	pair<int, int> d(i,j+1);
	pair<int, int> bg(i+1,j-1);
	pair<int, int> b(i+1,j);
	pair<int, int> bd(i+1,j+1);

	if(hg.first>=0 && hg.second>=0 && h.first<map.getLigne() && hg.second<map.getColonne() && map[hg].isEstOccupe())
	{
		lionaualentour = map[hg].getPionCase()->name=="Lion";
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


}
