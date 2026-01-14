//103. Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Approach-
  1. Make a queue and insert elements in it level by level
  2. create a flag LeftToRight with bool variable and switch it alternatively
  3. When LeftToRight is true enter the queue elements in vector list- Level, when false, enter the element in list on size-1-ith index
  4. Insert the children of current nodes into the queue and continue the process till queue is empty
  5. Insert each level into an ans list- vector of vectors
  6. Return ans

//Code-
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        bool LeftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i=0 ; i<size ; i++){
                TreeNode* temp = q.front();
                q.pop();
                int index = LeftToRight ? i : size-1-i;
                level[index] = temp->val;
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            LeftToRight = !LeftToRight;
            ans.push_back(level);
        }
        return ans;
    }
}; TC -> O(N) SC -> O(N)
