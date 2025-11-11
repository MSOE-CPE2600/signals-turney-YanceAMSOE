/**
 * File: signal_sigaction.c
 * Description: Demonstrates the use of sigaction system call to register a signal handler
 *              that receives additional information about the signal, including the sender's PID
 *              Requires two command promts
 * Modified by: Aden Yance
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    printf("SIGUSR1 received from process ID: %d\n", info->si_pid);
}

int main() {
    struct sigaction sa;
    
    // Initialize the sigaction structure
    sa.sa_sigaction = handle_sigusr1;  // Use sa_sigaction for three-parameter handler
    sigemptyset(&sa.sa_mask);           // Clear the signal mask
    sa.sa_flags = SA_SIGINFO;           // Use SA_SIGINFO flag to get detailed signal info
    
    // Register the signal handler using sigaction
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    
    printf("Process ID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");
    printf("Send SIGUSR1 using: kill -SIGUSR1 %d\n", getpid());
    
    // Wait in an infinite loop for signals
    while(1) {
        pause();  // Wait for any signal
    }
    
    return 0;
}
