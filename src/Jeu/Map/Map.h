#ifndef MAP_H_
#define MAP_H_

#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

#include "Case.h"

class Jeu;

#define LIGNE 7
#define COLONNE 8

using namespace std;

class Map {
private:
	Case **tab;
	static Map m_instance;

	/*
		 * Constructeur par defaut
		 */


		 Map& operator= (const Map& m){
		    return *this;
		 }

		 Map (const Map& m){
		    cout<<"Map::Singleton"<<endl;
		 }

public:
	static Map& Instance();

	Map()
			{
				//tab = (Case**) calloc(ligne,sizeof(Case*));
				/* A CHANGER SUREMENT */
				int tabSecteur[LIGNE][COLONNE]={{0,-1,-1,-1,-1,-1,-1,0},{-1,1,2,3,3,3,3,-1},{-1,1,2,2,3,4,4,-1},{-1,1,1,2,3,3,4,-1},{-1,5,2,3,3,3,6,-1},{-1,5,5,6,6,6,6,-1},{0,-1,-1,-1,-1,-1,-1,0}};
				bool tabRiviere[30][4] = {{false,true,false,false},{true,true,false,false},{true,false,false,true},{false,false,false,false},{false,false,false,true},{false,false,false,true},
										  {false,true,false,false},{true,false,false,true},{false,true,true,false},{true,true,false,false},{true,false,true,true},{false,false,true,false},
										  {false,false,false,true},{false,true,true,false},{true,true,false,false},{true,false,false,true},{false,true,true,true},{true,false,false,true},
										  {false,true,true,false},{true,true,false,true},{true,false,false,true},{false,false,true,true},{false,true,true,true},{true,false,true,false},
										  {false,false,false,false},{false,true,true,false},{true,false,true,false},{false,false,true,false},{false,false,true,false},{false,false,false,false}};
				/* Faire init des rivieres */
				tab = new Case*[LIGNE];

				if(tab==NULL)
				{
					cout<<"Erreur allocation"<<endl;
				}

				for(int j = 0; j<LIGNE; j++)
				{
					//tab[j] = (Case*)calloc(colonne,sizeof(Case));
					tab[j] = new Case[COLONNE];
					if(tab[j]==NULL)
					{
						cout<<"Erreur allocation"<<endl;
					}
				}
		        int w = 0;
		        for(int i = 0; i<LIGNE; i++)
				{
		        	for(int j = 0; j<COLONNE; j++)
					{

		        		Case c(i, j, tabSecteur[i][j]);

						if(i!=0 && j!=0 && i!=LIGNE-1 && j!=COLONNE-1)
						{
							for(int i=0; i<4; i++)
							{
							  c.setTab(i,tabRiviere[w][i]);
							}
							w++;
						}
						else
						{
							for(int i=0; i<4; i++){
								c.setTab(i,false);
							}
						}
						tab[i][j] = c;
					}
		        }
		        //m_instance = this;
			}


			/*
			 * Destructeur
			 */
			virtual ~Map(){
				cout<<"Destruction d'une Map"<<endl;
				/* LIBERATION  DE LA MEMOIRE */
			}



	void init();

	void affiche();

	Case * operator[](const std::pair<int,int>& Index)
	{
		return &tab[Index.first][Index.second];
	}
    /* solution provisoire */
	int getSecteur(int x, int y)
	{
		return tab[x][y].getSecteur();
	}

	int getColonne() const {return COLONNE;}
	int getLigne() const {return LIGNE;}


	vector<Case*> proposeCases(Case* impala);

	void gainBonus(Jeu j);
	void chercheBonus(Jeu j, int secteur);

	bool estComplete(Jeu j);
	void chercheJoueurEnMajorite(Jeu jo, int secteur);
	vector<Case*> getCaseSecteur(int secteur);
	vector<int> getListJoueur(vector<Case*> caseSecteur);
	int getPoint(vector<Case*> caseSecteur);
};

#endif /* MAP_H_ */
