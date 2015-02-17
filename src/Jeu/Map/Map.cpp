/*
 * Map.cpp
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#include "Map.h"


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

	for(i = 0; i<LIGNE;i++)
	{
		for(int k = 0; k<COLONNE; k++){cout<<"-----------";}
		cout<<endl;
		cout<<"|";
		for(int k = 0; k<COLONNE; k++){cout<<"          |";}

		cout<<endl;
		for(j = 0; j<COLONNE; j++)
		{
			message = tab[i][j].getAffiche();
			if(j==0)
			{
				cout<<"|";
				cout<<message;
				cout<<"|";
			}
			else if(j<COLONNE-1 && j>0)
			{
				if(j>0 && i>0 && i<LIGNE-2)
				{
					cout<<message<<"|";
				}
				else
				{
					cout<<message;cout<<"|";
				}
			}
			else
			{
				cout<<message;cout<<"|";
			}
			//cout<<" ";
		}

		cout<<endl;
		for(j = 0; j<COLONNE; j++)
		{
			message = tab[i][j].getPionAffiche();
			if(j==0)
			{
				cout<<"|";
				cout<<message;
				cout<<"|";
			}
			else if(j<COLONNE-1 && j>0)
			{
				if(j>0 && i>0 && i<LIGNE-2)
				{
					cout<<message<<"|";
				}
				else
				{
					cout<<message;
					cout<<"|";
				}
			}
			else
			{
				cout<<message;cout<<"|";
			}
			//cout<<" ";
		}


		cout<<endl;
		cout<<"|";
		for(int k = 0; k<COLONNE; k++){cout<<"          |";}
		cout<<endl;
		for(int k = 0; k<COLONNE; k++){cout<<"-----------";}
		cout<<endl;
	}

}
