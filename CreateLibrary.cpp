
#include "CreateLibrary.h"
#include "Components.h"

library::library() {
    cout << "Welcome to the library creation tool: " << endl;
    cout << "To add resistor insert r, for an inductor insert i, and for a capacitor insert c: " << endl;
    char answer;
    cin >> answer;
    if (answer == "r") {
        //call the make make resistor function
       
    } else if (answer == "i"){
        //call inductor
    } else if (answer == "c"){
        //call capacitor
    }
}

void library::add_resistor() {
    cout << "You chose to insert a resistor in your library:" << endl;
    cout << "Please insert the name of the resistor without spaces:" << endl;
    string name;
    cin >> name;
    cout << "Please insert the resistance of the resistor in Ohms:" << endl;
    double resistance;
    cin >> resistance;
    shared_ptr<component> NewResistor = make_shared<resistor>(resistance,name);
    
    
}