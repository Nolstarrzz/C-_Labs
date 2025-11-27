#include <iostream>
using namespace std;

const int RESOLUTION = 10;

class Image
{
    private:
        // private member variables for pixels and symbol
        char filled = '#';
        char empty = '_';
        // private fill
        char Box[RESOLUTION][RESOLUTION];
        void fill()
        {
            for(int i=0;i<RESOLUTION;i++)
            {
                for(int j=0;j<RESOLUTION;j++)
                {
                    Box[i][j] = empty;
                }
            }
        }
        
    public:
        char getSymbol() {return filled;}
        void setSymbol(char symbol) {filled = symbol;}
        char getPixel(int x, int y) {return Box[x][y];}
        Image()
        {
            fill();
        }
        void setPixel(int row, int column){Box[row][column] = filled;}
        void flip()
        {
            //when the space its on is filled, it will swap it to the other side of the box
            //then replaces the original with a space
            for(int i=0;i<RESOLUTION;i++)
            {
                for(int j=0;j<(RESOLUTION/2);j++)
                {
                    char temp = Box[i][j];
                    Box[i][j] = Box[i][RESOLUTION-j-1];
                    Box[i][RESOLUTION-j-1] = temp;
                }
            }
        }
        void flop()
        {
            //when the space its on is filled, 
            // it will swap it to the other side of the box with the other side thing
            for(int i=0;i<(RESOLUTION/2);i++)
            {
                for(int j=0;j<(RESOLUTION);j++)
                {
                    char temp = Box[i][j];
                    Box[i][j] = Box[RESOLUTION-i-1][j];
                    Box[RESOLUTION-i-1][j] = temp;
                }
            }
        }
        void output()
        {
            for(int i=0;i<RESOLUTION;i++)
            {
                for(int j=0;j<RESOLUTION;j++)
                {
                    cout << Box[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }
        // get/set symbol
        
        // get/set(2)/clear pixel
        
        // output
        
        // flip and flop

};

int main()
{

    Image im;
    im.setPixel(0,0);
    im.setPixel(2,2);
    im.setPixel(9,9);
    im.output();
    im.flip();
    im.output();
    im.flop();
    im.output();
    
	
}
/*
make a char array
if the row is correct, go to the next column
on the row if the row is correct and column is correct, put the mark
keep going down the rows untill the box it filled

take the value of where it is in the j box and do resolution - j
*/
