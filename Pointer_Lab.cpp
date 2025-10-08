#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void get_number_of_rolls(int &rolls);
int roll_dice(int &rolls);
void display_result(int rolls, int numbers[]);

int main() 
{
  srand(time(0));
  int distribution_of_numbers[5] = {0};
  int number_of_rolls;
  int *number_pointer = &number_of_rolls;
  get_number_of_rolls
    return 0;
}

void display_result(int &rolls, int numbers[])
{
  
}

int roll_dice(int &rolls)
{
  
}

void get_number_of_rolls(int &rolls)
{
  cout << "Let’s roll some dice!" << endl << "Please enter the number of rolls to make: ";
  cin >> &rolls;
  cout << "Rolling...";
}
