# [CPU SCHEDULING](https://github.com/Ajallen14/OS_LAB/tree/Allen/CPU%20scheduling)

## [First Come first serve](https://github.com/Ajallen14/OS_LAB/blob/Allen/CPU%20scheduling/1st_come_1st_serve.c)
First-Come, First-Served (FCFS) is one of the simplest scheduling algorithms used in CPU scheduling. It operates on a straightforward principle: the process that arrives first in the ready queue is the one that gets executed first.

### How FCFS Works
* **Queue Structure**: Processes are maintained in a queue. When a process arrives, it is added to the end of the queue.
* **Execution Order**: The CPU picks the process at the front of the queue and executes it until it completes. Once a process is finished, the CPU moves on to the next process in the queue.
* **Non-preemptive**: FCFS is a non-preemptive scheduling algorithm, meaning that once a process starts executing, it cannot be interrupted until it finishes. This can lead to inefficiencies if a long process blocks shorter ones.

### Advantages of FCFS
* **Simplicity**: FCFS is easy to understand and implement. It requires minimal overhead and is straightforward in terms of process management.
* **Fairness**: Every process gets a chance to execute in the order of arrival, which can be perceived as fair.

## Disadvantages of FCFS
* Convoy Effect*: Shorter processes may have to wait for a long process to complete, leading to increased average waiting time and turnaround time. This is known as the convoy effect.
* **Non-preemptive**: Since it does not allow preemption, a long-running process can delay all subsequent processes, which can be inefficient in a time-sharing environment.
* **Poor Performance**: In scenarios with a mix of short and long processes, FCFS can lead to poor performance metrics compared to other scheduling algorithms.


## [Priority](https://github.com/Ajallen14/OS_LAB/blob/Allen/CPU%20scheduling/priority.c)


## [Round Robin](https://github.com/Ajallen14/OS_LAB/blob/Allen/CPU%20scheduling/round_robin.c)


## [Shortest](https://github.com/Ajallen14/OS_LAB/blob/Allen/CPU%20scheduling/shortest.c)
