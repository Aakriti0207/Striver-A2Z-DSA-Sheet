//543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

//Brute Force Approach-
  Imagine each point as a turning point-
  1. for each node calculate left height, right height and return diameter + 1(parent)
  2. Keep a track of maximum diameter achieved

//Code- 
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int leftH = height(root -> left);
        int rightH = height(root -> right);
        return 1+max(leftH , rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int DiaLeft = diameterOfBinaryTree(root->left);
        int DiaRight = diameterOfBinaryTree(root->right);
        int DiaRoot = height(root->left) + height(root->right);
        int first = max(DiaLeft , DiaRight);
        int ans = max(first , DiaRoot);
        return ans;
    }
}; //TC -> O(N^2) 

//Optimal Approach-
In order to reduce time complexity- use the bottom up approach (DFS) , finish on lower parts first and keep track of maximum diameter simultaneously

//CODE-
class Solution {
public:
    int dfs(TreeNode* root , int &maxi){
        if(root == NULL) return 0;
        int leftH = dfs(root -> left , maxi);
        int rightH = dfs(root -> right , maxi);
        maxi = max(maxi , leftH + rightH);
        int ans = 1 + max(leftH,rightH);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        dfs(root , maxi);
        return maxi;
    }
}; 
