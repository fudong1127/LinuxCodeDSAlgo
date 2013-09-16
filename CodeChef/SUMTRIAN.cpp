/*
 * PRPALIN.cpp
 *
 *  Created on: Sep 16, 2013
 *      Author: micgomes
 */



#include <iostream>
#include <vector>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define MAX(a,b) ((a>=b)?(a):(b))

int getMaxSum(int row,int col,vector< vector<int> >& matrix,vector< vector<int> >& cache){
	int limit = matrix.size();
	if((row >= limit) || (col >= limit))
		return 0;

	if(cache[row][col] == -1){
		cache[row][col] = matrix[row][col] + MAX(getMaxSum(row + 1,col,matrix,cache),getMaxSum(row + 1,col+1,matrix,cache));
	}
	return cache[row][col];
}

int main(int argc,char** argv){
	int num_test = 0;
	cin>>num_test;
	while(num_test)
	{
		num_test--;
		unsigned int num_sides = 0;
		cin>>num_sides;

		vector< vector<int> > matrix(num_sides);
		vector< vector<int> > cache(num_sides);
		for(unsigned int row = 0;row < num_sides;row++)
		{
			for(unsigned int col = 0;col <= row;col++)
			{
				int value = 0;
				cin>>value;

				matrix[row].push_back(value);
				cache[row].push_back(-1);
			}
		}
		cout<<getMaxSum(0,0,matrix,cache)<<endl;
	}
	return 0;
}
