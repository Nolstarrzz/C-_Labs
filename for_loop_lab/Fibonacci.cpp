#include <iostream>
#include <vector>
using namespace std;

int main() {
    while(true)
    {
        int terms = 0;
        vector<int> fibs = {0,1};
        while(terms < 2)
        {
            cout << "Give me the number of terms to use (has to be greater then 2): ";
            cin >> terms;
        }
        for(int i=0;i<(terms-2);i++)
        {
            int term_added = fibs[i] + fibs[i+1];
            fibs.push_back(term_added);
        }
        for(int num : fibs)
        {
            cout << num << " ";
        }
        cout << endl << "do you want to go again? reply with any number if yes, 0 if no: " << endl;
        int checker;
        cin >> checker;
        if(checker == 0)
            break;
    }
    return 0;
}
