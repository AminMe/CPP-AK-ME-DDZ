
#include "Action.h"
#include <sstream>

#include <iostream>
#include <utility>

#include "../Jeu/Map/Map.h"
#include "../Pion/Animal.h"
#include "../Pion/Pion.h"
#include "Joueur.h"
#include "../Jeu.h"


bool Action::put(Pion *a, Case* c)
{

   c->setPion(a);
   Animal *p = dynamic_cast<Animal*>(a);
   if(p!=NULL)
   {
   p->check(*c);
   return true;
   }
   else
	   return false;
}


bool Action::choixPion(Joueur * j,bool robot)
{
	j->affiche();
	int resultat,resultat2;
	Map& map = Map::Instance();
	vector<Case*> possibilite = map.proposeCases(impala.getC());

	if(!robot)
	{
		ostringstream m;
		m << "Veuillez choisir l'animal que vous voulez placer sur la map\n";
		for(int i=0; i<j->getMesAnimaux().size();i++)
		{
			m<<i+1<<". "<<j->getMesAnimaux().at(i)->getName()<<"\n";
		}
		string err = "Veuiller choisir un numero correct";

		resultat = Jeu::testSaisie(m.str(),1,j->getMesAnimaux().size(),err);



		string message = "Les differentes possibilite de placement du pion sont :\n";
		err.clear();
		err="Veuiller selectionner un numero correspondant au proposition \n";

		ostringstream m1;
		m1<<message;

		int i=1;
		for(Case* c : possibilite)
		{
			m1<<i<<". "<< " ligne : "<< c->getX()<< " colonne : "<< c->getY()<<"\n";
			i++;
		}
		m1<<"Selectionner la case ";

		resultat2 = Jeu::testSaisie(m1.str(),1,possibilite.size(),err);

	}
	else
	{
		resultat = tirage_entier(1,j->getMesAnimaux().size()+1);
		resultat2 = tirage_entier(1,possibilite.size()+1);
	}
	int idChoix = j->getMesAnimaux().at(resultat-1)->getId();
	vector<Animal*>::iterator it = j->getMesAnimaux().begin();

	for(int iterateur=0;iterateur<j->getMesAnimaux().size();iterateur++)
	{
		if(j->getMesAnimaux()[iterateur]->getId() == idChoix)
		{
			put(j->getMesAnimaux().at(resultat-1), possibilite[resultat2-1]);
			j->getMesAnimaux().erase(it+iterateur);
			iterateur=j->getMesAnimaux().size();
		}
	}
	return true;
}

int tirage_entier(int a,int b)
{
    int r;
    r=(rand()/((double)RAND_MAX))*(b-a)+a;
    return (int)r;
}

int Action::testSaisiBis(string message, string val)
{
	if(val!="x" && val!="y")
		return -1;
	bool ok = false;
	string position;
	int resultat = -1;
	int cpt = 0;
	while(!ok)
	{
		if(cpt!=0)
		{
			cout<<"Erreur veuillez re-saisir : ";
		}
		cout<<message<<endl;
		cin >>position;
		if(isInteger(position))
		{
			resultat = atoi(position.c_str());

			if(resultat==0 || (val=="y" && resultat<=COLONNE-1 && resultat>=0) || (val=="x" && resultat<=LIGNE-1 && resultat>0))
			{
				ok = true;
			}
		}
		if(cpt==0)
		{
			cpt ++;
		}
	}
	return resultat;
}

bool Action::deplacementImpalaPremiereFois()
{
	Map& map = Map::Instance();

	int x,y;

	x = testSaisiBis("Ligne : ","x");
	y = testSaisiBis("Colonne : ","y");

	pair<int, int> index(x,y);
	Case * c = map[index];

	if(c->getSecteur()==-1)
	{
		impala.setC(c);
		c->setPion(&impala);
		return true;
	}
	else
	{
		while(c->getSecteur()!=-1)
		{
			cout<<" Veuillez positionner impala sur une bonne case"<<endl;
			x = testSaisiBis("Ligne : ","x");
			y = testSaisiBis("Colonne : ","y");
			pair<int, int> index(x,y);
			c=map[index];
		}
		impala.setC(c);
		c->setPion(&impala);
		return false;
	}
}

bool Action::deplacementImpala(bool robot)
{
	vector<Case*> choix = estPossibleDeplacement();
	if(choix.empty())
	{
		if(parcourir(impala.getC()->getX(),impala.getC()->getY()) == NULL)
		{
			cout<<"Aucune disponibilte"<<endl;
			return false;
		}
		else
		{
			Case * caseImp = parcourir(impala.getC()->getX(),impala.getC()->getY());
			impala.getC()->setPion(NULL);
			impala.setC(caseImp);
			caseImp->setPion(&impala);
			return true;
		}
	}
	else
	{
		if(choix.size()==1)
		{
			cout<<"Il n'y a qu'une seule possibilite, Impala est placer automatiquement, c'est le tour du joueur suivant"<<endl;
			impala.getC()->setPion(NULL);
			impala.setC(choix[0]);
			choix[0]->setPion(&impala);
			return true;
		}
		else
		{
			int resultat;

			if(!robot)
			{
				ostringstream m;
				m<<"Vous avez "<<choix.size()<< " possibilite pour le deplacement de Impala\n";

				for(int i=0;i<choix.size();i++)
				{
					m<<i+1<<". La case i: "<<choix[i]->getX()<<" j: "<<choix[i]->getY()<<"\n";
				}
				m<<" Veuiller choisir la case sur laquelle vous voulez placer Impala"<<endl;
				resultat = Jeu::testSaisie(m.str(),1,choix.size(),"Veuiller choisir une variable correcte");
			}
			else
			{
				resultat = tirage_entier(1,choix.size()+1);
			}

			impala.getC()->setPion(NULL);
			impala.setC(choix[resultat-1]);
			choix[resultat-1]->setPion(&impala);
			return true;
		}
	}
}
vector<Case*> Action::estPossibleDeplacement()
{
	Map& map = Map::Instance();
	vector<Case*> possibilite;
	bool dispo;
	int x = impala.getC()->getX();
	int y = impala.getC()->getY();
	for(int i=1;i<4;i++)
	{
		/* Impala se situe au niveau de la premiere ligne */
		if(x==0)
		{
			if(map.getSecteur(x,y+1)==0)
			{
				dispo = caseDisponible(false,x+1);
				if(dispo)
				{
					pair<int, int> index(x+1,y+1);
					possibilite.push_back(map[index]);
				}
				x=x+1;
				y=y+1;
			}
			else
			{
				dispo = caseDisponible(true,y+1);
				if(dispo)
				{
					pair<int, int> index(x,y+1);
					possibilite.push_back(map[index]);
				}
				y=y+1;
			}

		}
		/*Impala se sotue au niveau de la derniere colonne */
		else if(y==COLONNE-1)
		{
			if(map.getSecteur(x+1,y)==0)
			{
				dispo = caseDisponible(true,COLONNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-1,COLONNE-2);
					possibilite.push_back(map[index]);
				}
				x = LIGNE-1;
				y = COLONNE-2;
			}
			else
			{
				 dispo = caseDisponible(false,x+1);
				 if(dispo)
				 {
					 pair<int, int> index(x+1,y);
					 possibilite.push_back(map[index]);
				 }
				 x = x+1;

			}
		}
		/* Impala se situe au niveau de la derniere ligne */
		else if(x==LIGNE-1)
		{
			if(map.getSecteur(x,y-1)==0)
			{
				dispo = caseDisponible(false,LIGNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-2,0);
					possibilite.push_back(map[index]);
				}
				x = LIGNE-2;
				y = 0;
			}
			else
			{
				dispo = caseDisponible(true,y-1);
				if(dispo)
				{
					pair<int, int> index(x,y-1);
					possibilite.push_back(map[index]);
				}
				y=y-1;
			}
		}
		/* Impala se situe au niveau de la premiere colonne */
		else if(y==0)
		{
			if(map.getSecteur(x-1,y)==0)
			{
				dispo = caseDisponible(true,1);
				if(dispo)
				{
					pair<int, int> index(0,1);
					possibilite.push_back(map[index]);
				}
				x=0;
				y=1;
			}
			else
			{
				dispo = caseDisponible(false,x-1);
				if(dispo)
				{
					pair<int, int> index(x-1,y);
					possibilite.push_back(map[index]);
				}
				x = x-1;
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
		for(int i=1;i<LIGNE-1;i++)
		{
			pair<int, int> index(i,x);
			if(!map[index]->isEstOccupe())
				return true;
		}
	}
	else
	{
		for(int i=1;i<COLONNE-1;i++)
		{
			pair<int, int> index(x,i);
			if(!map[index]->isEstOccupe())
			{
				return true;
			}
		}
	}

	return false;
}

Case* Action::parcourir(int x, int y)
{
	/* Parcours du plateau */
	/* On sait qu'il y a au plus : 26 */

	Map& map = Map::Instance();
	bool dispo = false;

	for(int i=0; i<26;i++)
	{
		if(x==0)
		{
			if(map.getSecteur(x,y+1)==0)
			{

				dispo = caseDisponible(false,x+1);
				if(dispo)
				{
					pair<int, int> index(x+1,y+1);
					return map[index];
				}
				x=x+1;
				y=y+1;
			}
			else
			{
				dispo = caseDisponible(true,y+1);
				if(dispo)
				{
					pair<int, int> index(x,y+1);
					return map[index];
				}
				y=y+1;
			}

		}
				/*Impala se sotue au niveau de la derniere colonne */
		else if(y==COLONNE-1)
		{
			if(map.getSecteur(x+1,y)==0)
			{
				dispo = caseDisponible(true,COLONNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-1,COLONNE-2);
					return map[index];
				}
				x = LIGNE-1;
				y = COLONNE-2;
			}
			else
			{
				 dispo = caseDisponible(false,x+1);
				 if(dispo)
				 {
					 pair<int, int> index(x+1,y);
					 return map[index];
				 }
				 x = x+1;
			}
		}
		/* Impala se situe au niveau de la derniere ligne */
		else if(x==LIGNE-1)
		{
			if(map.getSecteur(x,y-1)==0)
			{
				dispo = caseDisponible(false,LIGNE-2);
				if(dispo)
				{
					pair<int, int> index(LIGNE-2,0);
					return map[index];
				}
				x = LIGNE-2;
				y = 0;
			}
			else
			{
				dispo = caseDisponible(true,y-1);
				if(dispo)
				{
					pair<int, int> index(x,y-1);
					return map[index];
				}
				y=y-1;
			}
		}
		/* Impala se situe au niveau de la premiere colonne */
		else if(y==0)
		{
			if(map.getSecteur(x-1,y)==0)
			{
				dispo = caseDisponible(true,1);
				if(dispo)
				{
					pair<int, int> index(0,1);
					return map[index];
				}
				x=0;
				y=1;
			}
			else
			{
				dispo = caseDisponible(false,x-1);
				if(dispo)
				{
					pair<int, int> index(x-1,y);
					return map[index];
				}
				x = x-1;
			}
		}
	}
	return NULL;
}

inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}
