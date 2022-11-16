#include <bits/stdc++.h>
using namespace std;
map<char, vector<string>> production;
set<char> nonTerminal, terminal;
map<char, set<char>> first, follow;
set<char> isVisited;

bool isCapital(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

bool isSmall(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

void storeProd(string prod)
{
    production[prod[0]].push_back(prod.substr(3));
    nonTerminal.insert(prod[0]);
}

void takeInput()
{
    int numberofprod;
    cin >> numberofprod;
    while (numberofprod--)
    {
        string prod;
        cin >> prod;
        storeProd(prod);
    }
}

void getFirst(char ch)
{
    if (isVisited.count(ch))
        return;
    isVisited.insert(ch);

    for (string prod : production[ch])
    {
        int len = prod.size();

        for (int i = 0; i < len; i++)
        {
            if (isCapital(prod[i]))
            {
                getFirst(prod[i]);

                for (char child : first[prod[i]])
                {
                    first[ch].insert(child);
                }
                if (first[prod[i]].count('#'))
                    continue;
                else
                    break;
            }
            else
            {
                first[ch].insert(prod[i]);
                break;
            }
        }
    }
}

void getFollow(char ch)
{
    if (isVisited.count(ch))
        return;
    isVisited.insert(ch);

    for (char left : nonTerminal)
    {
        for (string prod : production[left])
        {
            int len = prod.size();
            bool isGet = false;
            for (int i = 0; i < len; i++)
            {
                if (isGet)
                {
                    if (isCapital(prod[i]))
                    {
                        for (char x : first[prod[i]])
                        {
                            follow[ch].insert(x);
                        }

                        if (first[prod[i]].count('#'))
                        {
                            continue;
                        }
                        else
                            isGet = false;
                    }
                    else
                    {
                        follow[ch].insert(prod[i]);
                        isGet = false;
                    }
                    continue;
                }
                if(prod[i]==ch) 
                {
                    isGet = true;
                }
            }
            if (isGet)
            {
                getFollow(left);
                for (int x : follow[left])
                {
                    follow[ch].insert(x);
                }
            }
        }
    }
    follow[ch].erase('#');
}

int main()
{
    takeInput();
    for (char ch : nonTerminal)
    {
        if (isVisited.count(ch))
            continue;
        getFirst(ch);
    }
    cout << "First\n\n";
    for (char ch : nonTerminal)
    {
        cout << ch << " ->";
        for (char x : first[ch])
        {
            cout << " " << x;
        }
        cout << endl;
    }
    isVisited.clear();
    follow['S'].insert('$');

    for (char ch : nonTerminal)
    {
        if (isVisited.count(ch))
            continue;
        getFollow(ch);
    }

    cout << "Follow\n\n\n";

    for (char ch : nonTerminal)
    {
        cout << ch << " ->";
        for (char x : follow[ch])
        {
            cout << " " << x;
        }
        cout << endl;
    }
    return 0;
}