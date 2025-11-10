/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by:
 * 
 * Brief summary of modifications:
 */

 #include <signal.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>

int main (int argc, char* argv[]) {

    void handle_segfault() {
        printf("A segmentation fault was received\n");
        // Return without performing any other action
        // Execution will continue from where it left off
    }

    // Register SIGSEGV signal handler
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}