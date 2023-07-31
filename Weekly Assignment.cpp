#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
char* generateAlphanumericString();
int calculateHighestBase(char* str);
void calculateFrequencyDistribution(int* frequency, char** arr, int size_of_array);
void plotFrequencyDistribution(int* frequency);

int main() {
    int size_of_array = 500;
    int i;
    char** arr = (char*)malloc(size_of_array * sizeof(char));
    int frequency[17] = {0}; // Frequency array, index 0 is not used.

    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Generate alphanumeric strings and store them in the array
    for (i = 0; i < size_of_array; i++) {
        arr[i] = generateAlphanumericString();
    }
    

    // Calculate the highest base for each alphanumeric string and update the frequency array
    calculateFrequencyDistribution(frequency, arr, size_of_array);

    // Plot the frequency distribution of bases
    plotFrequencyDistribution(frequency);

    // Free dynamically allocated memory
    for (i = 0; i < size_of_array; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

char* generateAlphanumericString() {
	int i;
    const char hexChars[] = "0123456789ABCDEF";
    int length = rand() % 8 + 3; // Random length between 3 and 10 characters
    char* result = (char*)malloc((length + 1) * sizeof(char));
    result[length] = '\0';

    for (i = 0; i < length; i++) {
        result[i] = hexChars[rand() % 16];
    }

    return result;
}

int calculateHighestBase(char* str) {
    int highestBase = 0;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            int digit = *str - '0';
            if (digit > highestBase) {
                highestBase = digit;
            }
        } else if (*str >= 'A' && *str <= 'F') {
            int digit = *str - 'A' + 10;
            if (digit > highestBase) {
                highestBase = digit;
            }
        }
        str++;
    }

    return highestBase + 1;
}

void calculateFrequencyDistribution(int* frequency, char** arr, int size_of_array) {
	int i;
    for (i = 0; i < size_of_array; i++) {
        int highestBase = calculateHighestBase(arr[i]);
        frequency[highestBase]++;
    }
}

void plotFrequencyDistribution(int* frequency) {
	int i,j;
    printf("Frequency Distribution of Bases:\n");
    for (i = 2; i <= 16; i++) {
        printf("%2d: ", i);
        for ( j = 0; j < frequency[i]; j++) {
            printf("*");
        }
        printf("\n");
}
}

