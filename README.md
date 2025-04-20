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

# [DEADLOCK](https://github.com/Ajallen14/OS_LAB/tree/Allen/Deadlock)

## [Banker's Algorithm](https://github.com/Ajallen14/OS_LAB/blob/Allen/Deadlock/deadlock_detection.c)
The Banker's Algorithm is a resource allocation and deadlock avoidance algorithm used in operating systems to manage multiple processes and ensure that they do not enter a deadlock state. It was developed by Edsger Dijkstra and is named for its analogy to a banking system, where the bank must ensure that it has enough resources available to satisfy the maximum needs of all customers (processes) without running into a deadlock.

How the Banker's Algorithm Works
The Banker's Algorithm operates in two main phases: Resource Request and Safety Check.

1. Resource Request
    When a process requests resources, the algorithm checks if the request can be granted without leading the system into an unsafe state. The steps are as follows:
    * Check Request Validity: Ensure that the requested resources do not exceed the maximum claim of the process and that the requested resources are available.
    ```
    if (Request[i][j] <= Need[i][j]) and (Request[i][j] <= Available[j]) then
    ```
    * Pretend to Allocate: Temporarily allocate the requested resources to the process and update the state:

        * Update the Available vector.
        * Update the Allocation matrix.
        * Update the Need matrix.
    * Safety Check: After the temporary allocation, check if the system is in a safe state using the safety algorithm (described below). If the system is safe, grant the request; otherwise, roll back the changes and deny the request.
2. Safety Check
    The safety algorithm checks if there exists a sequence of processes that can finish executing without leading to a deadlock. The steps are as follows:
    
    * **Initialization**: Create a Work vector initialized to the Available resources and a Finish array initialized to false for all processes.
    
    * **Find a Process**: Look for a process that can finish with the current Work resources (i.e., its Need can be satisfied by Work).

    * Simulate Execution: If such a process is found:

        * Assume it finishes and add its allocated resources back to Work.
        * Mark the process as finished.
    * Repeat: Continue this process until either all processes are finished (safe state) or no further processes can be found (unsafe state).