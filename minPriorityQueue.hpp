// Purpose: 
// Author: 
// Date of Creation: 
// Bugs:

#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1
#include "seqLinearList.hpp"
#include <climits>

 namespace cs202{
 	
 	template<typename T>
 	class MinPriorityQueue{
 		// Private attributes and functions for class
 		// If you need any more functions / attributes
 		// define them yourself along with proper reasoning
 		// why they were introduced.
 		// DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
 		// YOU NEED TO USE THEM ALL.


 		// Primary container used in MinPriorityQueue
 		seqLinearList<T> _heap;
 		int _heapSize;

 		// heapifies the heap at position pos 
 		void heapify(const size_t& pos);

 		// return the parent of an element
 		inline int parent(const size_t& pos);

 		// return the left child of an element
 		inline int left_child(const size_t& pos);

 		// return the right child of an element
 		inline int right_child(const size_t& pos);

 		inline void exchange(T& a, T& b);

 	public:
 		// default constructor
 		MinPriorityQueue();

 		// construct a heap from the elements of a seqLinearList
 		MinPriorityQueue(const LinearList<T>& v);

 		// insert a value to the heap
 		void insert(const T& a);

 		// get the minimum element from the heap
 		inline T minimum();

 		// return the minimum element from the heap and remove it
 		// as well
 		T extract_min();

 		// return the heap size
 		inline int heap_size();

 		// build a heap from elements of a seqLinearList container 
 		void build_heap(const LinearList<T>& v);

 		// check if MinPriorityQueue is empty
 		inline bool empty();

 		// heap_decrease_key function
 		void heap_decrease_key(const size_t& pos);
 	};

 	template<class T>
 	MinPriorityQueue<T>::MinPriorityQueue(){

 		_heapSize.resize(11);
 		_heapSize = 0;
 	}

 	template<class T>
	MinPriorityQueue<T>::MinPriorityQueue(const LinearList<T>& v){
		_heapSize = v.size();
		_heap = v;

		for(int i = 1; i <= _heapSize/2; i++)
			heapify(i);
	}

	template<class T>
	int MinPriorityQueue<T>::heap_size(){
		return _heapSize;
	}

	template<class T>
	bool MinPriorityQueue<T>::empty(){
		if(_heapSize)
			return false;
		else
			return true;
	}

	template<class T>
	int MinPriorityQueue<T>::parent(const size_t& pos){
		
		if(pos/2 < 1)
			return pos/2;
		else
			return INT_MAX;
	}

	template<class T>
	int MinPriorityQueue<T>::left_child(const size_t& pos){
		
		if(2*pos <= _heapSize)
			return 2*pos;
		else
			return INT_MAX;
	}

	template<class T>
	int MinPriorityQueue<T>::right_child(const size_t& pos){
		
		if(2*pos + 1 <= _heapSize)
			return 2*pos + 1;
		else
			return INT_MAX;
	}

	template<class T>
	T MinPriorityQueue<T>::minimum(){
		if(_heapSize)
			return _heap[0];
		else
			throw "Queue is empty";
	}

	template<class T>
	T MinPriorityQueue<T>::extract_min(){
		if(_heapSize){
			T min = _heap[0];
			return min;
		}
		else
			throw "Queue is empty";
	}

	template<class T>
	void MinPriorityQueue<T>::build_heap(const LinearList<T>& v){
		_heapSize = v.size();
		_heap = v;

		for(int i = 0; i < _heapSize/2; i++)
			heapify(i);
	}

	template<class T>
	void MinPriorityQueue<T>::insert(const T& a){

		_heapSize++;

		_heap[_headSize] = a;

		heap_decrease_key(_heapSize);
	}

	template<class T>
	void MinPriorityQueue<T>::heap_decrease_key(const size_t& pos){

		if(pos < _heapSize)
			return;

		int i = pos;

		int parent = parent(i);

		while(i > 1 && _heap[parent] > _heap[i]){
			
			exchange(_heap[i], _heap[parent]);

			i = parent;
			parent = parent(i); 
		}
	}

	template<class T>
	void MinPriorityQueue<T>::heapify(const size_t& pos){

		if(pos >= _heapSize)
			return;
		
		int i = pos;
		int l = left_child(i), r = right_child(i);

		11

		

	}

	template<class T>
	void MinPriorityQueue<T>::exchange(T& a, T& b){

		 T tmp;
		 tmp = b;
		 b = a;
		 a = tmp; 
	}







 	
#endif 