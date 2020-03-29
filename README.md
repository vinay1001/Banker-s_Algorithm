# Banker-s_Algorithm
## Code for Banker's Algorithm in c++.

### PROBLEM STATEMENT
Write a multithreaded program that implements the banker's algorithm. Create n threads that request and release resources from the bank. The banker will grant the request only if it leaves the system in a safe state. It is important that shared data be safe from concurrent access. To ensure safe access to shared data, you can use mutex locks.

### Banker’s Algorithm:

The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for predetermined maximum possible amounts of all resources, then makes an “s-state” check to test for possible activities, before deciding whether allocation should be allowed to continue.

### Deadlock:
A deadlock is a situation in which two computer programs sharing the same resource are effectively preventing each other from accessing the resource, resulting in both programs ceasing to function. The earliest computer operating systems ran only one program at a time.

### Safe Sequence:
The sequence of processes in a system, that assures that their execution doesn’t create any deadlock.

If there are n no. of processes in a system, each process needs certain instances of resources available. Banker’s Algorithm allows to check whether there could be a chance of deadlock if the process continue to access the resources. Banker’s Algorithm helps to create the safe sequence of processes.
                                
                                
### Algorithm:

```
1.	Repeat steps 2 to 25 While( finished < Processes)//p times
2.	{
3.	   Safe = false;

4.	   Repeat steps 5 to 24 For p from 1 to processes //p times
5.	   {
6.	     If(!finished)
7.	     {
8.	       Possible = true;
9.	        For r from 1 to resources
10.	      {
11.	         If(needed_resources > available_resources)
12.	         {
13.	           Possible = false;
14.	           Break;
15.	         }
16.	    }

17.	   If(possible = false)
18.	   {
19.	        Free the resources for that process  //r times
20.	        And add to available resources

21.	         Add process p to safe sequence.
22.	   }
23.	  }  
24.	  }
25.	  }
```
### Complexity of Algorithm:
The outside while loop runs p(no.of active processes) times,and for each process for loop also runs p times to check need and availability condition.After each process is completed the r resources will be freed using for loop.

So the time complexity for bankers algorithm is  r*(P*P).

r  No.of resources.
P  No.of Active Processes.

### Constraints:

1.	Number of processes and resources can’t be altered during the execution of code. They should be fixed initially.
2.	This code provides only one safe sequence even if multiple safe sequences are possible.
3.	Speed of execution depends on total no.of active processes in the system.


### Code Execution and Test Cases:

### Test Case 1: Input   - Safe sequence is possible
```
Enter total no.of processes - 5
Enter no.of resources - 3
Enter instances available for each resource (R1 R2 ...) - 3 3 2
Enter allocated resources for process 1 - 0 1 0

Enter allocated resources for process 2 - 2 0 0

Enter allocated resources for process 3 - 3 0 2

Enter allocated resources for process 4 - 2 1 1

Enter allocated resources for process 5 - 0 0 2




Enter maximum resources for process 1 - 7 5 3

Enter maximum resources for process 2 - 3 2 2

Enter maximum resources for process 3 - 9 0 2

Enter maximum resources for process 4 - 2 2 2

Enter maximum resources for process 5 - 4 3 3
```
 Output:
 
 ```
 SAFE SEQUENCE IS : 2 4 5 1 3

Thread created successfully

Thread created successfully

Thread created successfully

Thread created successfully

Thread created successfully



----------PROCESS 2

Maximum requirement - 3 2 2
Allocated           - 2 0 0
Needed              - 1 2 2


Available for allocation
Resource Allocated
Process started
Process terminated and resources released
Current Available Resources - 5 3 2





----------PROCESS 4

Maximum requirement - 2 2 2
Allocated           - 2 1 1
Needed              - 0 1 1


Available for allocation
Resource Allocated
Process started
Process terminated and resources released
Current Available Resources - 7 4 3





----------PROCESS 5

Maximum requirement - 4 3 3
Allocated           - 0 0 2
Needed              - 4 3 1


Available for allocation
Resource Allocated
Process started
Process terminated and resources released
Current Available Resources - 7 4 5





----------PROCESS 1

Maximum requirement - 7 5 3
Allocated           - 0 1 0
Needed              - 7 4 3


Available for allocation
Resource Allocated
Process started
Process terminated and resources released
Current Available Resources - 7 5 5





----------PROCESS 3

Maximum requirement - 9 0 2
Allocated           - 3 0 2
Needed              - 6 0 0


Available for allocation
Resource Allocated
Process started
Process terminated and resources released
Current Available Resources - 10 5 7
```
### Test Case 2: 

### Input
```
Enter total no.of processes - 3
Enter no.of resources - 4
Enter instances available for each resource (R1 R2 ...) - 3 0 1 2
Enter allocated resources for process 1 - 1 2 2 1

Enter allocated resources for process 2 - 1 1 3 3

Enter allocated resources for process 3 - 1 2 1 0




Enter maximum resources for process 1 - 3 3 2 2

Enter maximum resources for process 2 - 1 2 3 4

Enter maximum resources for process 3 - 1 3 5 0
```
### Output
```
NO SAFE SEQUENCE FOUND
```
 
 


