#include <stdio.h>
#include <stdlib.h> //system( )
int main()
{
 printf("Current Directory\n");
 system("pwd"); //to execute an operating system command
 printf("\nFiles\n");
 system("ls -l");
 printf("\nCreating Directory\n");
 system("mkdir Demo");
 printf("\nListing Files Again\n"); 3
 system("ls");
 printf("\nRemoving Directory\n");
 system("rmdir Demo");
 return 0;
}
