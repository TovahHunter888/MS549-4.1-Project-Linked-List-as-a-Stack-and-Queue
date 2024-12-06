#pragma once
#include <iostream>
#include <queue>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H
//#include <algorithm>
using namespace std;
using namespace std::chrono;

// Node structure for creating a doubly linked list with an integer data type
struct Node
{
	int numdata;
	struct Node* prev;
	struct Node* next;

	// constructor to intiliaze the new node
	Node(int value)
	{
		numdata = value;
		next = NULL;
		prev = NULL;
	}
};

// Queue class using a doubly linked list
class Queue
{
private:
	Node* head;
	Node* tail;

public:
	Queue(); // constructor

	void enqueue(int value); // insert a value at the rear of the queue
	void dequeue(); // remove a value from the front of the queue
	void printQueue(); // print the current queue
};

// stack functions using doubly linked list

void push(Node*& top, int& currentSize, int value, const int MAX_SIZE); // push a value onto the stack
void popBack(Node*& top, int& currentSize); // pop a value from the top of the stack
void printStack(Node* top); // print the stack from top to bottom


// declare the measureTime function
void measureTime(); // measure the time for stack and queue operations

#endif //QUEUE_STACK_H







