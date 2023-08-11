#include <iostream>

using namespace std;

int main() {

  int early_years = 21; //first 2 years = 21
  int dog_age;
  string dog_name;

  cout << "what's your dogs age?";
  cin >> dog_age;
  cout << "what's your dogs name?";
  cin >> dog_name;

int later_years = (dog_age - 2) * 4;//each year is 4 dog years minus the first two years
int human_years = early_years + later_years;

cout << dog_name << " is " << human_years << "\n";

}
