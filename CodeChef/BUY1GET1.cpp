#include <stdio.h>
#include <string.h>
#define LEN 201
#define CNT 256
int main(int argc,char** argv){
	int size = 0;
	scanf("%d ",&size);
	for(int i = 0;i<size;i++)
	{
		int cost 	 = 0;
		char ip[LEN] = {0};
		int cnt[CNT] = {0};
		scanf("%s",ip);
		int len = strlen(ip);

		for(int j = 0;j<len;j++)
		{
			cnt[ip[j]]++;
		}

		for(int j = 0;j<CNT;j++)
		{
			if(cnt[j] == 0)
			continue;
			if(cnt[j] %2 == 0)
				cost += (cnt[j] /2);
			else
				cost += (cnt[j] /2) + 1;
		}
		printf("%d\n",cost);
	}
	return 0;
}
