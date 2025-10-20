#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void get_number_of_rolls(long &rolls);
void roll_dice(long &rolls, long *pointer);
void display_result(long numbers[]);
int snake_eyes_roller();
void display_result_snake_eyes(long value);

int main() 
{
  srand(time(0));
  long distribution_of_numbers[6] = {0};
  long total;
  long *numbers_pointer = &distribution_of_numbers[0];
  long number_of_rolls;
  get_number_of_rolls(number_of_rolls);
  roll_dice(number_of_rolls, numbers_pointer);
  display_result(distribution_of_numbers);
  total = snake_eyes_roller();
  display_result_snake_eyes(total);
  
  return 0;
}

void display_result_snake_eyes(long value)
{
  cout << endl << "Trying to roll double 1s..." << endl 
  << "omg it took " << value << " rolls to get snake eyes!" << endl;
}

void display_result(long numbers[])
{
  cout << "1 was rolled " << numbers[0] <<  " times"
  << endl << "2 was rolled " << numbers[1] <<  " times"
  << endl << "3 was rolled " << numbers[2] <<  " times"
  << endl << "4 was rolled " << numbers[3] <<  " times"
  << endl << "5 was rolled " << numbers[4] <<  " times"
  << endl << "6 was rolled " << numbers[5] <<  " times" << endl;
}

int snake_eyes_roller()
{
  int total_rolls = 0;
  int snake_eye_checker = 0;
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
        total_rolls++;
        return total_rolls;
      }
    }
    total_rolls++;
  }
    return total_rolls;
}

void roll_dice(long &rolls, long *pointer)
{
  for(long i = 0; i < rolls; i++)
  {
    int temp_roll = rand() % 6;
    pointer[temp_roll]++;
    }
}

void get_number_of_rolls(long &rolls)
{
  cout << "Let's roll some dice!" << endl << "Please enter the number of rolls to make: ";
  cin >> rolls;
  cout << "Rolling..." << endl;
}

/*
Question 1:
Pointers allow the creation and manipulation of 
arrays whose sizes are determined at runtime.
This is because a pointer can reference memory 
allocated dynamically, and pointer arithmetic 
lets us access array elements regardless of the 
array’s size.

Question 2:
Vectors are more efficient and flexible than 
standard arrays because they can automatically 
resize during runtime.
They allocate space as needed, so the program 
always has the right amount of memory for its 
data, avoiding wasted space or overflow errors.
*/
