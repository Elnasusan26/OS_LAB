#include <stdio.h>
#include <stdlib.h>

int main() {
    int f, n;
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    int frames[f];
    int frequencies[f];

    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        frequencies[i] = 0;
    }

    int pages[n];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Frames: ");
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == page) {
                frequencies[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            int minFreqIndex = 0;
            for (int j = 1; j < f; j++) {
                if (frequencies[j] < frequencies[minFreqIndex]) {
                    minFreqIndex = j;
                }
            }

            frames[minFreqIndex] = page;
            frequencies[minFreqIndex] = 1;
            pageFaults++;
        }

        for (int j = 0; j < f; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}
