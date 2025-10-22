#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

const int CYPHER_OFFSET = 5;
void getSecretText(char text[50]);
string getFileName();

char encrypt(char c)
{
    char encrypted = c;
    // check if we get a character
    if(isalpha(encrypted))
    {
        if(isupper(encrypted))
        {
            for(int counter = 0; counter < CYPHER_OFFSET; counter++)
            {
                if(encrypted == 90)
                {
                    encrypted = 64;
                }
                encrypted++;
            }
            return encrypted;
        }
        if(islower(encrypted))
        {
            for(int counter = 0; counter < CYPHER_OFFSET; counter++)
            {
                if(encrypted == 122)
                {
                    encrypted = 96;
                }
                encrypted++;
            }
            return encrypted;
        }
    }
    else if(isdigit(encrypted))
    {
        for(int counter = 0; counter < CYPHER_OFFSET; counter++)
            {
                if(encrypted == 57)
                {
                    encrypted = 47;
                }
                encrypted++;
            }
            return encrypted;
    }    // upper case convert 
    else
    {
        return encrypted;
    }

        // lower case convert

    // or a digit and convert

    // pass through anything else

    return encrypted;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char secret_text[100];

    // get the filename to save to
    string filename = getFileName();

    // open output file and make sure it works
    fout.open(filename);
    if(fout.fail())
    {
        cout << "Unable to open file. This is fatal!";
        exit(1);
    }
    // get input secret text
    getSecretText(secret_text);
    for(char c : secret_text)
    {
        char result = encrypt(c);
        fout << result;
    }
    fout.close();
    // loop through each input character
        // encrypt
        // put into file
    // close file
    

    string result;
    // open file input and make sure it works
    fin.open(filename);
    if(fin.fail())
    {
        cout << "Unable to open file. This is fatal!";
        exit(1);
    }
    while(!fin.eof())
    {
        char test;
        fin.get(test);
        result.push_back(test);
    }  
    cout << "Here's what the encrypted file looks like: " << result << endl;
    fin.close();

    // print all the characters back to the screen
    // close the fin

    return 0;
}

void getSecretText(char text[50])
{
    cout << "give me your text: " << endl;
    cin.getline(text, 50);
}

string getFileName()
{
    string file;
    cout << "give me file: ";
    getline(cin, file);
    return file;
}
