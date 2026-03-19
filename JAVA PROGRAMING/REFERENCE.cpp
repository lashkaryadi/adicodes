REFERENCE.TXT


//1
#include <iostream>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum = 0;

    int* ptr = numbers;
    
    for (int i = 0; i < 5; i++) {
        sum += *(ptr + i);
    }
    
    std::cout << "The sum of the numbers in the array is: " << sum << std::endl;

return 0;
}


//2
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

//3
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    // Open the input file
    std::ifstream inputFile("random_integers.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    // Open the output file
    std::ofstream outputFile("line_sums.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        int sum = 0;
        int num;
        char comma;
        while (ss >> num) {
            sum += num;
            ss >> comma; // Consume the comma
        }
        outputFile << sum << std::endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "Line sums stored in 'line_sums.txt' successfully.\n";

    return 0;
}

//4

#include <iostream>

// Function to find the length of a string
int stringLength(const char* str) {
    int length = 0;
    // Iterate through the characters of the string until null terminator is encountered
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    const char* str = "Hello, World!";
    int length = stringLength(str);
    std::cout << "Length of the string: " << length << std::endl;
    return 0;
}
//5

#include <iostream>

// Function to convert a string to lowercase
void toLowercase(char* str) {
    // Iterate through each character of the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Convert uppercase characters to lowercase
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A');
        }
    }
}

int main() {
    char str[] = "Hello, World!";
    toLowercase(str);
    std::cout << "Lowercase string: " << str << std::endl;
    return 0;
}
//6

#include <iostream>

// Function to convert a string to uppercase
void toUppercase(char* str) {
    // Iterate through each character of the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Convert lowercase characters to uppercase
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= ('a' - 'A');
        }
    }
}

int main() {
    char str[] = "Hello, World!";
    toUppercase(str);
    std::cout << "Uppercase string: " << str << std::endl;
    return 0;
}
//7

#include <iostream>

// Function to append one string to the end of another
void appendString(char* destination, const char* source) {
    // Find the end of the destination string
    int destLength = 0;
    while (destination[destLength] != '\0') {
        destLength++;
    }
    
    // Copy characters from the source string to the end of the destination string
    int i = 0;
    while (source[i] != '\0') {
        destination[destLength + i] = source[i];
        i++;
    }
    
    // Append null terminator to the end of the combined string
    destination[destLength + i] = '\0';
}

int main() {
    char destination[100] = "Hello, ";
    const char* source = "World!";
    
    appendString(destination, source);
    
    std::cout << "Appended string: " << destination << std::endl;
    
    return 0;
}
//8

#include <iostream>

// Function to append the first n characters of one string to the end of another
void appendSubstring(char* destination, const char* source, int n) {
    // Find the end of the destination string
    int destLength = 0;
    while (destination[destLength] != '\0') {
        destLength++;
    }
    
    // Copy the first n characters from the source string to the end of the destination string
    int i = 0;
    while (source[i] != '\0' && i < n) {
        destination[destLength + i] = source[i];
        i++;
    }
    
    // Append null terminator to the end of the combined string
    destination[destLength + i] = '\0';
}

int main() {
    char destination[100] = "Hello, ";
    const char* source = "World!";
    int n = 3; // Number of characters to append
    
    appendSubstring(destination, source, n);
    
    std::cout << "Appended string: " << destination << std::endl;
    
    return 0;
}

//9

#include <iostream>

// Function to copy a string into another
void copyString(char* destination, const char* source) {
    // Iterate through each character of the source string and copy it to the destination
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    // Append null terminator to the end of the destination string
    destination[i] = '\0';
}

int main() {
    const char* source = "Hello, World!";
    char destination[100];

    copyString(destination, source);

    std::cout << "Copied string: " << destination << std::endl;

    return 0;
}

//10

#include <iostream>

// Function to copy the first n characters of one string into another
void copySubstring(char* destination, const char* source, int n) {
    // Iterate through each character of the source string and copy it to the destination
    int i = 0;
    while (source[i] != '\0' && i < n) {
        destination[i] = source[i];
        i++;
    }
    // If there are less than n characters in the source string, append null terminator
    if (i < n) {
        destination[i] = '\0';
    }
}

int main() {
    const char* source = "Hello, World!";
    char destination[100];
    int n = 5; // Number of characters to copy

    copySubstring(destination, source, n);

    std::cout << "Copied string: " << destination << std::endl;

    return 0;
}
//11

#include <iostream>

// Function to compare two strings character by character
int compareStrings(const char* str1, const char* str2) {
    // Iterate through each character of both strings
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        // If characters at current position are not equal, return the difference
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    // If both strings are equal, return 0
    return 0;
}

int main() {
    const char* str1 = "Hello";
    const char* str2 = "Hello";
    
    int result = compareStrings(str1, str2);

    if (result == 0) {
        std::cout << "Both strings are equal.\n";
    } else if (result < 0) {
        std::cout << "String 1 comes before string 2.\n";
    } else {
        std::cout << "String 1 comes after string 2.\n";
    }

    return 0;
}
//12

#include <iostream>

// Function to compare the first n characters of two strings
int compareSubstring(const char* str1, const char* str2, int n) {
    // Iterate through each character of both strings up to n characters
    int i = 0;
    while ((str1[i] != '\0' || str2[i] != '\0') && i < n) {
        // If characters at current position are not equal, return the difference
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    // If both strings are equal up to n characters, return 0
    return 0;
}

int main() {
    const char* str1 = "Hello";
    const char* str2 = "Hella";
    int n = 3; // Number of characters to compare
    
    int result = compareSubstring(str1, str2, n);

    if (result == 0) {
        std::cout << "The first " << n << " characters of both strings are equal.\n";
    } else if (result < 0) {
        std::cout << "The first " << n << " characters of string 1 come before string 2.\n";
    } else {
        std::cout << "The first " << n << " characters of string 1 come after string 2.\n";
    }

    return 0;
}

//13

#include <iostream>

// Function to convert a string to lowercase
void toLowercase(char* str) {
    // Iterate through each character of the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Convert uppercase characters to lowercase
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A');
        }
    }
}

// Function to compare two strings without regard to case
bool compareIgnoreCase(const char* str1, const char* str2) {
    // Make copies of the strings to work with
    char str1Copy[100];
    char str2Copy[100];
    strcpy(str1Copy, str1);
    strcpy(str2Copy, str2);

    // Convert both strings to lowercase
    toLowercase(str1Copy);
    toLowercase(str2Copy);

    // Iterate through each character of both strings
    int i = 0;
    while (str1Copy[i] != '\0' && str2Copy[i] != '\0') {
        // If characters at current position are not equal, return false
        if (str1Copy[i] != str2Copy[i]) {
            return false;
        }
        i++;
    }

    // If both strings are of different lengths, return false
    if (str1Copy[i] != str2Copy[i]) {
        return false;
    }

    // If both strings are equal (ignoring case), return true
    return true;
}

int main() {
    const char* str1 = "Hello";
    const char* str2 = "HELLO";

    if (compareIgnoreCase(str1, str2)) {
        std::cout << "The strings are equal (ignoring case)." << std::endl;
    } else {
        std::cout << "The strings are not equal (ignoring case)." << std::endl;
    }

    return 0;
}

//14

#include <iostream>

// Function to find the first occurrence of a given character in a string
int findFirstOccurrence(const char* str, char target) {
    // Iterate through each character of the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // If the current character matches the target character, return its index
        if (str[i] == target) {
            return i;
        }
    }
    // If the target character is not found, return -1
    return -1;
}

int main() {
    const char* str = "Hello, World!";
    char target = 'o';

    int index = findFirstOccurrence(str, target);

    if (index != -1) {
        std::cout << "The first occurrence of '" << target << "' is at index " << index << std::endl;
    } else {
        std::cout << "The character '" << target << "' is not found in the string." << std::endl;
    }

    return 0;
}

//15
#include <iostream>

// Function to find the last occurrence of a given character in a string
int findLastOccurrence(const char* str, char target) {
    // Initialize a variable to store the index of the last occurrence
    int lastIndex = -1;

    // Iterate through each character of the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // If the current character matches the target character, update the last occurrence index
        if (str[i] == target) {
            lastIndex = i;
        }
    }
    // Return the index of the last occurrence (or -1 if not found)
    return lastIndex;
}

int main() {
    const char* str = "Hello, World!";
    char target = 'o';

    int index = findLastOccurrence(str, target);

    if (index != -1) {
        std::cout << "The last occurrence of '" << target << "' is at index " << index << std::endl;
    } else {
        std::cout << "The character '" << target << "' is not found in the string." << std::endl;
    }

    return 0;
}

//16

#include <iostream>

// Function to find the first occurrence of a substring in a string
int findFirstSubstring(const char* mainStr, const char* subStr) {
    // Iterate through each character of the main string
    for (int i = 0; mainStr[i] != '\0'; ++i) {
        // Check if the current position matches the start of the substring
        if (mainStr[i] == subStr[0]) {
            // Check if the substring is present from the current position onwards
            int j = 0;
            while (subStr[j] != '\0' && mainStr[i + j] == subStr[j]) {
                j++;
            }
            // If the entire substring is found, return the index of the start position
            if (subStr[j] == '\0') {
                return i;
            }
        }
    }
    // If the substring is not found, return -1
    return -1;
}

int main() {
    const char* mainStr = "Hello, World!";
    const char* subStr = "World";

    int index = findFirstSubstring(mainStr, subStr);

    if (index != -1) {
        std::cout << "The first occurrence of '" << subStr << "' starts at index " << index << std::endl;
    } else {
        std::cout << "The substring '" << subStr << "' is not found in the string." << std::endl;
    }

    return 0;
}

//17
#include <iostream>

// Function to set all characters of a string to a given character
void setCharacters(char* str, char ch) {
    // Iterate through each character of the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Set the current character to the given character
        str[i] = ch;
    }
}

int main() {
    char str[] = "Hello, World!";
    char ch = '*';

    setCharacters(str, ch);

    std::cout << "Modified string: " << str << std::endl;

    return 0;
}

//18

#include <iostream>

// Function to set the first n characters of a string to a given character
void setFirstNCharacters(char* str, char ch, int n) {
    // Iterate through the first n characters of the string
    for (int i = 0; i < n && str[i] != '\0'; ++i) {
        // Set the current character to the given character
        str[i] = ch;
    }
}

int main() {
    char str[] = "Hello, World!";
    char ch = '*';
    int n = 5; // Number of characters to set

    setFirstNCharacters(str, ch, n);

    std::cout << "Modified string: " << str << std::endl;

    return 0;
}

//19
#include <iostream>

// Function to reverse a string
void reverseString(char* str) {
    // Find the length of the string
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Swap characters from the beginning and end of the string until reaching the middle
    for (int i = 0; i < length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str[] = "Hello, World!";
    
    reverseString(str);

    std::cout << "Reversed string: " << str << std::endl;

    return 0;
}
//20

#include <iostream>

// Function to count the number of words in a string
int countWords(const char* str) {
    int wordCount = 0;
    bool inWord = false;

    // Iterate through each character of the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Check if the current character is a space or any other delimiter
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') {
            // If we were in a word, increment the word count
            if (inWord) {
                wordCount++;
                inWord = false;
            }
        } else {
            // We are in a word
            inWord = true;
        }
    }

    // If the last character was a word, increment the word count
    if (inWord) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    const char* str = "Hello, World! This is a test string.";

    int words = countWords(str);

    std::cout << "Number of words: " << words << std::endl;

    return 0;
}


