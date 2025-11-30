//Tree Boundary Traversal
Given a root of a Binary Tree, return its boundary traversal in the following order:

->Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.

->Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.

->Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.

Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

//Approach-
  1. Initialise an empty array 
  2. Create helper functions to check if node is leaf, downwardLeft and Traversal Right
  3. Recursive Function for left-
      -> For each leaf node, add value to the array
      -> if another left exists call leftRecur again else right
  4. For right Boundary-
      -> Make another array and store all right boundaries into it
      -> add the reverse element to the ans array
  6. For leaf nodes-
      -> make a helper function to check if the node is a leaf node- 
          if it is add it in the ans array
      -> Check for left subtree leaf nodes as well as right subtree leaf nodes

//CODE-

class Solution {
  public:
    bool isLeaf(Node *root){
        if(root -> left == NULL && root -> right == NULL){
            return true;
        }
        return false;
    }
    void leftBoundary(Node *root , vector<int>& ans){
        Node* curr = root -> left;
        while(curr){
            if(!isLeaf(curr)) {
                ans.push_back(curr->data);
            }
            if(curr->left){
              curr = curr -> left;  
            } 
            else {
                curr = curr -> right;
            }
        }
    }
    void rightBoundary(Node* root , vector<int>& ans){
        vector<int> temp;
        Node* curr = root -> right;
        while(curr){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr -> right){
                curr = curr -> right;
            }else{
                curr = curr -> left;
            }
        }
        int size = temp.size();
        for(int i=size-1 ; i>=0 ; i--){
            ans.push_back(temp[i]);
        }
    }
    void leafNode(Node* root , vector<int>& ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
        }
        if(root -> left) leafNode(root -> left , ans);
        if(root -> right) leafNode(root -> right , ans);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        if(!isLeaf(root)){
            ans.push_back(root -> data);
        }
        leftBoundary(root,ans);
        leafNode(root,ans);
        rightBoundary(root,ans);
        return ans;
    }
}; TC -> O(N) SC -> O(N) /*Ans array*/  + O(H) /*Recur stacl*/
  //H- N for skewed and logN for Balanced Binary Tree
