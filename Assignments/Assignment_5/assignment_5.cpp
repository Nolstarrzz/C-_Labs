#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;
//so get a line, then find if its a # or ., then print the symbol
//and keep looking for it there are more and increment a counter,
//then put the symbol and the number into a string
//repeat till the line is done or /n, then do it again
//till the file is done
string evaluateLineOfString(string line);
string getFileName();
void splitString(vector<string> &lines);
void findString(vector<string> &line, ifstream &filename);
string revertString(string line);

const string ascii_pic =    "##.....##.####..######...##.....##.....#######..##....##....########.####.########..########.\n"
                            "##.....##..##..##....##..##.....##....##.....##.###...##....##........##..##.....##.##.......\n"
                            "##.....##..##..##........##.....##....##.....##.####..##....##........##..##.....##.##.......\n"
                            "#########..##..##...####.#########....##.....##.##.##.##....######....##..########..######...\n"
                            "##.....##..##..##....##..##.....##....##.....##.##..####....##........##..##...##...##.......\n"
                            "##.....##..##..##....##..##.....##....##.....##.##...###....##........##..##....##..##.......\n"
                            "##.....##.####..######...##.....##.....#######..##....##....##.......####.##.....##.########.\n";


int main()
{
    //declaring variables and setting correct files
    ofstream outfile;
    ifstream infile;
    string resultingString;
    vector<string> lines;
    vector<string> newline;
    double encodedLength = 0.0;
    string filename = getFileName();
        
    //opens the file and checks if the file opened correctly
    outfile.open(filename);
    if(outfile.fail())
    {
        cout << "Failed ";
        exit(1);
    }
    
    //splits the lines and places them into a vector
    splitString(lines);
    
    //outputs the contents of the vector to print the photo
    for(string s : lines)
    {
        outfile << evaluateLineOfString(s) << endl;
    }
    //opens the infile and closes the output file
    outfile.close();
    infile.open(filename);
    //checks if the file is open and throws error if wrong
    if(infile.fail())
    {
        cout << "failed!!";
        exit(1);
    }
    
    //gets the input from file and prints the redone ascii pic
    findString(newline, infile);
    for (string s: newline)
    {
        cout << revertString(s) << endl;
        //counts how many chars in the string (+1) is for the \n
        encodedLength += s.length() + 1;
    }
    infile.close(); //closes the file
    cout << "Source image size: " << ascii_pic.length() << endl 
    << "Encoded image size: " << encodedLength  << fixed << setprecision(2) << endl << "Encoding is " 
    << abs(((encodedLength/ascii_pic.length()) * 100) - 100) << "% smaller!";
}

//Turns the compressed version of the picture to the uncompressed version
string revertString(string line)
{
    string returnString;
    int i=0;
    //while there is still a char to read in
    while(i<line.length())
    {
        char currentChar = line[i];
        int numstart = i+1;
        int numend = i+1;
        //checks if it is a digit
        while(isdigit(line[numend])) 
        {
            numend++;
        }
        //converts the string to an int
        string currentNumber = line.substr(numstart, numend - numstart);
        int currentNum = stoi(currentNumber);
        //prints the amount of char of the number
        for(int j = 0; j<currentNum; j++)
        {
            returnString += currentChar;
        }
        i = numend;
    }
    return returnString;
}

//splits the big string by the \n and places each smaller string into a vector
void splitString(vector<string> &lines)
{
    int startPosition = 0;
    int endPosition = ascii_pic.find('\n', startPosition);
    while (endPosition != string::npos) 
    {
        string line = ascii_pic.substr(startPosition, endPosition - startPosition);
        lines.push_back(line);
        startPosition = endPosition + 1;
        endPosition = ascii_pic.find('\n', startPosition);
    }

}

//puts the input file string, into smaller strings and places it into a vector
void findString(vector<string> &line, ifstream &filename)
{
    string currentline;
    while(getline(filename, currentline))
        line.push_back(currentline);
}

//checks the char used and the number in a row of that cahr and compresses it into an int and its char
string evaluateLineOfString(string line)
{

    string returnString;
    int i = 0;
    while (i < line.length())
    {
        char currentChar = line[i];
        int count = 1;
        int j = i + 1;
        while (j < line.length() && line[j] == currentChar) {
            count++;
            j++;
        }
        returnString += currentChar;
        returnString += to_string(count);
        i = j;
    }
    return returnString;
}

//gets the filename from an input
string getFileName()
{
    string file;
    cout << "Give me filename: ";
    cin >> file;
    return file;
}

/*
Line 1: Missing the ctime library
Line 5: Added a 4 into the parameters as string deck[][13] does not show the amount of string arrays in the array
Line 20: (drawn+i) = deck[suit][number]; This is wrong becasue it isnt accessing the value at the location so the *(drawn+i)
needs an asterisk in front of it to access the contents
Line 26: The line was checking the drawn then incrementing afterwards and moving the memory address itself reather then 
checking if it were the same card. SO the fix was to make it add the i value
Line 38-42: The array wasnt being initialized properly as it was using square brackets, the fix is to use {} to initialize the array
*/
