#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Vector3D
{
    //private variables that cannot be changed except for specific functions
    private:
        double x = 0,y = 0,z = 0;
        string vectorNumber;
    
    public:
        //constructor function
        Vector3D(string num)
        {
            vectorNumber = num;
        }
        //calculates the cross product using the values in another object as well as its own
        void cross(Vector3D &otherVector)
        {
            double tempx,tempy,tempz, crossproduct;
            tempx = otherVector.getX();
            tempy = otherVector.getY();
            tempz = otherVector.getZ();
            output(((y * tempz)-(z * tempy)),((z * tempx)-(x * tempz)),((x * tempy)-(y * tempx)), 0);
        }
        //gets the values from the other object to be able to use them to calculate the dot product
        void dot(Vector3D &otherVector)
        {
            double tempx,tempy,tempz, dotproduct;
            tempx = otherVector.getX();
            tempy = otherVector.getY();
            tempz = otherVector.getZ();
            dotproduct = (tempx * x) + (y * tempy) + (z * tempz);
            output(0, 0, 0, dotproduct);
        }
        //gets the x value from the object
        double getX()
        {
            return x;
        }
        //gets the y value from the object
        double getY()
        {
            return y;
        }
        //gets the z value from the object
        double getZ()
        {
            return z;
        }
        //gets the vector from the user to be able to be used
        void input()
        {
            cout << "Please enter the contents of the " << vectorNumber << " vector: ";
            double a,b,c;
            cin >> a >> b >> c;
            set(a,b,c);
        }
        //returns the length of the vector
        double length()
        {
            return sqrt((x * x) + (y * y) + (z * z));
        }
        //outputs the dot product and crossproduct, only one at a time when it is called specifically with certain perimeters
        void output(double resultx, double resulty, double resultz, double dot)
        {
            if(dot != 0)
                cout << "The dot product of these vectors is: " << dot << endl;
            else
            {
                cout << "The cross product of these vectors is: (" << resultx << ", " << resulty << ", " << resultz << ")" << endl;
            }
        }
        //sets the private variables in the object class
        void set(double a, double b, double c)
        {
            x = a;
            y = b;
            z = c;
        }
};

//sets up 2 different objects with different names for cout purposes
int main()
{
    Vector3D vector1("First");
    Vector3D vector2("Second");
    vector1.input();
    vector2.input();
    vector1.dot(vector2);
    vector1.cross(vector2);
}
