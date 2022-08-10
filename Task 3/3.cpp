#include<bits/stdc++.h>
using namespace std;

map<string,string>store;
map<string,string>year;
map<string,string>semester;
map<string,string>courseName;
map<string,string>courseType;

void setUpSampleText()
{
    store["CSE"] = "Computer Science & Engineerring";
    year["1"] = "1st year";
    year["2"] = "2nd year";
    year["3"] = "3rd year";
    year["4"] = "4th year";

    semester["1"] = "1st semester";
    semester["2"] = "2nd semester";
    semester["3"] = "3rd semester";
    semester["4"] = "4th semester";

    courseName["1"] = "System Analysis and Design";
    courseName["2"] = "Database Management System";
    courseName["3"] = "Digital Signal Processing";
    courseName["4"] = "Compiler Design";
    courseName["5"] = "Computer Networks";

    courseType["1"] = "Theory";
    courseType["2"] = "Lab";
}

int main()
{
    freopen("3.txt", "r", stdin);
    string str;
    getline(cin, str);

    setUpSampleText();

    int i = 0;
    string code_name, code_year, code_semester, code_course, code_cs_type;
    while(str[i]!='-')
    {
        code_name+=str[i];
        i++;
    }
    i++;
    code_year = str[i++];
    code_semester = str[i++];
    code_course = str[i++];
    code_cs_type = str[i++];

    cout << store[code_name];
    cout << ", ";
    cout << year[code_year];
    cout << ", ";
    cout << semester[code_semester];
    cout << ", ";
    cout << courseName[code_course];
    cout << ", ";
    cout << courseType[code_cs_type];
    cout << endl;
}
