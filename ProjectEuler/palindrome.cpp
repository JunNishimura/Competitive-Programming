#include <iostream> 
#include <string> 
using namespace std;

bool isPalindrome(string input)
{
    if (input.length() <= 1) return true;

    string tmp(input);
    input.erase(input.begin()); input.pop_back();
    return (tmp.front() == tmp.back()) && isPalindrome(input);
}

bool isPalindrome2(string input) 
{
    if (input.length() <= 1) return false;
    int l = 0;
    int h = input.length()-1;
    while(l < h){
        if (input[l++] != input[h--]) 
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    string s_in;
    cout << "input >> " << flush;
    cin >> s_in;
    if (isPalindrome2(s_in)) 
    {
        cout << "Yes, this is a palindrome." << endl;
    }
    else 
    {
        cout << "No, This is not a palindrome" << endl;
    }
    cout << "sentence is: " << s_in << endl;
}