#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
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

const string ascii_pic = "########.##....##..######...########.....##...########..#######..\n"
                         "##.......###...##.##....##..##.....##..####...##.......##.....##.\n"
                         "##.......####..##.##........##.....##....##...##..............##.\n"
                         "######...##.##.##.##...####.########.....##...#######...#######..\n"
                         "##.......##..####.##....##..##...##......##.........##........##.\n"
                         "##.......##...###.##....##..##....##.....##...##....##.##.....##.\n"
                         "########.##....##..######...##.....##..######..######...#######..\n";


int main()
{
    ofstream outfile;
    ifstream infile;
    string resultingString;
    vector<string> lines;
    vector<string> newline;
    double encodedLength = 0.0;
    string filename = getFileName();
    outfile.open(filename);
    if(outfile.fail())
    {
        cout << "Failed ";
        exit(1);
    }
    splitString(lines);
    for(string s : lines)
    {
        outfile << evaluateLineOfString(s) << endl;
        cout << evaluateLineOfString(s) << endl;
    }
    outfile.close();
    infile.open(filename);
    if(infile.fail())
    {
        cout << "failed!!";
        exit(1);
    }
    findString(newline, infile);
    for (string s: newline)
    {
        cout << revertString(s) << endl;
        encodedLength += s.length();
    }
    infile.close();
    cout << "Source image size: " << ascii_pic.length() << endl 
    << "Encoded image size: " << encodedLength << endl << "Encoding is " 
    << abs(((encodedLength/ascii_pic.length()) * 100) - 100) << "% smaller!";
}

string revertString(string line)
{
    string returnString;
    int i=0;
    while(i<line.length())
    {
        char currentChar = line[i];
        int numstart = i+1;
        int numend = i+1;
        while(isdigit(line[numend])) 
        {
            numend++;
        }
        string currentNumber = line.substr(numstart, numend - numstart);
        int currentNum = stoi(currentNumber);
        for(int j = 0; j<currentNum; j++)
        {
            returnString += currentChar;
        }
        i = numend;
    }
    return returnString;
}

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

void findString(vector<string> &line, ifstream &filename)
{
    string currentline;
    while(getline(filename, currentline))
        line.push_back(currentline);
}

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

string getFileName()
{
    string file;
    cout << "Give me filename: ";
    cin >> file;
    return file;
}

/*
Line 5: Added a 4 into the parameters as string deck[][13] does not show the amount of string arrays in the array
Line 20: (drawn+i) = deck[suit][number]; This is wrong becasue it isnt accessing the value at the location so the *(drawn+i)
needs an asterisk in front of it to access the contents
Line 26: The line was checking the drawn then incrementing afterwards and moving the memory address itself reather then 
checking if it were the same card. SO the fix was to make it add the i value
Line 38-42: The array wasnt being initialized properly as it was using square brackets, the fix is to use {} to initialize the array
*/
