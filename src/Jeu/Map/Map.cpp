/*
 * Map.cpp
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#include "Map.h"

#include <string>

#include "../../Jeu.h"
#include "../../Joueur/Joueur.h"
#include "../../Pion/Animal.h"


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
					cout<<message<<"|" /*"          |"*/;
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
					cout<<"~~~~~~~~~~";
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

void Map::gainBonus(Jeu j)
{
	for(Joueur *joueur : j.getJoueur())
	{
		if(joueur->getBonus())
		{
			return;
		}
	}

	/*
	 * Si on est la aucun joueur n'a encore eu de bonus
	 * On cherche si un joueur a eu le bonus
	 */
	for(int secteur = 1; secteur<7; secteur++)
	{
		chercheBonus(j,secteur);
	}

}

void Map::chercheBonus(Jeu j, int secteur)
{
	if(secteur<1)
		return;

	vector<Case*> caseSecteur;

	/*
	 * On cherche les cases de ce secteur
	 */
	caseSecteur = getCaseSecteur(secteur);

	/*
	 * On a toutes les cases du secteur
	 * On recupere la liste de joueur dessus
	 * (1,1,2) signigie que le joueur 1 est present 2 fois et le joueur 2 est present 1 fois
	 */
	vector<int> idJoueur = getListJoueur(caseSecteur);

	/*
	 * Si on arrive la toute les case du secteur sont bien occupe
	 * Le but est de cherche quel joueur a la majorite
	 */
	int occurence[j.getJoueur().size()];

	int cpt = 0;

	for(Joueur *joueur : j.getJoueur())
	{
		cpt = 0;
		for(int id : idJoueur)
		{
			if(id == joueur->getNum())
			{
				cpt++;
			}
		}
		occurence[joueur->getNum()] = cpt;
	}



	/*
	 * On cherche le max
	 */
	int max = 0;
	int idMax = 0;
	for(int k = 0; k<j.getJoueur().size(); k++)
	{
		if(max<occurence[k])
		{
			max = occurence[k];
			idMax = k;
		}
	}
    cout<<"Le joueur "<<idMax<<" gagne le bonus sur le secteur "<<secteur<<endl;
	j.getJoueur()[idMax]->setBonus(true);

}

bool Map::estComplete(Jeu jo)
{

	for(int i = 1; i<LIGNE-1; i++)
	{
		for(int j = 1; j<COLONNE-1; j++)
		{
			Animal *p = dynamic_cast<Animal*>(tab[i][j].getPionCase());
			if(p==NULL)
				return false;
		}
	}

	for(int secteur = 1; secteur<7; secteur++)
	{
		chercheJoueurEnMajorite(jo,secteur);
	}

	return true;
}

void Map::chercheJoueurEnMajorite(Jeu j, int secteur)
{
	vector<Case*> caseSecteur;

   /*
	* On cherche les cases de ce secteur
	*/
	caseSecteur = getCaseSecteur(secteur);

	vector<int> idJoueur = getListJoueur(caseSecteur);

	int occurence[j.getJoueur().size()];

	int cpt = 0;

	for(Joueur *joueur : j.getJoueur())
	{
		cpt = 0;
		for(int id : idJoueur)
		{
			if(id == joueur->getNum())
			{
				cpt++;
			}
		}
		occurence[joueur->getNum()] = cpt;
	}

	/*
	 * On cherche le max
	 */
	int max = 0;
	int idMax = 0;
	for(int k = 0; k<j.getJoueur().size(); k++)
	{
		if(max<occurence[k])
		{
			max = occurence[k];
			idMax = k;
		}
	}

	j.getJoueur()[idMax]->addPoint(getPoint(caseSecteur));

}

vector<Case*> Map::getCaseSecteur(int secteur)
{
	vector<Case*> caseSecteur;
	for(int i = 1; i<LIGNE-1; i++)
	{
		for(int j = 1; j<COLONNE-1; j++)
		{
			if(tab[i][j].getSecteur()==secteur)
			{
				caseSecteur.push_back(&tab[i][j]);
			}
		}
	}
	return caseSecteur;
}

vector<int> Map::getListJoueur(vector<Case*> caseSecteur)
{
	vector<int> idJoueur;
	for(Case *c : caseSecteur)
	{
		if(c->getPionCase()==NULL)
		{
			return idJoueur;
		}

		Animal *p = dynamic_cast<Animal*>(c->getPionCase());
		if (p == NULL)
			return idJoueur;

		idJoueur.push_back(p->getJoueur()->getNum());
	}
	return idJoueur;
}

int Map::getPoint(vector<Case*> caseSecteur)
{
	int point = 0;

	for(Case * c : caseSecteur)
	{
		if(c->getPionCase()==NULL)
		{
			return 0;
		}

		Animal *p = dynamic_cast<Animal*>(c->getPionCase());
		if (p == NULL)
			return 0;

		point+=p->getValeur();
	}

	return point;
}
