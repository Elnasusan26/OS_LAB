#include <stdio.h>
#include <stdlib.h>

void main() {
    int req[20], new[20], ini, size, i, j, headm = 0, d, temp, cpy, space, copy;
    int dir;

    printf("Enter disk space: ");
    scanf("%d", &space);
    printf("Enter number of requests: ");
    scanf("%d", &size);
    printf("Enter requests: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter head location: ");
    scanf("%d", &ini);
    copy = ini;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                temp = req[j + 1];
                req[j + 1] = req[j];
                req[j] = temp;
            }
        }
    }

    new[0] = 0;
    new[size + 1] = space - 1;
    for (i = 0; i < size; i++) {
        new[i + 1] = req[i];
    }

    do {
        printf("\nDirections:\n");
        printf("1. Right\n2. Left\n3. Exit\nEnter Direction: ");
        scanf("%d", &dir);

        switch (dir) {
            case 1:
                i = 0;
                while (new[i] < ini) {
                    i++;
                }
                cpy = i;
                for (; i < size + 2; i++) {
                    d = abs(ini - new[i]);
                    headm += d;
                    ini = new[i];
                    printf("%d\t", new[i]);
                }
                for (i = cpy - 1; i > 0; i--) {
                    d = abs(ini - new[i]);
                    headm += d;
                    ini = new[i];
                    printf("%d\t", new[i]);
                }
                printf("Total head movement: %d\n", headm);
                break;

            case 2:
                headm = 0;
                ini = copy;
                i = 0;
                while (new[i] < ini) {
                    i++;
                }
                cpy = i;
                for (i = cpy - 1; i >= 0; i--) {
                    d = abs(ini - new[i]);
                    headm += d;
                    ini = new[i];
                    printf("%d\t", new[i]);
                }
                for (i = cpy; i < size + 1; i++) {
                    d = abs(ini - new[i]);
                    headm += d;
                    ini = new[i];
                    printf("%d\t", new[i]);
                }
                printf("Total head movement: %d\n", headm);
                break;

            case 3:
                printf("Exit\n");
                break;
        }
    } while (dir != 3);
}
