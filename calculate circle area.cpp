#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Enter radius: ";
    double radius;
    cin >> radius;
    const double pi = 3.1415;
    cout << "area: " << pi * (radius * radius);
}
