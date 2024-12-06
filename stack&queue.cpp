#include <iostream>
#include <queue>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include "queue&stack.h"
#include <iomanip>
using namespace std;

// Code is referenced from Geek for Geek 

Queue queue1; 

// Queue constructor
	Queue::Queue() 
	{
		head = tail = NULL;
	}

	// Insert values into the queue
void Queue::enqueue(int value)
{
	Node* newNode = new Node(value); // create a new node

		// if the queue is empty then the front and rear point to new node
		if (tail == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
}
	// function to delete
void Queue::dequeue()
{
		if (head == NULL)
		{
			cout << "Queue is empty. There is nothing to dequeue" << endl;
			return;
		}

		Node* temp = head; // Temporary pointer to hold front node
		head = head->next; // move front pointer to the next node

		if (head != NULL)
		{
			head->prev = NULL; // set the previous pointer of the new front to null
		}
		else
		{
			tail = NULL; // if the queue is empty , tail shpuld also be null
		}
		delete temp; // delete the old front node
}
void Queue::printQueue()
{
		if (head == NULL)
		{
			cout << "Que is empty. " << endl;
		}

		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->numdata << "  "; // print data of each node
			temp = temp->next; // move to next node
		}
		cout << endl;
}



// create a stack doubly linked list
	Node* top = NULL; // stack is empty
	int MAX_SIZE = 10000; //Maximum size for the stack
	int currentSize = 0;

//Function to insert(push), add a newnode into the top of stack
void push(Node*& top, int& currentSize, int value, int MAX_SIZE)
{
		
		if (currentSize >= MAX_SIZE)
		{
			std::cout << "Stack is full. Cannot push " << value << std::endl;
			return;
		}
		
		// create a new node
		Node* newNode = new Node(value); // create a new node with given value

		if (top == NULL)
		{
			// if stack is empty, new node goes to the top
			top = newNode;
		}
		else
		{
			//otherwise insert at the top of the stack
			newNode->next = top; // new node next points to the top
			top->prev = newNode; // current top prev points to the new node
			top = newNode; // top is now the new node
		}
		//currentSize++; // increase the size of the stack
}

	// function to remove(pop) the top node from the stack
void popBack(Node*& top, int& currentSize)
{
		if (top == NULL)// if stack is empty
		{
			std::cout << "Stack is empty. There is nothing to delete" << std::endl;
			return; // prevent pop if stack is empty
		}

		struct Node* temp = top;// Temporary pointer to store the current top node
		top = top->next;// move top to the next node in the stack

		if (top != NULL)// if stack isn't empty after pop
		{
			top->prev = NULL;// update the new head's prev pointer to null
		}
		delete temp;// delete the old top node and free memory of the popped node
		currentSize--; // decrease the current size of the stack 
}
	
	// function to print stack from top to bottom and clean up any remaining nodes in the stack
void printStack(Node* top)
{
		if (top == NULL)
		{
			std::cout << "List is empty " << std::endl;
			return;
		}

		struct Node* temp = top;
		while (temp != NULL)
		{

			std::cout << temp->numdata << " "; // Print the data of the node
			temp = temp->next; // Move to the next node
		}
		std::cout << std::endl;
}



//function to measure time to take for insertion and deletion of random numbers
void measureTime()
{
	// Time measurement for insertion(enqueue) into queue
	{
		//Measure time for enqueueing 100 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 100; j++)
			{
				queue1.enqueue(rand() % 10000); // insert random numbers betweeon 0 9999
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto enQueueDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			std::cout << fixed << setprecision(5) << "EnQueue 100 " << enQueueDuration.count() << " microseconds." << std::endl;
		}

		// Measure time for enqueuing 1000 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 1000; j++)
			{
				queue1.enqueue(rand() % 10000); // insert random numbers betweeon 0 9999
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto enQueueDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			std::cout << fixed << setprecision(5) << "EnQueue 1000 " << enQueueDuration.count() << " microseconds." << std::endl;
		}

		// Measure time for enqueuin 10000 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 10000; j++)
			{
				queue1.enqueue(rand() % 10000); // insert random numbers betweeon 0 9999
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto enQueueDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			std::cout << fixed << setprecision(5) << "Enqueue 10000 " << enQueueDuration.count() << " microseconds." << std::endl;
		}
	}

	//Time measurement for insertion(push) into Doubly linked list stack
	{
		// Measure time for Push 100 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 100; j++)
			{
				push(top, currentSize, rand() % 100, 10000); // insert random numbers between 100 and 9999 
			}

			auto end = std::chrono::high_resolution_clock::now();
			auto pushDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			std::cout << fixed << setprecision(5) << "Push 100 " << pushDuration.count() << " microseconds." << std::endl;
		}

		// Measure time for Push 1000 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 1000; j++)
			{
				push(top, currentSize, rand() % 100, 10000); // insert random numbers between 100 and 9999
			}

			auto end = std::chrono::high_resolution_clock::now();
			auto pushDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			std::cout << fixed << setprecision(5) << "Push 1000 " << pushDuration.count() << " microseconds." << std::endl;
		}

		// Measure time for Push 10000 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 10000; j++)
			{
				push(top, currentSize, rand() % 100, 10000); // insert random numbers between 100 and 9999
			}

			auto end = std::chrono::high_resolution_clock::now();
			auto pushDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			std::cout << fixed << setprecision(5) << "Push 10000 " << pushDuration.count() << " microseconds." << std::endl;
		}
	}

	// Time measurement for dequeue(deletion) from queue
	{
		// Measure time for dequeung 100 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 100; j++)
			{
				queue1.dequeue(); // dequeue(delete) operation

			}
			auto end = std::chrono::high_resolution_clock::now();
			auto deQueueduration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			std::cout << fixed << setprecision(5) << "Dequeue 100 " << deQueueduration.count() << " microseconds." << std::endl;
		}

		// Measure time for dequeuing 1000 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 1000; j++)
			{
				queue1.dequeue(); // dequeue(delete) operation

			}
			auto end = std::chrono::high_resolution_clock::now();
			auto deQueueduration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			std::cout << fixed << setprecision(5) << "Dequeue 1000 " << deQueueduration.count() << " microseconds." << std::endl;
		}

		// Measure time for dequeuing 10000 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 10000; j++)
			{
				queue1.dequeue(); // dequeue(delete) operation

			}
			auto end = std::chrono::high_resolution_clock::now();
			auto deQueueduration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			std::cout << fixed << setprecision(5) << "Dequeue 10000 " << deQueueduration.count() << " microseconds." << std::endl;
		}
	}

	// Time measurement for popBack(deletion) from stack
	{
		// Measure time for popBack 100 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 100; j++)
			{
				popBack(top, currentSize); // pop the top values of the stack
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto popBackDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			cout << fixed << setprecision(5) << "Pop Back 100 " << popBackDuration.count() << " microseconds." << endl;
		}

		// Measure time for popBack 1000 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 1000; j++)
			{
				popBack(top, currentSize); // pop the top values of the stack
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto popBackDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			cout << fixed << setprecision(5) << "Pop Back 1000 " << popBackDuration.count() << " microseconds." << endl;
		}

		// Measure time for popBack 10000 elements
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 0; j < 10000; j++)
			{
				popBack(top, currentSize); // pop the top values of the stack
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto popBackDuration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			cout << fixed << setprecision(5) << "Pop Back 10000 " << popBackDuration.count() << " microseconds." << endl;
		}
	}
}

	

