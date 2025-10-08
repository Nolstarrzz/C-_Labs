#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void get_number_of_rolls(int &rolls);
void roll_dice(int &rolls, int *pointer);
void display_result(int numbers[]);
int snake_eyes_roller();
void display_result_snake_eyes(int value);

int main() 
{
  srand(time(0));
  int distribution_of_numbers[6] = {0};
  int total;
  int *numbers_pointer = &distribution_of_numbers[0];
  int number_of_rolls;
  get_number_of_rolls(number_of_rolls);
  roll_dice(number_of_rolls, numbers_pointer);
  display_result(distribution_of_numbers);
  total = snake_eyes_roller();
  display_result_snake_eyes(total);
  
  return 0;
}

void display_result_snake_eyes(int value)
{
  cout << endl << "Trying to roll double 1s..." << endl 
  << "omg it took " << value << " rolls to get snake eyes!";
}

void display_result(int numbers[])
{
  cout << "1 was rolled " << numbers[0] <<  " times"
  << endl << "2 was rolled " << numbers[1] <<  " times"
  << endl << "3 was rolled " << numbers[2] <<  " times"
  << endl << "4 was rolled " << numbers[3] <<  " times"
  << endl << "5 was rolled " << numbers[4] <<  " times"
  << endl << "6 was rolled " << numbers[5] <<  " times";
}

/*
  roll a 1 
  if it was a one then store it
  roll again
  if i was a one again, then it was snake eyes
*/
int snake_eyes_roller()
{
  int total_rolls = 0;
  int snake_eye_checker = 0;
  int num_snake_eyes;
  while(true)
  {
    int checker;
    int temp_roll = rand() % 6;
    checker = temp_roll + 1;
    if(checker == 1)
    {
      snake_eye_checker++;
      if(snake_eye_checker == 2)
      {
        num_snake_eyes++;
        break;
      }
    }
    total_rolls++;
  }
    return total_rolls;
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
