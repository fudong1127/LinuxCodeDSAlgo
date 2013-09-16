#include <iostream>
#include <vector>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

bool isAmbigous(vector<int>& arr){
	bool result = true;
	unsigned int size = arr.size();
	for(unsigned int index = 1;index <= size;index++)
	{
		unsigned int pos = arr[index-1];
		if(arr[pos-1] != index)
			return false;
	}
	return result;
}
int
main(int argc,char** argv){
	while(1)
	{
		unsigned int num_elems = 0;
		cin>>num_elems;

		if(!num_elems)
			break;

		vector<int> perm(num_elems);
		for(unsigned int index = 0;index < num_elems;index++){
			cin>>perm[index];
		}

		if(true == isAmbigous(perm))
			cout<<"ambiguous"<<endl;
		else
			cout<<"not ambiguous"<<endl;
	}
	return 0;
}
