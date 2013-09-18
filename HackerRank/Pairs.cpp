#include<stdio.h>
#include<stdlib.h>
#include<iostream>

int compare (const void * a, const void * b);

unsigned int N;
unsigned int K;

int main(void){
	std::cin>>N>>K;
	int* arr = (int*)malloc(sizeof(int) * N);
	for(unsigned int index = 0;index < N ; index++){
		std::cin>>arr[index];
	}

	qsort(arr,N,sizeof(int),compare);

	int cnt = 0;

	for(unsigned int start = 0;start < N ; start++)
	{
		for(unsigned int end = N;end > start ; end--)
		{
			if((arr[end] - arr[start]) == K)
				cnt++;
		}
	}
	std::cout<<cnt;
	free(arr);
    return 0;
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
