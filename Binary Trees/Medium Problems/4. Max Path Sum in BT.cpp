//124. Binary Tree Maximum Path Sum
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

//Approach
  1. Traverse each node as turning point
  2. Check maxPathLeft as well as maxPathRight
      -> maxPathLeft = max(0 , maxPathLeft(root->left,maxi)) similarly for right
                          why 0? In order to ignore negative values of node
  3. Keep a track of maximum path calculated 
  4. Return the max possible path from left to right- since it can't be both while considering upper node

//CODE-
  class Solution {
public:
    int dfs(TreeNode* root , int& maxi){
        if(root == NULL) return 0;
        int leftH = max(0 , dfs(root->left , maxi));
        int rightH = max(0 , dfs(root->right , maxi));
        maxi = max(maxi , root->val + leftH + rightH);
        return root -> val + max(leftH , rightH);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;      //Positively use maxi as INT_MIN to avoid edge case which contains all negative values of elements
        dfs(root , maxi);
        return maxi;
    }
};
