#ifndef MAP_H_
#define MAP_H_

#include <cstdlib>
#include <iostream>

#include "Case.h"

#define TAILLE 5

using namespace std;
class Map {
private:
	Case **tab;
	int ligne,colonne;
	/* solution provisoire pour initialiser les scénario */
	int tabSecteur[5][6]={{1,2,3,3,3,3},{1,2,2,3,4,4},{1,1,2,3,3,4},{5,2,3,3,3,6},{5,5,6,6,6,6}};
	static Map& Instance();
public:


    Map& operator= (const Map&){}
    Map (const Map&){}

    static Map m_instance;




	/*
	 * Constructeur par defaut
	 */
	Map(int ligne, int colonne):ligne(ligne),colonne(colonne)
	{
		//tab = (Case**) calloc(ligne,sizeof(Case*));
		tab = new Case*[ligne];

		if(tab==NULL)
		{
			cout<<"Erreur allocation"<<endl;
		}

		for(int j = 0; j<ligne; j++)
		{
			//tab[j] = (Case*)calloc(colonne,sizeof(Case));
			tab[j] = new Case[colonne];
			if(tab[j]==NULL)
			{
				cout<<"Erreur allocation"<<endl;
			}

		}

		for(int i = 0; i<ligne; i++)
		{
			for(int j = 0; j<colonne; j++)
			{
				// pour les cases normaux
				if((i==0 )|| (j==0) || (i==ligne-1) || (j=colonne-1)){
				Case c(i,j,-1);
				tab[i][j] = c;
				}
				else{
				Case c(i, j, tabSecteur[i][j]);
				tab[i][j] = c;
				}
				//Todo : presence rivière ou non

			}
		}
	}

	/*
	 * Destructeur
	 */
	virtual ~Map(){cout<<"Destruction d'une Map"<<endl;}

	void init();

	void affiche();

	Case operator[](const std::pair<int,int>& Index)
	{
		return tab[Index.first][Index.second];
	}

	int getColonne() const {return colonne;}
	void setColonne(int colonne) {this->colonne = colonne;}
	int getLigne() const {return ligne;}
	void setLigne(int ligne) {this->ligne = ligne;}

};

#endif /* MAP_H_ */
