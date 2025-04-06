#include<stdio.h>

int main(){
    int i, n, a_t[10], b_t[10], burst = 0, w_t[10], temp[10], ta_t[10];
    float avgwt = 0, avgtt = 0;

    printf("Enter the no. of process :");
    scanf("%d", &n);

    temp[0] = 0;

    for( i = 0; i < n; i++){
        printf("Enter the arrival time of P%d : ", i+1);
        scanf("%d", &a_t[i]);

        printf("Enter the burst time of P%d : ", i+1);
        scanf("%d", &b_t[i]);
        
        burst += b_t[i];
        temp[i+1] = burst;

        if(i == 0){
            w_t[i] = 0;
        }else {
            w_t[i] = temp[i] - a_t[i];
        }
        ta_t[i] = w_t[i] + b_t[i]; 
    }

    printf("----------------------\n");
    printf("PID\tAT\tBT\tWT\tTAT");
    printf("\n----------------------\n");
    for(i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, a_t[i], b_t[i], w_t[i], ta_t[i]);
    }

    printf("\nGANTT CHART\n");
    printf("----------------------------\n");
    printf("|");
    for(i = 0; i < n; i++){
        printf("P%d\t|", i+1);
    }
    printf("\n----------------------------\n");

    printf("\n0");
    for(i = 0; i < n; i++){
        printf("\t%d", temp[i + 1]);
    }

    for(i = 0; i < n; i++){
        avgwt += w_t[i];
        avgtt += ta_t[i];
    }
    avgwt /= n;
    avgtt /= n;
    printf("\nAvg waiting time : %f\n", avgwt);
    printf("Avg turnaround time %f\n: ", avgtt);
}
