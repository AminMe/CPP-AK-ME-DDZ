/*
 * Joueur.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */
#include "Joueur.h"

/*Joueur::~Joueur()
	{
		for(int i=0;i<mesAnimaux.;i++)
		{

		}
	}
*/

void Joueur::affiche()
{
	string sbonus = bonus?"Oui":"Non";
	cout<<"Joueur : "<<name<<" / Bonus : "<<sbonus<<" / Main : ";

	string *animaux = new string[mesAnimaux.size()];
	int *compteur = (int*)calloc(mesAnimaux.size(),sizeof(int));
	int curseur = 0;
	for(int i = 0; i<mesAnimaux.size();i++)
	{
		int retour = contains(animaux,mesAnimaux.at(i)->getName());
		if(retour==-1)
		{
			animaux[curseur] = mesAnimaux.at(i)->getName();
			compteur[curseur]++;
			curseur++;
		}
		else
		{
			compteur[retour]++;
		}
	}
	for(int i = 0; i<animaux->size() && compteur[i]!=0; i++)
	{
		cout<<animaux[i]<<" = "<<compteur[i]<<" .. ";
	}
	cout<<endl;
}

int Joueur::contains(string *animaux,string key)
{
	for(int i = 0; i<animaux->size(); i++)
	{
		if(animaux[i]==key)
		{
			return i;
		}
	}
	return -1;
}
