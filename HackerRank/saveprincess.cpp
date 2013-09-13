#include <iostream>
#include <vector>
using namespace std;

typedef struct _pos{
        int x;
        int y;
}pos;

void 
displayPathtoPrincess(int n, vector <string> grid){
      pos p_pos;
      //find princess position.
      if(grid[0][0] == 'p'){
        p_pos.x = 0;
        p_pos.y = 0;
      }
      else if(grid[0][n-1] == 'p'){
        p_pos.x = 0;
        p_pos.y = n-1;
      }
      else if(grid[n-1][0] == 'p'){
        p_pos.x = n-1;
        p_pos.y = 0;
      }
      else if(grid[n-1][n-1] == 'p'){
        p_pos.x = n-1;
        p_pos.y = n-1;
      }

      //my position.
      pos my_pos;
      my_pos.x = n/2;
      my_pos.y = n/2;
      
      //my position.
      int up   = my_pos.x - p_pos.x;
      int left = my_pos.y - p_pos.y;
      if(up > 0)
      {
        for (int i = 0; i < up; i++) {
            cout<<"UP"<<endl;  
        }
      }else
      {
        up = -1 * up;
        for (int i = 0; i < up; i++) {
            cout<<"DOWN"<<endl;  
        }      
      }
      
      if(left > 0)
      {
        for (int i = 0; i < left; i++) {
            cout<<"LEFT"<<endl;  
        }
      }else
      {
        left = -1 * left;
        for (int i = 0; i < left; i++) {
            cout<<"RIGHT"<<endl;  
        }      
      }
}

int 
main(void) {
        int m;
        vector <string> grid;
       
        cin >> m;
       
        for(int i=0; i<m; i++) {
             string s; cin >> s;
             grid.push_back(s);
        }
       
        displayPathtoPrincess(m,grid);
        return 0;
}
