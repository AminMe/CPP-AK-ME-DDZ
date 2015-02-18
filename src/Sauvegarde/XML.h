/*
 * XML.h
 *
 *  Created on: 18 févr. 2015
 *      Author: Amin
 */

#ifndef SRC_SAUVEGARDE_XML_H_
#define SRC_SAUVEGARDE_XML_H_

#include <string>

using namespace std;

class XML {
private:
	string name;
public:
	static string datarepertory = "../Data";
	XML(){}

	XML(string name):name(name)
	{

	}
	virtual ~XML(){}

	string getName() const {
		return name;
	}
};

#endif /* SRC_SAUVEGARDE_XML_H_ */
