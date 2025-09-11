#include <iostream>
using namespace std;

int main()
{
    //Declare vars
    const double pie = 3.14000;
    double volume_Sphere, radius_sphere, radius_Cylinder, height_Cylinder, volume_Cylinder;
    string units = "m^3";

    /*Getting values from user (dont like bc nums can appear in the value)
    cout << "What units would you like to use (ex. m or NM): ";
    cin >> units;
    */

    //Getting Values
    cout << "What radius are you using for your sphere? ";
    cin >> radius_sphere;
    cout << "What radius are you using for your cylinder? ";
    cin >> radius_Cylinder;
    cout << "What height are you using for your cylinder? ";
    cin >> height_Cylinder;


    //Calculate and display values
    volume_Cylinder = pie * (radius_Cylinder * radius_Cylinder) * height_Cylinder;
    volume_Sphere = (4.00000/3.00000) * pie * (radius_sphere * radius_sphere * radius_sphere); 
    cout << "Here is your volume for the sphere: " << volume_Sphere << units <<endl;
    cout << "Here is your volume for the cylinder: " << volume_Cylinder<< units<<endl;

    return 0;
}


/*
Question 1:
Syntax Error -> Forgeting a semicolon on the end of a line
Runtime Error -> A while loop that runs infinitely without having a way of stopping
Logical Error -> A error in logic such as forgetting to add something to an array before sorting it or forgetting
pie when trying to find the area of a circle
*/
/*
Question 2;
-List the numbers in the list unsorted
-Create a variable called "biggest" that holds the biggest number so far, assign the first value to it
-Create a variable called "smallest" that holds the smallest number so far
-give the second value in the list to the smallest variable, check first if its smaller then the other value, if so switch the numbers
-Create a variable that holds the testing number called "test"
-Create a for loop that loops for each number in the list
-give the first value to that variable
-compare the variables and whatever is bigger, is assigned to the "biggest"
-Whatever was the smaller variable from "smallest" vs the "test" , assign its value to another variable that holds the smallest number or drop it
-Compare the 3rd value to the other values and keep it if its the new smallest or biggest 
-if the number isnt the biggest or smallest, drop the value
-After having finished running through the list, display the largest and smallest number from the list
*/

/* Code for question 2
#include <iostream>
using namespace std;

int main()
{
    int list[] = {100,0,2,7,91,55,1,4,5,6};
    int biggest, smallest, testing_number, searching_num;
    biggest = list[0];
    if(list[1] <= list[0])
    {
        smallest = list[1];
    }
    else
    {
        biggest = list[1];
        smallest = list[0];
    }
    
    for(int num : list)
    {
        if(num > biggest)
        {
            biggest = num;
        }
        else if (num < smallest)
        {
            smallest = num;
        }
        
    }
    cout << "biggest is: " << biggest << endl << "the smallest is: " << smallest;
    return 0;
}
*/