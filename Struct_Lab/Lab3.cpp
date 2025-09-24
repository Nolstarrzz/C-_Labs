#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
};

Point get_point()
{
    Point point;
    cout << "Give me your point: ";
    cin >> point.x >> point.y;
    return point;
} //read in point coords from user and return a Point
float distance(Point p1, Point p2)
{
    double dist = sqrt((pow((p2.x - p1.x), 2.0)) + (pow((p2.y - p1.y), 2.0)));
    return dist;
}    
// calc the distance between 2 points

string get_equation(Point p1, Point p2)
{
    string equation;
    double slope = ((p2.y - p1.y) / (p2.x - p1.x));

    string b = to_string(p1.y - (slope * p1.x));
    string mx = to_string(slope);
    b = b.erase(b.find(".")+2);
    mx = mx.erase(mx.find(".")+2);

    //concatinates the string
    equation = "y = " + mx + "x " + "+ " + b;

    return equation;
} 
// use the string class to build a y=mx+b style string to return from this function
// keep the slope and intercept to one decimal
//you can use string.substr and string.find for this


int main()
{
    /*
        Read in point 1
        Read in point 2
        calc dist and output
        calc line equation and output
    */
    Point point1 = get_point();
    Point point2 = get_point(); 
    float calculated_distance = distance(point1, point2);
    string equation = get_equation(point1, point2);
    cout << "Here is your distance: ";
    cout << calculated_distance << endl;
    cout << "Here is your equation: ";
    cout << equation << endl;
    return 0;
}