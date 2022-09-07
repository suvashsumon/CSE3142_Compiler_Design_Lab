#include<bits/stdc++.h>
using namespace std;
vector<char>stk;
int main()
{
    /*
    Production Rules for this problem:
        E -> 2E2
        E -> 3E3
        E -> 4
    */

    freopen("input.txt", "r", stdin);
    string input;
    getline(cin, input);
    cout << "Given input : "  << input << endl;

    for(int i=0; i<input.size(); i++)
    {
        stk.push_back(input[i]);

        if(stk[stk.size()-1]=='4')
        {
            stk.pop_back();
            stk.push_back('E');
        }
        else if(stk[stk.size()-1]=='2')
        {
            int n = stk.size()-1;
            if(stk[n-1]=='E' && stk[n-2]=='2')
            {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back('E');
            }
        }
        else if(stk[stk.size()-1]=='3')
        {
            int n = stk.size()-1;
            if(stk[n-1]=='E' && stk[n-2]=='3')
            {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back('E');
            }
        }
    }

    if(stk.size()==1 && stk[0]=='E') cout << "Accepted" << endl;
    else cout << "Rejected" << endl;
}
