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

int vertex, start;


#define N_MAX 100 // number of iterm 
#define W_Constraint 50 // constraint of sum weight

int V[N_MAX][W_Constraint];
int K[N_MAX][W_Constraint];
int i; 


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


int binarySearch2(int *arrA, int low, int high, int target)
{   
	
	if (low > high)
	{
		
		// cout << "-1"; 
		
		return -1; 
	}

	
	int  mid = (high + low) / 2; 
	
	// cout << "target = " << target << "; arrA[mid] = " << arrA[mid] << "mid = " << mid <<  endl ;

	if (target < arrA[mid])
		{			
			binarySearch2(arrA, low, mid - 1, target);			
		}
	else if (target > arrA[mid])
		{
			binarySearch2(arrA, mid + 1, high, target);
			//cout << "test";
		}
	else
		{
			
			// cout << mid; 
			return mid;
		}

}


// DFS algorithm 
#define VERTEX_MAX 30 


int map[VERTEX_MAX][VERTEX_MAX];
int visit[VERTEX_MAX];

void DFS(int v) // v: starting node 
{
	visit[v] = 1; 
	// cout << v << " ";  // add 
	// cout << "v = " << v << " " << vertex;

	for (int i = 1; i <= vertex; i++)
	{
		if (map[v][i] == 1 && visit[i]==0)
		{
			
			// visit[i] = 1; 
			cout << " " << i ;
			DFS(i); // find child of this node
		}

	}

	/*using at main to test 

	cin >> vertex >> start; // number of node


	for (int i = 1; i <= vertex; i++)
	{
	visit[i] = 0;
	}

	for (int i = 1; i <= vertex; i++)
	{
	for (int i = 1; i <= vertex; i++)
	{
	map[i][j] = 0;
	}
	}






	bool con = true;
	while (con == true)
	{

	cin >> i >> j;
	// cout << i << j;
	if (i == -1 && j == -1)
	{
	con = false;
	}
	else
	{
	map[i][j] = 1;
	map[j][i] = 1;
	}


	}
	// cout << "input" << N << start;

	cout << "#" << test_case << " ";
	cout << start;
	DFS(start);



	// print_matrix(arrA, NUM);

	cout << endl;
	
	*/
}


int rear = 0, front = 0; 
int queue[VERTEX_MAX]; 


void BFS(int v)
{
	visit[v] = 1; 
	cout << v << " ";  // display v; 

	queue[rear++] = v; 
	while (front < rear)
	{
		int vx = queue[front++]; 
		for (int i = 1; i <= vertex; i++)
		{
			if (!visit[i] && map[vx][i] == 1)
			{
				queue[rear++] = i; // update to next node need to check. Due to the father node will be updated first.  
				visit[i] = 1; 
				cout << i << " "; 
			}
		}
	}
/* in main 

cin >> vertex >> start; // number of node


for (int i = 1; i <= vertex; i++)
{
visit[i] = 0;
}

for (int i = 1; i <= vertex; i++)
{
for (int i = 1; i <= vertex; i++)
{
map[i][j] = 0;
}
}






bool con = true;
while (con == true)
{

cin >> i >> j;
// cout << i << j;
if (i == -1 && j == -1)
{
con = false;
}
else
{
map[i][j] = 1;
map[j][i] = 1;
}


}
// cout << "input" << N << start;

cout << "#" << test_case << " ";
BFS(start);


*/
}



// Parametric Search 
#define MAX_RIBBON 100
int K;
int N;
int low, high, mid, numRibbonTape, max;
int sizeRibbonTape[MAX_RIBBON];

void search()
{
	numRibbonTape = 0; 
	mid = (low + high) / 2;
	for (int i = 0; i < K; i++)
	{
		// cat each type i 
		numRibbonTape = numRibbonTape + sizeRibbonTape[i] / mid;
	}

	if (numRibbonTape >= N)
	{
		low = mid + 1; 
		if (max < mid)
		{
			max = mid; 
		}

	}
	else
	{
		high = mid - 1; 
	}

	/* main
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
	low = 1;
	high = 0;
	max = -1;
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
	cin >> sizeRibbonTape[i];
	if (high < sizeRibbonTape[i])
	{
	high = sizeRibbonTape[i];
	}
	}
	while (low <= high)
	{
	search();
	}
	cout << "#" << test_case << " " <<  max;

	*/
}

// dynamic programming 

int dp[2][100001]; 
int board[2][100001]; 
// int N; 

const int maxab(const int a, const int b)
{
	return (a > b ? a : b); 
}

void findSticker()
{
	dp[0][0] = board[0][0];
	dp[1][0] = board[1][0]; 
	dp[0][1] = dp[1][0] + board[0][1]; 
	dp[1][1] = dp[0][0] + board[1][1];

	for (int i = 2; i < N; i++)
	{
		dp[0][i] = maxab(maxab(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]) + board[0][i]; 
		dp[1][i] = maxab(maxab(dp[0][i - 2], dp[1][i - 2]), dp[0][i - 1]) + board[1][i];
	}
	/*
	for (int j = 0; j < 2; j++)
	{
	for (int i = 0; i < N; i++)
	{
	cin >> board[j][i];

	}
	}

	findSticker();


	// cout << maxab(low,high);

	cout << maxab(dp[0][N - 1], dp[1][N - 1]);


	*/

}
#define MAX_STRING_LENGTH 10

int stackTop = 0; 
char combinationStack[MAX_STRING_LENGTH];

void swap(char *x, char *y)
{
	char temp = *x; 
	*x = *y; 
	*y = temp; 
}

void permutation(char *str, int l, int r)
{
	if (l == r) { cout << str << endl; }
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(str + l, str + i); 
			permutation(str, l + 1, r); 
			swap(str + l, str + i);

		}
	}
}

int stackPop = 0; 
void push(char ch)
{
	combinationStack[stackPop++] = ch;
	combinationStack[stackPop] = '\0'; 
}
void pop()
{
	combinationStack[--stackTop] = '\0';
}


void combination(const char *str, int length, int offset, int k) // chua chay day ne. 
{
	if (k == 0) { cout << combinationStack << endl; return; }
	
	for (int i = offset; i <= length - k; ++i)
	{
		
			push(str[i]); 
			combination(str, length, i + 1, k - 1); 
			pop();
		}

	/*
	cin >> str >> N >> K;
	// cout << "in main" << str << endl;
	str[N] = 0;

	permutation(str, 0, N - 1);

	combination(str, N, 0, K);
	*/
	
}
/**/

#define INF 1000
#define N_MAX 30 
int dist[N_MAX];
int visitD[N_MAX];
int V; //number of node 
int mapD[N_MAX][N_MAX]; // matrix of cost 
int sick; 
int route[N_MAX]; 

int index; 




void find_route(int s, int d)
{   	
	int current = d;
	index = 1;
	route[index++] = current;
	int vi[N_MAX];
	for (int i = 1; i < V; i++)
	{
		vi[i] = 0; 
	}
	vi[d] = 1; 
	while (current != s)
	{		
		for (int i = 1; i <= 7; i++)
		{
			cout << " dist[current] - map[current][i]=  " << dist[current] - mapD[current][i];

			if (dist[current] - mapD[current][i] == dist[i] && vi[i] ==0)
				{					
					route[index++] = i;	
					vi[i] = 1;
					current = i;
					// break;
				}
		}		
	}
	
}

int find_front_node(int current, int source)
{   
	if (i == source)
	{
		return source;
	}

	for (int i = 1; i <= 7; i++)
	{  		
		if (dist[current] - mapD[current][i] == dist[i])
		{
			
			return find_front_node(i, source);
			
		}
	}
	
}




void dijkstra()
{
	int i = 1; 
	dist[start] = 0; 
	while (i <= vertex)
	{
		// determine which node will be updated to visted node list

		int min = INF; 
		int v; 

		for (int j = 1; j <= vertex; j++)
		{
			if (!visit[j] && min > dist[j])
			{
				min = dist[j]; // which node will be updated. 
				v = j; 
			}
		}

		visit[v] = 1; 



		for (int j = 1; j <= vertex; j++)
		{
			if (dist[j] > dist[v] + map[v][j])
			{
				dist[j] = dist[v] + map[v][j]; 
			}
		}



		i++; 
	}

}

int maxx(int a, int b)
{
	return (a > b) ? a : b; 
}

int kn(int W, int wt[], int val[], int n)
{
	if (W == 0 || n == 0)
	{
		return 0; 
	}
	if (wt[n - 1] > W)
	{
		return (kn(W, wt, val, n - 1));
	}
	else
	{
		int kn1 = val[n - 1] + kn(W - wt[n-1], wt, val, n - 1);
		int kn2 = kn(W, wt, val, n - 1);
		return maxx(kn1, kn2);
	}


}

























void dijstra()
{	
	int i = 1, j, min;
	dist[start] = 0; 
	//route[start][start] = start; 
	int v; 
	while (i <= V) // all node will be passed. 
	{   
		// cout << "i = " << i; ok
		min = INF; 
		for (j = 1; j <= V; j++)
		{
			if (visitD[j]==0 && min > dist[j]) // find smallcess node to go that not be visited. 
			{
				min = dist[j];
				v = j; 
			}
		}
		visitD[v] = 1;




		

		
		for (j = 1; j <= V; j++)
		{
			if (dist[j] > dist[v] + mapD[v][j]) // current dist < new dist from v to j // update to other nodes 
			{
				dist[j] = dist[v] + mapD[v][j];

				// update next route: 
				

			}
		}
		


		i++; 
	}
	/*
	cin >> V >> start >> sick;

	//cout << V << start << sick;

	cin >> nARC; // number of edges
	// cout << nARC;
	for (int i = 1; i <= V; i++)
	{
	for (int j = 1; j <= V; j++)
	{
	mapD[i][j] = INF;

	}

	visitD[i] = 0;
	dist[i] = INF;

	}

	int from = 0, to = 0;
	for (int i = 1; i <= nARC; i++)
	{


	cin >> from >> to;
	cin >> mapD[from][to];

	mapD[to][from] = mapD[from][to];

	// cout << "from" << from << "to" << to << "map[from][to]" << map[from][to] << " " << endl;

	}
	dijstra();

	cout << "#" << test_case << " " << dist[sick];

	for (int i = 1; i <= V; i++)
	{
	cout << " " << dist[i] << " " ;
	}

	for (int i = 1; i <= V; i++)
	{
	cout << " " << visitD[i] << " ";
	}









	find_route(start, sick);

	cout << endl;

	cout << "route =  ";
	for (int i = 1; i <= V; i++)
	{
	cout << route[i] << " ";
	}
	*/
}






/*


void dijkstra()
{	
	cost[start] = 0; 
	int v = start; 
	for (int i = 1; i <= N; i++)
	{
		int min = INF;

		for (int j = 1; j <= N; j++)
		{
			if (!visit[j] && min > map[v][j])
			{
				min = map[v][j];
				v = j;
			}
		}
		visit[v] = 1;

		for (j = 1; j <= N; j++)
		{
			if (cost[j] > map[v][j] + cost[v])
			{
				cost[j] = map[v][j] + cost[v];
			}
		}
	}		
}
*/

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
	int i = 0, j = 0;
	int N, K;
	int nARC;
	char str[MAX_STRING_LENGTH];	

	
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

	// cout << "T = " << T ; 
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int val[] = { 60, 100, 120 };

		double val[] = { 60, 100, 120 };

		int wt[] = { 10, 20, 30 };
		int  W = 50;
		int n = sizeof(val) / sizeof(val[0]);
		cout << n << " " << sizeof(val) << endl;
		cout << kn(W, wt, val, n);
		return 0;

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int knap(int W, int wt[], int val[], int n)
{
	if (W == 0 || n == 0)
	{
		return 0; 
	}

	if (wt[n - 1] > W)
	{
		return (knap(W, wt, val, n - 1));
	}
	else
	{
		int np1 = val[n - 1] + knap(W - wt[n - 1], wt, val, n - 1);
		int np2 = knap(W, wt, val, n - 1);
		return maxx(np1, np2);

	}
}

/// another way to do


void knap(int val[], int wt[], int n, int W)
{
	int i; 
	


	for (i=0; i<= W;i++)
	{
		V[0][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if ((wt[i] <= j) && (val[i]+V[i-1][W - wt[i-1]] > V[i-1][W]))
			{
				V[i][j] = val[i] + V[i - 1][W - wt[i - 1]];
				K[i][j] = 1; 
			}
			else
			{
				V[i][j] = V[i - 1][j];
				K[i][j] = 0;				
			}
		}
	}
	int X = W; 
	for (i = n; i >= 1; i--)
	{
		if (K[i][X] == 1)
		{
			cout << i; 
			X = X - wt[i];
		}	
	}
}
