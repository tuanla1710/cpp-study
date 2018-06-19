// Time complexity : O(ElogV)
#include "stdafx.h"

#include<vector>
#include<iostream>
#include<queue>
#include<list>
#include<array>

using namespace std;

struct Node
{
	double updateSumCost; 
	queue <int> updateRoute; 
	vector <int> neighboorNode; 
	bool updateLabelFlage; 
	int nodeId; 
};


void Dijistra(int source, int N)
{

	return; 
}

Node node[6];
int N = 6;
int lable = 1;
int main()
{   	
	

	
	cout << "\n Number of nodes: " << N << endl; 	
	cout << "\n Enter the cost of all links or curve. " << endl;

	

	cout << "update ot matrix cost and nodeInfo "; 
	int costMatrix[6][6] = {{0, 0,0,0,0,0},
							{2,0,0,0,0,0}, 
	                        {4,1,0,0,0,0}, 
	                        {100000, 4,10000, 0,0,0 }, 
	                        {10000, 2, 3, 3, 0, 0}, 
	                        {10000, 10000, 10000, 2,2}};
	for (int i = 0; i < N; i++)
	{
		node[i].nodeId = i;
		node[i].updateSumCost = 1e10;
		for (int j = 0; j < N; j++)
		{
/*
			if (i != j)
			{
				cout << "Enter the cost between node " << i << " and node " << j << ": ";
				cin >> costMatrix[i][j];
			}
			else { costMatrix[i][j] = 0; }
			*/
			if (costMatrix[i][j] != 0)
			{
				node[i].neighboorNode.push_back(j); // push current to the list. 
			}

		}
	}

	
	node[0].updateLabelFlage = 1; 
	while (lable <= N) 
	{   
		for (int i = 1; i <= N; i++)
		{   
        // if ((node[i].updateLabelFlage == lable)&&(node[i].updateLabelFlage != 0))
		// which node to update
			if (node[i].updateLabelFlage = lable)
			{   
				vector<int> candidateNodeToLabel; 

				for (int k = 1; k < node[i].neighboorNode.size(); k++) // for all node in node i's neighbor. 
				{   
					if (node[k].updateLabelFlage!= 0)
					{
						// find cost and next lable node to assign. 
						if (costMatrix[i][k] + node[i].updateSumCost < node[k].updateSumCost) // if cost from node i is lower than current cost of node k. Then update. 
						{
							node[k].updateSumCost = costMatrix[i][k] + node[i].updateSumCost; // update cost from source to this node. 
							node[k].updateRoute = node[i].updateRoute; // copy route of node i
							node[k].updateRoute.push(i); // update node i to route 							
						}
						candidateNodeToLabel.push_back(node[i].neighboorNode[k]);
					}
				}

				// find next label: 
				int nodeToLabel = candidateNodeToLabel[0]; 
				for (int k = 1; k < candidateNodeToLabel.size(); k++) // for all node in node i's neighbor. 
				{
					if (node[candidateNodeToLabel[k]].updateSumCost < node[nodeToLabel].updateSumCost)
					{
						nodeToLabel = candidateNodeToLabel[0]; 
					}
					lable++;
					node[nodeToLabel].updateLabelFlage = lable; 
					cout << lable;
				}


				break; 
			}
		}
			// update to nodes
	

		
	}

	cout << node[5].updateRoute.size();

	return 0; 

}
