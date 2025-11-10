/**
 * File: signal_alarm.c
 * Modified by: Aden Yance
 * 
 * Brief summary of program: schedules an alarm to be sent to after 5 seconds. Then writes a signal
handler to print out that the signal was received
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGALRM - prints that the alarm signal was received
 */
void handle_alarm(int sig) {
    printf("\nSIGALRM received! The alarm went off after 5 seconds.\n");
}

int main() {
    // Register signal handler for SIGALRM
    signal(SIGALRM, handle_alarm);
    
    printf("Scheduling an alarm for 5 seconds...\n");
    printf("Program will continue running until alarm fires.\n\n");
    
    // Schedule an alarm to be sent after 5 seconds
    alarm(5);
    
    // Wait and print status messages
    int count = 0;
    while(1) {
        printf("Waiting... (%d seconds elapsed)\n", count);
        sleep(1);
        count++;
        
        // After alarm fires, continue running (or exit if desired)
        // The alarm only fires once, so we'll keep running
    }
    
    return 0;
}
