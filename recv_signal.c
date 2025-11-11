/**
 * File: recv_signal.c
 * Description: Receives SIGUSR1 signals with data using sigaction
 *              The handler retrieves and prints the integer value sent via sigqueue
 * 
 * Modified by: Aden Yance
 * 
 * Brief summary of program:
 * - Uses sigaction() with SA_SIGINFO flag to register a handler for SIGUSR1
 * - Handler receives siginfo_t structure containing the data sent via sigqueue
 * - Retrieves and prints the sival_int value from the signal data
 * - Waits in an infinite loop for signals to be received
 * 
 * Compile: gcc -o recv_signal recv_signal.c
 * 
 * Usage: Run this program first, note the PID, then run send_signal with that PID
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    printf("SIGUSR1 received from process ID: %d\n", info->si_pid);
    printf("Received integer value: %d\n", info->si_value.sival_int);
}

int main() {
    struct sigaction sa;
    
    // Initialize the sigaction structure
    sa.sa_sigaction = handle_sigusr1;  // Use sa_sigaction for three-parameter handler
    sigemptyset(&sa.sa_mask);           // Clear the signal mask
    sa.sa_flags = SA_SIGINFO;           // Use SA_SIGINFO flag to receive signal data
    
    // Register the signal handler using sigaction
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    
    printf("Receiver Process ID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal with data...\n");
    printf("Run send_signal with this PID: %d\n", getpid());
    
    // Wait in an infinite loop for signals
    while(1) {
        pause();  // Wait for any signal
    }
    
    return 0;
}
