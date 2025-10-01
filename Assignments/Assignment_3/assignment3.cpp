#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//declaring a struct
struct GIC
{
    float value;
    float interest_rate;
    int term;
};

//declaring functions
float calculate_interest(GIC account);
void display_account(GIC account, float interest);
GIC get_account_values();
void do_gic();

int main()
{
    do_gic();
    do_gic();
    return 0;
}

//does all the functions together in one so its easier to do it multiple times
void do_gic()
{
    float interest;
    GIC account;
    account = get_account_values();
    interest = calculate_interest(account);
    display_account(account, interest);
}

//calculate interest using an equation
float calculate_interest(GIC amount)
{
    return amount.value * (amount.interest_rate/100.0) * (amount.term / 12.0);
}

//displays the account and the calculated interest value
void display_account(GIC account, float interest)
{
    cout << "The interest generated on the account valued: "<< endl;
    cout << "$" << account.value << " at " << account.interest_rate<< "% is $" << interest << endl;    
}

//Gets a value from the user for a GIC account, then it removes the non number values (if the info is given correctly)
//and returns it
GIC get_account_values()
{
    GIC account1;
    string value, interest_rate;
    cout << "Please enter the value, interest rate and term remaining (months) for the GIC:" << endl;
    cin >> value >> interest_rate >> account1.term;
    account1.value = stof(value.substr(1));
    interest_rate.pop_back();
    account1.interest_rate = stof(interest_rate);
    return account1;
}

/*

Question 1:
Local Variable -> They are variables that can only be used in the function that it is declared in or the functions
that it is passed to. Its useful if you want the value to only do one thing like count up to 5 in a loop whenever the 
function is called but the variable shouldnt be used anywhere else

Global Variable -> They are variables that can be used anywhere in the function and their value can be affected anywhere in
the program. They are useful if the program is designed to reuse and change variables and their data to perform an action,
such as a bank account getting affected by deposits, tax and interest, they all should be able to change the variable

Question 2:
A enum that describes the length of each month of the year has to have each month in it as well as all their respective values
enum Month_Length{
    JAN = 31,
    FEB = 28,
    MAR = 31,
    APR = 30,
    MAY = 31,
    JUN = 30,
    JUL = 31,
    AUG = 31,
    SEP = 30,
    OCT = 31,
    NOV = 30,
    DEC = 31
};

*/
