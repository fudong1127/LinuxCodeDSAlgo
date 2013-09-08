#include "Graph.h"

void Graph::
doBFS_Util(int source,vector<int>& BFS_Tree){
	queue<int> BFS_Queue;
	BFS_Queue.push(source);

	while(false == BFS_Queue.empty()){
		int U = BFS_Queue.front();
		BFS_Queue.pop();
		if((*pVisited)[U] == true)
			continue;
		
		(*pVisited)[U] = true;
		for(unsigned int index = 0;index < pAdjList[U].size();index++){
			int node = pAdjList[U][index];
			if(true == (*pVisited)[node])
				continue;
			BFS_Tree[node] = U;
			BFS_Queue.push(node);	
		}	
	}
}

void Graph::
doBFS(int source,vector<int>& BFS_Tree){
	setVisited(false);
	doBFS_Util(source,BFS_Tree);
	setVisited(true);	
}

