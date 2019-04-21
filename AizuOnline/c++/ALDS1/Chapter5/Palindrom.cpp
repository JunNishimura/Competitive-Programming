#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrom(string moji) 
{
    if (moji.length() <= 1) return true;
    return moji[0] == moji[moji.length()-1] && isPalindrom(moji.substr(1, moji.length()-2));
}

int main() 
{
    string moji;
    getline(cin, moji);
    string temp(moji.c_str(), moji.length());
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end()); // remove space
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower); // turn into lowercase
    if (isPalindrom(temp)) cout << "This moji is Palindrom: ";
    else cout << "This is not Palindrom: ";
    cout << moji << endl;
}