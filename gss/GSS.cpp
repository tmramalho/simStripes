#include "GSS.h"

GSS::GSS(FitnessFunction *ff) {
	SettingsCont *s = SettingsCont::getInstance();
	_dim = s->dim;
	_ff = ff;
	_init = NULL;
	_dtol = s->acc;
	_verbose = s->verbose;

	omp_set_num_threads(s->numThreads);
}
		
GSS::~GSS() {

}

void GSS::setInitConds(dvec *x) {
	if(x == NULL) _init = NULL;
	else if(x->size() == (unsigned int)_dim) _init = x;
	else _init = NULL;
}

dvec *GSS::makeRandomVector() {
	dvec *x = new dvec(_dim);

	for (int i = 0 ; i < _dim ; i++) {
		x->at(i) = mt_drand();
	}

	return x;
}

dvec *GSS::train() {
	
	double dtol = _dtol;
	double dstep = 3;
	double a = 1e-1;
	double absTol = 1e-3;
	int check = 0;
	
	std::vector<dvec*> *genSet = new std::vector<dvec*>;
	std::vector<double> *scoreList = new std::vector<double>;
	
	for (int i = 0 ; i < _dim ; i++) {
		dvec *basisElem = new dvec(_dim);
		basisElem->at(i) = 1;
		genSet->push_back(basisElem);
		scoreList->push_back(0);
		basisElem = new dvec(_dim);
		basisElem->at(i) = -1;
		genSet->push_back(basisElem);
		scoreList->push_back(0);
	}
	
	dvec *x;
	if(_init == NULL) x = this->makeRandomVector();
	else x = _init;
	
	double best = _ff->run(x);
	if(_verbose) std::cout << std::endl << "(GSS) Starting a new run at: " << best << std::endl << std::endl;
	
	while ( dstep > dtol ) {
		int success = 0;
		dvec xbest(_dim);
		
		if( dstep == 0.5 ) check = 0;
		
#pragma omp parallel for
		for ( unsigned int n=0 ; n < genSet->size(); n++ ) {
			/*int id = omp_get_thread_num();
#pragma omp critical
			std::cout << n << "," << id << std::endl;*/
			dvec *xn = new dvec(_dim);
			for(unsigned int i=0; i<x->size(); i++) {
				xn->at(i) = x->at(i) + genSet->at(n)->at(i) * dstep;
			}

			double score = _ff->run(xn);
			scoreList->at(n) = score;
#pragma omp critical
			{
				if((score + a*dstep*dstep) < best && fabs((score-best)/best) > absTol) {
					best = score;
					xbest.copy(xn);
					success = 1;
				}
			}

			delete xn;
		}

		if(!success) { //contract
			dstep *= 0.5;
			if( dstep <= dtol && check ) {
				dstep = 1;
			}
			if(_verbose) std::cout << "Contracting (" << dstep << "): " << best << std::endl;
		} else {
			if(_verbose == 2) std::cout << "(GSS) New best found: " << best << std::endl << xbest << std::endl;
			x->copy(xbest);
			check = 1;
		}
	}
	
	if(_verbose) std::cout << "(GSS) Result: " << best << std::endl << *x << std::endl;
	_best = best;
	
	for ( unsigned int n=0 ; n < genSet->size(); n++ ) {
		delete genSet->at(n);
	}
	
	delete genSet;
	delete scoreList;
	
	return x;
}
