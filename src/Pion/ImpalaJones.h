/*
 * ImpalaJones.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_IMPALAJONES_H_
#define SRC_IMPALAJONES_H_

#include "Pion.h"

class ImpalaJones : public Pion {
public:
	ImpalaJones(int x, int y):Pion("Impala Jones",0,0){};
	virtual ~ImpalaJones(){}
};

#endif /* SRC_IMPALAJONES_H_ */
