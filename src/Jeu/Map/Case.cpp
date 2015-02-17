/*
 * Case.cpp
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#include "Case.h"

#include <sstream>

#include "../../Pion/Pion.h"
#include "Map.h"

using namespace std;

void Case::affiche()
{
	if(secteur==-1){
		cout<<"       o       ";
	}
	else if((x==0 && y==0) || (x==0 && y==COLONNE-1) || (x==LIGNE-1 && y==0) || (x==LIGNE-1 && y==COLONNE-1))
	{
		cout<<" --------> ";
	}
	else{
		cout<<"Case : "<<getX()<<","<<getY()<<" s ="<<secteur;
	}
}

string Case::getAffiche()
{
	string message = "";
	if(secteur==-1){
		return "    o     ";
	}
	else if((x==0 && y==0) || (x==0 && y==COLONNE-1) || (x==LIGNE-1 && y==0) || (x==LIGNE-1 && y==COLONNE-1))
	{
		return "    ->    ";
	}
	else{
		//message = "("+"a"+","+getY()+") s ="+secteur;
		ostringstream m;
		if(x>=10 || y>=10)
		{
			if(x>=10 && y>=10)
			{
				m<<"("<<getX()<<","<<getY()<<")s="<<secteur;
			}
			else
			{
				m<<"("<<getX()<<","<<getY()<<") s="<<secteur;
			}
		}
		else
		{
			m<<"("<<getX()<<","<<getY()<<") s= "<<secteur;
		}
		message = m.str();
	}
	return message;
}


string Case::getPionAffiche()
{
	string message = "";
	if(pionCase==NULL)
	{
		return "   Vide   ";
	}
	else{
		//message = "("+"a"+","+getY()+") s ="+secteur;
		ostringstream m;
		m<<"("<<pionCase->getName()<<")";
		message = m.str();
	}
	return message;
}
