// WAP to implement Extended Euclidean algorithm for finding GCD.

#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y) {
    int q, r;
    int r1 = a, r2 = b;
    int t1 = 0, t2 = 1, t;
    int s1 = 1, s2 = 0, s;

    while (r2 != 0) {
        q = r1 / r2;
        r = r1 - q * r2;
        t = t1 - q * t2;
        s = s1 - q * s2;

        r1 = r2;
        r2 = r;
        t1 = t2;
        t2 = t;
        s1 = s2;
        s2 = s;
    }

    x = s1;
    y = t1;
    return r1;
}
int main() {
    int a, b, x, y;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD: " << gcdExtended(a, b, x, y) << endl;
    return 0;
}