#include <iostream>

using namespace std;

int main() {
    cout << "enter a value in celsius: ";
    double celsius;
    cin >> celsius;
    double fahrenheit;
    fahrenheit = celsius * 9/5 + 32;
    cout << fahrenheit;
}