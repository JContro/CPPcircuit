#ifndef CIRCUIT_CPP
#define CIRCUIT_CPP


#include "circuit.h"
#include "Components.h"
#include "AddSeriesParallel.h"
using namespace std;

circuit::circuit() { component_pointer = nullptr;
    
}

void circuit::add2Map(string name, shared_ptr<component> comp) {
	library_map[name] = comp;
}

shared_ptr<component> circuit::insert_component(istream &is) {
    shared_ptr<component> component_input;
    char key_char;
    is >> key_char;
    if (key_char == '{') {
        component_input = insert_parallel(is);  
    } else if (key_char == '(') {
        component_input = insert_series(is); 
    } else if (key_char == '"')  {
        component_input = add_real_component(is); 
    } else if (key_char == '}' || key_char == ')') {
        cerr << "There was an error trying to open an empty chain of components" << endl;
    }
    return component_input;
}

shared_ptr<ParallelChain> circuit::insert_parallel(istream& is) {
    shared_ptr<ParallelChain> Pchain = make_shared<ParallelChain>();
    int switch_num = 0;
    while (switch_num != 1) {
        Pchain->add_component(insert_component(is));
        cout << "Added component" << endl;
        char key_char;
        if (is >> key_char) {
            if (key_char == '+') {
                cout << "taking +" << endl; break; // break here is to exit the if loop and go to 
            } else if (key_char == '}') {
                switch_num = 1; break;
            } else {
                cerr << "There was an error trying to add a component to the parallel chain" << endl;
            }
            
        } else {switch_num = 1;}
    } return Pchain;
}

shared_ptr<SeriesChain> circuit::insert_series(istream& is) {
    shared_ptr<SeriesChain> Schain = make_shared<SeriesChain>();
    int switch_num = 0;
    while (switch_num != 1) {
        Schain->add_component(insert_component(is));
        cout << "Added component" << endl;
        char key_char;
        if (is >> key_char) {
            if (key_char == '+') {
                cout << "taking +" << endl; break; // break here is to exit the if loop and go to 
            } else if (key_char == '}') {
                switch_num = 1; break;
            } else {
                cerr << "There was an error trying to add a component to the series chain" << endl;
            }
            
        } else {switch_num = 1;}
    } return Schain;
}

shared_ptr<component> circuit::add_real_component(istream &is){
	string name;
	getline(is, name, '"');
	if (library_map.find(name) == library_map.end()){
		cerr << "The component doesn't exist"<< name << endl; system("PAUSE");
		is.setstate(ios::failbit); return nullptr ;
	}else {
		cout << "Adding component.\n";
		return library_map[name]; 
	}
}



void circuit::add_resistor_library(string _name, double res) {
    shared_ptr<component> temp_res = make_shared<resistor>(res,_name);
    
    
}
circuit::~circuit() {}

complex<double> circuit::getimpedance() { // MUST UPDATE THIS EXPERIMENT!!
    complex<double> c(1.0,5.0);
    return c;
}
#endif