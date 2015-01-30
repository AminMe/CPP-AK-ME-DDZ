/*
 * Case.h
 *
 *  Created on: 26 janv. 2015
 *      Author: firminrabefiringa
 */

#ifndef CASE_H_
#define CASE_H_

class Case {
public:
	int x;
	int y;
	int secteur;
	bool estOccupe;
	Case (int posiX, int posiY, int secteurNum);
	void setOccupe(bool caseOcupe);

	virtual ~Case();
};

#endif /* CASE_H_ */
