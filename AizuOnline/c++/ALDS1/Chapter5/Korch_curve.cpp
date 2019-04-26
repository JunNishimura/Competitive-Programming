#include <iostream>
#include <math.h>
using namespace std;
int n;

struct Point 
{
    double x, y;
};

void KorchCurve(int d, Point p1, Point p2) {
    if (d == 0) return;

    // 与えられたp1, p2から三等分する
    Point s, u, t;
    double theta = M_PI * 60.0 / 180.0;
    s.x = (p1.x*2 + p2.x)/3;
    s.y = (p1.y*2 + p2.y)/3;
    t.x = (p1.x + p2.x*2)/3;
    t.y = (p1.y + p2.y*2)/3;
    u.x = (t.x-s.x)*cos(theta) - (t.y-s.y)*sin(theta) + s.x;
    u.y = (t.x-s.x)*sin(theta) + (t.y-s.y)*cos(theta) + s.y;

    KorchCurve(d-1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    KorchCurve(d-1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    KorchCurve(d-1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    KorchCurve(d-1, t, p2);
}


int main() {
    scanf("%d", &n);
    Point a, b;
    a.x = 0;
    a.y = 0;
    b.x = 100;
    b.y = 0;

    printf("%.8f %.8f\n", a.x, a.y);
    KorchCurve(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);
    return 0;
}