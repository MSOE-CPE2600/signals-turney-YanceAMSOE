/**
 * file: signal_segfault.c
 * Description: Program that demonstrates SIGSEGV signal handling
 * 
 * Modified by: Aden Yance
 * 
 *   Modifications:
 * - Installed a signal handler for SIGSEGV
 * - Handler prints a message when segmentation fault occurs
 * - Handler returns without performing any corrective action
 * - This causes execution to continue from the faulting instruction, resulting
 *   in an infinite loop of segmentation faults
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void handle_segfault(int sig) {
    printf("A segmentation fault (SIGSEGV) was received\n");
    // Execution will continue from where it left off
}

int main(int argc, char* argv[]) {
    // Register SIGSEGV signal handler
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer - this will trigger SIGSEGV
    // After the handler returns, execution continues here, causing another SIGSEGV
    // This creates an infinite loop of segmentation faults
    printf("The value of i is: %d\n", *i);

    // This line will never be reached due to the infinite loop of SIGSEGV signals
    return 0;
}