//994. Rotting Oranges
/*
Given - A grid (matrix) where-
        0 = empty cell
        1 = fresh orange
        2 = rotten orange
If we encounter any fresh orange in four directions of the rotten orange- make them all rotten in 1 minute

Return minutes ONLY when no fresh oranges are left. If fresh oranges are remaining - return -1
*/

/* 

Apprach-
  1. First traverse the entire grid and store number of fresh oranges in a variable and index[i][j] of rotten oranges in a queue.
  2. Initialise "minutes" variable & "visited" vector.
  3. Initialise arrays for indexes of all four directions
  4. while queue is not empty & fresh oranges exists-
      -> initialise a for loop to traverse through the queue-
          - pop the first element of the queue and initialise its ith & jth indexes as x & y
          - for loop again to traverse all four neighbouring sides
          - iff neighbouring sides are greater than/equal to zero and less than there col/row size & the value of the cell is equal to 1
                    - decrement fresh
                    - overwrite the cell's value as 2
                    - insert the rotten index in queue

  5. If fresh == 0 -> return minutes, else return -1

*/


// CODE-

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int minutes = 0;
        vector<int> visited;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!q.empty() && fresh>0){
            int len = q.size();
            minutes++;
            for(int i=0 ; i<len ; i++){
                auto cell = q.front();
                q.pop();
                int x = cell.first;
                int y = cell.second;
                for(int d=0 ; d<4 ; d++){
                    int neighx = x + dx[d];
                    int neighy = y + dy[d];
                    if(neighx >= 0 && neighy >= 0 && neighx < n && neighy < m && grid[neighx][neighy] == 1){
                        grid[neighx][neighy] = 2;
                        q.push({neighx,neighy});
                        fresh--;
                    }
                }
            }

        }
        if(fresh == 0){
            return minutes;
        }
        return -1;
    }
};
