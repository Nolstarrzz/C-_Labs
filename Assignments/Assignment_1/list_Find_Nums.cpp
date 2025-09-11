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