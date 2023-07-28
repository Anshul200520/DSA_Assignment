#include <stdio.h>  /* This line includes the standard input/output library,
                       which is necessary for functions like printf and scanf. */
#include <stdlib.h> /* This line includes the standard library,
                       which provides functions for memory allocation,
                       random number generation, and other utility functions. */
#include <time.h>   /* This line includes the time library,
                       which is used to work with time-related functions.
                       in this code - for generate the random number generator with the current time */

int main()
{
    srand(time(NULL)); 
    /* This sets the seed value for the random number generator to the current time,
	   ensuring different random values on each program run. */

    // Generate a random length between 3 to 10 characters
    int L = rand() % 8 + 3; // Random number between 3 and 10 

    // Generate the random alphanumeric string of the specified length(randomly)
    char anshu[L + 1]; // +1 for the null character
    char domain[] = "0123456789ABCDEF";
    /*  This line defines a character array called domain,
	    which contains the characters '0' to '9' followed by 'A' to 'F'.
		This character set represents all the possible characters
		from which we can choose a random character.  */
    int i;
    for (i = 0; i < L; i++)
	{
    	// Generate a random index to access a character from the charset
        int index = rand() % (sizeof(domain) - 1);
        anshu[i] = domain[index];
    }
    anshu[L] = '\0'; // Null terminator to indicate the end of the string

    // Print the random alphanumeric string
    printf("The Randomly Generated Alphanumeric Character is %s\n", anshu);

    return 0;
}

/* the program generates a random alphanumeric string of
   random length between 3 to 10 characters and prints the output message as required. */
