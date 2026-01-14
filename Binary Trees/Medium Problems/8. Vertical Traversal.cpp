//987. Vertical Order Traversal of a Binary Tree
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

//Approach-
  1. In order to solve this problem we need to assign each node with values of x-axis and y-axis
  2.root will be assigned (0,0) for its left child we reduce the x-axis and for right child we increment x-axis
  3. we create a map data structure based on vertical and level info of each node-
      map<int,map<int,multiset<int>>> -> outer map for x-axis, inner map for y-axis and multiset in order to store sorted nodes automatically
  4. Initialise a queue which will store the node value and its co-ordinates
      queue<pair<int,pair<int,int>>>
  5. add nodes in queue first then traverse and add the node in map then add the left and right children of the node in queue
  6. when all node values are added in map DS create a final vector list and store all the nodes in it
  7. Return the final vector

//CODE-
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode* ,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> nodes;
        q.push({root , {0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(temp -> val);
            if(temp -> left){
                q.push({temp->left , {x-1 , y+1}});
            }
            if(temp -> right){
                q.push({temp->right , {x+1 , y+1}});
            }
        }
        for(auto p : nodes){
            vector<int>col;
            for(auto q : p.second){
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
}; 

Time Complexity->
1. Insertion in Multiset - O(logM)
2. Insertion in Maps - O(logK)
3. BFS - O(n)
overall- O(NlogN) worst case

Space Complexity->
O(N)
