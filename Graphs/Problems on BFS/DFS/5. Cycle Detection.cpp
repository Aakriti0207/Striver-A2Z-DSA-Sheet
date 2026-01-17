//Cycle Detection in an Undirected Graph

//BFS

class Solution {
  private:
    bool bfs(int start , vector<vector<int>>& adj , vector<int>& visited){
        queue<pair<int,int>> q;
        q.push({start,-1});
        visited[start] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto neigh: adj[node]){
                if(!visited[neigh]){
                    q.push({neigh , node});
                    visited[neigh] = 1;
                }else if(visited[neigh] && neigh != parent){
                    return true;
                }
            }
        }
        return false;
    }
bool dfs(int start , int parent , vector<vector<int>>& adj , vector<int>& visited){
  //DFS me we don't use queue instead store parent seperately & check the condition.
        visited[start] = 1;
        for(auto neigh: adj[start]){
            if(!visited[neigh]){
                visited[neigh] = 1;
                if(dfs(neigh,start,adj,visited)){
                    return true;
                }
                visited[neigh] = 1;
            }else if(visited[neigh] && parent != neigh){
                return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        bool ans = false;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        //cycle detection using BFS-
            // If we visit a node which is already visited before & is not the parent- cycle
        // int n = adj.size();
        vector<int> visited(V,0);
        for(int i=0 ; i<V ; i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};


//DFS
