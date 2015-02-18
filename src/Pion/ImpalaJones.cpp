/*
 * ImpalaJones.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include<stdio.h>

#include "ImpalaJones.h"

using namespace std;

ImpalaJones ImpalaJones::m_inst=ImpalaJones();

ImpalaJones& ImpalaJones::Instance()
{
	return m_inst;
}
