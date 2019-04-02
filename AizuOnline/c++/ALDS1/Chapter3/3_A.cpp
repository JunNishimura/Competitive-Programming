#include <iostream>
#include <cstdlib>
using namespace std;
int st[101], top = 0;
int POP() {
    top--;
    return st[top+1];
}
void PUSH(int v){
    st[++top] = v;
}
int main() {
    int a1, a2;
    char s[3];
    while (cin >> s) {   
        if (s[0] == '+') {
            a1 = POP();
            a2 = POP();
            PUSH(a1+a2);
        } else if (s[0] == '-') {
            a1 = POP();
            a2 = POP();
            PUSH(a2-a1);
        } else if (s[0] == '*') {
            a1 = POP();
            a2 = POP();
            PUSH(a1*a2);
        } else {
            PUSH(atoi(s));
        }
    }
    printf("%d\n", POP());
}

