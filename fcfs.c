#include <stdio.h>
#include <math.h>

int main() {
    int size, head, seek_count = 0, cur_req, distance;
    int arr[10];

    printf("Enter the number of disk requests (array size): ");
    scanf("%d", &size);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the disk request tracks (separated by spaces): ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Request Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Seek Sequence:\n");
    for (int i = 0; i < size; i++) {
        cur_req = arr[i];
        distance = fabs(head - cur_req);
        seek_count += distance;
        head = cur_req;
        printf("%d ", arr[i]);
    }

    printf("\n");
    printf("Total number of seek operations: %d\n", seek_count);
    return 0;
}

