/*
 * ImpalaJones.cpp
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#include "ImpalaJones.h"

ImpalaJones ImpalaJones::j_instance=ImpalaJones();

ImpalaJones& ImpalaJones::Instance()
{
	return j_instance;
}
