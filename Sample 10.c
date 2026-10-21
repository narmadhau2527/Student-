#include <stdio.h>
#include <signal.h> // signal handling functions (signal, raise) and macros (SIGINT)
#include <unistd.h> // for process handling system calls like getpid()
/* Signal handler function:
 * Executes asynchronously whenever the registered signal is caught by the process.
 * 'signal_number' receives the exact ID of the triggered signal from the OS. */
void handler(int signal_number)
{
 printf("\nSignal received successfully\n");
 printf("Signal Number : %d\n", signal_number);
}
int main()
{
 //Register SIGINT handler.
 /* signal() system call:
 * Registers our custom 'handler' function to catch the SIGINT signal.
 * SIGINT is the interrupt signal typically sent by pressing Ctrl+C. */
 signal(SIGINT, handler);
 /* getpid(): Retrieves the unique Process ID (PID) of the current running program */
 printf("Current Process ID: %d\n", getpid());
 printf("Generating SIGINT using raise()\n");
 //raise() sends SIGINT signal to the same process.
 raise(SIGINT);
 printf("\nProgram execution completed\n");
 return 0;
}
