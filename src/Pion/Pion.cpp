/*
 * Pion.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "Pion.h"

void Pion::affiche()
{
	std::cout<<"Le nom du pion est : "<<name<<endl;
	std::cout<<"Il est situer sur la case x: "<<c.getX() << "y: "<<c.getY()<<endl;
}
