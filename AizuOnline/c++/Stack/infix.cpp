#include <iostream> 
#include <stack> 

using namespace std;

void Evaluate_PostFix() 
{
    stack<int> S;
    char input[10];

    while(1) 
    {
        cout << "-----数字または演算記号を入力してください。(exit:c)-----" << endl;
        cin >> input;
        if (*input == '+')
        {
            if (S.size() < 2) 
            {
                cout << "There is not enough numbers to operate " << input << " in stack" << endl;
                continue;
            }
            int out1 = S.top(); S.pop();
            int out2 = S.top(); S.pop();
            cout << out1 + out2 << "をstackに追加します。" << endl;
            S.push(out1 + out2); // add numbers and push it to the stack
        }
        else if (*input == '-') 
        {
            if (S.size() < 2) 
            {
                cout << "There is not enough numbers to operate " << input << " in stack" << endl;
                continue;
            }
            int out1 = S.top(); S.pop();
            int out2 = S.top(); S.pop();
            cout << out2 - out1 << "をstackに追加します。" << endl;
            S.push(out2 - out1);
        }
        else if (*input == '*')
        {
            if (S.size() < 2) 
            {
                cout << "There is not enough numbers to operate " << input << " in stack" << endl;
                continue;
            }
            int out1 = S.top(); S.pop();
            int out2 = S.top(); S.pop();
            cout << out1 * out2 << "をstackに追加します。" << endl;
            S.push(out1 * out2);
        }
        else if (*input == '/')
        {
            if (S.size() < 2) 
            {
                cout << "There is not enough numbers to operate " << input << " in stack" << endl;
                continue;
            }
            int out1 = S.top(); S.pop();
            int out2 = S.top(); S.pop();
            cout << out1 / out2 << "をstackに追加します。" << endl;
            S.push(out1 / out2);
        }
        else if (*input == 'c')
        {
            cout << "終了します。" << endl << "<Stackに残っている数>" << endl;
            while (! S.empty())
            {
                cout << S.top() << ", ";
                S.pop();
            }
            break;
        }
        else 
        {
            S.push(atoi(input));
        }
    }
}

int main() 
{
    Evaluate_PostFix();
}