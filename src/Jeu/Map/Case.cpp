/*
 * Case.cpp
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#include "Case.h"

Case::Case(int posiX, int posiY, int secteurNum) {
	x=posiX;
	y=posiY;
	secteur=secteurNum;
	estOccupe=false;
}

Case::~Case() {
	// TODO Auto-generated destructor stub
}

void Case::setOccupe(bool caseOcupe)
{
	estOccupe = caseOcupe;
}

