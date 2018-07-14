// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#define max_N 100 
#define max_D 100

using namespace std;

int NUM, D; // number of entities 
int arrA[max_N]; // array of entities 
int sortedA[max_N]; // sorted array 
int arrB[max_D]; 
int i, j;
int index_found; 

int arrA_to_S[max_N];

void init_matrix(int A[], int size)
{
	for (i = 0; i <= size; i++)
	{
		A[i] = 0; 
	}
}


void CoutingSort()
{
	
	init_matrix(arrB, D); 

	for (i = 0; i < NUM; i++) { arrB[arrA[i]]++;	}
	for (i = 1; i <= D; i++) { arrB[i] = arrB[i-1] + arrB[i];}
	for (i = NUM -1; i >= 0; i--) { sortedA[--arrB[arrA[i]]] = arrA[i];}
}


long long fibo(int n)
{
	if (n == 0)
	{
		return 1; 
	}
	else
	{
		return (n*fibo(n - 1)); 
	}
}

void insert_sort()
{
	for (i = 1; i < NUM; i++)
	{   
		int temp = arrA[i];
		j = i - 1; 

		while (j >= 0 && temp < arrA[j])
		{
			arrA[j + 1] = arrA[j]; 
			j--; 
		}
		arrA[j + 1] = temp; 

	}
}

void quicSort(int F, int L)
{
	// matrix arrA;
	// NUM; // number of elements 
	// 1. 
	if (F < L)
	{
		int pivot = F;
		i = F;
		j = L;
		while (i < j)
		{
			while (i < L && arrA[i] <= arrA[pivot]) // i< L chu ko phai la i <= L; 
			{
				i++; 
			}

			while (arrA[j] > arrA[pivot])
			{
				j--; 
			}

			if (arrA[i] < arrA[j])
			{
				int temp = arrA[i]; 
				arrA[i] = arrA[j]; 
				arrA[j] = temp; 


				// swap(i, j) 
			}
			int temp = arrA[pivot];
			arrA[pivot] = arrA[j];
			arrA[j] = temp;
			// swap(j, pivot) 
			quicSort(F, j - 1);
			quicSort(j + 1, L);

		}

	}



	// 
}

void binarySearch(int *arrA, int low, int high, int target) // high - N-1 
{
	// input: arrA; increasing value 
	// NUM; 
	int mid_index; 
	index_found = -2;
	if (low > high)
	{
		index_found = -1; 
		// cout << "-1"; 
		return;
	}
	mid_index = (low + high) / 2; // low + high /
	
	if (target < arrA[mid_index])
	{		
		binarySearch(arrA, low, mid_index - 1, target);
	}
	else if ( target > arrA[mid_index])
	{		
		binarySearch(arrA, mid_index + 1, high, target);
	}
	else
	{
		index_found = mid_index; 
		// cout << mid_index; 
		return;
	}

}


void binarySearch1(int* arrA, int low, int high, int target)
{
	int mid;

	// cout << "???????????????????????"; 
	if (low > high)
	{
		cout << "-1" << " ";
		return;
	}

	mid = (low + high) / 2;

	if (target < arrA[mid])
	{
		binarySearch1(arrA, low, mid - 1, target);
	}
	else if (arrA[mid] < target)
	{
		binarySearch1(arrA, mid + 1, high, target);
	}
	else
	{
		cout << mid << " "; 
		return;
	}
}





// function need to write everytime 

// print matix to test; 

void print_matrix(int A[], int size)
{
	for (i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}

}

// return a 2d array in C++ 
int ** create2DArray(unsigned height, unsigned width)
{
	unsigned h, w;
	int ** array2D = 0; 
	array2D = new int *[height];
	for (h = 0; h < height; h++)
	{
		array2D[h] = new int[width]; 
		for (w = 0; w < width; w++)
		{
			array2D[h][w] = w + width * h; 
		}
	}
	return array2D; 
}

// return a vector 

int * return_vector(int L) // neu L la static thi ko can con tro dong o day. 
{
	int *V = 0; 
	V = new int [L]; 
	for (int l = 0; l < L; l++)
	{
		V[l] = l; 
	}
	return V; 
// int *Vector = return_vector(10); 
	// delete [] Vector[L]; 
	// Vector = 0; 
}


/**
// return a 2D array in C++ 
int **create_a2D(int H, int W)
{
	int **a2D = 0; 
	a2D = new int *[H]; 
	for (int h = 0; h < H; h++)
	{
		a2D[h] = new int[W]; 
		for (int w = 0; w < W; w++)
		{
			a2D[h][w] = 1; 
		}
	}
	return a2D; 
	// Then, at the main function; we also have to use : int **mya2D = create_a2D(10, 5) // example; 
	// Then, delete pointers 
	/*
	for (int h = 0; h < H; h++)
	{
		delete[] mya2D[h]; 
	}
	delete[] my2D; 
	my2D = 0; 
	
}
**/



int main(int argc, char** argv)
{
	int test_case;
	int T;

	

	/*
	아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	//여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	//cout << "T = " << T ; 
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int NUM_to_S = 0, NUM = 0;
		

		cin >> NUM;
		cin >> NUM_to_S;
	    // enter arrA matrix 
		for (int i = 0; i < NUM; i++)
		{
			cin >> arrA[i]; // enter numbers 			
		}
		// print_matrix(arrA, NUM);
		// enter arrA_to_S matrix 
		for (int i = 0; i < NUM_to_S; i++)
		{
			cin >> arrA_to_S[i]; // enter numbers 			
		}
		// print_matrix(arrA_to_S, NUM_to_S);

		// print_matrix(arrA, NUM);


		cout << "#" << test_case << " ";
		for (int i = 0; i < NUM_to_S; i++)
		{	
			// cout << "arrA_to_S[i] = " << arrA_to_S[i] ;

			binarySearch(arrA, 0, NUM - 1, arrA_to_S[i]);
			cout << index_found << " "; 


			//binarySearch1(arrA,  0, NUM - 1, arrA_to_S[i]);
			
		}		

		
		

		
		// print_matrix(arrA, NUM);

		cout << endl;
		
		


		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 1;//정상종료시 반드시 0을 리턴해야합니다.
}
