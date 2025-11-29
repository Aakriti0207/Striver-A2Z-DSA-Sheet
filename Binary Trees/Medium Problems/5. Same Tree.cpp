//100. Same Tree
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

//Approach-
use recursive method- check left subtree as well as right subtree
//Code
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right)){
            return true;
        }
        return false;
    }
}; TC -> O(N+M) SC -> O(1)
