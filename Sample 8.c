#include <stdio.h>
#include <fcntl.h> // open()
#include <unistd.h> // read(), write(), close()
#include <string.h> // strlen()
int main()
{
 int choice, fd, bytes;
 char sentence[100]; // sentence typed by the user
 char buffer[100]; // text read back from the file
 do
 {
 printf("\n===== MENU =====\n");
 printf("1. Write sentence into file\n");
 printf("2. Read file and display\n");
 printf("3. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 getchar(); // remove the Enter key left by scanf
 switch (choice)
 {
 case 1:
 printf("Enter a sentence: ");
 fgets(sentence, sizeof(sentence), stdin); // read a full line
 // O_TRUNC -> replace old content with the new sentence
 fd = open("sentence.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
 if (fd < 0)
 {
 printf("File creation failed\n");
 break;
 } 17
 write(fd, sentence, strlen(sentence));
 close(fd);
 printf("Sentence written to file\n");
 break;
 case 2:
 fd = open("sentence.txt", O_RDONLY);
 if (fd < 0)
 {
 printf("File not found. Write a sentence first (choice 1)\n");
 break;
 }
 bytes = read(fd, buffer, sizeof(buffer) - 1);
 buffer[bytes] = '\0'; // end of string
 close(fd);
 printf("File content: %s", buffer);
 break;
 case 3:
 printf("Exiting program\n");
 break;
 default:
 printf("Invalid choice\n");
 }
 } while (choice != 3);
 return 0;
}
