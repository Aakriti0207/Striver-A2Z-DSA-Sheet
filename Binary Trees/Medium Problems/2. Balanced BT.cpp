//110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced- A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

//Brute Force Approach-
  -> Here we check every Node, store its hieght and check if height of left and height of right differs more than one
  -> If this condition holds, recursively call the isBalanced function on the left and right child nodes
  -> If both subtrees are balanced and the current node also satisfies the height condition, return true.
//Code

class Solution {
public:
    //Balanced BT -> when the difference between left and right nodes is NOT more than one
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        int leftH = getHeight(root -> left);
        int rightH = getHeight(root -> right);
        return 1 + max(leftH , rightH);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int leftH = getHeight(root -> left);
        int rightH = getHeight(root -> right);
        if(abs(rightH - leftH) <= 1 && isBalanced(root -> left) && isBalanced(root -> right)){
            return true;
        }
        return false;
    }
}; TC -> O(n^2) we traverse all nodes twice 

//Optimal Approach-
  -> simultaneously check the balance condition while traversing in BOTTOM-UP manner

//Code
class Solution {
public:
    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;
        int leftH = dfsHeight(root -> left);
        if(leftH == -1) return -1;
        int rightH = dfsHeight(root -> right);
        if(rightH == -1) return -1;
        if(abs(leftH - rightH) > 1) return -1;
        return 1 + max(leftH , rightH);
    }
    bool isBalanced(TreeNode* root) {
        if(dfsHeight(root) != -1){
            return true;
        }
        return false;
    }
};TC -> O(N)

//Space Complexity will remain same for both the methods-
  SC -> O(H)
    H will be logN for balanced tree and N for skewed tree(worse case)
