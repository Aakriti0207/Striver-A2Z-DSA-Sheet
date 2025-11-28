//104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

//Recursive Approach-
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftH = maxDepth(root -> left);
        int rightH = maxDepth(root -> right);
        return (1 + max(leftH , rightH));
    }
};
//Level Order Traversal-
class Solution {
public:
//Level Order Traversal-
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.size() != 0){
            int size = q.size();
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node -> left);
                }
                if(node->right){
                    q.push(node -> right);
                }
            }
            level++;
        }
        return level;
    }
};
