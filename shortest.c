#include<stdio.h>

struct process{
    int id;
    int a_time;
    int b_time;
    int w_time;
    int t_time;
} p[10], temp;

int main() {
    int n, i, j, burst = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        p[i].id = i;
        p[i].a_time = 0;
        printf("Enter burst time of p%d: ", i);
        scanf("%d", &p[i].b_time);
        p[i].w_time = burst;
        burst = burst + p[i].b_time;
        p[i].t_time = p[i].w_time + p[i].b_time;
    }
    for(i = 1; i <= n; i++) {
        for(j = i + 1; j <= n; j++) {
            if(p[i].b_time > p[j].b_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    int temp_time[10];
    temp_time[1] = 0;
    for(i = 1; i <= n; i++) {
        p[i].w_time = temp_time[i];
        temp_time[i + 1] = temp_time[i] + p[i].b_time;
        p[i].t_time = p[i].w_time + p[i].b_time;
    }

    float avgwt = 0;
    float avgtt = 0;
    for(i = 1; i <= n; i++) {
        avgwt = avgwt + p[i].w_time;
        avgtt = avgtt + p[i].t_time;
    }

    printf("\n--------------\n");
    printf("PID \tAT\tBT \tWT \tTAT \n");
    printf("--------------\n");

    for(i = 1; i <= n; i++) {
        printf("p%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].a_time, p[i].b_time, p[i].w_time, p[i].t_time);
    }

    printf("\n--------------\n");
    printf("\nGantt chart:\n");
    printf("--------------\n");
    printf("|");

    for(i = 1; i <= n; i++) {
        printf("p%d\t|", p[i].id);
    }
    printf("|");
    printf("\n--------------\n");

    for(i = 1; i <= n; i++) {
        printf("%d\t", p[i].t_time);
    }

    printf("\n\n");
    printf("Average waiting time: %f\n", avgwt / n);
    printf("Average turn around time: %f\n", avgtt / n);

    return 0;
}
	


