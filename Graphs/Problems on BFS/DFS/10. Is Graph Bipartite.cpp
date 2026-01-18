//785. Is Graph Bipartite?

/*
Bipartite means- all the nodes of graph is colored alternatively
If 2 adjacent nodes have the same color- NOT bipartite

Approach-
   Instead of visited array- keep a color array and initialise it to -1. We'll reinitialise it to 0 & 1- 2 alternative colors
      Why 0 & 1 - coz both the nos. conviniently satisfies the formula-> 1-color[parent/prev]
*/

//CODE
class Solution {
private:
    bool bfs(int i, vector<vector<int>>& graph, vector<int>& color, int n){
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neighbour : graph[node]){
                if(color[neighbour] == -1){
                    color[neighbour] = 1-color[node];
                    q.push(neighbour);
                }else if(color[neighbour] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0 ; i<n ; i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!bfs(i,graph,color,n)){
                    return false;
                }
            }
        }
        return true;
    }
};
