#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define YES				"YES"
#define NO				"NO"
#define GET(n)           cin>>n
#define PUT(n)           cout<<n<<endl
#define INDEX(val)		 (val-'a')
#define MAX 			 40001
#define ALPHA_RANGE		 26

int main(){
	int nTestCases = 0;
	GET(nTestCases);
	while(nTestCases--)
	{
		long long int arr[ALPHA_RANGE] = {0};
		int parent_len = 0;
		for(int i = 0;i<2;i++)
		{
			char PARENT[MAX] = {0};
			GET(PARENT);
			parent_len += strlen(PARENT);
			int j = 0;
			while(j < MAX && PARENT[j] != '\0')
			{
				if(PARENT[j] >= 'a' && PARENT[j]<='z')
					arr[INDEX(PARENT[j])]++;
				j++;
			}
		}

		int nChildrenCnt = 0;
		GET(nChildrenCnt);
		int child_len = 0;
		for(int i = 0; i < nChildrenCnt;i++)
		{
			char KIDNAME[MAX] = {0};
			GET(KIDNAME);
			child_len += strlen(KIDNAME);
			int j = 0;
			while(j < MAX && KIDNAME[j] != '\0')
			{
				if(KIDNAME[j] >= 'a' && KIDNAME[j] <='z')
					arr[INDEX(KIDNAME[j])]--;
				j++;
			}
		}

		if(child_len > parent_len){
			PUT(NO);
			continue;
		}

		bool bNo = false;
		for(int i = 0;i<ALPHA_RANGE && !bNo;i++)
		{
				if(arr[i] < 0)
					bNo = true;
		}
		if(bNo == true)
			PUT(NO);
		else
			PUT(YES);
	}
	return 0;
}
