#include <iostream>
#include <cmath>
using namespace std;
int calc_factorial();

int main() {
    int finished_factorial = calc_factorial();
    cout << "Here is your num: " << endl << finished_factorial;
    return 0;
}

int calc_factorial()
{
    double num;
    while(num < 1)
    {
        cout << "Give me a number, not less then 0: " << endl;
        cin >> num;
    }
    int finished_num = num;
    for(int i=1; i<num ;i++)
    {
        finished_num = finished_num * (i);
    }
    return finished_num;
}
