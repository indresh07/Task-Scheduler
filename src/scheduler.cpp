#include <iostream>
#include <stdlib.h>
#include <string>

#include "../include/minPriorityQueue.hpp"

using namespace std;
using namespace cs202;

class request{
	public:
		int deviceID;
		int burstTime;
		int delayTime;
		int priority;
		std::string status;


		request(){};

		request(int Id, int BT, int DT, int p){
			deviceID = Id;
			burstTime = BT;
			delayTime = DT;
			priority = p;
			status = "Queued"; 
		}

		bool operator<(const request& d){
			if(priority < d.priority)
				return true;
			else
				return false;
		}

		void operator=(request d){
			deviceID = d.deviceID;
			burstTime = d.burstTime;
			delayTime = d.delayTime;
			priority = d.priority;
			status = d.status;
		}
};

void display(const request& d){

	cout<<d.deviceID<<"\t";
	cout<<d.burstTime<<"\t\t";
	cout<<d.delayTime<<"\t\t";
	cout<<d.priority<<"\t\t";
	cout<<d.status<<"\n";
}

void display(MinPriorityQueue<request> queue){

	while(!queue.empty()){
		display(queue.extract_min());
	}

	cout<<"\n";
}



int main(int argc, char* argv[]){

	system("clear");
	MinPriorityQueue<request> queue;
	int ID, burstTime, delayTime, priority;
	request d;
	int totalBurst = 0, totalDelay = 0;
	char end;

	while(1){

		cout<<"\nEnter task details\n";
		cout<<"ID : ";
		cin>>ID;

		cout<<"Burst Time : ";
		cin>>burstTime;

		cout<<"Delay Time : ";
		cin>>delayTime;

		cout<<"Priority : ";
		cin>>priority;

		totalDelay += delayTime;

		cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";

		while(!queue.empty()){
			d = queue.minimum();
			
			if(d.burstTime <= totalDelay){

				d = queue.extract_min();
				d.status = "Completed";

				totalDelay -= d.burstTime;
				totalBurst -= d.burstTime;

				display(d);
			}
			else
				break;
		}

		if(totalBurst >= totalDelay)
			if(!queue.empty() && queue.minimum().priority > priority){
				queue.minimum().status = "Pre-empted";
				queue.minimum().burstTime -= totalDelay;
				totalBurst -= totalDelay;
				totalDelay = 0;
			}

		queue.insert(request(ID, burstTime, delayTime, priority));
		totalBurst += burstTime;

		queue.minimum().status = "In Progress";
		display(queue);

		cout<<"Exit(y/n) : ";
		cin>>end;

		if(end == 'y' || end == 'Y'){

			cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";
			while(!queue.empty()){

				d = queue.extract_min();
				d.status = "Completed";

				display(d);
			}

			exit(EXIT_SUCCESS);			
		}
	}

	return 0;
}