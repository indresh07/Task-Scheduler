#include <iostream>
#include <stdlib.h>

#include "../include/minPriorityQueue.hpp"

using namespace std;
using namespace cs202;

int options(){

	int choice;

	cout<<"\n[1] Insert\n";
	cout<<"[2] Minimum\n";
	cout<<"[3] Extract minimum\n";
	cout<<"[4] Heap Size\n";
	cout<<"[5] Is Heap empty\n";
	cout<<"[0] Exit\n";

	cout<<"Enter your choice : ";
	cin>>choice;

	return  choice;
}

int main(int argc, char* argv[]){

	MinPriorityQueue<int> L;
	int data;

	while(1){

		switch(options()){

			case 1 :	cout<<"Enter value : ";
						cin>>data;
						L.insert(data);
						break;

			case 2 :	try{
							cout<<"Minimum : "<<L.minimum()<<endl;
						}
						catch(const char* err){
							cout<<err<<endl;
						}

						break;

			case 3 :	try{
							cout<<"Minimum : "<<L.extract_min()<<"\nMinimum extracted.\n";
						}
						catch(const char* err){
							cout<<err<<endl;
						}

						break;

			case 4 :	cout<<"Heap Size : "<<L.heap_size()<<endl;
						break;

			case 5 :	if(L.empty())
							cout<<"Heap is empty.\n";
						else
							cout<<"Heap is not empty.\n";

						break;

			case 0 :	exit(EXIT_SUCCESS);

			default :	cout<<"Invalid choice.\n";
						break;
		}
	}

	return 0;
}
