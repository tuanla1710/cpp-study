// Time complexity : O(ElogV)
#include "stdafx.h"
#include <iostream>

#define N_max 100 

using namespace std; 

class STACK
{
private: 
	int top; 
	int num[N_max]; 

public:
	STACK();
	void init(); 
	int isEmpty(); 
	int isFull(); 
	int pop(int *value); 
	int push(int value); 
	void display(); 
	void display_not_remove_stack();
	int size(); 

};

STACK::STACK()
{
	top = 0; 
}

void STACK::init()
{
	top = 0; 
}

int STACK::isEmpty()
{   
	return (top == 0);
}

int STACK::isFull()
{
	return (top == N_max); 
}

int STACK::push(int value)
{
	if (isFull())
	{
		cout << "Stack is overflow"; 
		return 0; 
	}	
	num[top] = value; 
	top++;
	return 1; 
		
}

int STACK::pop(int *value)
{
	if (top == 0)
	{
		cout << "this stack is empty";
			return 0; // exit 
	}
	top--; 
	*value = num[top];  // top = 0;
	return 1; 
	
}


void STACK::display()
{   
	if (isEmpty())
	{
		cout << "stack is empty";
	}

	while (!isEmpty())
	{
		int value; 
		if (pop(&value) == 1)
		{
			cout << value;  // top = 0;
		}		
		cout << " "; 
	}
}

void STACK::display_not_remove_stack()
{
	if (isEmpty())
	{
		cout << "stack is empty";
	}

	for (int i = 1; i <= top; i++)
	{
		cout << num[top - i] << " "; 
	}
}

int STACK::size()
{
	return top; 
}

int main()
{
	int T, N; 
	STACK stack; 
	cin >> T; 
	stack.init(); 
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N; 
		for (int i = 0; i < N; i++)
		{
			int value; 
			cin >> value; 
			stack.push(value);
		}
		cout << "#" << test_case << " ";
		// stack.display();
		stack.display_not_remove_stack();
		cout << "next"; 
		// stack.display();
		stack.display_not_remove_stack();
		
		cout << "Size of this stack = " << stack.size(); 
	}
	return 1; 
}































/*
#define N_max 100

// int top; 
// int stack[N_max]; 

using namespace std; 

// decleration class 
class STACK
{
private: 
	int num[N_max];
	int top;
public: 
	STACK(); // default; 
	void stackInit();
	int stackIsEmpty();
	int stackIsFull();
	int stackPop(int *value);
	int stackPush(int value);
	int stackDisplay();
};

int STACK::stackDisplay()
{
	
	while (!stackIsEmpty()) // return top == 0 
	{
		int value;
		if (stackPop(&value) == 1)
		{
			cout << value << " ";
		}
	}
	
	return 1; 
}


STACK::STACK()
{
	top = 0; 
}


// decleration functions: 
 


void STACK::stackInit()
{
	top = 0; // number of entities = 0; 	
}
int STACK::stackPush(int value)
{
	if (stackIsFull())
	{
		cout << "stack is overflow!"; 
		return 0; 
	}
	num[top] = value;
	top++; 
	return 1; 
}

int STACK::stackIsEmpty()
{
	return (top == 0); 
}

int STACK::stackIsFull()
{
	return (top == N_max); 
}

int STACK::stackPop(int *value)
{
	if (top == 0)
	{
		cout << "stack is empty"; 
		return 0; 
	}
	top--; 

	*value = num[top];
	return 1; 
}


int main()
{
	int N, T; // N: number of entities in stack, T: Number of test_cases 
	cin >> T; // number of test_cases; 
	for (int test_case = 1; test_case <= T; test_case++)
	{   
		STACK stack; 

		cin >> N; // enter N value; 
		stack.stackInit();

		for (int i = 0; i < N; i++)
		{
			int value; 	
			cin >> value; 
			stack.stackPush(value);
		}
		// display output
		cout << "#" << test_case << " ";
		stack.stackDisplay(); 
		cout << "\n";
	}



	return 1; 
}

*/
