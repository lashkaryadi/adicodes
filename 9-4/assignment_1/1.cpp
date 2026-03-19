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