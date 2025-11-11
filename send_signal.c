/**
 * File: send_signal.c
 * Description: Sends SIGUSR1 signal with data using sigqueue
 *              Generates a random integer and sends it to a target process
 * 
 * Modified by: Aden Yance
 * 
 * Brief summary of program:
 * - Takes target process ID as command line argument
 * - Seeds random number generator with current time
 * - Generates a random integer
 * - Prints the random number
 * - Uses sigqueue() to send SIGUSR1 with the random integer as data
 * Usage: ./send_signal <target_pid>
 *        Example: ./send_signal 12345
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    pid_t target_pid;
    int random_value;
    union sigval value;
    
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <target_pid>\n", argv[0]);
        fprintf(stderr, "Example: %s 12345\n", argv[0]);
        exit(1);
    }
    
    // Convert command line argument to process ID
    target_pid = (pid_t)atoi(argv[1]);
    
    if (target_pid <= 0) {
        fprintf(stderr, "Error: Invalid process ID\n");
        exit(1);
    }
    
    // Seed random number generator with current time
    srand((unsigned int)time(NULL));
    
    // Generate random integer
    random_value = rand();
    
    // Prepare the value to send with the signal
    value.sival_int = random_value;
    
    // Print the random number before sending
    printf("Sending SIGUSR1 to process %d with random integer: %d\n", target_pid, random_value);
    
    // Send SIGUSR1 with data using sigqueue
    if (sigqueue(target_pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        exit(1);
    }
    
    printf("Signal sent successfully\n");
    
    return 0;
}
