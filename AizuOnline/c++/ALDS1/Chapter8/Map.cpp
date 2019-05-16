#include <iostream> 
#include <map> 
#include <string>
using namespace std;

void Print(map<string, int> T) 
{
    cout << T.size() << endl;
    for (map<string, int>::iterator it = T.begin(); it != T.end(); it++) 
    {
        cout << (*it).first << "--->" << (*it).second << endl;
    }
    cout << endl;
}

int main() 
{
    map<string, int> T;

    T["Tigers"] = 100;
    T["Dragons"] = 200;
    T["Giants"] = 300;

    Print(T);

    T.insert(make_pair("Baystars", 400));
    T.insert(make_pair("Carp", 500));
    T.erase("Giants");

    Print(T);

    pair<string, int> target = *T.find("Tigers");
    cout << target.first << "--->" << target.second << endl;

    return 0;
}