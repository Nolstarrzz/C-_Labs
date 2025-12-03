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
        friend Image operator +(Image& im1, Image& im2)
        {
            Image temp;
            for(int i = 0; i < RESOLUTION; i++)
            {
                for(int j = 0; j < RESOLUTION; j++)
                {
                    if(im1.Box[i][j] == im1.filled || im2.Box[i][j] == im1.filled)
                    {
                        temp.setPixel(i,j);
                    }
                }
            }
            return temp;
        }
        friend ostream& operator <<(ostream& outs, Image& im)
        {
            for(int i=0;i<RESOLUTION;i++)
            {
                for(int j=0;j<RESOLUTION;j++)
                {
                    outs << im.Box[i][j];
                }
                outs << endl;
            }
            outs << endl;
            return outs;
        }
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
};

class Triangle : public Image{
    private:
        void fill()
        {
            for(int i=0;i<RESOLUTION;i++)
            {
                for(int j=0;j<RESOLUTION;j++)
                {
                    if(i >= j)
                        setPixel(i,j);
                }
            }
        }
    public:
        Triangle() : Image() { fill(); }

};

int main()
{
    Triangle t1, t2, t3;
    Image im1, im2, im3;
    im1.setPixel(0,0);
    im2.setPixel(1,1);
    im3 = im1 + im2;
    im3.output();
    
    t1.flip();
    t1.output();
    im3 = t1 + t2;
    im3.output();
	
}