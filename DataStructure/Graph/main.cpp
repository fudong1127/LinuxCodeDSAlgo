#include "Graph.h"

int 
main(int argc,char** argv){
	int nNodes ;
	cout<<"Enter number of nodes:";
	cin>>nNodes;

	Graph* p_graph =new Graph(nNodes);

	int src,dest;
	do{
		cout<<endl<<"Enter node[u][v]:(-1,-1 to end)";
		cin>>src>>dest;

		if(src == -1 || dest == -1)
			break;

		p_graph->addEdge(src,dest);
	}while(true);

	vector<int> tree(p_graph->getSize(),-1);
	p_graph->doDFS(0,tree);

	for(unsigned int i = 0;i<tree.size();i++){
		cout<<tree[i]<<" ";
	}
	
	delete p_graph;
	return 0;
}

