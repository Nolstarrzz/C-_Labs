#include <iostream>
#include <cmath>
using namespace std;
double calc_factorial(int nums);
double factorial_approximation(double calc_num);
double error_calc(int n, double nf);

int main() {
    int num = 0;
    while(num < 1)
    {
        cout << "Give me a number, not less then 1: " << endl;
        cin >> num;
    }
    double finished_factorial = calc_factorial(num);
    double approximation = factorial_approximation(num);
    double errors = error_calc(finished_factorial, approximation);
    cout << "Here is your num: " << endl << finished_factorial << endl;
    cout << "Here is your approximation: " << endl << approximation << endl;
    cout << "Here is your error: " << endl << errors << "%";
    return 0;
}

double calc_factorial(int nums)
{
    int finished_num = nums;
    for(int i=1; i<nums ;i++)
    {
        finished_num = finished_num * (i);
    }
    return finished_num;
}

double factorial_approximation(double n){
    return (sqrt(2 * M_PI * n) * pow((n/M_E), n));
}

double error_calc(int n, double nf)
{
    return ((abs(nf-n)/n) * 100);
}
