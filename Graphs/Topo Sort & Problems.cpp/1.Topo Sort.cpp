//Topological Sort

/*
 Topo Sort -> Way to arrange the graph in a linear fashion. 
           -> Only for directed acyclic graphs[DAG]
           -> If a directed edge (u->v) u will always appear before v.
*/


// Method1 -> DFS (Stack Approach)

/*
    -> Start DFS traversal from 0 to V vertices, Traverse its neighbours- if not visited -> push into stack & mark as visited. After traversal, reverse the given stack.
*/

//CODE

class Solution {
  private:
    void dfs(int start, stack<int>& st, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[start] == 1) return;
        visited[start] = 1;
        for(int neigh : adj[start]){
            if(!visited[neigh]){
                dfs(neigh, st, adj, visited);
            }
        }
        st.push(start); // Push node AFTER all neighbours
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> visited(V,0);
        stack<int> st; 
        for(int i=0 ; i<V ; i++){
            if(!visited[i]){
                dfs(i, st, adj, visited);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            int front = st.top();
            st.pop();
            ans.push_back(front);
        }
        return ans;
    }
};
