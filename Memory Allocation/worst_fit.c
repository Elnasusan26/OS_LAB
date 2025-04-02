#include <stdio.h>

void main() {
    int bs[50], ps[50]; 
    int frag[50];
    int a[50], alloc[50] = {0}; 
    int i, m, n, j, temp, highest;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each memory block:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &bs[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &ps[i]);
        a[i] = -1; 
    }

    for (i = 0; i < n; i++) {
        highest = -1; 
        int worstIdx = -1;

        for (j = 0; j < m; j++) {
            if (!alloc[j]) { 
                temp = bs[j] - ps[i];
                if (temp >= 0 && temp > highest) {
                    highest = temp;
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) { 
            a[i] = worstIdx;
            frag[i] = highest;
            alloc[worstIdx] = 1; 
        } else {
            frag[i] = -1; 
        }
    }

    printf("\nProcess_no \tProcess_size \tBlock_no \tBlock_size \tFragment");
    for (i = 0; i < n; i++) {
        if (a[i] != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, ps[i], a[i] + 1, bs[a[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated", i + 1, ps[i]);
        }
    }
    printf("\n");
}