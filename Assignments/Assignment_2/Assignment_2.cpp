#include <iostream>
using namespace std;
void get_input(double degrees_f[]);
void convert_to_celsius(double degrees_f[], double degrees_c[]);
void display_result(double degrees_c[]);

int main() 
{
    double results[5];
    double degrees_c[5];
    double degrees_f[5];
    get_input(degrees_f);
    convert_to_celsius(degrees_f, degrees_c);
    display_result(degrees_c);
}

//getting values from the user
void get_input(double degrees_f[])
{
    cout << "Please enter 5 temperatures to convert:";
    for(int i=0; i<5;i++)
    {
        cin >> degrees_f[i];
    }
}

//uses the equation to convert farenheit to celsius
void convert_to_celsius(double degrees_f[], double degrees_c[])
{
    for(int i=0;i<5;i++)
    {
        degrees_c[i] = (5.0/9.0)*(degrees_f[i] - 32.0); 
    }
}

//displays the results from the array
void display_result(double degrees_c[])
{
    for(int i=0;i<5;i++)
    {
        cout << "Your converted temps are: " << degrees_c[i] << endl;
    }
}

/*
Question 1:
-Memory Management
-Null Termination
-Functionality and Operators
-Type Safety
-Dynamic Sizing

Question 2:

line 19-> Logic Error as the number will be calculated 
but not answer the right thing as the division will be used first
Solution-> avg = (x + y + z) / 3

line 8-> Syntax Error as there isnt any initialization of the variables
of x, y, and z.
Solution->int x, y, x; -> in a line above it

line 19-> Possible out of bounds error, using different variables then allowed
in the function
Solution-> avg = (a + b + c) / 3;

Line 3-> Syntax error, variables not initialized in the function 

Line 11-> Syntax Error, using endline, when it should be endl
Solution: cout <<  compute_average(x,y,z) << endl;
*/
