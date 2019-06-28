#include <iostream> 
#include <string> 
using namespace std;

bool CheckPalindrome(string str) 
{
    if (str.length() <= 1) return true;
    
    string tmp(str);
    str.erase(str.begin()); str.pop_back(); // erase front and back;
    return (tmp.front() == tmp.back()) && CheckPalindrome(str);
}

int main() 
{
    int in1, in2;
    string s_in;

    for (int i = 999; i >= 900; --i)
    {
        for (int j = i; j >= 900; --j)
        {
            s_in = to_string(i * j);
            if (CheckPalindrome(s_in)) 
            {
                cout << "This is a palindrome" << endl
                    << i << " * " << j << ": " << s_in << endl;
            }
        }
    }
}