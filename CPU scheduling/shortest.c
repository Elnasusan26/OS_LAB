#include<stdio.h>

struct process{
    int id;
    int at;
    int bt;
    int wt;
    int tt;
}p[10], temp;

int main(){
    int n, i, j, burst = 0;
    printf("Enter number of process : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        p[i].id = 0;
        p[i].at = 0;
        printf("Enter burst time of p%d : ", i);
        scanf("%d", &p[i].bt);

        p[i].wt = burst;
        burst += burst + p[i].bt;
        p[i].tt = p[i].wt + p[i].bt;
    }P3

    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(p[i].bt > p[j].bt){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int temp_time[10];
    temp_time[0] = 0;
    for(i = 0; i < n; i++){
        p[i].wt = temp_time[i];
        temp_time[i + 1] = temp_time[i] + p[i].bt;
        p[i].tt = p[i].wt + p[i].bt;
    }

    float avgwt = 0, avgtt = 0;
    for(i = 0; i < n; i++){
        avgwt = avgwt + p[i].wt;
        avgtt = avgtt + p[i].tt;
    }

    printf("\n-------------------\n");
    printf("PID\tAT\tBT\tWT\tTAT\n");
    printf("\n-------------------\n");

    for(i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tt);
    }

    printf("\n--------------------\n");
    printf("\nGANTT CHART\n");
    printf("-------------------\n");
    printf("|");
    for(i = 0; i < n; i++){
        printf("P%d\t|", i);
    }
    printf("\n-----------------\n");
    printf("0\t");
    for(i = 0; i < n; i++){
        printf("%d\t", p[i].tt);
    }

    printf("\nAvg waiting time : %f\n", avgwt / n);
    printf("Avg turnaround time : %f\n", avgtt / n);
}
