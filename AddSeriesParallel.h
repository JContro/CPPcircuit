#ifndef ADDSERIESPARALLEL_H
#define ADDSERIESPARALLEL_H

#include "Components.h"

// Make an object that contains other objects. Use pointers
class SeriesChain : public component {
public:
	
	vector<shared_ptr<component>> srs_chain;
	void add_component(shared_ptr<component> comp);
	complex<double> getimpedance();

};


class ParallelChain : public component {
public:

	vector<shared_ptr<component>> prl_chain;
	void add_component(shared_ptr<component> comp);
	complex<double> getimpedance();

};


#endif
