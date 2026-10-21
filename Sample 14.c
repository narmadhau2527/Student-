#include <stdio.h>
int main()
{
 // Array to store page reference string (maximum 100 pages)
 int pages[100];
 // Array to represent memory frames (maximum 50 frames)
 int frames[50];
 int n, f; // n = number of pages, f = number of frames
 int i, j; // Loop variables
 int pageFaults = 0; // Counts total page faults
 int index = 0; // Points to the next frame to be replaced (FIFO pointer)
 int found; // Flag to check whether page is already in memory
 // Read number of page references
 printf("Enter number of pages: ");
 scanf("%d", &n);
 // Read page reference string
 printf("Enter page reference string:\n");
 for (i = 0; i < n; i++)
 scanf("%d", &pages[i]);
 // Read number of available frames
 printf("Enter number of frames: ");
 scanf("%d", &f);
 // Initially all frames are empty
 for (i = 0; i < f; i++)
 frames[i] = -1;
 // Display heading
 printf("\nPage\tFrames\n");
 // Process each page in the reference string
 for (i = 0; i < n; i++)
 {
 // Assume page is not present
 found = 0;
 // Search all frames to check if page already exists
 for (j = 0; j < f; j++)
 { 
 // Page found in memory
 if (frames[j] == pages[i])
 {
 found = 1;
 break; // No need to continue searching
 }
 }
 // If page is not found, page fault occurs
 if (!found)
 {
 // Replace the oldest page using FIFO
 frames[index] = pages[i];
 // Move pointer to next frame
 index = (index + 1) % f;
 // Increase page fault count
 pageFaults++;
 }
 // Print current page
 printf("%d\t", pages[i]);
 // Display contents of all frames
 for (j = 0; j < f; j++)
 {
 // Empty frame
 if (frames[j] == -1)
 printf("- ");
 // Occupied frame
 else
 printf("%d ", frames[j]);
 }
 // Display if page fault occurred
 if (!found)
 printf("(Page Fault)");
 printf("\n");
 }
 // Display final statistics
 printf("\nTotal Page Faults = %d\n", pageFaults);
 // Hits = Total Pages - Page Faults
 printf("Total Page Hits = %d\n", n - pageFaults);
 return 0;
}
