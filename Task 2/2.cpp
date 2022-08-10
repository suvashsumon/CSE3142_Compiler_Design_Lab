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

void solveC(string str)
{
    char word_cons[500];
    char word_vow[500];
    int ci=0, vi=0, indic = 0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==' ')
            continue;
        else
        {
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
                    str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
            {
                indic = i;
                while(str[i]!=' ')
                {
                    word_vow[vi] = str[indic];
                    vi++;
                    i++;
                }
                word_vow[vi] = ' ';
                vi++;
            }
            else if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
            {
                indic = i;
                while(str[i]!=' ')
                {
                    word_cons[ci] = str[indic];
                    ci++;
                    i++;
                }
                word_cons[ci] = ' ';
                ci++;
            }
        }
    }
    for(int i=0; i<ci-1; i++)
    {
        cout << word_cons[ci];
    }
    cout << endl;
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
    cout << endl;


    cout << "(c)" << endl;
    solveC(str);
    return 0;
}
