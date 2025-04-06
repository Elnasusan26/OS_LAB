#include <stdio.h>

int main() {
    int i, n, total = 0, x, t_quantum, w_time = 0, t_time = 0;
    int a_time[10], b_time[10], temp[10], wt[10], tat[10];
    float avgwt, avgtt;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    x = n;

    // Input arrival time, burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &a_time[i]);
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &b_time[i]);
        temp[i] = b_time[i];  // Copy burst time to temp array
    }

    // Input time quantum
    printf("Enter Time Quantum: ");
    scanf("%d", &t_quantum);

    printf("\n----------------------------\n");
    printf("PID\tAT\tBT\tWT\tTAT\n");
    printf("----------------------------\n");

    int completed = 0, time = 0;

    // While not all processes are completed
    while (completed != n) {
        int executed = 0;
        
        // Iterate through all processes
        for (i = 0; i < n; i++) {
            // Only execute processes that are not completed and have arrived
            if (temp[i] > 0 && a_time[i] <= time) {
                executed = 1;

                // If burst time left is greater than time quantum, process runs for time quantum
                if (temp[i] > t_quantum) {
                    time += t_quantum;
                    temp[i] -= t_quantum;
                } else {
                    time += temp[i];
                    temp[i] = 0;
                    completed++;

                    // Calculate turnaround time (TAT) and waiting time (WT)
                    tat[i] = time - a_time[i];  // Turnaround time = Completion time - Arrival time
                    wt[i] = tat[i] - b_time[i]; // Waiting time = Turnaround time - Burst time

                    // Print process details
                    printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, a_time[i], b_time[i], wt[i], tat[i]);

                    // Accumulate total waiting time and turnaround time
                    w_time += wt[i];
                    t_time += tat[i];
                }
            }
        }

        // If no process was executed in the current round, break the loop
        if (!executed)
            break;
    }

    // Calculate average waiting time and average turnaround time
    avgwt = (float) w_time / n;
    avgtt = (float) t_time / n;

    // Output the average waiting time and average turnaround time
    printf("----------------------------\n");
    printf("Average Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtt);

    return 0;
}
