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

int prime_arr[] = {2,3,5,7,11,13,17,19,23,29,31,
                   37,41,43,47,53,59,61,67,71,
                   31,37,41,43,47,53,59,61,67,71,
                   73,79,83,89,97,101,103,107,109,113,
                   127,131,137,139,149,151,157,163,167,173,
                   179,181,191,193,197,199,211,223,227,229,
                   233,239,241,251,257,263,269,271,277,281,
                   283,293,307,311,313,317,331,337,347,349,
                   353,359,367,373,379,383,389,397,401,409,
                   419,421,431,433,439,443,449,457,461,463,
                   467,479,487,491,499,503,509,521,523,541,
                   547,557,563,569,571,577,587,593,599,601,
                   607,613,617,619};

vector <int> chache(500,-1);

int
getNumberOfMonsters(int lowest){
    int nMonsters = 0;
    int left      = 0;
    int right     = ARR_SIZE(prime_arr) - 1;

    if(chache[lowest] != -1)
      nMonsters = chache[lowest];

    else{
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
    }
    return nMonsters;
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
      SET_MIN(min,left_count);
  }

  //get right_count
  for (unsigned int j = col + 1; j < m_grid[row].size() && m_grid[row][j] == '^' && right_count < min ; j++)
  {
        right_count++;
        SET_MIN(min,right_count);
  }

  //get up_count
  for (unsigned int i = row - 1; i >= 0 && m_grid[i][col] == '^' && up_count < min; i--)
  {
        up_count++;
        SET_MIN(min,up_count);
  }

  //get down_count
  for (unsigned int i = row + 1; i < m_grid.size() && m_grid[i][col] == '^' && down_count < min; i++)
  {
        down_count++;
        SET_MIN(min,down_count);
  }

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
