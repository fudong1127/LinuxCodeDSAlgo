#include "Graph.h"

void Graph::
doDFS(int source,vector<int>& DFS_Tree){
	setVisited(false);
	doDFS_Util(source,DFS_Tree);
	setVisited(true);	
}

void Graph::
doDFS_Util(int source,vector<int>& DFS_Tree){
	(*pVisited)[source] = true;
	for(unsigned int index = 0;index < pAdjList[source].size();index++){
		int node = pAdjList[source][index];
		if(true == (*pVisited)[node])
			continue;
		
		DFS_Tree[node] = source;
		doDFS_Util(node,DFS_Tree);		
	}
}

