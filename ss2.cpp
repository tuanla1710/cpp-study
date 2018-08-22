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
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
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

int dijsktra(int arr[MAX][MAX], int sour, int dest, int n )
{
	// find minimum value 
	int min = INF; 
	int v = sour; // temp node v
	int dist[MAX]; 
	int visit[MAX]; 
	int prevNode[MAX]; 

	for (int j = 1; j <= n; j++)
	{
		dist[j] = INF; 
		visit[j] = 0;
		prevNode[j] = j; // point to itseft 
	}
	//cout << sour << "-->" << dest << endl; 
	//print_v(dist, n); 
	//print_v(visit, n);
	//print_v(prevNode, n);
	//print_v(dist, n);
	dist[sour] = 0; 
	//print_v(dist, n);
	// prevNode[sour] = sour; 
	

	for (int i = 1; i <= n; i++) // visit all node 
	{
		min = INF;
		for (int j = 1; j <= n; j++)
		{
			if (!visit[j] && min > dist[j])
			{
				min = dist[j]; 
				v = j; 
			}
		}

		//cout << v << "-->"; 

		visit[v] = 1; 
		// update cost 
		for (int j = 1; j <= n; j++)
		{
			if (dist[j] > dist[v] + arr[v][j])
			{
				
				dist[j] = dist[v] + arr[v][j];
				//print_v(dist, n);
				prevNode[j] = v; 
			}
		}
	}
	// print_v(prevNode, n);

	return dist[dest]; 
}

int max(int a, int b)
{
	return (a > b ? a : b); 
}

int knap01(int wt[], int val[], int W, int n) 
{   

	int K[MAX][MAX]; 

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			K[i][j] = 0; 
		}
	}


	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
			{
				K[i][w] = 0; 
			}
			else if (wt[i - 1] < w)
			{
				K[i][w] = max(K[i - 1][w], val[i-1] + K[i - 1][w - wt[i - 1]]); 
			}
			else
			{
				K[i][w] = K[i-1][w]; 
			}
		}
	}
	print_m(K, n, W); 
	// cout << K[n][W]; 
	return K[n][W]; 
	
}


void sorting(int wt[], int val[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (wt[i] > wt[j])
			{
				int temp = wt[i]; 
				wt[i] = wt[j]; 
				wt[j] = temp;

				temp = val[i];
				val[i] = val[j];
				val[j] = temp;
				
			}
		}
	}
	// print_v(val, n); 
	//return wt, val; 
}



void bfs(int root, int arr[MAX][MAX], int n)
{
	int queue[MAX]; 
	int visit[MAX];

	for (int i = 0; i < n; i++)
	{
		queue[i] = 0; 
		visit[i+1] = 0; 
	}

	int rear = 0, front = 0; 
	visit[root] = 1; 
	queue[rear++] = root; 

	while (front < rear)
	{
		//cout << "rear = " << rear << " front = " << front << endl;
		//print_v(queue, n);
		//print_v(visit, n+1);
		int temp = queue[front++]; 
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i] && arr[temp][i]==1)
			{
				//print_v(queue, n);
				queue[rear++] = i; 
				//print_v(queue, n);
				visit[i] = 1; 
			}
		}

	}
	print_v(queue, n);
}

int couter = 0;
int out[MAX]; 

void dfs(int root, int arr[MAX][MAX], int n, int visit[])
{
	out[couter++] = root;
	visit[root] = 1; 
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i] && arr[root][i])
		{
			dfs(i, arr, n, visit); 
		}
	}


}

int main(int argc, char** argv)
{  
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

	int T;
	int map[MAX][MAX] ; 
	int N; // number of Node 

	int source, destination; 
	int from = 0, to = 0; 

	freopen("input.txt", "r", stdin); // _CRT_SECURE_NO_WARNINGS

	cin >> T; 
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> source >> destination;

		// init map
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					map[i][j] = 0; 
				}			
			}


			while (from != -1 || to != -1)
			{
				cin >> from >> to; 
				cin >> map[from][to]; 
				map[to][from] = map[from][to] = 1;
				//cout << "debug : " << map[from][to] << "---"; 
			}

			//cout << source; 
			//print_m(map, N, N); 

			bfs(source, map, N);

			int visit[MAX]; 
			for (int i = 1; i <= N; i++)
			{
				visit[i] = 0; 
				out[i] = 0; 
			}
			dfs(source, map, N, visit);
			print_v(out, N); 


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


