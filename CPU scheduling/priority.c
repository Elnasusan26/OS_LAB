#include <stdio.h>

struct process {
    int id;
    int a_time;
    int b_time;
    int w_time;
    int t_time;
    int priority;
} p[10], temp;

void main() {
    int n, i, j;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].id = i + 1;  
        p[i].a_time = 0;   
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &p[i].b_time);
        printf("Enter Priority of P%d: ", i + 1);
        scanf("%d", &p[i].priority);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int wt_temp[10]; 
    wt_temp[0] = 0;  

    for (i = 0; i < n; i++) {
        p[i].w_time = wt_temp[i];
        wt_temp[i + 1] = wt_temp[i] + p[i].b_time;
        p[i].t_time = p[i].w_time + p[i].b_time;
    }

    float avgwt = 0, avgtt = 0;
    for (i = 0; i < n; i++) {
        avgwt += p[i].w_time;
        avgtt += p[i].t_time;
    }
    avgwt /= n;
    avgtt /= n;

    printf("-----------------------------------------------\n");
    printf("PID\tAT\tBT\tPR\tWT\tTAT\n");
    printf("-----------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].a_time, p[i].b_time, p[i].priority, p[i].w_time, p[i].t_time);
    }

    printf("-----------------------------------------------\n");
    printf("\nGantt Chart:\n");
    printf("--------------------------\n");
    printf("|");
    for (i = 0; i < n; i++) {
        printf("   P%d  |", p[i].id);
    }
    printf("\n--------------------------\n");

    for (i = 0; i <= n; i++) {
        printf("%d\t", wt_temp[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtt);
}