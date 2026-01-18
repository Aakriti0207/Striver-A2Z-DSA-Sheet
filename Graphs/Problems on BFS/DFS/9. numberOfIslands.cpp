//200. Number of Islands

class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid,vector<vector<int>>& visited, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == '0' || visited[i][j] == 1){
            return;
        }
        visited[i][j] = 1;
        int dx[8] = {0,0,1,-1};
        int dy[8] = {1,-1,0,0};
        for(int d=0 ; d<8 ; d++){
            int nx = i + dx[d];
            int ny = j + dy[d];
            dfs(nx,ny,grid,visited,n,m);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    dfs(i,j,grid,visited,n,m);
                }
            }
        }
        return count;
    }
};
