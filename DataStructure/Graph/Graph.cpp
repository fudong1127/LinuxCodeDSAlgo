#include "Graph.h"

void Graph::
setVisited(bool status){
	for(unsigned int index = 0;index < (*pVisited).size();index++)
		(*pVisited)[index] = status;
}

Graph::
~Graph(){
	delete []pAdjList;
	delete pVisited;
}

Graph::
Graph(int size,bool isDirected){
	nNodes 	 = size;
	this->b_isDirected = isDirected;
	pAdjList = new vector<int>[size];
	pVisited = new vector<bool>(size,false);
}

int Graph::
getSize(void){
	if(!this->pAdjList || !this->pVisited)
		return 0;
	return nNodes;
}

void Graph::
addEdge(int source,int dest){
	if(this->b_isDirected == false){
		pAdjList[source].push_back(dest);
		pAdjList[dest].push_back(source);
	}else{
		pAdjList[source].push_back(dest);
	}
}

