// piyush kumar varma uid 23bcs14116

#include <iostream>

using namespace std;

int power(int x, int y) {
    int result = 1;

    while (y > 0) {
        if (y % 2 == 1) {
            result *= x;
        }
        x = x * x;
        y = y / 2;
    }

    return result;
}

int main() {
    int base, exponent;

    cout << "Enter Base value: ";
    cin >> base;

    cout << "Enter Exponent value: ";
    cin >> exponent;

    int ans = power(base, exponent);

    cout << "Result (base^exponent): " << ans << endl;

    return 0;
}
