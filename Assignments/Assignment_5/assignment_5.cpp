#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//so get a line, then find if its a # or ., then print the symbol
//and keep looking for it there are more and increment a counter,
//then put the symbol and the number into a string
//repeat till the line is done or /n, then do it again
//till the file is done
string evaluateLineOfString(string line);
string getFileName();
void splitString(vector<string> &lines);

const string ascii_pic = "##.....##.########.##.....##.\n"
                         "##.....##.##.......##.....##.\n"
                         "##.....##.##.......##.....##.\n"
                         "##.....##.######...##.....##.\n"
                         "##.....##.##........##...##..\n"
                         "##.....##.##.........##.##...\n"
                         ".#######..##..........###....\n";

int main()
{
    ofstream outfile;
    //ifstream infile;
    string resultingString;
    vector<string> lines; 

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
        cout << evaluateLineOfString(s) << endl;
    }
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