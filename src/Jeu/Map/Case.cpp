/*
 * Case.cpp
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#include "Case.h"
#include <iostream>
using namespace std;

void Case::affiche()
{
	if(secteur==-1){
		cout<<secteur;
	}
	else{
		cout<<" "<<secteur;
	}
}

void Case::setTab(int position, bool valeur)
{
	tabRiviere[position] = valeur;
}
