//2685. Count the Number of Complete Components

/* 
Given- 'N' vertices of an undirected graph.
        array of edges
*/

//Complete: When there exists an edge between every pair of vertices

/*
Approach-
  1. Transform the array of edges into an adjacent list
  2. Create "visited" vector & initialise count variable
  3. Traverse the graph through bfs/dfs
  4. While traversing keep a track of nodes & edges
      - Main Idea:
            if edges == nodes*(nodes-1)/2
                  - then it is a complete graph
      NOTE- for an undirected graph: edges = EDGES/2
  5. If condition satisfied, increment counter and return count variable at the end.
  */


//Code
class Solution {
private:
    void bfs(int first, int n, vector<vector<int>>& adj, vector<int>& visited, int &nodes, int &edges){
        queue<int> q;
        q.push(first);
        visited[first] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodes++;
            for(auto neighbour : adj[node]){
                edges++;
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n , 0);
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                int nodes = 0 , edges = 0;
                bfs(i , n , adj , visited , nodes , edges);
                edges /= 2; //undirected
                if(edges == nodes*(nodes-1)/2){
                    count++;
                }
            }
        }
        return count;
    }
};
