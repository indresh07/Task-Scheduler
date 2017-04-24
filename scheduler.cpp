#include <iostream>
#include <stdlib.h>
#include <string>

#include "minPriorityQueue.hpp"

using namespace std;
using namespace cs202;

class device{
	public:
		int id;
		int burstTime;
		int delayTime;
		int priority;
		std::string status;


		device(){};

		device(int Id, int BT, int DT, int p){
			id = Id;
			burstTime = BT;
			delayTime = DT;
			priority = p;
			status = "Queued"; 
		}

		bool operator<(const device& d){
			if(priority < d.priority)
				return true;
			else
				return false;
		}

		void operator=(device d){
			id = d.id;
			burstTime = d.burstTime;
			delayTime = d.delayTime;
			priority = d.priority;
			status = d.status;
		}
};

void display(const device& d){

	cout<<d.id<<"\t";
	cout<<d.burstTime<<"\t\t";
	cout<<d.delayTime<<"\t\t";
	cout<<d.priority<<"\t\t";
	cout<<d.status<<"\n";
}

void display(MinPriorityQueue<device> queue){

	cout<<"\nTasks in processor";
	cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";

	while(!queue.empty()){
		display(queue.extract_min());
	}

	cout<<"\n";
}



int main(int argc, char* argv[]){

	system("clear");
	MinPriorityQueue<device> queue;
	int ID, burstTime, delayTime, priority;
	device d;
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

		if(queue.empty()){
			queue.insert(device(ID, burstTime, delayTime, priority));
			totalBurst += burstTime; 
		} 
		else{

			d = queue.minimum();

			if(d.burstTime <= totalDelay)
				cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";

			while(!queue.empty() && d.burstTime <= totalDelay){
				d = queue.minimum();
				
				if(d.burstTime <= totalDelay){

					d = queue.extract_min();
					d.status = "Completed";

					totalDelay -= d.burstTime;
					totalBurst -= d.burstTime;

					display(d);
				}
			}

			if(totalBurst >= totalDelay)
				if(queue.minimum().priority > priority){
					queue.minimum().status = "Pre-empted";
					queue.minimum().burstTime -= totalDelay;
					totalBurst -= totalDelay;
					totalDelay = 0;
				}

			queue.insert(device(ID, burstTime, delayTime, priority));
			totalBurst += burstTime;
		}

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