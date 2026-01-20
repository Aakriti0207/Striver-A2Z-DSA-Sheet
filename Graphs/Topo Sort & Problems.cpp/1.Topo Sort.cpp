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


//Method2 -> BFS + Indegree + Queue -> Kahn's Algorithm

/*
Approach-
 1. Calculate indegree of graph ie the number of nodes with incoming edges towards the curr node
 2. Create a queue & start pushing the nodes with indegree = 0
 3. Traverse the queue & reduce the indegree of its neighbours by 1.
 4. If indegree of any neighbour after reduction becomes 0-> push it into the queue
 5. Repeat until queue is empty
*/

//CODE-
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //BFS-Kahn's Algorithm
        //We use queue & indegree here... 
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0 ; i<V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(int neigh : adj[top]){
                if(indegree[neigh]) indegree[neigh]--;
                if(!indegree[neigh]) q.push(neigh);
            }
        }
        return ans;
    }
};
