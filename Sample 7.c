#include <stdio.h>
#include <fcntl.h> // open()
#include <unistd.h> // write(), close()
#include <string.h> // strlen()
int main()
{
 int fd;
 int bytes; // number of bytes written
 char data[] = "Operating Systems Laboratory\n"
 "File handling using system calls\n";
 // O_TRUNC -> if the file already exists, clear its old content
 fd = open("os_notes.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
 if (fd < 0)
 {
 printf("File creation failed\n");
 return 1;
 }
 // write() returns the number of bytes written
 bytes = write(fd, data, strlen(data));
 close(fd);
 printf("Data written successfully\n");
 printf("Bytes written : %d\n", bytes);
 return 0;
}
