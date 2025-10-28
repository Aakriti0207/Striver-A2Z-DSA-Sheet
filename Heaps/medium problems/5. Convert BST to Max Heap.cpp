//BST to max heap
Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

  //Code
  // User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
    void inorder(Node* root , vector<int> &arr){
        if(!root) return;
        inorder(root->left , arr);
        arr.push_back(root -> data);
        inorder(root->right , arr);
    }
    void postorder(Node* root , vector<int> &arr , int &index){
        if(!root) return;
        postorder(root->left , arr , index);
        postorder(root->right , arr , index);
        root->data = arr[index++];
    }
    void convertToMaxHeapUtil(Node* root) {
        //Use post order for max-heap
        vector<int>arr;
        inorder(root,arr);
        int index = 0;
        postorder(root,arr,index);
    }
}; TC -> O(n) SC-> O(n)
