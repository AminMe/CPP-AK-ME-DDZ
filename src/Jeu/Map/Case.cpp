/*
 * Case.cpp
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#include "Case.h"
#include <iostream>
using namespace std;

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


void Case::affiche()
{
	cout<<"1 - Z";
}
