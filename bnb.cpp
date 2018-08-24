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
using namespace std; 

// dijisktra algorithm 
#define MAX 100
#define INF 100000

void print_m(int arr[MAX][MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " "; 
		}
		cout << endl; 
	}		
}

void print_v(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " "; 
	}
	cout << endl; 
}



int N; 
int M[MAX][MAX]; 
int couter[MAX];


int *bfs(int root, int arr[MAX][MAX], int n)
{
	int *queue = new int[MAX];
	int front = 0, rear = 0;	
	int visit[MAX]; 
	int visit_all[MAX][MAX];

	

	for (int i = 0; i < n; i++)
	{
		queue[i] = 0;	
		visit[i] = 0; 

		for (int j = 0; j < n; j++)
		{
			visit_all[i][j] = 0; 
		}
	}
	
	print_v(queue, n);	

	queue[rear++] = root;
	visit[root] = 1; 
	while (front < rear)
	{		
		int temp = queue[front++];
		for (int i = 0; i < n; i++)
		{
			if (!visit[i] && arr[temp][i])
			{
				queue[rear++] = i;
				visit[i] = 1;
				M[temp][couter[temp]++] = i; 
				M[i][couter[i]++] = temp;
				
			}
		}
	}

	//print_v(queue, n);
	//print_m(M, n, n); 
	return queue; 
}




int *find_min_row(int arr[MAX][MAX], int n)
{
	int *min_row = new int[n]; 
	for (int i = 0; i < n; i++)
	{
		min_row[i] = INF;
		for (int j = 0; j < n; j++)
		{
			if (min_row[i] > arr[i][j])
			{
				min_row[i] = arr[i][j];
			}
		}
	}
	return min_row; 
}


int *find_min_column(int arr[MAX][MAX], int n)
{
	int *min_col = new int[n];
	for (int j = 0; j < n; j++)
	{
		min_col[j] = INF;
		for (int i = 0; i < n; i++)
		{
			if (min_col[j] > arr[i][j])
			{
				min_col[j] = arr[i][j];
			}
		}
	}
	return min_col;
}

//int **minus_row(int arr[MAX][MAX], int min[], int n)
//{   
//	int **arr_reduce = new int*[MAX];
//	for (int i = 0; i < MAX; i++)
//	{
//		arr_reduce[i] = new int[MAX];
//		for (int j = 0; j < MAX; j++)
//		{
//			arr_reduce[i][j] = 0;
//		}
//	}
//
//	for (int i = 0; i < n; i++) // all row 
//	{
//		for (int j = 0; j < n; j++) // all entities in columns 
//		{
//			arr[i][j] = arr[i][j] - min[i]; 
//			arr_reduce[i][j]= arr[i][j] - min[i];
//		}
//	}
//
//	return arr_reduce;
//}

void minus_row(int arr[MAX][MAX], int min[], int n)
{   	
	for (int i = 0; i < n; i++) // all row 
	{
		for (int j = 0; j < n; j++) // all entities in columns 
		{
			arr[i][j] = arr[i][j] - min[i]; 		
		}
	}	
}

//int **minus_column(int arr[MAX][MAX], int min[], int n)
//{
//	int **arr_reduce = new int*[MAX];
//	for (int i = 0; i < MAX; i++)
//	{
//		arr_reduce[i] = new int[MAX];
//		for (int j = 0; j < MAX; j++)
//		{
//			arr_reduce[i][j] = 0;
//		}
//	}
//
//	for (int j = 0; j < n; j++) // all row 
//	{
//		for (int i = 0; i < n; i++) // all entities in columns 
//		{
//			arr[i][j] = arr[i][j] - min[j];
//			arr_reduce[i][j] = arr[i][j];
//		}
//
//	}
//	return arr_reduce;
//}
void minus_column(int arr[MAX][MAX], int min[], int n)
{	
	for (int j = 0; j < n; j++) // all row 
	{
		for (int i = 0; i < n; i++) // all entities in columns 
		{
			arr[i][j] = arr[i][j] - min[j];			
		}

	}
	
}

int compute_penal(int arr[MAX][MAX], int n, int i, int j)
{
	if (arr[i][j] != 0)
	{
		return -1;
	}
	else
	{
		// find min_row row of i 
		int MIN = INF; 
		for (int c = 0; c < n; c++)
		{   if (c== j)
			{
				continue;
			}
			else if (MIN > arr[i][c])
			{
				MIN = arr[i][c]; 
			}
		}
		int min_row = MIN;
		
		// find min_col column of j
		MIN = INF;
		for (int r = 0; r < n; r++)
		{
			if (r == i)
			{
				continue;
			}
			else if (MIN > arr[r][j])
			{
				MIN = arr[r][j];
			}
		}
		int min_colm = MIN;

		return (min_row + min_colm); 
	}
	return -1; 
}

void delete_r_c(int arr[MAX][MAX], int r, int c, int &n)
{
	//print_m(arr, n, n); 

	for (int i = r; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = arr[i + 1][j]; 
		}
	}
	//print_m(arr, n, n);

	for (int j = c; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i][j] = arr[i][j+1];
		}
	}

	//print_m(arr, n, n);
	n = n - 1; 
	//return (n - 1); 
}

void update_node_index_row(int node_index_row[MAX], int r, int n)
{
	for (int i = r; i < n; i++)
	{
		node_index_row[i] = node_index_row[i + 1]; 
	}
}
void update_node_index_column(int node_index_column[MAX], int c, int n)
{
	for (int i = c; i < n; i++)
	{
		node_index_column[i] = node_index_column[i + 1];
	}
}


int NEXT[MAX]; 
int visit[MAX]; 
int node_index_row[MAX]; 
int node_index_column[MAX];



int BnB(int root, int arr[MAX][MAX], int n)
{   
	int MAP[MAX][MAX]; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			MAP[i][j] = arr[i][j]; 
		}
	}

	for (int i = 0; i < n; i++)
	{
		node_index_row[i] = i; 
		node_index_column[i] = i;
	}

	
	for (int i = 0; i <= N; i++)
	{
		bool check = true; 
		while (check)
		{
			// reducing row 
			int *MIN_row = find_min_row(arr, n);

			//print_v(MIN_row, n); 

			// substraction 
			minus_row(arr, MIN_row, n);

			//print_m(arr, n,n); 

			// arr is reducing 

			// reduce colum 
			
			int *MIN_column = find_min_column(arr, n);
			//print_v(MIN_column, n);

			minus_column(arr, MIN_column, n);

			//print_m(arr, n, n);


			int sum = 0; 
			for (int j = 0; j < n; j++)
			{
				sum = sum+ MIN_column[j];
				sum = sum + MIN_row[j];
			}
			delete[] MIN_column;
			delete[] MIN_row;

			if (sum == 0)
			{
				check = false; 
			}
			

		}
		




		int penal[MAX][MAX]; 
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				penal[j][k] = -1;
			}
		}

		//cout << "debug-1: " << endl; 
		//print_m(penal, n, n); 

		// find penalty 
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				penal[j][k] = compute_penal(arr, n, j, k);
			}
		}
		//cout << "debug-2: " << endl;
		//print_m(penal, n, n);

		// find max penaltiy in penal matrix 
		int max = -1; 
		int r = 0; 
		int c = 0;
		int j, k; 
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (max < penal[j][k])
				{
					max = penal[j][k]; 
					r = j; c = k; 
				}
			}
		}
		//cout << "debug-3: " << endl; 

		//cout << "c =  " << c << " r = " << r << endl;

		//print_m(penal, n, n);

		// problem: not index is not the same --> solved 

		int node_c = node_index_column[c];
		int node_r = node_index_row[r]; 
		
		//cout << node_c << "_" << node_r << endl; 
		
		// max is max with r, c
		// delete row r and column c; 
		
		
		delete_r_c(arr, r, c, n); /// n reduce 1 ; 

		//cout << "debug-4: " << endl;
		//print_m(arr, n, n); 

		//cout << "debug-10: " << endl; 

		//print_v(node_index_row, N);
		//print_v(node_index_column, N);

		// update r, c 
		NEXT[node_index_row[r]] = node_index_column[c];
		visit[node_index_column[c]] = 1;

		//cout << NEXT[node_index_row[r]] << " - " << NEXT[node_index_column[c]] << endl;

		//cout << "debug-5: " << endl;
		//print_v(NEXT, N); 

		// update node_index; 
		update_node_index_column(node_index_column, c, N); // due to n is reduced by 1 when delete 
		update_node_index_row(node_index_row, r, N);// due to n is reduced by 1 when delete. have to keep N 

		//cout << "debug-6: " << endl;
		//print_v(node_index_column, n); // only n 
		//print_v(node_index_row, n); // only consider to n 

		// out: arr reduced

		// put linked connection will be INF 
		
		for (int j = 0; j < n; j++)
		{ 
			for (int k = 0; k < n; k++)
			{
				if (node_index_row[j] == node_c && node_index_column[k] == node_r)
				{
					arr[j][k] = INF;
				}
			}
			
		}

		//cout << "debug-7: " << endl;
		//print_m(arr, n, n); 

		// 
		if (n == 0)
		{
			//cout << "break " << endl; 
			break; 
		}
		//cout << "debug-8: " << endl;
		//print_v(NEXT, N);
		//print_v(visit, N);
	}

	/*for (int i = 0; i < N; i++)
	{
		if (visit[i] == 0) { visit[i] = root;}
	}*/

	//print_v(NEXT, N);
	//print_v(visit, N);


	// compute total route: 
	int sum = 0; int source = root; 
	for (int i = 0; i < N; i++)
	{
		sum = sum + MAP[root][NEXT[root]];
		root = NEXT[root]; 
		
		
	}

	return sum; // value of minimum in root 
}




int main(int argc, char** argv)
{   
	
	freopen("input.txt", "r", stdin);

	int source, edge; 
	for (int iter = 0; iter < 50; iter++)
	{

	cin >> N >> source >> edge; 

	// cout << "debug: N" << N << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			M[i][j] = INF+1; 
		}
	}

	int from, to;

	for (int i = 0; i < edge; i++)
	{   
		cin >> from >> to; 

		 //cout << from << " " << to << " " << endl;

		cin >> M[from][to]; 
		M[to][from] = M[from][to]; 
		// cout << "debug: 1" << M[from][to]; 
	}
	//print_m(M, N, N); 
	//cout << source << N; 

	cout << "#: = " << BnB(source, M, N) << endl; 

	//int N;
	//int source;
	//int map[MAX][MAX];
	//int edge;
	//int from, to;
	//int *result;
	//cin >> N >> source >> edge;

	//for (int i = 0; i < MAX; i++)
	//{
	//	for (int j = 0; j < MAX; j++)
	//	{
	//		M[i][j] = -1; 
	//	}
	//	couter[i] = 0;
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		map[i][j] = 0; 
	//	}		
	//}


	//for (int i = 0; i < edge; i++)
	//{
	//	cin >> from >> to; 
	//	map[from][to] = 1; 
	//	map[to][from] = map[from][to]; 
	//}

	//print_m(map, N, N); 
	//


	//result = bfs(source, map, N); 
	//print_v(result, N); 




	// dijstra 
	//int T;
	//int map[MAX][MAX] ; 
	//int N; // number of Node 

	//int source, destination; 
	//int from = 0, to = 0; 

	//freopen("input.txt", "r", stdin); // _CRT_SECURE_NO_WARNINGS

	//cin >> T; 
	//for (int t = 1; t <= T; t++)
	//{
	//	cin >> N >> source >> destination; 

	//	// init map
	//	for (int i = 1; i <= N; i++)
	//	{
	//		for (int j = 1; j <= N; j++)
	//		{
	//			map[i][j] = INF; 
	//		}			
	//	}


	//	while (from != -1 || to != -1)
	//	{
	//		cin >> from >> to; 
	//		cin >> map[from][to]; 
	//		map[to][from] = map[from][to];
	//		//cout << "debug : " << map[from][to] << "---"; 
	//	}

	//	//cout << N << "-" << source << "-" << destination << endl;


	//	cout << "#" << t << ": " << dijsktra(map, source, destination, N);
	//	cout << endl; 
	//}

	// knap problem 
	// cout << max(10, 8);

	//int wt[3] = { 3, 1, 4}; 
	//int val[5] = { 1, 5, 4}; 
	//int W = 6;
	//int n = 3; 

	//print_v(wt, n);
	//print_v(val, n);

	//sorting(wt, val, n);

	//print_v(wt, n); 
	//print_v(val, n);

	//cout << knap01(wt, val, W, n);


	// bfs 

	//int T;
	//int map[MAX][MAX] ; 
	//int N; // number of Node 

	//int source, destination; 
	//int from = 0, to = 0; 

	//freopen("input.txt", "r", stdin); // _CRT_SECURE_NO_WARNINGS

	//cin >> T; 
	//for (int t = 1; t <= T; t++)
	//{
	//	cin >> N >> source >> destination;

	//	// init map
	//		for (int i = 1; i <= N; i++)
	//		{
	//			for (int j = 1; j <= N; j++)
	//			{
	//				map[i][j] = 0; 
	//			}			
	//		}


	//		while (from != -1 || to != -1)
	//		{
	//			cin >> from >> to; 
	//			cin >> map[from][to]; 
	//			map[to][from] = map[from][to] = 1;
	//			//cout << "debug : " << map[from][to] << "---"; 
	//		}

	//		//cout << source; 
	//		//print_m(map, N, N); 

	//		//bfs(source, map, N);

	//		int visit[MAX]; 
	//		for (int i = 1; i <= N; i++)
	//		{
	//			visit[i] = 0; 
	//			out[i] = 0; 
	//		}
	//		//dfs(source, map, N, visit);
	//		// print_v(out, N); 


	//		int A[5] = { 1, 2, 3, 4, 5 }; 
	//		int NN = 5; 
	//		for (int i = 0; i <= NN - 3; i++)
	//		{
	//			for (int j = i + 1; j <= NN - 2; j++)
	//			{
	//				for (int k = j + 1; k <= NN - 1; k++)
	//				{
	//					cout << A[i] << " " << A[j] << " " << A[k]  << endl;
	//				}
	//			}
	//		}


	//}



	 }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}



// main for dijstra
//int main(int argc, char** argv)
//{
//	int map[max_N][max_N];
//	int dist[max_N];
//	int visit[max_N];
//	int sNode, dNode, N, E, from, to;
//	int T; 
//	
//	
//
//	// int i, child, parent;
//	// decleration N: 
//	
//
//	
//
//
//	
//	/*
//	아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
//	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
//	//여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
//	freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
//	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
//	freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
//	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
//	*/
//	freopen("input_1.txt", "r", stdin); // _CRT_SECURE_NO_WARNINGS
//
//
//
//
//	// cout << "T = " << T ; 
//	/*
//	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
//	*/
//	//code
//	//code
//	
//	cin >> T;
//
//
//	for (int t = 1; t <= T; t++)
//	{
//		cin >> N >> sNode >> dNode >> E; 
//
//		for (int i = 1; i <= N; i++)
//		{
//			for (int j = 1; j <= N; j++)
//			{
//				map[i][j] = INF;
//			}
//			visit[i] = 0; 
//			dist[i] = INF; 
//			
//		}
//
//
//
//		for (int e = 1; e <= E; e++)
//		{
//			cin >> from >> to;
//			cin >> map[from][to];
//			map[to][from] = map[from][to];
//		}
//
//		//print_matrix(map, N);
//
//
//		 cout << dijkstra(map, dist, visit, sNode, dNode, N); 
//
//
//
//	}
//
//
//
//
//
//
//		
//
//		
//
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}


