#include "iostream"
#include "vector"
#include "limits.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

#define SET_MIN(min,val) if(val < min){min = val;}
#define ARR_SIZE(a)		sizeof(a)/sizeof(a[0])

typedef vector< vector<char> > grid;

int prime_arr[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

vector <int> chache(500,-1);

int
getNumberOfMonsters(int lowest){
    int nMonsters = 0;
    int left      = 0;
    int right     = ARR_SIZE(prime_arr) - 1;

    if(chache[lowest] != -1)
      return chache[lowest];

    while(left<=right){
         int mid = (left + right)/2;
         if(prime_arr[mid] == lowest){
            nMonsters = mid - left + 1;
            break;
         }
         else if(lowest > prime_arr[mid] && lowest < prime_arr[mid+1]){
           nMonsters = mid - left + 1;
           break;
         }
         if(prime_arr[mid] > lowest){
            right = mid - 1;
         }
         else if(prime_arr[mid] < lowest){
            left = mid + 1;
         }
    }
    chache[lowest] = nMonsters;
    return chache[lowest];
}

bool
isMonsterPresent(grid& m_grid,int row,int col,int& min){
  int  left_count  = 0;
  int  right_count = 0;
  int  down_count  = 0;
  int  up_count    = 0;
  min              = INT_MAX;

  //get left_count
  for (unsigned int j = col - 1; j >= 0 && m_grid[row][j] == '^'; j--)
  {
      left_count++;
  }
  SET_MIN(min,left_count);

  //get right_count
  for (unsigned int j = col + 1; j < m_grid[row].size() && m_grid[row][j] == '^'; j++)
  {
        right_count++;
  }
  SET_MIN(min,right_count);

  //get up_count
  for (unsigned int i = row - 1; i >= 0 && m_grid[i][col] == '^'; i--)
  {
        up_count++;
  }
  SET_MIN(min,up_count);

  //get down_count
  for (unsigned int i = row + 1; i < m_grid.size() && m_grid[i][col] == '^'; i++)
  {
        down_count++;
  }
  SET_MIN(min,down_count);

  if(min < 2)
      return false;
  return true;
}

void
initGrid(grid& m_grid){
  int rowSize = m_grid.size();
  for (int row = 0; row < rowSize; row++)
  {
    int colSize = m_grid[row].size();
    for (int col = 0; col < colSize; col++)
    {
      cin>>m_grid[row][col];
    }
  }
}

int
getCount(grid& m_grid){
  int count = 0;
  int rowSize = m_grid.size();
  for (int row = 0; row < rowSize; row++)
  {
    int colSize = m_grid[row].size();
    for (int col = 0; col < colSize; col++)
    {
      int CRC_Count = 0;
      if('^'== m_grid[row][col] && isMonsterPresent(m_grid,row,col,CRC_Count))
      {
         count += getNumberOfMonsters(CRC_Count);
      }
    }
  }
  return count;
}

int
main(int argc,char** argv){
  int nTest = 0;
  cin>>nTest;
  while(nTest--){
    int row = 0;
    int col = 0;

    cin>>row>>col;

    grid m_grid (row,vector<char>(col,'^'));

    initGrid(m_grid);

    cout<<getCount(m_grid)<<endl;
  }
  return 0;
}
