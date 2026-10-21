#include <stdio.h>
#include <sys/stat.h> // stat(), struct stat
int main()
{
 struct stat fileInfo; // stat() stores the file details here
 printf("\n--- File Information ---\n");
 // stat() returns 0 on success
 if (stat("student.txt", &fileInfo) == 0)
 {
 // size of the file in bytes
 printf("File Size : %ld bytes\n", (long)fileInfo.st_size);
 // number of hard links to the file
 printf("Number of Links : %ld\n", (long)fileInfo.st_nlink);
 // permissions in octal (& 0777 keeps only the permission bits)
 printf("Permissions : %o\n", fileInfo.st_mode & 0777);
 }
 else
 {
 printf("Unable to get file information\n");
 }
 return 0;
}
