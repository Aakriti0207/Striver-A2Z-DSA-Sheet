//LC 547- 
/*Understanding the problem-
In a graph- connected or disconnected, provinces refer to the entirely connected graph. 
For example- if a graph is broken into 4 parts- 4 provinces
           - single graph - 1 province
*/

/*
Approach-
1. Start a BFS/DFS traversal. 
2. Check for all connected components while traversing
3. Everytime we encounter a new unvisited node- start of another province. 
        thus, count++
4. Return Count.
*/

//Code-

class Solution {
private: 
    void bfs(int start , vector<vector<int>>& isConnected , vector<int>& visited){
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j = 0 ; j < isConnected.size() ; j++){
                if(!visited[j] && isConnected[node][j] == 1){
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }
    }
    //DFS Version
    void dfs(int start , vector<vector<int>>& isConnected , vector<int>& visited){
        visited[start] = 1;
        for(int j = 0 ; j < isConnected.size() ; j++){
            if(!visited[j] && isConnected[start][j] == 1){
                dfs(j , isConnected , visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> visited(n , 0);
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                bfs/dfs(i , isConnected , visited);
                count++;
            }
        }
        return count;
    }
};