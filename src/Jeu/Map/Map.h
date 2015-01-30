/*
 * Map.h
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef MAP_H_
#define MAP_H_
#include "Case.h"

#define TAILLE 15

using namespace std;
class Map {
private:

	Case **tab;
	int ligne,colonne;
public:

	/*
	 * Constructeur par defaut
	 */
	Map(int ligne, int colonne):ligne(ligne),colonne(colonne)
	{



		tab = (Case**) calloc(ligne,sizeof(Case*));
		if(tab==NULL)
		{
			cout<<"Erreur allocation"<<endl;
		}

		for(int j = 0; j<colonne; j++)
		{
			tab[j] = (Case*)calloc(colonne,sizeof(Case));
			if(tab[j]==NULL)
			{
				cout<<"Erreur allocation"<<endl;
			}
		}

		for(int i = 0; i<ligne; i++)
		{
			for(int j = 0; j<colonne; j++)
			{
				Case c(1,false);
				tab[i][j] = c;
			}
		}
	}

	/*
	 * Destructeur
	 */
	virtual ~Map(){cout<<"Destruction d'une Map"<<endl;}

	void init();

	void affiche();
};

#endif /* MAP_H_ */
