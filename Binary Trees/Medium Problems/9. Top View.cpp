//Top View of Binary Tree
You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 

//Approach-
  -> Similar like previous problem-> just we don't need to store levels here

//CODE-
  class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<Node* , int>> q;
        map<int,int> mpp;
        q.push({root , 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* temp = p.first;
            int line = p.second;
            if(mpp.find(line) == mpp.end()){
                mpp[line] = temp -> data;
            }
            if(temp -> left) q.push({temp->left , line-1});
            if(temp -> right) q.push({temp->right , line+1});
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};


/* BFS traversal	O(N)
Map insert/search	O(log N) per node
Overall time	O(N log N) */

//SC -> O(N)
