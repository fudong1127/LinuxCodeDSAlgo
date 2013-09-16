#include <stdio.h>
#include <stdlib.h>


static int nNumOfTestCases;
static char InputString[100]={0};
static unsigned int* pResult = NULL;

unsigned int getNumberOfHolesInTheString(const char* pInputString){
	unsigned int numOfHoles=0;
	const char* pStr = pInputString;
	while(*pStr != '\0'){
		if((*pStr == 'A') || (*pStr == 'D') || (*pStr == 'O') || (*pStr == 'P') || (*pStr == 'Q')||(*pStr == 'R'))
			numOfHoles = numOfHoles + 1;
		else
		if(*pStr == 'B')
			numOfHoles = numOfHoles + 2;
		pStr++;
	}
	return numOfHoles;
}

int
main(int argc,char* argv[])
{
	 scanf("%d",&nNumOfTestCases);
	 int index = 0;
	 pResult = (unsigned int*)malloc(nNumOfTestCases * sizeof(int));

	 for(index=0;index<nNumOfTestCases;index++)
	 {
		scanf("%s",InputString);
		pResult[index] = getNumberOfHolesInTheString(InputString);
	 }
	 for(index=0;index<nNumOfTestCases;index++)
	 {
		 printf("%d\n",pResult[index]);
	 }

	 free(pResult);
	 return 0;
}
