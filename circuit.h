#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "AddSeriesParallel.h"
#include "Components.h"
#include <map> 
#include <iostream>
#include<memory>

class circuit : public component {
private:
	shared_ptr<component> component_pointer; 
        map<string, shared_ptr<component>> library_map; //Only want to access the library from inbuilt circuit functions
public:
	circuit();
	circuit(shared_ptr<component> comp);
	~circuit();
	vector<shared_ptr<component>> CircuitVector;
	void add2Map(string name, shared_ptr<component> comp);
	//friend istream &operator>>(istream &is, shared_ptr<component> comp);
	shared_ptr<component> insert_component(istream &is);
        shared_ptr<ParallelChain> insert_parallel(istream &is);
        shared_ptr<SeriesChain> insert_series(istream &is);
	shared_ptr<component> add_real_component(istream &is);
        void add_resistor_library(string _name, double res);
        complex<double> getimpedance();
};

	
#endif 