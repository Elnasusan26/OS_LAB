#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, f, i, j, k;
    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &n);
    int pages[n];

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);
    int frames[f];
    int pageFaults = 0;

    for (i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\nReference String: ");
    for (i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }

    printf("\n\nPage Frames:\n");
    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int farthest = i;
            int farthestIndex = 0;

            for (k = 0; k < f; k++) {
                int l;
                for (l = i - 1; l >= 0; l--) {
                    if (frames[k] == pages[l]) {
                        if (l < farthest) {
                            farthest = l;
                            farthestIndex = k;
                        }
                        break;
                    }
                }

                if (l < 0) {
                    farthestIndex = k;
                    break;
                }
            }

            frames[farthestIndex] = page;
            pageFaults++;
        }

        for (k = 0; k < f; k++) {
            printf("%d ", frames[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}
