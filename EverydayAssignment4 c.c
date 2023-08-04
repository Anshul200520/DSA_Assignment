#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random character between '0'-'9' or 'A'-'F'
char generateRandomChar() {
    int choice = rand() % 2;
    if (choice == 0) {
        return '0' + rand() % 10;
    } else {
        return 'A' + rand() % 6;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator with current time

    int numIterations = 50; // Number of iterations
    int minStringLength = 3;
    int maxStringLength = 10;
    
    int i,j;

    for (i = 0; i < numIterations; i++) {
        // Generate random length between minStringLength and maxStringLength
        int length = minStringLength + rand() % (maxStringLength - minStringLength + 1);
        char alphanumericString[maxStringLength + 1]; // +1 for null terminator

        // Generate random alphanumeric string
        for (j = 0; j < length; j++) {
            alphanumericString[j] = generateRandomChar();
        }
        alphanumericString[length] = '\0'; // Null-terminate the string

        // Calculate the highest base
        int highestBase = 0;
        for (j = 0; j < length; j++) {
            int base;
            if (alphanumericString[j] >= '0' && alphanumericString[j] <= '9') {
                base = alphanumericString[j] - '0';
            } else {
                base = alphanumericString[j] - 'A' + 10;
            }
            if (base > highestBase) {
                highestBase = base;
            }
        }

        // Print the result
        printf("The Highest Base of %s is %d\n", alphanumericString, highestBase + 1);
    }

    return 0;
}
