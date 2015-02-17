/*
 * Action.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Action.h"

Action::Action() {
	// TODO Auto-generated constructor stub

}

Action::~Action() {
	// TODO Auto-generated destructor stub

}

bool Action::put(Pion *a, Case c, Case impala)
{
	if(!c.isEstOccupe())
	{
	   if(impala.getX()>0 && c.getX()==impala.getX())
	   {
		   c.setPion(a);
		   return true;
	   }
	   else if(impala.getY()>0  && c.getY()==impala.getY())
	   {
		   c.setPion(a);
		   return true;
	   }
	}

	return false;
}

bool Action::deplacementImpala(ImpalaJones *impala)
{
	Case *possible;
	possible = new Case[3];
	possible = estPossibleDeplacement(impala);
	Case *choix;

	int cpt = 0;
	for(int i=0; i<3;i++)
	{
		if(!possible[i].getX()!=-1)
			cpt++;
	}

	if(cpt!=0)
	{
		choix= new Case[cpt];
		int j=0;
		for(int i=0; i<3;i++)
		{
			if(possible[i].getX()!=-1)
			{
				choix[j] = possible[i];
				j++;
			}
		}

		if(cpt==1)
		{
			cout<<"Il n'y a qu'une seule possibilite, Impala est placer automatiquement, c'est le tour du joueur suivant";
			impala->setC(choix[0]);
		}
		else
		{
			int resultat;
			cout<<"Vous avez "<<cpt<< "possibilite pour le deplacement de Impala";
			for(int i=0;i<j;i++)
			{
				cout<<j+1<<". La case x: "<<choix[i].getX()<<"y: "<<choix[i].getY();
			}

			cout<<" Veuiller choisir la case sur laquelle vous voulez placer Impala";
			cin>>resultat;
			while(resultat>j || resultat<1)
			{
				cout<<"Veuiller choisir une variable correcte";
				cin>>resultat;
			}
			impala->setC(choix[resultat-1]);
		}
	}
	else
	{
		cout<<"Recherche automatique de la prochaine case disponible";
		/* Parcours de la map
		 * On garde en memoire le x et le y
		 * Si on parcours, et qu'on ne trouve rien
		 */
	}
	return true;
}

Case* Action::estPossibleDeplacement(ImpalaJones *impala)
{
	/* On commencer par regarder les 3 cases apres la postion de Impala*/
	/* Si on est sur x, et qu'on switch sur y FAUT GERER ÇA */
	Map& map = Map::Instance();
	/*Case *possibilite;
	possibilite = new Case[3];
	*/
	Case possibilite[3];
	bool dispo;
	for(int i=0;i<3;i++)
	{
		/* Impala se situe au niveau de la premiere ligne */
		if(impala->getC().getX()==0 && impala->getC().getY()>0)
		{
			if(map.getSecteur(impala->getC().getX(),impala->getC().getY()+1)==0)
			{
				/*On est sur une case interdite
				* on test sur le y+1, et on incremettant x aussi
				*/
				/* y doit bouher*/
				dispo = caseDisponible(false,impala->getC().getX()+1);
				if(dispo)
				{
					/* Peut être faire l'affichage directement ici */
					pair<int, int> index(impala->getC().getX()+1,impala->getC().getY());
					possibilite[i] = map[index];
				}
				else
				{
					possibilite[i]=Case();
				}

			}
			else
			{
				/* true => on regarde la ligne , false, on regarde la colonne*/
				dispo = caseDisponible(true,impala->getC().getY()+1);
				if(dispo)
				{
					pair<int, int> index(impala->getC().getX(),impala->getC().getY());

				}
				else
				{
					possibilite[i]=Case();
				}
			}

		}
		/*Impala se sotue au niveau de la derniere colonne */
		else if(impala->getC().getY()==COLONNE-1 && impala->getC().getX()>0)
		{
			if(map.getSecteur(impala->getC().getX()+1,impala->getC().getY())==0)
			{
				dispo = caseDisponible(true,COLONNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-1,COLONNE-2);
					possibilite[i] =  map[index];
				}
				else
				{
					possibilite[i]=Case();
				}
			}
			else
			{
				 dispo = caseDisponible(false,impala->getC().getX()+1);
				 if(dispo)
				 {
					 pair<int, int> index(impala->getC().getX()+1,impala->getC().getY());
					 possibilite[i] =  map[index];
				 }
				 else
				 {
					possibilite[i]=Case();
				 }

			}
		}
		/* Impala se situe au niveau de la derniere ligne */
		else if(impala->getC().getX()==LIGNE-1 && impala->getC().getX()>0)
		{
			if(map.getSecteur(impala->getC().getX(),impala->getC().getY()-1)==0)
			{
				dispo = caseDisponible(false,LIGNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-2,0);
					possibilite[i] =  map[index];
				}
				else
				{
					possibilite[i]=Case();
				}
			}
			else
			{
				dispo = caseDisponible(true,impala->getC().getY()-1);
				if(dispo)
				{
					pair<int, int> index(impala->getC().getX(),impala->getC().getY()-1);
					possibilite[i] =  map[index];
				}
				else
				{
					possibilite[i]=Case();
				}
			}
		}
		/* Impala se situe au niveau de la premiere colonne */
		else if(impala->getC().getX()>0 && impala->getC().getY()==0)
		{
			if(map.getSecteur(impala->getC().getX()-1,impala->getC().getY())==0)
			{
				dispo = caseDisponible(true,1);
				if(dispo)
				{
					pair<int, int> index(0,1);
					possibilite[i] =  map[index];
				}
				else
				{
					possibilite[i]= Case();
				}
			}

			else
			{
				dispo = caseDisponible(false,impala->getC().getX()-1);
				if(dispo)
				{
					pair<int, int> index(impala->getC().getX()-1,impala->getC().getY());
					possibilite[i] = map[index];
				}
				else
				{
					possibilite[i]= Case();
				}
			}
		}
	}
	return possibilite;
}

bool Action::caseDisponible(bool etat,int x)
{
	Map& map = Map::Instance();
	if(etat)
	{
		for(int i=1;i<COLONNE-1;i++)
		{
			pair<int, int> index(i,x);
			if(!map[index].isEstOccupe())
				return true;
		}
	}
	else
	{
		for(int i=1;i<LIGNE-1;i++)
		{
			pair<int, int> index(x,i);
			if(!map[index].isEstOccupe())
				return true;
		}
	}
	return false;
}
