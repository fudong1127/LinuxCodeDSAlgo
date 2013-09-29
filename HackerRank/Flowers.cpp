#include <stdio.h>
#include <stdlib.h>

int* friends;
int* flowers;
int* rank;

int compare (const void * a, const void * b){
  int value_a = flowers[*(int*)a];
  int value_b = flowers[*(int*)b];
  return (value_a - value_b);
}


int
main(int argc,char** argv)
{
	int N    = 0;
	int K 	 = 0;
	int cost = 0;
	scanf("%d %d ",&N,&K);

	friends = (int*)malloc(sizeof(int) * K);
	flowers = (int*)malloc(sizeof(int) * N);
	rank	  = (int*)malloc(sizeof(int) * N);

	for(int i = 0;i < N;i++)
  {
		scanf("%d",&flowers[i]);
		rank[i] = i;
	}

	qsort(rank,N,sizeof(int),compare);

	int j = 0;
	for(int i = N-1;i >= 0;i--)
  {
		cost += (friends[j] + 1)*flowers[rank[i]];
		++friends[j++];
		if(j == K)
			j = 0;
	}
	printf("%d",cost);

	free(friends);
	free(flowers);
	free(rank);
	return 0;
}
