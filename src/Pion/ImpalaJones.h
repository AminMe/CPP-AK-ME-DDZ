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
private:
	ImpalaJones(int x, int y):Pion("Impala Jones",0,0){}
	ImpalaJones():Pion("Impala Jones",0,0){}
	virtual ~ImpalaJones(){}
	ImpalaJones& operator =(const ImpalaJones&){}
	ImpalaJones (const ImpalaJones&):Pion("Impala Jones",0,0){}
	static ImpalaJones m_instance;
public :
	static ImpalaJones& Instance();
};

#endif /* SRC_IMPALAJONES_H_ */
