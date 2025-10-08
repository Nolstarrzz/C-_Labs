#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void get_number_of_rolls(int &rolls);
void roll_dice(int &rolls, int *pointer);
void display_result(int numbers[]);

int main() 
{
  srand(time(0));
  int distribution_of_numbers[6] = {0};
  int *numbers_pointer = &distribution_of_numbers[0];
  int number_of_rolls;
  get_number_of_rolls(number_of_rolls);
  roll_dice(number_of_rolls, numbers_pointer);
  display_result(distribution_of_numbers);
  return 0;
}

void display_result(int numbers[])
{
  cout << "1 was rolled " << numbers[0] <<  " times"
  << "2 was rolled " << numbers[1] <<  " times"
  << "3 was rolled " << numbers[2] <<  " times"
  << "4 was rolled " << numbers[3] <<  " times"
  << "5 was rolled " << numbers[4] <<  " times"
  << "6 was rolled " << numbers[5] <<  " times";
}

void roll_dice(int &rolls, int *pointer)
{
  for(int i = 0; i < rolls; i++)
  {
    int temp_roll = rand() % 6;
    pointer[temp_roll]++;
    }
  }

void get_number_of_rolls(int &rolls)
{
  cout << "Let’s roll some dice!" << endl << "Please enter the number of rolls to make: ";
  cin >> rolls;
  cout << "Rolling...";
}
