#include <stdio.h>
void main() {
	int bs[50], ps[50];
	int frag[50];
	static int a[50], alloc[50];
	int i, m, n, j, temp, lowest = 10000;
	printf("Enter the number of memory blocks: ");
	scanf("%d", &m);
	printf("Enter the size of each memory block:\n");
	for (int i = 1; i <= m; i++) {
		scanf("%d", &bs[i]);
	}
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the size of each process:\n"); 
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ps[i]);
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (alloc[j] != 1) {
				temp = bs[j] - ps[i];
				if (temp >= 0){
					if (lowest > temp) {
						a[i] = j;
						lowest = temp;
					}
				}
			}
		}
		frag[i] = lowest; alloc[a[i]] = 1;
		lowest = 10000;
	}
	printf("\nFile No\t File Size\t Block No\t Block Size\t Fragment");
	for (i = 1; i <= n; i++) {
		printf("\n%d \t\t%d\t\t%d\t\t%d\t\t%d", i, ps[i], a[i], bs[a[i]], frag[i]);
	}
	printf("\n");
}