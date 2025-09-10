#include <iostream>
using namespace std;

int main() 
{
    //Initialize the vars
    double fuel, fuel_efficiency, distance_left;

    //Getting the Vars Values
    cout << "Please enter the cars fuel efficiency in (L/100km)";
    cin >> fuel_efficiency;
    cout << "Please enter the fuel remaining in the tank (L) ";
    cin >> fuel;

    //equation for the distance left
    distance_left = (fuel * 100) / fuel_efficiency;

    //returning the variable
    cout << "You have" << distance_left << "kms left" << endl;
    
    return 0;
}