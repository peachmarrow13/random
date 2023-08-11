#include <iostream>
#include <fstream>
#include <mutex>

using namespace std;

// Create a list of all the characters to generate combinations from
const string characters = "abcdefghijklmnopqrstuvwxyz0123456789";

// A mutex to synchronize access to the file
mutex file_lock;

// Function to generate combinations recursively
void generateCombinations(ofstream& file, string combination, int length) {
    if (length == 0) {
        lock_guard<mutex> lock(file_lock);
        file << combination << endl;
        return;
    }

    for (char c : characters) {
        generateCombinations(file, combination + c, length - 1);
    }
}

int main() {
    // Open a file named "combinations" in write mode
    ofstream file("combinations.txt");

    // Generate combinations of length 4
    generateCombinations(file, "", 4);

    return 0;
}
