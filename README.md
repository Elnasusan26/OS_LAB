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

### Disadvantages of FCFS
* Convoy Effect*: Shorter processes may have to wait for a long process to complete, leading to increased average waiting time and turnaround time. This is known as the convoy effect.
* **Non-preemptive**: Since it does not allow preemption, a long-running process can delay all subsequent processes, which can be inefficient in a time-sharing environment.
* **Poor Performance**: In scenarios with a mix of short and long processes, FCFS can lead to poor performance metrics compared to other scheduling algorithms.


## [Priority](https://github.com/Ajallen14/OS_LAB/blob/Allen/CPU%20scheduling/priority.c)
Priority scheduling is a CPU scheduling algorithm that assigns a priority level to each process, determining the order in which processes are executed based on their priority. The process with the highest priority is selected for execution first. If two processes have the same priority, they may be scheduled using a secondary criterion, such as First-Come First-Served (FCFS).

### How Priority Scheduling Works
* **Priority Assignment**: Each process is assigned a priority value, which can be based on various factors such as importance, urgency, or resource requirements. The priority can be static (fixed) or dynamic (changing over time).

* **Queue Structure**: Processes are maintained in a priority queue. The CPU scheduler selects the process with the highest priority from this queue for execution.

* **Execution Order**: The CPU executes the highest-priority process first. If a new process arrives with a higher priority than the currently running process, the current process may be preempted (if the scheduling is preemptive) and the new process will be executed.

## [Round Robin](https://github.com/Ajallen14/OS_LAB/blob/Allen/CPU%20scheduling/round_robin.c)
Round Robin (RR) is a widely used CPU scheduling algorithm that is particularly effective in time-sharing systems. It is designed to provide fair allocation of CPU time to all processes in the ready queue, ensuring that each process gets an equal opportunity to execute.

### How Round Robin Works
* **Time Quantum**: Round Robin scheduling operates on the principle of time slices or time quanta. A fixed time quantum (e.g., 10 milliseconds) is defined, which determines how long a process can run before it is preempted.

* **Queue Structure**: Processes are maintained in a circular queue. When a process arrives, it is added to the end of the queue.

* **Execution Order**: The CPU scheduler picks the first process in the queue and allows it to execute for a duration equal to the time quantum. If the process completes its execution within this time, it is removed from the queue. If it does not complete, it is preempted and moved to the back of the queue, allowing the next process in line to execute.

* **Cyclic Nature**: This process continues in a cyclic manner until all processes are completed. Each process gets a chance to execute in a round-robin fashion, hence the name

## [Shortest Job First](https://github.com/Ajallen14/OS_LAB/blob/Allen/CPU%20scheduling/shortest.c)
Shortest Job First (SJF) is a CPU scheduling algorithm that selects the process with the smallest execution time (or burst time) to execute next. It is designed to minimize the average waiting time and turnaround time for a set of processes. SJF can be implemented in two ways: non-preemptive and preemptive.

### How Shortest Job First Works
* **Process Selection**: In SJF, the scheduler selects the process with the shortest burst time from the ready queue. This means that the process that requires the least amount of CPU time will be executed first.

* **Non-Preemptive SJF**: Once a process starts executing, it cannot be interrupted until it completes. If a new process arrives with a shorter burst time than the currently running process, it will have to wait until the current process finishes.

* **Preemptive SJF (Shortest Remaining Time First)**: In this variant, if a new process arrives with a shorter burst time than the remaining time of the currently running process, the CPU will preempt the current process and allocate the CPU to the new process.