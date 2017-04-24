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

void display(MinPriorityQueue<device> queue){

	device d;

	cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";

	while(!queue.empty()){
		d = queue.extract_min();

		cout<<d.id<<"\t";
		cout<<d.burstTime<<"\t\t";
		cout<<d.delayTime<<"\t\t";
		cout<<d.priority<<"\t\t";
		cout<<d.status<<"\n";
	}

	cout<<"\n";
}



int main(int argc, char* argv[]){

	MinPriorityQueue<device> queue;
	int ID, burstTime, delayTime, priority;
	device d;
	int totalBurst = 0, totalDelay = 0;
	char end;

	while(1){

		cout<<"\nEnter process details\n";
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
			if(totalBurst >= totalDelay){

			if(queue.minimum().priority > priority){
				queue.minimum().status = "Paused and Queued";
				queue.minimum().burstTime -= totalDelay;
				totalBurst -= totalDelay;
			}

			queue.insert(device(ID, burstTime, delayTime, priority));
			totalBurst += burstTime;

			}
			else if(totalBurst < totalDelay){

				cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";
				while(!queue.empty()){

					d = queue.extract_min();

					totalDelay -= d.delayTime;
					totalBurst -= d.burstTime;

					cout<<d.id<<"\t";
					cout<<d.burstTime<<"\t\t";
					cout<<d.delayTime<<"\t\t";
					cout<<d.priority<<"\t\t";
					cout<<"Completed\n";
				}

				queue.insert(device(ID, burstTime, delayTime, priority));
				totalBurst += burstTime;
			}
		}

		queue.minimum().status = "In Progress";
		display(queue);

		cout<<"Exit(y/n) : ";
		cin>>end;

		if(end == 'y' || end == 'Y'){

			cout<<"\nID\tBurst Time\tDelay Time\tPriority\tStatus\n";
			while(!queue.empty()){

				d = queue.extract_min();

				cout<<d.id<<"\t";
				cout<<d.burstTime<<"\t\t";
				cout<<d.delayTime<<"\t\t";
				cout<<d.priority<<"\t\t";
				cout<<"Completed\n";
			}

			exit(EXIT_SUCCESS);			
		}
	}

	return 0;
}