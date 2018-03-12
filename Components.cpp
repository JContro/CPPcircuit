#ifndef COMPONENTS_CPP
#define COMPONENTS_CPP

#include "Components.h"

using namespace std;

complex<double> inductor::getimpedance() { return impedance; }
complex<double> capacitor::getimpedance() { return impedance; }
complex<double> resistor::getimpedance() { return impedance; }

component::~component() {}





inductor::inductor(){ inductance = 0;  /* The impedance is set to 0,0 from default complex constructor*/ }
inductor::inductor(double _inductance, string _name) { 
	while (_inductance < 0 || cin.fail() || !_inductance) {
		cerr << "Error message: the inductance entered was not a valid input. Please re-enter: \n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	inductance = _inductance; impedance.imag(freq*inductance); 
        name = _name;
}
string inductor::getname() { return name; }





capacitor::capacitor() { capacitance = INFINITY; impedance.imag(1 / (freq*capacitance)); }
capacitor::capacitor(double _capacitance, string _name) {
	while (_capacitance < 0 || cin.fail() || !_capacitance) {
		cerr << "Error message: the capacitance entered was not a valid input. Please re-enter: \n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	capacitance = _capacitance; impedance.imag(1 / (freq*capacitance)); 
        name = _name;
}
string capacitor::getname() { return name; }



resistor::resistor() {resistance = 0; } // impedance set 0,0 from default constructor of complex
resistor::resistor(double _resistance, string _name) {
	while (_resistance < 0 || cin.fail() || !_resistance) {
		cerr << "Error message: the capacitance entered was not a valid input. Please re-enter: \n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	resistance = _resistance; impedance.real(resistance);
        name = _name;
}
string resistor::getname() { return name; }



#endif 