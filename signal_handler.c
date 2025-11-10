/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Aden Yance
 * 
 * Brief summary of modifications: I removed the exit() call from the signal handler
*/


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
   
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}


/*
Signals you can send
SIGINT - Interrupt program (Ctrl+C)
SIGTERM - Terminate program (kill -15)
SIGKILL - Kill program (kill -9)
SIGUSR1 - User-defined signal 1 (kill -10)
SIGUSR2 - User-defined signal 2 (kill -12)
Ctrl+\ - Quit program
Ctrl+Z - Suspend program
Ctrl+C - Interrupt program
Ctrl+D - End of file
Ctrl+L - Clear screen
Ctrl+R - Redo
Ctrl+S - Suspend
Ctrl+Q - Resume
Ctrl+U - Undo
Ctrl+W - Delete word
*/
