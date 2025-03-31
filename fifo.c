#include <stdio.h>

int main() {
    int frames[10];
    int pages[20];
    int nFrames, nPages;
    int pageFaults = 0;
    int i, j, k, flag;

    printf("Enter the number of frames: ");
    scanf("%d", &nFrames);
    printf("Enter the number of pages: ");
    scanf("%d", &nPages);

    printf("Enter the reference string: ");
    for (i = 0; i < nPages; i++) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < nFrames; i++) {
        frames[i] = -1;
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < nPages; i++) {
        printf("Reference String: %d\n -> ", pages[i]);

        flag = 0;
        for (j = 0; j < nFrames; j++) {
            if (frames[j] == pages[i]) {
                flag = 1; 
                break;
            }
        }

        if (flag == 0) {
            frames[pageFaults % nFrames] = pages[i];
            pageFaults++;
        }

        for (k = 0; k < nFrames; k++) {
            printf("%d ", frames[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
