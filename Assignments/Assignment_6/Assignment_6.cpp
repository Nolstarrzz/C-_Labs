#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Vector3D
{
    private:
        double x = 0,y = 0,z = 0;
        string vectorNumber;
    
    public:
        Vector3D(string num)
        {
            vectorNumber = num;
        }
        void cross(Vector3D &otherVector)
        {
            double tempx,tempy,tempz, crossproduct;
            tempx = otherVector.getX();
            tempy = otherVector.getY();
            tempz = otherVector.getZ();
            output(((y * tempz)-(z * tempy)),((z * tempx)-(x * tempz)),((x * tempy)-(y * tempx)), 0);
            

        }
        void dot(Vector3D &otherVector)
        {
            double tempx,tempy,tempz, dotproduct;
            tempx = otherVector.getX();
            tempy = otherVector.getY();
            tempz = otherVector.getZ();
            dotproduct = (tempx * x) + (y * tempy) + (z * tempz);
            output(0, 0, 0, dotproduct);
        }
        double getX()
        {
            return x;
        }
        double getY()
        {
            return y;
        }
        double getZ()
        {
            return z;
        }
        void input()
        {
            cout << "Please enter the contents of the " << vectorNumber << " vector: ";
            double a,b,c;
            cin >> a >> b >> c;
            set(a,b,c);
        }
        double length()
        {
            return sqrt((x * x) + (y * y) + (z * z));
        }
        void output(double resultx, double resulty, double resultz, double dot)
        {
            if(dot != 0)
                cout << "The dot product of these vectors is: " << dot << endl;
            else
            {
                cout << "The cross product of these vectors is: (" << resultx << ", " << resulty << ", " << resultz << ")" << endl;
            }
        }
        void set(double a, double b, double c)
        {
            x = a;
            y = b;
            z = c;
        }
};


int main()
{
    Vector3D vector1("First");
    Vector3D vector2("Second");
    vector1.input();
    vector2.input();
    vector1.dot(vector2);
    vector1.cross(vector2);
}