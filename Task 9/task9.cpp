#include<bits/stdc++.h>
using namespace std;
string PN[] = {"Sagor", "Selim", "Salma", "Nipu"};
string P[] = {"he", "she", "I", "we", "you", "they"};
string N[] = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
string V[] = {"read", "eat", "take", "run", "write"};

vector<string>words;

bool isPN(string str)
{
    for(int i=0; i<4; i++)
    {
        if(str==PN[i]) return true;
    }
    return false;
}

bool isP(string str)
{
    for(int i=0; i<6; i++)
    {
        if(str==P[i]) return true;
    }
    return false;
}

bool isN(string str)
{
    for(int i=0; i<7; i++)
    {
        if(str==N[i]) return true;
    }
    return false;
}

bool isV(string str)
{
    for(int i=0; i<5; i++)
    {
        if(str==V[i]) return true;
    }
    return false;
}

void makeWords(string str)
{
    string word = "";
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='.')
        {
            words.push_back(word);
            break;
        }
        else if(str[i]==' ')
        {
            words.push_back(word);
            word = "";
        }
        else word += str[i];
    }
}

void printVector()
{
    for(int i=0; i<words.size(); i++) cout << words[i] << " ";
    cout << endl;
}

int main()
{
    freopen("in9.txt", "r", stdin);
    string sentence;
    getline(cin, sentence);
    makeWords(sentence);

    if(words.size()<2) cout << "Invalid Sentence." << endl;
    else if(words.size()==2)
    {
        if((isPN(words[0])|| isP(words[0])) && isV(words[1])) cout << "Valid Sentence." << endl;
        else cout << "Invalid Sentence" << endl;
    }

    else if(words.size()==3)
    {
        if((isPN(words[0])|| isP(words[0])) && isV(words[1]) && isN(words[2])) cout << "Valid Sentence." << endl;
        else cout << "Invalid Sentence" << endl;
    }

}
