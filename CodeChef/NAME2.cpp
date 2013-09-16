#include <iostream>
#include <string.h>
using namespace std;
#define YES              "YES"
#define NO               "NO"
#define GET(n)           cin>>n
#define PUT(n)           cout<<n<<endl

int isSubSeq(char* pLongStr1,char* pSmallStr2){
    while(*pLongStr1 != '\0')
    {
        if(*pSmallStr2 == *pLongStr1)
            pSmallStr2++;
        if(*pSmallStr2 == '\0')
            break;
        pLongStr1++;
    }
    if(*pSmallStr2 == '\0')
        return 1;
    return 0;
}

int main(){
    int nTestCases = 0;
    GET(nTestCases);
    while(nTestCases--)
    {
         char name1[25001] = {0};
         char name2[25001] = {0};
         GET(name1);
         GET(name2);
         int name1_len = strlen(name1);
         int name2_len = strlen(name2);
         if(name1_len > name2_len){
             ((isSubSeq(name1,name2) == 1)?PUT(YES):PUT(NO));
         }
         else if(name2_len > name1_len){
             ((isSubSeq(name2,name1) == 1)?PUT(YES):PUT(NO));
         }else{
             ((strcmp(name1,name2) == 0)?PUT(YES):PUT(NO));
         }
	}
	return 0;
}
