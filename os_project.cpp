#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include<iostream>
using namespace std;

int no_process ,no_resources;
int p_number= 0;
void*process(void *arg);
pthread_mutex_t lock;              //to lock the threads
pthread_cond_t condition;

int main()
{
	//taking input for no.of process
	cout<<"Enter total no.of processes - ";
	cin>>no_process; //taking input of process number
	
	//taking input for no.of resources
	cout<<"Enter no.of resources - ";
	cin>>no_resources;  //taking inpput of no of resources
	
	//taking input for total availability of resources;
	int current_resources[no_resources];
	cout<<"Enter instances available for each resource (R1 R2 ...) - ";
	for(int i = 0;i<no_resources;i++)
	{
		cin>>current_resources[i];
	}
	
	int allocated_resources[no_process][no_resources];
	//taking input for allocated resources for eaach process
	for(int i = 0;i<no_process;i++)
	{
        cout<<"Enter allocated resources for process "<<(i+1)<<" - ";
		for(int j = 0;j<no_resources;j++)
		{
			cin>>allocated_resources[i][j];
		}
		cout<<"\n";
	}
	 
	cout<<"\n\n\n";
	
	int max_req[no_process][no_resources];
	//taking input for max_requirement of resources for each process
	for(int i = 0;i<no_process;i++)
	{
		cout<<"Enter maximum resources for process "<<(i+1)<<" - ";
		for(int j = 0;j<no_resources;j++)
		{
			cin>>max_req[i][j];
		}
		cout<<"\n";
	}
	
	int rem_need[no_process][no_resources]; //matrix for remaining need of resources for each process;
	
	for(int i = 0;i<no_process;i++)
	{
		for(int j = 0;j < no_resources;j++)
		{
			rem_need[i][j] = max_req[i][j] - allocated_resources[i][j];
		}
	}
	
	//array to store safe sequence
	int safe_seq[no_process];
	for(int i = 0;i<no_process;i++)
	{
		safe_seq[i] = -1;
	}
	bool s;
	//cout<<"\nFINAL OUTPUT - "<<s
	
	int copy_current_resources[no_resources];
	for(int i = 0;i<no_resources;i++)
	{
		copy_current_resources[i] = current_resources[i];
	}
	
	bool finish[no_process]; //to store finish status of processes;
	for(int i = 0;i<no_process;i++)
	{
		finish[i] = false;  //initially all processes are not finished
	}
	
	int no_finish = 0; //no_of finished processes are zero initially
	
	while(no_finish <no_process)
	{
		bool safe = false;
		
		for(int i = 0;i<no_process;i++)   //running loop for each process to check for finish status
		{
			if(!finish[i])
			{
				bool possible = true;
				for(int j = 0;j<no_resources;j++)
				{
					if(rem_need[i][j] > copy_current_resources[j])  //checking need and availability of resources for each process
					{
						possible = false;
						break;
					}
			    }
			    
			    if(possible)
			    {
			    	for(int j = 0;j<no_resources;j++)
			    	{
			    		copy_current_resources[j] += allocated_resources[i][j];
					}
					safe_seq[no_finish] = i;
			    	finish[i] = true;              //updating the finish status
			    	no_finish++;
			    	safe = true;
				}
			}
		}
		
		if(!safe)
		{
			for(int j = 0;j<no_process;j++)
			{
				safe_seq[j] = -1;            
				s = false;      //no safe sequence found after all process checks.
				cout<<"NO SAFE SEQUENCE FOUND";
				sleep(5);
				exit(0);
			}
		}
	}
	s = true;
	
	if(s == true){
	cout<<"SAFE SEQUENCE IS : ";
	for(int i = 0;i<no_process;i++)
	{
		
		cout<<safe_seq[i] + 1<<" ";
	}
	cout<<"\n";
}

    //creating and running threads
    pthread_t processes[no_process];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

	int processNumber[no_process];
	for(int i=0; i<no_process; i++) processNumber[i] = i;{

        for(int i=0; i<no_process; i++)
               { pthread_create(&processes[i], &attr, process,(void *)(&processNumber[i]));
                 
			   }

        for(int i=0; i<no_process; i++)
               { pthread_join(processes[i], NULL);}
               
        for(int i = 0;i<no_process;i++)
		{
			cout<<"\n\n\n";
			cout<<"----------PROCESS "<<safe_seq[i]+1<<"\n\n";
			int k = safe_seq[i];
			cout<<"Maximum requirement - ";
			for(int j = 0;j < no_resources;j++)
			{cout<<max_req[k][j]<<" ";}
			cout<<"\n";
			cout<<"Allocated           - ";
			for(int j = 0;j < no_resources;j++)
			{cout<<allocated_resources[k][j]<<" ";}
			cout<<"\n";
			cout<<"Needed              - ";
			for(int j = 0;j < no_resources;j++)
			{cout<<rem_need[k][j]<<" ";}
			cout<<"\n";
			cout<<"\n\n";
			
			cout<<"Available for allocation\n";
			sleep(1);
			cout<<"Resource Allocated\n";
			sleep(1);
			cout<<"Process started\n";
			sleep(1);
			cout<<"Process terminated and resources released";
			cout<<"\nCurrent Available Resources - ";
			
			for(int j = 0;j < no_resources;j++)
			{
				current_resources[j] =  current_resources[j] + allocated_resources[k][j];
				cout<<current_resources[j]<<" ";
			}
			cout<<"\n\n\n";
			
			
		   }   
}
	return 0;
}
//thread process to be performed to use mutex lock
void *process(void*arg)
{
	int p = *((int *) arg);
	//resources locked
	pthread_mutex_lock(&lock);
	
	cout<<"\nThread created successfully\n";
	
}


