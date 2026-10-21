#include <stdio.h>
#include <unistd.h> // Required for pipe(), fork(), read(), write(), and close()
#include <string.h> // Required for strlen() to measure message size
#include <fcntl.h>
int main()
{
 /* fd[2] array holds two file descriptors: fd[0] for reading, fd[1] for writing */
 int fd[2];
 /* pid_t is a data type used to represent process IDs */
 pid_t pid;
 char message[] = "Hello from Parent Process";
 char buffer[100];
 // Create pipe, fd[0] -> Reading end, fd[1] -> Writing end
 if (pipe(fd) == -1)
 {
 printf("Pipe creation failed\n");
 return 1;
 }
 /* fork() system call: Clones the calling process to create a new child process.
 * Returns 0 to the child process, and the child's actual PID to the parent */
 pid = fork();
 /* Checks if fork() failed to allocate/spawn a new process */
 if (pid < 0)
 {
 printf("Process creation failed\n");
 return 1;
 }
 // Child Process: Reads data from pipe
 else if (pid == 0)
 {
 // Unused descriptors should be closed; child only reads, so it closes the write end (fd[1])
 close(fd[1]);
 read(fd[0], buffer, sizeof(buffer));
 printf("\nChild received message:\n");
 printf("%s\n", buffer);
 close(fd[0]);
 }
 // Parent Process: Writes data into pipe 
 else
 {
 close(fd[0]);
 /* write() system call: Pushes the message data string into the write end of the pipe (fd[1]).
 'strlen(message) + 1' ensures the null terminator ('\0') is also sent through the pipe. */
 write(fd[1], message, strlen(message) + 1);
 printf("Parent sent message\n");
 close(fd[1]);
 }
 return 0;
}
