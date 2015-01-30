#ifndef MAP_H_
#define MAP_H_
#include "Case.h"
#include <cstdlib>
#include <iostream>
#define TAILLE 5

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
				//Case c(1,false)
				Case c(i, j, 1);/* a definir secteur */
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
