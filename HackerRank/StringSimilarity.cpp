#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct __Node{
	char**				ppStringlist;
	unsigned long int	number_of_string;
}Node;

int main(int argc,char** argv){
	Node* pNode = (Node*)malloc(sizeof(Node));

	scanf("%ld",&(pNode->number_of_string));
	pNode->ppStringlist = (char**)malloc(pNode->number_of_string * sizeof(char*));

	for(unsigned int i = 0 ;i < pNode->number_of_string ;i++)
	{
		pNode->ppStringlist[i] = (char*)malloc(sizeof(char) * 100000);
		scanf("%s", pNode->ppStringlist[i]);
	}

	unsigned int sum = 0;
	char *in, *cur;
	for (unsigned int i=0; i < pNode->number_of_string; i++) {
		sum = 0;
		in = pNode->ppStringlist[i];

		sum += strlen(in);
		for (cur = in+1; *cur != '\0'; cur++) {
			if (*cur == *in) {
				unsigned int index;
				for (index=1; cur[index] == in[index]; index++);
				sum += index;
			}
		}
		printf("%u\n", sum);
	}


	for(unsigned int i = 0 ;i < pNode->number_of_string ;i++)
		free(pNode->ppStringlist[i]);
	free(pNode->ppStringlist);
	free(pNode);
}
