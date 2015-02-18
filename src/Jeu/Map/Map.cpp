/*
 * Map.cpp
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#include "Map.h"

#include <string>


Map Map::m_instance=Map();

Map& Map::Instance()
{
	return m_instance;
}

void Map::init()
{
	int i = 0;
	int j = 0;
	for(i = 0; i<LIGNE;i++)
	{
		for(j = 0; j<COLONNE; j++)
		{
			tab[i][j] = Case();
		}
	}
}

void Map::affiche()
{
	int i = 0;
	int j = 0;
	/*cout<<"Grille de jeu : "<<endl;
	cout<<"-------------------------------------------"<<endl;
	for(i = 0; i<LIGNE;i++)
	{
		cout<<"|";

		for(j = 0; j<COLONNE; j++)
		{
			cout<<"[";
			tab[i][j].affiche();
			cout<<"]";
		}
		if(j==COLONNE)
		{
			cout<<"|";
		}
		cout<<endl;
	}
	cout<<"-------------------------------------------"<<endl;*/

	string message = "   o  ";
	//cout<<"------------";cout<<"------------";
	//cout<<endl<<"|";cout<<"          |";cout<<"          |";
	//cout<<endl;
	//cout<<"|  ";cout<<message;cout<<"  |";cout<<"  ";cout<<message;cout<<"  |";
	//cout<<endl;
	//cout<<"|";cout<<"          |";cout<<"          |";
	//cout<<endl;
	//cout<<"------------";cout<<"------------";
	//cout<<endl;
	for(int k = 0; k<COLONNE;k++)
	{
		cout<<"     "<<k<<"     ";
	}
	cout<<endl;
	for(i = 0; i<LIGNE;i++)
	{
		cout<<" |";
		for(int k = 0; k<COLONNE; k++)
		{
			if(tab[i][k].getTabRiviere()[RIVIERE_HAUT])
				cout<<"§§§§§§§§§§§";
			else if(i==0 || k==0 || i==LIGNE-1 || k==COLONNE-1 || i==1)
			{
					cout<<"-----------";
			}
			else
			{
				if(tab[i][k].getTabRiviere()[RIVIERE_DROITE])
					cout<<"          §";
				else
					cout<<"           ";
			}
		}

		cout<<endl;
		cout<<" |";
		for(int k = 0; k<COLONNE; k++)
		{
			if(tab[i][k].getTabRiviere()[RIVIERE_DROITE])
				cout<<"          §";
			else if(i==0 || k==0 || i==LIGNE-1 || k==COLONNE-1 || k==COLONNE-2)
				cout<<"          |";
			else
				cout<<"           ";
		}

		cout<<endl;
		for(j = 0; j<COLONNE; j++)
		{
			if(j==0)
			{
				cout<<i;
				cout<<"|";
			}
			message = tab[i][j].getAffiche();
			if(tab[i][j].getTabRiviere()[RIVIERE_DROITE])
			{

				cout<<message;
				cout<<"§";
			}
			else
			{


				if(i==0 || j==0 || i==LIGNE-1 || j==COLONNE-1)
					cout<<"          |";
				else
				{
					cout<<message<<" ";
				}
			}
			//cout<<" ";
		}




		cout<<endl;
		if(i==LIGNE-1)
		{
			cout<<" |";
			for(int k = 0; k<COLONNE; k++)
			{
				cout<<"          |";
			}
			cout<<endl;
			for(int k = 0; k<COLONNE; k++)
			{
				if(tab[i][k].getTabRiviere()[RIVIERE_BAS])
					cout<<"§§§§§§§§§§";
				else if(i==0 || k==0 || i==LIGNE-1 || k==COLONNE-1 || k==COLONNE-2)
					cout<<"----------";
				else
					cout<<"           ";

				if(k==COLONNE-1)
					cout<<"----------";
			}
		}
		else
		{
			cout<<" |";
			for(int k = 0; k<COLONNE; k++)
			{
				if(tab[i][k].getTabRiviere()[RIVIERE_DROITE])
					cout<<"          §";
				else if(i==0 || k==0 || i==LIGNE-1 || k==COLONNE-1 || k==COLONNE-2)
					cout<<"          |";
				else
					cout<<"           ";
			}
		}
		cout<<endl;
	}

}

vector<Case*> Map::proposeCases(Case* impala)
{
	int i = impala->getX();
	int j = impala->getY();
	vector<Case*> retour;

	/*
	 * Dans ce cas on renvoi une ligne entiere
	 */
	if(i>0)
	{
		/*Seules les cases du jeu nous interesse
		 * Celles de l'impala ne servent a rien
		 */
		for(int k = 1;k<COLONNE-1;k++)
		{
			if(tab[i][k].getPionCase()==NULL)
				retour.push_back(&tab[i][k]);
		}
	}
	/*
	 * Dans ce cas on renvoi une colonne entiere
	 */
	else
	{
		/*Seules les cases du jeu nous interesse
		 * Celles de l'impala ne servent a rien
		 */
		for(int k = 1;k<LIGNE-1;k++)
		{
			if(tab[k][j].getPionCase()==NULL)
				retour.push_back(&tab[k][j]);
		}

	}
	return retour;
}
