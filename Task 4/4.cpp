#include<bits/stdc++.h>
using namespace std;

bool isInt(string str)
{
    bool flag = false;
    for(int i=0; i<str.size(); i++)
    {
        if(i%2==0)
        {
            if((str[i]>='i' & str[i]<='n') || (str[i]>='I' & str[i]<='N')) flag = true;
        }
        else
        {
            if((str[i]>='a' & str[i]<='z') || (str[i]>='A' & str[i]<='Z') || (str[i]>='0' & str[i]<='9')) flag = true;
        }
        if(flag == false) break;
    }
    return flag;
}

bool isShortInt(string str)
{
    bool flag = false;
    if(str.size()<1 || str.size()>4) return flag;
    else
    {
        if(str[0]>='1' & str[0]<='9') flag = true;
        else return flag;
        for(int i=1; i<str.size(); i++)
        {
            if(str[i]>='0' & str[i]<='9') flag = true;
            else break;
        }

    }
    return flag;
}

bool isLongInt(string str)
{
    bool flag = false;
    if(str.size()==0) return flag;
    else
    {
        if(str[0]>='1' & str[0]<='9') flag = true;
        else return flag;
        for(int i=1; i<str.size(); i++)
        {
            if(str[i]>='0' & str[i]<='9') flag = true;
            else break;
        }

    }
    return flag;
}

int main()
{
    freopen("4.txt", "r", stdin);
    string str;
    getline(cin, str);
    if(isInt(str)) cout << "Integer Variable" << endl;
    else if(isShortInt(str)) cout << "ShortInt Number" << endl;
    else if(isLongInt(str)) cout << "LongInt Number" << endl;
    else cout << "Invalid Input or Undefined" << endl;
}
