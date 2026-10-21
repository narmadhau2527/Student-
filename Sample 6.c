#include <stdio.h>
#include <sys/stat.h> // mkdir()
#include <dirent.h> // opendir(), readdir(), closedir()
int main()
{
 DIR *dir; // directory stream
 struct dirent *entry; // one entry (file or folder) of the directory
 // Create a directory (0755: owner rwx, others r-x)
 printf("\n--- Creating Directory ---\n");
 if (mkdir("TestDirectory", 0755) == 0)
 printf("Directory created successfully\n");
 else
 printf("Directory may already exist\n");
 // Display directory contents
 printf("\n--- Directory Contents ---\n");
 // opendir(".") opens the current directory
 dir = opendir(".");
 if (dir == NULL)
 {
 printf("Cannot open directory\n");
 return 1;
 }
 // readdir() gives one entry each time; it returns NULL at the end
 while ((entry = readdir(dir)) != NULL)
 {
 printf("%s\n", entry->d_name); // d_name = name of the entry
 }
 closedir(dir);
 return 0;
}
