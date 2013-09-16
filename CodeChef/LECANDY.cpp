#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000*2
static int nNumTestCases = 0;
static char** ppString = NULL;
static char eachElepInput[SIZE];

char* willElephantBeHappy(char* pInputString, int totalNumOfCandies);
char* getInputFromStdin(char input[]);

int main(){
	int index = 0;
	int nNumElephant = 0;
	int nNumCandies = 0;
	char* ch;
	scanf("%d",&nNumTestCases);

	ppString = (char**)malloc(nNumTestCases * sizeof(char*));
	memset(ppString,0,nNumTestCases);

	for(index = 0; index < nNumTestCases; index++)
	{
		memset(eachElepInput,'\0',sizeof(eachElepInput));
		scanf("%d %d",&nNumElephant,&nNumCandies);
        getInputFromStdin(eachElepInput);
  	    ppString[index] = willElephantBeHappy(eachElepInput,nNumCandies);
	}

	for(index = 0; index < nNumTestCases; index++)
		printf("\n%s",ppString[index]);
	free(ppString);
}

char* getInputFromStdin(char* input){
 while(getchar()!='\n');  //clean the stdin
	fgets(input,SIZE,stdin);
 return input;
}

char* willElephantBeHappy(char* pInputString, int totalNumOfCandies){
	char* pos1   = NULL;
	long int sum = 0;
    long int val = 0;
	if(NULL == pInputString)
		return "No";

	pos1 = pInputString;

    do{
	     val = strtol(pos1,&pos1,10);
		 sum += val;
 	 }while(val !=0);

	if(sum <= totalNumOfCandies)
		return "Yes";
	else
		return "No";
}

