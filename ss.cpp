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

// link list 

#define MAX 100

//int visit[MAX];
int map[MAX][MAX]; 
int queue[MAX]; 
//int N; 
int status[MAX];


#define MAX  1000
#define INF 100000;
int graph[MAX][MAX];
int dist[MAX];

int dist_node[MAX][MAX];

int visit[MAX];

int circle_pos[MAX][MAX];

int M, N, K, T;
long R; 

void bfs(int root)
{
	int v;
	int rear = 0, front = 0; 
	visit[root] = 1; 
	int couter_node = 0; // root node 
	status[couter_node] = 0;


	

	queue[rear++] = root; 
	//cout << root << " "; 
	
	while (front < rear)
	{
		v = queue[front++]; 
		cout << v << " ";
		
		for (int i = 1; i <= N; i++)
		{
			//cout << "debug-1: " << visit_d[i] << "----" << map_d[v][i] <<  endl;
			if (visit[i] == 0 && map[v][i] == 1)
			{   
				//cout << "debug-3"; 
				queue[rear++] = i; 
				visit[i] = 1; 
				

				status[i] = status[v] + 1; 
				
			}
		}
	}
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << status[i] << " ";
	}
}

void dfs(int root)
{   
	visit[root] = 1; 
	cout << root << " "; 
	for (int i = 1; i <= N; i++)
	{
		//cout << "test-2";
		if (visit[i] == 0 && map[root][i] == 1)
		{			
			dfs(i); 
		}
	}
}

double distance(int x1, int x2, int y1, int y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}


void dijisktra(int sNode, int dNode)
{
	int temp = sNode;
	//visit[sNode] = 1;
	dist[sNode] = 0; 
	for (int n = 1; n <= M * N; n++)
	{
		int min = INF; 
		for (int i = 1; i <= M * N; i++)
		{
			if (min > dist[i]&&!visit[i])
			{
				min = dist[i]; 
				temp = i; 
			}
		}
		visit[temp] = 1;


		for (int i = 1; i <= M * N; i++)
		{
			if (dist[i] > dist[temp] + graph[temp][i])
			{
				dist[i] = dist[temp] + graph[temp][i];				
			}

		}
	}
	


	
}

// testing 
#define MMAX 100 
int **testM(int arr[MMAX][MMAX], int a, int b)
{   
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << arr[i][j]; 
		}
	}
	
	int **ab = new int *[MMAX]; 
	for (int i = 0; i < MMAX; i++)
	{
		ab[i] = new int[MMAX]; 
	}
	return ab;
}

#define MAX 100 




int main(int argc, char** argv)
{

	
	

	// int i, child, parent;
	// decleration N: 
	

	


	
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
	
	



	// cout << "T = " << T ; 
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	//code
	//code
	
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		// input; 
		

		cin >> M >> N >> K >> R; 

		// input circle

		for (int k = 1; k <= K; k++)
		{
			for (int i = 1; i <= 2; i++)
			{
				cin >> circle_pos[k][i]; 
				cout << circle_pos[k][i] << " "; 
			}
			cout << endl; 
		}

		int i, j; 

		for (int i = 1; i <= M*N; i++)
		{   						
			// visit 
			visit[i] = 0; 
			dist[i] = INF; 
		}


		// init dist
		for (int i = 1; i <= M * N; i++)
		{
			for (int j = 1; j <= M * N; j++)
			{
				bool b = ((abs(i%N - j%N) == 1) && (i / N == j / N)); 
				bool c = (i%N == j % N) && (abs(i / N - j / N) == 1);
				
				if (i == j)
				{
					graph[i][j] = 0;
				}
				else if (b || c)
				{
					graph[i][j] = 1;
				}
				else
				{
					graph[i][j] = INF;
				}

			}
		}

		// cout << "(d <= R)" << R; 
		for (int i = 1; i <= M * N; i++)
		{
			
				// cout << dist[i][j] << " "; 
				int x,y; 
				if (i % N == 0)
				{
					x = N;
					y = i / N;
				}
				else
				{
					x = i % N;
					y = i / N + 1;
				}
				

				//cout << " x = " << x << " y = " << y << endl; 
				
				for (int j = 1; j <= K; j++)
				{
					//cout << " circle_pos[j][1] = " << circle_pos[j][1] << " circle_pos[j][2] = " << circle_pos[j][2] << endl;
					double d = distance(x, circle_pos[j][2], y, circle_pos[j][1]);

					//cout << "d = " << d << " "; 
					if (d <= R)
					{
						visit[i] = 1; 
					}
				}				
			//cout << endl; 
		}

		dijisktra(1, M*N); 

		if (dist[M*N] < 100000)
		{
			cout << "possible";
		}
		else
		{
			cout << "impossible";
		}
		// display visit
		/*for (int i = 1; i <= M * N; i++)
		{
			cout << visit[i] << " ";
		}
*/			
		// using bfs to find shortest parth
		cout << endl; 

		// update dist









		

		cout << endl;    
	
		//cin >> vertex >> start_node >> end_node >> edge;

		//// cout << vertex << start_node << end_node << edge;
		//int i, j; 
		//for (i = 1; i <= vertex; i++)
		//{
		//	for (j = 1; j <= vertex; j++)
		//	{
		//		if (i != j)
		//		{
		//			map_d[i][j] = INF;
		//		}
		//	}
		//}
		//int from, to, value;
		//for (i = 1; i <= edge; i++)
		//{
		//	 
		//	cin >> from >> to >> value;
		//	// cout << from << to << value << endl;

		//	map_d[from][to] = value;


		//}
		//for (i = 1; i <= vertex; i++)
		//{
		//	dist_d[i] = INF;
		//	visit_d[i] = 0;
		//}


		//cout << "#" << t; 
		//dijisktra();
		//cout << dist_d[end_node] << endl;
		 

	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


