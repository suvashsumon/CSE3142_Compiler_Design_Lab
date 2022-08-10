#include<bits/stdc++.h>
using namespace std;
vector<char>letters, digits, otherchar;

void findChar(char ch)
{
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)) letters.push_back(ch);
    else if(ch>='0' && ch<='9') digits.push_back(ch);
    else otherchar.push_back(ch);
}

int countWordNumber(string str)
{
    int cnt = 0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==' ')
        {
            cnt++;
        }
        else findChar(str[i]); // we don't consider space as a character
    }
    return cnt+1;
}

int main()
{
    freopen("1.txt", "r", stdin);
    string str;
    getline(cin, str);
    //cin >> str;
    int wordNumber = countWordNumber(str);
    cout<<"Number of Word : ";
    cout << wordNumber << endl << endl;
    cout << "Number of Letters " << letters.size() << endl;
    cout << "Letters: ";
    for(int i=0; i<letters.size(); i++) cout << letters[i] << " ";
    cout << endl << endl;

    cout << "Number of Digits " << digits.size() << endl;
    cout << "Digits: ";
    for(int i=0; i<digits.size(); i++) cout << digits[i] << " ";
    cout << endl << endl;

    cout << "Number of other character " << otherchar.size() << endl;
    cout << "Special Character: ";
    for(int i=0; i<otherchar.size(); i++) cout << otherchar[i] << " ";
    cout << endl << endl;
    return 0;
}
