#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
Examples: 

5
five

49
forty nine

525
five hundred twenty five

1111
one thousand one hundred eleven

20105
twenty thousand one hundred five

456789
four hundred fifty six thousand seven hundred eighty nine
*/
string convert_number_recursive(long num);
void get_input(long& num);
// read in a number from the user

string convert_number(long num);
// handling outputting of large factors from billion -> hundreds

string parse_hundreds(int num);
// handle outputting hundreds independently 

const string TENS[] = {"", "", "twenty", "thirty", "forty", "fifty", 
                       "sixty", "seventy", "eighty", "ninety"};

const string BELOW_TWENTY[] =  {"zero", "one", "two", "three", "four", "five", 
                                "six", "seven", "eight", "nine", "ten", 
                                "eleven", "twelve", "thirteen", "fourteen", 
                                "fifteen", "sixteen", "seventeen", "eighteen", 
                                "nineteen"};

// recursive approach
const string DENOMINATIONS[] = {"", "thousand", "million", "billion", "trillion",
                                "quadrillion", "quintillion", "sextillion",
                                "septillion", "octillion", "nonillion"};

// making some constants here to help the readability below
const long BILLION  = 1'000'000'000;
const long MILLION  = 1'000'000;
const long THOUSAND = 1'000;

int main()
{
    //Setting up Vars
    long number;
    char ask;

    //does the inputing and ouputting
    do 
    {
        get_input(number);
        if(number == 0)
        {
            cout << "zero";
        }
        cout << convert_number_recursive(number) << endl;

        cout << "Would you like another number [Y/N]: ";
        cin >> ask;
    } while (ask == 'Y' || ask == 'y');

    return 0;
}

//gets input from keyboard
void get_input(long& num)
{
    cout << "Please enter the number to convert: ";
    cin >> num;
}

//gets the number and turns it into string in 3 digits sections
string parse_hundreds(int num)
{
    string s = "";

    // split out hundreds component
    while(true)
    {
        if(num >= 100 && num < 1000)
        {
            s += (BELOW_TWENTY[num/100]);
            s += " ";
            s += ("hundred");
            num = num - ((num/100) *100);
        }
        // split out tens component
        else if(num >= 20 && num < 100)
        {
            s += (TENS[num/10]);
            num = num - ((num/10) *10);
        }
        // split out below 20 
        else if(num == 0)
        {
            break;
        }
        else
        {
            s += (BELOW_TWENTY[num]);
            break;
        };
        s += " ";
    }


    return s;
}

// iterative approach
string convert_number(long num)
{
    vector<string> word_part;
    string result;

    // push words into our string vector
    // from billions -> millions -> thousands -> hundreds -> the rest
    
    while(num > 0)
    {
        //sets a string to use when calling functions
        string temp_string;
        //takes the numbers and sections them then minuses the n until the next section
        if(num >= BILLION)
        {
            temp_string = parse_hundreds(num/BILLION);
            word_part.push_back(temp_string);
            word_part.push_back(DENOMINATIONS[3]);
            num = num - ((num/BILLION) *BILLION);
        }
        else if(num >= MILLION && num < MILLION*1000)
        {
            temp_string = parse_hundreds(num/MILLION);
            word_part.push_back(temp_string);
            word_part.push_back(DENOMINATIONS[2]);
            num = num - ((num/MILLION) *MILLION);
        }
        else if(num >= THOUSAND && num < THOUSAND*1000)
        {
            temp_string = parse_hundreds(num/1000);
            word_part.push_back(temp_string);
            word_part.push_back(DENOMINATIONS[1]);
            num = num - ((num/THOUSAND) *THOUSAND);
        }
        else{
            temp_string = parse_hundreds(num);
            word_part.push_back(temp_string);
            num = 0;
        }
        // parse billion component
        // continue with remainder

        // parse million component
        // continue with remainder

        // etc.

        // deal with last hundred component
        // exit
    }
    for(string s : word_part)
    {
        result += s;
        result += " "; 
    }
    return result;
    // collapse our vector string down into a single string
}


// recursive approach
// we are breaking incoming number down into chunks of max 3 digits
// and then converting the chunk into text using parse hundreds. 
// we continue processing the rest of the string recursively.
string convert_number_recursive(long num)
{
    string str_num, chunk_process, chunk_left, result;
    str_num = to_string(num);
    
    // pull the leading chunk off the string, broken into 3 digits chunks
    // eg. 123456 -> we want the 123
    int chunk_size = str_num.length()%3;
    if(chunk_size == 0) chunk_size = 3;
    chunk_process = str_num.substr(0, chunk_size);
    result += parse_hundreds(stoi(chunk_process));

    chunk_left = str_num.substr(chunk_size, str_num.size()-chunk_size);
    result += " " + DENOMINATIONS[chunk_left.size()/3] + " "; 

    if(!chunk_left.empty())
    {
        result += convert_number_recursive(stoi(chunk_left));
    }
    // get whats left and add appropriate denominations to the string output
    // eg. 123456 -> we want the 456
    
    // if we have anything left, make our recursive call
 
    return result;
}


