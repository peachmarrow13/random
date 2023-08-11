#include <iostream>

using namespace std;

int main() {
    // Initialize the sales amount and tax rates
    double sales = 95000;
    double county_tax = 0.04;  // 4% county tax rate
    double state_tax = 0.02;   // 2% state tax rate

    // Display the initial sales amount
    cout << "Sales: $" << sales << endl;

    // Calculate and display the county tax amount
    cout << "County tax: $" << sales * county_tax << endl;

    // Calculate and display the state tax amount
    cout << "State tax: $" << sales * state_tax << endl;

    // Calculate and display the total earnings after deducting taxes
    cout << "Total earnings: $" << sales - sales * county_tax - sales * state_tax;

    return 0;
}
