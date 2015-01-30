/*
 * Etat.h
 *
 *  Created on: 27 janv. 2015
 *      Author: Amin
 */

#ifndef SRC_ETAT_H_
#define SRC_ETAT_H_

class Etat {
public:
	Etat();
	virtual ~Etat();
	void play();
	void pause();
	void stop();
	void save();
	bool isFinished();
};

#endif /* SRC_ETAT_H_ */
