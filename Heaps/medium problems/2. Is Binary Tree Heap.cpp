//You are given the root of a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

//A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.

  //Code

/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeCount(Node* tree){
        if(tree == NULL){
            return 0;
        }
        int ans = 1 + nodeCount(tree->left) + nodeCount(tree->right);
        return ans;
    }
    bool isCBT(Node* root , int i , int NodeCount){
        if(root == NULL) return true;
        if(i >= NodeCount) return false;
        else{
            bool left = isCBT(root->left , (2*i+1) , NodeCount);
            bool right = isCBT(root->right , (2*i+2) , NodeCount);
            if(left && right) return true;
        }
        return false;
    }
    bool isMaxOrder(Node* root){
        //leafNode
        if (root->left == NULL && root -> right == NULL) return true;
        //only left child exists
        if(root -> right == NULL){
            bool left = isMaxOrder(root -> left);
            if(left && (root -> data >= root->left->data)) return true;
        //Both child exists
        }else{
            bool left = isMaxOrder(root -> left);
            bool right = isMaxOrder(root -> right);
            if(left && right && (root -> data >= root->left->data) && (root->data >= root->right->data)){
                return true;
            }
        }
        return false;
    }
    bool isHeap(Node* tree) {
        int index = 0;
        int totalCount = nodeCount(tree);
        return (isCBT(tree , index , totalCount) && isMaxOrder(tree));
    }
};
