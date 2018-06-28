// Time complexity : O(ElogV)
#include "stdafx.h"
#include <iostream>

#define N_max 100
#define N_min 2 

#define V_max 50
#define V_min 0 

using namespace std; 

class QUEUE
{
public:
	QUEUE(); // declaration queue
	void init(); // init queue 
	int isEmpty(); // check queue is empty or not 
	int isFull(); // check queu is full or not 
	int push(int value); // push value to queue
	int pop(int *value); // pop the first entity in the queue
	int size(); // return queue_size 

private: 
	int qLength;
	int num[N_max]; 
};

// details functions in class: 

QUEUE::QUEUE()
{
	qLength = 0;
}
void QUEUE::init()
{
	qLength = 0;
}

int QUEUE::isEmpty()
{
	return (qLength == 0);
}

int QUEUE::isFull()
{
	return (qLength == N_max);
}

int QUEUE::push(int value) // push value to queue; 
{
	if (isFull())
	{
		return 0; 
	}
	num[qLength] = value;
	qLength++;
	return 1; 
}

int QUEUE::pop(int *value)
{
	if (qLength == 0) // queue length = 0?
	{
		cout << "queue is empty!";
		return 0; 
	}
	*value = num[0]; //return the first entity in the queue. 
	for (int i = 1; i < qLength; i++)
	{
		num[i - 1] = num[i];
	}
	num[qLength - 1] = 0; // ??
	qLength--;
	return 1; 
}

int QUEUE::size()
{
	return qLength;
}


// decleration functions out of class: 
int getInRange();


// details functions out of class
int getInRange()
{	
	while (true)
	{
		int v;
		cin >> v;
		if (v <= V_max && v >= V_min)
		{
			return v; 
		}
		else
		{
			cout << "Out of range (" << V_min << "," << V_max << ")" << "Try again! " << endl ;
		}
	}

}


int main()
{   
	int N, T; 
	cin >> T; 

	int** a = NULL;
	a = new int*[10];
	for int ()


	delete[] pointer;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N; // enter the number of entity in the queue; 
		QUEUE queue; // make a queue and set top = 0; 
		queue.init();

		for (int i = 0; i < N; i++)
		{
			int value; 
			value = getInRange(); 
			// push value into queue
			queue.push(value);
		}

		cout << "#" << test_case << " "; 
		
		// pop value out of queue and display them. 
		// anaylis: while queu is not empty. pop out of final value in the queue (FIFO)
		while (!queue.isEmpty())
		{
			int value;
			if (queue.pop(&value) == 0)
			{
				return 0; 
			}
			cout << value << " ";
		}

		cout << "\n"; 
	}
	
	return 1;
}
