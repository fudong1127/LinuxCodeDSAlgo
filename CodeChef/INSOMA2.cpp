#include "iostream"
#include "vector"
#include "string"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

typedef vector< vector<char> > MATRIX;

bool isValidRange(int range,int  max){
    if(range < 0 || range == max){
        return false;
    }
    return true;
}
void 
createMatrix(MATRIX& matrix)
{
    int size = matrix.size();
    for (int row = 0; row < size; row++) 
    {
        for (int col = 0; col < size; col++) 
        {
             cin>>matrix[row][col];
        }
    } 
}

int 
getCount(MATRIX& matrix,string str,unsigned int index,int row,int col){
   int cnt = 0;
   if(!isValidRange(row,matrix.size()) || !isValidRange(col,matrix.size()) || index == str.length() || matrix[row][col] != str[index]){
         cnt = 0;
   }
   else if((matrix[row][col] == str[index]) && (str.length() == index + 1)){
        cnt = 1; 
   }
   else{
        cnt = getCount(matrix,str,index + 1,row - 1,col - 1) +
              getCount(matrix,str,index + 1,row - 1,col + 1) +
              getCount(matrix,str,index + 1,row + 1,col - 1) +
              getCount(matrix,str,index + 1,row + 1,col + 1);
   }
   return cnt;
}

int 
getTotalCount(MATRIX& matrix,string str){
    int nCount = 0;
    int size = matrix.size();
    
    for (int row = 0; row < size; row++) 
    {
        for (int col = 0; col < size; col++) 
        {
            if(matrix[row][col] == 'A'){
	            nCount += getCount(matrix,str,0,row,col);            
            } 
        }
    } 
    return nCount;
}

int
main(int argc,char** argv){
    string str;
    //Read the Size
    int N = 0;
    cin>>N;

    //Get the matrix
    MATRIX  let_Matrix(N,vector<char>(N,0));
    createMatrix(let_Matrix); 
    
    cin>>str;

    cout<<getTotalCount(let_Matrix,str); 
    return 0;
}
