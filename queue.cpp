// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>; 
#define max(a,b) (a>b ?a:b)



using namespace std;

void add101(int *a) // gia tri con tro. 
{
	*a = *a + 10; // gia tri contro + 10; 
}
// add101(&n); gan con cho p vao dia chi cua n. Nhu vay con tro nay co gia tri giong nhu n. Khi thay doi gia tri p thi gia tri n cung thay doi theo. 
// cout << n << endl;

void add102(int a)
{
	a = a + 10;
}

void add103(int &a) // tham chieu. dia chi cua a bai toan se la int &a = n; a dc tham chieu nhu n. 
{
	a = a + 10;
}

/*
int binarySearch(int(&a)[10], const int &x)
{
	int low = 0, high = 9;
	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (a[mid] < x)
		{
			low = mid + 1;
		}
		else if (a[mid] > x)
			high = mid - 1;
		else return mid;
	}
	return -1;
}
*/

int binarySearch(int(&a)[10], const int &value)
{
	int low = 0, high = 9;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (a[mid] < value)
		{
			low = mid + 1;
		}
		else if (a[mid] > value)
		{
			high = mid - 1;
		}
		else if (a[mid] == value)
		{
			return mid;
		}
	}
	return -1;
}

#define N_max 100 

class QUEUE
{
private:
	int front, rear;
	int Q[N_max];
public:
	void init();
	int isEmpty();
	int isFull();
	int enQueue(int value); 
	int deQueue(int &value);
	int size();




};

void QUEUE::init() // init queue 
{
	front = 0;
	rear = 0;
}
int QUEUE::isEmpty()
{	
	return (front == rear);
}
int QUEUE::isFull()
{
	return ((rear + 1) % N_max == front); 
}

int QUEUE::enQueue(int value)
{
	if (isFull())
	{
		cout << "queue is full"; 
		return 0; 
	}
	Q[rear] = value; 
	rear++;
	if (rear == N_max)
	{
		rear = 0;
	}
	// rear = (rear + 1) % N_max; // make a round number for the queue
	return 1; 
}
int QUEUE::deQueue(int &value)
{
	if (isEmpty())
	{
		cout << "Queue is empty"; 
		return 0; 
	}	
	value = Q[front];	
	front++;
	if (front == N_max)
	{
		front = 0;
	}
//	front = (front + N_max - 1) % N_max;
	// cout << value; 
	return 1; 
}

int QUEUE::size()
{  
	return ((front - rear + N_max) / N_max);
}






int main()
{
	/*
	int a[10] = { 1, 3, 8, 12, 45, 100, 263, 354, 356, 500}; 
	
	cout << binarySearch(a, 101); 
	cout << 2 % 10; 
	*/
	int T, N;
	cin >> T; 

	QUEUE queue;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N; 
		
		queue.init(); 		

		for (int i = 0; i < N; i++)
		{
			int value;
			cin >> value; 
			queue.enQueue(value); 
		}
		cout << "#" << test_case << " "; 

		while (!queue.isEmpty())
		{
			int value; 
			if (queue.deQueue(value)==1)
			{
				cout << value << " "; 
			}
			
		}
		cout << "\n";
		

		cout << queue.size(); 
	}
    return 0;
}


