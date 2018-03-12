/*	Final Project
	Jack Contro
	92200480
	26/4/2017

	AC circuits
	*Brief Description of the code*

*/


#include "Components.h"
#include "AddSeriesParallel.h"
#include "circuit.h"


using namespace std;

double component::freq = 10.0; // this is the angular frequency 

int main() {
	// Create a circuit and its library 
    cout << "Welcome to the AC circuit simulator" << endl;
    cout << "First you must create your library: " << endl;
    // 
    
    cout << "You have chosen to add a resistor to your library. Please enter the name of the resistor" << endl;
    string temp_name;
    cin >> temp_name;
    cout << "Now please enter the resistance of your resistor: " << endl;
    double temp_resistance;
    cin >> temp_resistance;
    cout << temp_resistance << endl;
    
    
    // test out whether this whole program works to give impedance 
    // create the library with a new circuit
    circuit NewCircuit;
    string name = "FirstObj";
    shared_ptr<component> FirstObj = make_shared<inductor>(2.3,name);
    NewCircuit.add2Map(name,FirstObj);
    name = "SecondObj";
    shared_ptr<component> SecondObj = make_shared<resistor>(2.3,name);
    NewCircuit.add2Map(name,SecondObj);
    name = "ThirdObj";
    shared_ptr<component> ThirdObj = make_shared<capacitor>(2.3,name);
    NewCircuit.add2Map(name,ThirdObj);
    
    
    cout << "Type in :" << endl;
    
    NewCircuit.insert_component(cin);
    
   
    
    getchar();
    

	return 0;
	
}