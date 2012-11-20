#ifndef GradientGSSearchModP_H_
#define GradientGSSearchModP_H_

#include <cstdlib>
#include <iostream>
#include <iostream>
#include <vector>
#include <cmath>
#include "../helpers/SettingsCont.h"
#include "../opt/FitnessFunction.h"
#include "mtwist.h"
#include "omp.h"

class GSS {
	
	public:
		GSS(FitnessFunction *ff);
		
		virtual ~GSS();
		
		dvec *train();
		void setFitnessFunction(FitnessFunction *ff) { _ff = ff; }
		void setInitConds(dvec *x);
		void setDim(int d) { _dim = d; }
		double getBestScore() { return _best; }
		
	private:
		dvec *makeRandomVector();
		
		FitnessFunction *_ff;
		
		int _dim;
		dvec *_init;
		double _best;
		double _dtol;
		int _verbose;
};

#endif /*GradientGSSearchModP_H_*/
