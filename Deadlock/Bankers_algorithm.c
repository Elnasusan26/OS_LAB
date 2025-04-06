#include<stdio.h>
#include<conio.h>

int max[100][100], alloc[100][100], need[100][100], avail[100], n, r;
void input();
void show();
void cal();

int main(){
    int i,j;
    printf("********** Banker's Algorithm ************\n");
    input();
    show();
    cal();
    getch();
    return 0;
}

void input(){
    int i,j;
    printf("Enter the no of Processes\t");
    scanf("%d",&n);
    printf("Enter the no of resources instances\t");
    scanf("%d",&r);

    printf("Enter the Max Matrix\n");
    for(i = 0;i < n; i++){
        for(j = 0; j < r; j++){
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix\n");
    for(i = 0;i < n; i++){
        for(j = 0; j < r; j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter the available Resources\n");
    for(j = 0; j < r; j++){
        scanf("%d",&avail[j]);
    }
}

void show(){
    int i,j;
    printf("Process\t Allocation\t Max\t Available\n");
    for(i = 0;i < n; i++){
        printf("\nP%d\t",i+1);

        for(j = 0;j < r; j++){
            printf("%d ",alloc[i][j]); 
        }
        printf("\t");
        for(j=0;j<r;j++){
            printf("%d ",max[i][j]);
        }
        printf("\t");
        if(i==0){
            for(j = 0; j < r; j++){
                printf("%d ",avail[j]);
            }
        }
    }
}

void cal(){
    int finish[100], need[100][100], flag = 1, k, c1 = 0, i, j;
    for(i = 0; i < n; i++){
        finish[i] = 0; 
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < r; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("\n");
    while(flag){
        flag = 0;
        for(i = 0; i < n; i++){
            int c = 0;
            for(j = 0; j < r; j++){
                if((finish[i] == 0) && (need[i][j] <= avail[j])){
                    c++;
                }
            }
            if(c == r){ // If all needs are satisfied
                for(k = 0; k < r; k++){
                    avail[k] += alloc[i][k]; // Correctly update available resources
                }
                finish[i] = 1; // Mark process as finished
                flag = 1; // Set flag to indicate that we found a process that can finish
                printf("P%d->", i + 1); // Output the finished process
            }
        }
    }

    for(i = 0; i < n; i++){
        if(finish[i] == 1){
            c1++;
        } else {
            printf("P%d->", i + 1); // Output the processes that are not finished
        }
    }
    if(c1 == n){
        printf("\nThe system is in a safe state\n");
    } else {
        printf("\nProcesses are in deadlock\n");
        printf("System is in an unsafe state\n");
    }
}