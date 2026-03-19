#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    // Open a file for writing
    std::ofstream outputFile("random_integers.txt");

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate 1000 rows of 5 integers each
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 5; ++j) {
            // Generate a random integer between 0 and 1000
            int randomInt = rand() % 1001;

            // Write the integer to the file
            outputFile << randomInt;

            // Separate integers with a comma, except for the last one in each row
            if (j < 4) {
                outputFile << ",";
            }
        }
        // End the row with a newline character
        outputFile << "\n";
    }

    // Close the file
    outputFile.close();

    std::cout << "File 'random_integers.txt' generated successfully.\n";

    return 0;
}
