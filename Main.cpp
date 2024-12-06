#include <iostream>
#include <queue>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include "queue&stack.h"
#include <iomanip>
using namespace std;

int main()
{
	/*
	Node* top = NULL; // stack is empty
	int MAX_SIZE = 3; //Maximum size for the stack
	int currentSize = 0;
	
	// insert(push) values onto the stack
	push(top, currentSize, 100, MAX_SIZE);
	push(top, currentSize, 1000, MAX_SIZE);
	push(top, currentSize, 10000, MAX_SIZE);
	cout << "Stack after pushing values: ";
	printStack(top);


	// PopBack a value from the stack
	popBack(top, currentSize); // remove the top value
	cout << "Stack after popBack one value: ";
	printStack(top);

	// create queue and stack objects
	Queue queue;
	queue.enqueue(100);
	queue.enqueue(1000);
	queue.enqueue(10000);

	//Print queue before any dequeue
		cout << "Queue before dequeue: ";
		queue.printQueue();
		
	// Perform dequeue on the queue
		queue.dequeue(); // dequeue from the front of the queue
		cout << "Queue after dequeue: ";
		queue.printQueue();

*/
	// call the measuretime function to start the timing and display the results
	measureTime();
	return 0;


}