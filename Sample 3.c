#include <stdio.h>
#include <fcntl.h> // open()
#include <unistd.h> // write(), close()
#include <string.h> // strlen()
int main()
{
 int fd; // file descriptor (a small number that identifies the open file)
 char data[] = "Linux System Calls Experiment\n"
 "B.Sc Cyber Security Laboratory";
 printf("\n--- Creating and Writing File ---\n");
 /* open(): O_CREAT -> create the file if it does not exist
 O_WRONLY -> open for writing only
 0644 -> permissions: owner read/write, others read only */
 fd = open("student.txt", O_CREAT | O_WRONLY, 0644);
 // open() returns -1 if it fails
 if (fd < 0)
 {
 printf("File creation failed\n");
 return 1;
 }
 // write(): copy the text into the file
 write(fd, data, strlen(data));
 // close(): release the file
 close(fd);
 printf("Data written successfully\n");
 return 0;
}
