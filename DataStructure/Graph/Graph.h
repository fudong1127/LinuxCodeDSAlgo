#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
  private:
	int nNodes; //Number of nodes
	
	bool b_isDirected;

	vector<int>* pAdjList;

	vector<bool>* pVisited;

	void doBFS_Util(int source,vector<int>& BFS_Tree);
	
	void doDFS_Util(int source,vector<int>& DFS_Tree);

	void setVisited(bool status);
	
  public:
	Graph(int size,bool isDirected = false);

	int getSize();

	virtual ~Graph();

	void addEdge(int source,int dest);

	void doBFS(int source,vector<int>& BFS_Tree);	
	
	void doDFS(int source,vector<int>& DFS_Tree);	 
};
#endif
