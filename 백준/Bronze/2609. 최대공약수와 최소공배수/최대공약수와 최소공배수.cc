//2609번 최대공약수와 최소공배수
#include <iostream>
#include <algorithm>
using namespace std;

// 유클리드 호제법
// a, b 최대공약수 = b, a % b 최대공약수
int gcd(int a, int b) {
    // (a, b) = (b, a % b)
    return a % b == 0 ? b : gcd(b, a % b);
}

// 최소 공배수
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {

    int a, b;
    cin >> a >> b;


    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;


    return 0;
}