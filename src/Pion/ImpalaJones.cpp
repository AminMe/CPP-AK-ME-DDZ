/*
 * ImpalaJones.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include<iostream>
#include<stdio.h>

#include "ImpalaJones.h"

using namespace std;

ImpalaJones ImpalaJones::m_instance=ImpalaJones();


ImpalaJones& ImpalaJones::Instance()
{
	return m_instance;
}
