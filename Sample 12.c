#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/mman.h> // Memory mapping operations like shm_open( ), mmap( )
#include<sys/unistd.h>
#include<sys/types.h>
#include<sys/wait.h> // Process waiting and synchronization wait(), waitpid(), etc
int main()
{
 // Name of the shared memory object
 const char *name = "/my_shm";
 // Size of the shared memory block (in bytes)
 const int SIZE = 4096;
 int shm_fd; //shared memory identifier
 void *ptr; //ptr to shared memory address
 /* 1. Create the shared memory object
 O_CREAT: Create object if it doesn't exist
 O_RDWR: Open for reading and writing
 0666: Read/Write permissions for User, Group, and Others */
 shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
 if (shm_fd == -1)
 {
 perror("shm_open failed"); //display an error message
 return 1;
 }
 //Configure the size of the shared memory segment
 if (ftruncate(shm_fd, SIZE) == -1)
 {
 perror("ftruncate failed");
 return 1; 25
 }
 //Map the shared memory object into memory
 ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,
 shm_fd, 0);
 if (ptr == MAP_FAILED)
 {
 perror("mmap failed");
 return 1;
 }
 //Fork a child process
 pid_t pid = fork(); //process id
 if (pid < 0)
 {
 perror("Fork failed");
 return 1;
 }
 else if (pid == 0)
 {
 //Child process reads the data from the shared memory segment
 sleep(1); // Simple delay to ensure the parent writes first
 printf("\nChild: Read data from shared memory: \"%s\"\n", (char *)ptr);
 munmap(ptr, SIZE); // Clean up memory mapping in child
 close(shm_fd);
 }
 else
 {
 //Parent process writes data into the shared memory segment
 const char *message = "Hello from the Shared Memory!";
 // Copying data into the memory mapped region
 sprintf(ptr, "%s", message);
 printf("Parent: Wrote data to shared memory: \"%s\"\n", message);
 // Wait for child to finish reading before cleaning up resource
 wait(NULL);
 munmap(ptr, SIZE); // Clean up and release shared memory resources
 close(shm_fd);
 shm_unlink(name); // Deletes the shared memory segment from system
 }
 return 0;
}
