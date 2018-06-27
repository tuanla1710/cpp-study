
// Time complexity : O(ElogV)
#include "stdafx.h"
#include <iostream>
using namespace std; 

// define variables 
#define MAX_N 100

// variable initialization
int top; 
int stack[MAX_N];

// others
using namespace std; 


// function initialization 
void stackInit(void); 
int stackIsFull(void); 
int stackPush(int value); 
int stackIsEmpty(void); 

// function in details
void stackInit(void)
{
	top = 0; 
}

int stackIsEmpty(void)
{
	return (top == 0); 
}

int stackIsFull(void)
{
	return (top == MAX_N);
}

int stackPush(int value)
{
	if (stackIsFull())
	{
		cout << "stack overflow!";
		return 0; 
	}
	else
	{
		stack[top] = value; 
		top++; 
	}
}

int stackPop(int *value)
{
	if (top == 0)
	{
		cout << "stack empty!";
		return 0;
	}
	else
	{		
		top--;
		*value = stack[top]; 
		return 1; 
	}
}


/* ***** main **** */


int main(int argc, char* argv[])
{
	int T, N; 

	cin >> T; // test case 
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N; // enter N ;
		stackInit(); 
		for (int i = 0; i < N; i++)
		{
			int value;
			cin >> value;
			stackPush(value);		
		}
		cout << test_case; 

		while (!stackIsEmpty())
		{
			int value; 
			if (stackPop(&value) == 1)
			{
				cout << value; 
			}
		}
		cout << "\n"; 

	}
	return 0; 
}
