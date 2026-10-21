#include <stdio.h>
#include <fcntl.h> // open()
#include <unistd.h> // read(), close()
int main()
{
 int fd;
 char buffer[100]; // memory to hold the text we read
 int bytes; // number of bytes actually read
 printf("\n--- Reading File Content ---\n");
 // O_RDONLY -> open the file for reading only
 fd = open("student.txt", O_RDONLY);
 if (fd < 0)
 {
 printf("File opening failed\n");
 return 1;
 }
 // read(): read at most 99 bytes (1 byte is kept free for '\0')
 bytes = read(fd, buffer, sizeof(buffer) - 1);
 // add '\0' at the end so that printf can treat it as a string
 buffer[bytes] = '\0';
 printf("%s\n", buffer);
 close(fd);
 return 0;
}
