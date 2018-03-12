#ifndef ADDSERIESPARALLEL_CPP
#define ADDSERIESPARALLEL_CPP

#include "AddSeriesParallel.h"
using namespace std;

void SeriesChain::add_component(shared_ptr<component> comp) {
	srs_chain.push_back(comp);
}

complex <double> SeriesChain::getimpedance() {
	vector<shared_ptr<component>>::iterator VectorIterator;
	complex<double> ImpedanceSum;
	for (VectorIterator = srs_chain.begin(); VectorIterator != srs_chain.end(); ++VectorIterator) {
		
		ImpedanceSum += (*VectorIterator)->getimpedance(); 
		
	}
	return ImpedanceSum;
};

void ParallelChain::add_component(shared_ptr<component> comp) {
	prl_chain.push_back(comp);
}

complex <double> ParallelChain::getimpedance() {
	vector<shared_ptr<component>>::iterator VectorIterator;
	complex<double> ImpedanceSum;
	for (VectorIterator = prl_chain.begin(); VectorIterator != prl_chain.end(); ++VectorIterator) {
		complex<double> temp = (*VectorIterator)->getimpedance();
		if (VectorIterator == prl_chain.begin()) {
			ImpedanceSum = temp;
		}
		else {
			ImpedanceSum = pow(temp, -1) + pow(ImpedanceSum, -1);
			ImpedanceSum = pow(ImpedanceSum, -1);
		}
	}
	return ImpedanceSum;
};


#endif 