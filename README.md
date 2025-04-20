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
Deadlock is a situation in a multiprogramming environment where two or more processes are unable to proceed because each is waiting for the other to release resources. In other words, a deadlock occurs when a set of processes is blocked because each process is holding a resource and waiting for another resource that is held by another process. This can lead to a complete halt in the execution of the involved processes, resulting in a system that is effectively frozen for those processes.

### Conditions for Deadlock

For a deadlock to occur, four necessary conditions must hold simultaneously:

1. **Mutual Exclusion**: At least one resource must be held in a non-shareable mode. If another process requests that resource, the requesting process must be delayed until the resource is released.

2. **Hold and Wait**: A process holding at least one resource is waiting to acquire additional resources that are currently being held by other processes.

3. **No Preemption**: Resources cannot be forcibly taken from a process holding them. A resource can only be released voluntarily by the process holding it after it has completed its task.

4. **Circular Wait**: There exists a set of processes \(\{P_1, P_2, \ldots, P_n\}\) such that \(P_1\) is waiting for a resource held by \(P_2\), \(P_2\) is waiting for a resource held by \(P_3\), and so on, with \(P_n\) waiting for a resource held by \(P_1\), forming a circular chain.

## [Banker's Algorithm](https://github.com/Ajallen14/OS_LAB/blob/Allen/Deadlock/Bankers_algorithm.c)
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


# [DISK SCHEDULING](https://github.com/Ajallen14/OS_LAB/tree/Allen/Disk%20Scheduling)
Disk scheduling is a crucial aspect of operating system design that manages how disk I/O requests are handled. Since disk access times are significantly slower than CPU processing times, efficient disk scheduling is essential for optimizing system performance and ensuring that processes can access data quickly and efficiently.

### Importance of Disk Scheduling

1. **Performance Optimization**: Disk scheduling algorithms aim to minimize the average wait time and seek time for disk I/O operations, which can significantly improve overall system performance.

2. **Resource Management**: Efficient disk scheduling helps manage the limited resources of the disk subsystem, ensuring that multiple processes can access the disk without causing bottlenecks.

3. **Fairness**: Disk scheduling algorithms can help ensure that all processes get a fair chance to access the disk, preventing starvation of any particular process.

4. **Throughput Improvement**: By optimizing the order of disk requests, disk scheduling can increase the number of requests serviced in a given time period, improving overall throughput.

## [First Come First Serve](https://github.com/Ajallen14/OS_LAB/blob/Allen/Disk%20Scheduling/fcfs.c)
First-Come, First-Served (FCFS) is one of the simplest disk scheduling algorithms used in operating systems to manage disk I/O requests. It operates on a straightforward principle: the disk scheduler services requests in the order they arrive in the queue.

### How FCFS Disk Scheduling Works
* **Request Queue**: When processes request access to the disk, these requests are placed in a queue. Each request typically specifies the track number on the disk that needs to be accessed.

* **Order of Service**: The disk scheduler services requests in the exact order they arrive. The first request in the queue is the first to be processed, followed by the second request, and so on.

* **No Preemption**: Once the disk head starts servicing a request, it will complete that request before moving on to the next one. There is no preemption in FCFS; the disk head will not switch to another request until the current one is finished.

## [Scan](https://github.com/Ajallen14/OS_LAB/blob/Allen/Disk%20Scheduling/scan.c)
The SCAN disk scheduling algorithm, also known as the elevator algorithm, is a widely used method for managing disk I/O requests in operating systems. It is designed to optimize the movement of the disk arm (or head) to reduce the average seek time and improve overall system performance. Here’s a detailed explanation of how the SCAN algorithm works, its advantages, disadvantages, and applications.

### How SCAN Works

1. **Movement Direction**: The SCAN algorithm moves the disk arm in one direction (either towards the outer edge of the disk or towards the inner edge) and services all requests in that direction until it reaches the end of the disk.

2. **Service Requests**: As the disk arm moves, it services all pending requests in the path of its movement. Once it reaches the end of the disk, it reverses direction and services requests on the way back.

3. **Example**: 
   - Consider a disk with tracks numbered from 0 to 199 and the current position of the disk head at track 100. 
   - If the pending requests are for tracks 30, 60, 10, 120, 150, and 180, the SCAN algorithm will service the requests in the following order:
     - Move from track 100 to track 120, then to 150, and finally to 180 (servicing requests in the upward direction).
     - After reaching track 180, the disk arm will reverse direction and move back to track 0, servicing requests for tracks 60, 30, and 10 on the way back.

## [C-Scan](https://github.com/Ajallen14/OS_LAB/blob/Allen/Disk%20Scheduling/c_scan.c)
C-SCAN (Circular SCAN) is a disk scheduling algorithm that is a variant of the SCAN algorithm. It is designed to optimize the servicing of disk I/O requests while minimizing the average wait time and ensuring a more uniform response time for requests. C-SCAN operates on the principle of treating the disk as a circular structure, which helps in providing a more predictable performance for disk access. Here’s a detailed explanation of how C-SCAN works, its advantages, disadvantages, and applications.

### How C-SCAN Works

1. **Movement Direction**: Similar to the SCAN algorithm, C-SCAN moves the disk arm in one direction (either towards the outer edge or the inner edge of the disk) and services all requests in that direction.

2. **Service Requests**: As the disk arm moves, it services all pending requests in its path. Once it reaches the end of the disk, instead of reversing direction and servicing requests on the way back (as in SCAN), the C-SCAN algorithm jumps back to the beginning of the disk without servicing any requests during this return trip.

3. **Example**:
   - Consider a disk with tracks numbered from 0 to 199 and the current position of the disk head at track 100.
   - If the pending requests are for tracks 30, 60, 10, 120, 150, and 180, the C-SCAN algorithm will service the requests in the following order:
     - Move from track 100 to track 120, then to 150, and finally to 180 (servicing requests in the upward direction).
     - After reaching track 180, the disk arm jumps back to track 0 without servicing any requests.
     - It then continues servicing requests in the upward direction again, starting from track 0.

# [INTER PROCESS COMMUNICATION](https://github.com/Ajallen14/OS_LAB/tree/Allen/Inter%20Process%20Communication)
Inter-Process Communication (IPC) refers to the mechanisms and methods that allow processes to communicate and synchronize their actions while executing concurrently. Since processes in an operating system can run independently and may not share memory, IPC is essential for enabling them to exchange data, coordinate their activities, and share resources effectively. IPC is crucial in multi-process systems, where multiple processes may need to work together to complete a task.

### Types of Inter-Process Communication

There are several IPC mechanisms, each with its own characteristics, advantages, and use cases. The main types of IPC include:

1. **Shared Memory**:
   - **Description**: In shared memory IPC, multiple processes can access a common memory segment. One process writes data to the shared memory, and other processes can read from it.
   - **Advantages**: Fast communication since data does not need to be copied between processes; efficient for large amounts of data.
   - **Disadvantages**: Requires synchronization mechanisms (like semaphores or mutexes) to prevent race conditions and ensure data consistency.

2. **Message Passing**:
   - **Description**: Processes communicate by sending and receiving messages. This can be done through various methods, such as message queues, mailboxes, or sockets.
   - **Advantages**: Simplifies synchronization since messages are sent and received in a controlled manner; suitable for distributed systems.
   - **Disadvantages**: Overhead due to message copying; may be slower than shared memory for large data transfers.

3. **Pipes**:
   - **Description**: Pipes provide a unidirectional communication channel between processes. Data written to a pipe by one process can be read by another process.
   - **Types**:
     - **Anonymous Pipes**: Used for communication between related processes (e.g., parent and child).
     - **Named Pipes (FIFOs)**: Can be used for communication between unrelated processes and are identified by a name in the file system.
   - **Advantages**: Simple to use; suitable for streaming data.
   - **Disadvantages**: Limited to unidirectional communication (for anonymous pipes); may require synchronization.

4. **Sockets**:
   - **Description**: Sockets provide a way for processes to communicate over a network. They can be used for both local and remote communication.
   - **Advantages**: Flexible and powerful; can be used for communication between processes on different machines.
   - **Disadvantages**: More complex to implement; involves network overhead.

5. **Signals**:
   - **Description**: Signals are a limited form of IPC used to notify a process that a specific event has occurred. For example, a process can send a signal to another process to indicate that it should terminate or handle an event.
   - **Advantages**: Lightweight and efficient for simple notifications.
   - **Disadvantages**: Limited in terms of data transfer; can be difficult to manage and handle.

6. **Semaphores**:
   - **Description**: Semaphores are synchronization primitives used to control access to shared resources. They can be used to signal between processes and manage resource allocation.
   - **Advantages**: Effective for preventing race conditions and ensuring mutual exclusion.
   - **Disadvantages**: Can lead to complexity in managing multiple semaphores; potential for deadlocks if not used carefully.

# [MEMORY ALLOCATION](https://github.com/Ajallen14/OS_LAB/tree/Allen/Memory%20Allocation)
Memory allocation is a critical aspect of operating system design and management, involving the process of assigning memory resources to various programs and processes during their execution. Efficient memory allocation is essential for optimizing system performance, ensuring that applications have the necessary resources to run, and preventing issues such as fragmentation and memory leaks. Here’s a detailed overview of memory allocation, its types, strategies, and challenges

