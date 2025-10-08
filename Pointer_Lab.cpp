#include <iostream>
using namespace std;

struct Point {
  double x;
  double y;
};

void get_point(Point* p);                      // read x/y coordinates from the user into a Point p
void get_move_coordinates(float& x, float& y); // get the x and y coordinates to move the point
void move_point(Point& p, float x, float y);   // add the x and y offsets to the Point p
void print_point(Point* p);                      // print our position of Point P neatly to the screen


void get_point(Point* pt)
{
  cout << "Please enter the coordinates for the point: " << endl;
  cin >> pt->x >> pt->y;
}

void get_move_coordinates(float& x, float& y)
{
  cout << "Please enter the move coordinates (x y): " << endl;
  cin >> x >> y;
}

void move_point(Point& p, float x, float y)
{
  p.x += x;
  p.y += y;
}

void print_point(Point* p)
{
  cout << "The new position of the point is: (4, 8) " << p->x << " " << p->y;
}

int main ()
{
  float move_x, move_y;
  Point *p = new Point;
    // read in point 
  get_point (p);
    // read in move coordinates
  get_move_coordinates(move_x, move_y);
    // calculate new point position
  move_point(*p, move_x, move_y);
  print_point(p);
   return 0;
}


/* 
Definition:
Write a program that uses a struct to represent a Point 
in 2D space. The program should allow the user to input 
the coordinates for a point, and a move position (x/y) 
and the program will output the new position of the 
point. Use pointers/references for passing the point 
variable to functions for input, movement and distance.

Please enter the coordinates for the point: 1 3
Please enter the move coordinates (x y): 3 5
The new position of the point is: (4, 8)
*/
