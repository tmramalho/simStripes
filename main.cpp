/*
 * main.cpp
 *
 *  Created on: Jan 12, 2012
 *      Author: tiago
 */


#include <iostream>
#include <time.h>
#include <vector>
#include <string>

#include "mtwist.h"

#include "helpers/SettingsCont.h"
#include "gss/GSS.h"
#include "opt/FitnessFunction.h"
#include "opt/TestFunction.h"
#include "opt/ProfileScore.h"
#include "numeric/dvec.h"
#include "helpers/SaveData.h"
#include "genetic/DiffEvolution.h"
#include "opt/BayesScore.h"

int main(int argc, char *argv[]) {
	//initialize random number generator
	mt_seed32( time(NULL) + getpid() );

	std::cout << "Welcome to stripes 2.0!" << std::endl;

	SettingsCont *s;
	s = SettingsCont::getInstance();
	s->setParameters(argc, argv);

	//optimization
	//FitnessFunction *f = new ProfileScore();
	FitnessFunction *f = new BayesScore();
	DiffEvolution *de = new DiffEvolution(f);
	dvec *res = de->train();
	GSS *gss = new GSS(f);
	gss->setInitConds(res);
	res = gss->train();
	SaveData::saveData(res, gss->getBestScore());

	return 0;
}

