#include<bits/stdc++.h>
using namespace std;
vector<char>vowels, consonants;
set<char>vow, cons;
int chararray[255] = {0};
void vowelConsonant(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
                str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
            vowels.push_back(str[i]), vow.insert(str[i]);
        else if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
            consonants.push_back(str[i]), cons.insert(str[i]);
        chararray[str[i]]++;
    }
}

bool isVowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
                c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
    return false;
}

bool isConsonant(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z')) return true;
    return false;
}

void solveC(string str)
{
    char vow[1000], cons[1000];
    int vi = 0, ci = 0;
    for(int i=0; i<str.size();)
    {
        if(isVowel(str[i]))
        {
            int j = i;
            while(str[j]!=' ' && j<str.size())
            {
                vow[vi] = str[j];
                vi++, j++;
            }
            i = j;
            vow[vi++] = ' ';
        }
        else if(isConsonant(str[i]))
        {
            int j = i;
            while(str[j]!=' ' && j<str.size())
            {
                cons[ci] = str[j];
                ci++, j++;
            }
            i = j;
            cons[ci++] = ' ';
        }
        else
        {
            i++;
        };

        vow[vi] = '\0';
        cons[ci] = '\0';
    }
    
    printf("Vowel string => %s\n", vow);
    printf("Consonant string => %s\n", cons);
}

int main()
{
    set<char>::iterator itr;
    freopen("2.txt", "r", stdin);
    string str;
    getline(cin, str);
    cout << str << endl;
    vowelConsonant(str);
    cout << "(a)" << endl;
    cout << "Number of vowels : " << vowels.size() << endl;
    cout << "Number of consonants : " << consonants.size() << endl;
    cout << endl;

    cout << "(b)" << endl;
    cout << "Vowels : ";
    for(itr=vow.begin(); itr!=vow.end(); itr++)
        cout << *itr << " ";
    cout << endl;
    cout << "Consonants : ";
    for(itr=cons.begin(); itr!=cons.end(); itr++)
        cout << *itr << " ";
    cout << endl << endl;


    cout << "(c)" << endl;
    solveC(str);
    return 0;
}
