//542. 01 Matrix

/*
Given- n*m binary matrix
Return- distance from nearest zero
        distance: min steps across all four directions
JUST like we always traverse matrix from rotten oranges in prev problem, here we traverse from zero
*/

/*
Approach-
  1. Create a queue for BFS
  2. Create a dist matrix to store all distances and initialise it to -1
  3. Traverse the matrix & push zeros into the queue & update distance of 0 to 0
  4. loop & check all 4 directions of the indexes inserted in queue
  5. Condition- if any element exits with dist[nx][ny] == -1 i.e. value 1
              - push this into queue & dist[nx][ny] = dist[x][y] + 1
  6. Return dist matrix
*/


//CODE
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n , vector<int>(m,-1));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!q.empty()){
            auto cell = q.front();
            int x = cell.first;
            int y = cell.second;
            q.pop();
            for(int d=0 ; d<4 ; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx>=0 && ny>=0 && nx<n && ny<m && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        return dist;
    }
};
