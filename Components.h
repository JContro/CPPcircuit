/* Header file for components 

*/

#ifndef COMPONENTS_H
#define COMPONENTS_H
const double pi = 3.14159265; // Define Pi
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <math.h>
#include <memory>


// Abstract base class components
class component {
protected:
	static double freq;
public:
	virtual ~component(); // Destructor
	// Overridden virtual function that applies to all components
	virtual complex<double> getimpedance() = 0;
	
};


class inductor : public component {
private:
	double inductance;
	complex<double> impedance;
	string name;
public:
	// Destructor
	virtual ~inductor() { cout << "inductor destructor called" << endl; }
	inductor(); // Default constructor
	inductor(double _inductance, string _name); // Par constructor
	complex<double> getimpedance();
	string getname();
        
	
};

class capacitor : public component {
private:
	double capacitance;
	complex<double> impedance;
	string name;
public:
	// Destructor
	~capacitor() {}
	capacitor(); 	// Default constructor
	capacitor(double _capacitance, string _name); // Par constructor
	complex<double> getimpedance(); // function to return impedance
	string getname();
};

class resistor : public component {
private:
	double resistance;
	complex<double> impedance;
	string name;
public:

	// Destructor
	virtual ~resistor() {}
	// Default constructor
	resistor(); 
	resistor(double _resistance, string _name); // Par constructor
	complex<double> getimpedance(); // function to return impedance
	string getname();
};


#endif