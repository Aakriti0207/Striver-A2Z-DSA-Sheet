//Merge kth sorted arrays-
You are given a 2D matrix mat[][] of size n x m. Each row in the matrix is sorted in non-decreasing order. Your task is to merge all the rows and return a single sorted array that contains all the elements of the matrix.
  //Brute Force-
  -> make another array and add all the elements in it then sort
//Code-
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        vector<int> merged;
        for(auto a : mat){
            for(auto x : a){
                merged.push_back(x);
            }
        }
        sort(merged.begin() , merged.end());
        return merged;
        
    }
}; TC -> O(N*K (log N*K)) SC -> O(N*K)

  //Better Approach-
  ->  merge 2 arrays at once, keep on merging one by one in a single array 
//Code
class Solution {
  public:
    vector<int> merge2arrays(vector<int> &a , vector<int> &b){
        vector<int> merged;
        int i=0 , j=0;
        while(i<a.size() && j<b.size()){
            if(a[i] < b[j]){
                merged.push_back(a[i]);
                i++;
            }else{
                merged.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()){
            merged.push_back(a[i]);
            i++;
        }
        while(j<b.size()){
            merged.push_back(b[j]);
            j++;
        }
        return merged;
    }
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        vector<int> ans = mat[0];
        for(int i=1 ; i<mat.size() ; i++){
            ans = merge2arrays(mat[i] , ans);
        }
        return ans;
    }
};TC -> O(N*K) to O(N*K^2) SC -> O(N*K)

//Optimal Approach-
  //Form a min heap of size k, where each element represents - {value, array_index , element_index}
1. Push the first element of all the arrays into heap
2. Pop the smallest element and add it to ans
3. Push the next element in heap(if any)
4. Repeat till heap is empty
//Code-

#include<queue>
class Node {
public:
    int data;
    int arrayIndex;
    int eleIndex;
    Node(int data , int i , int j){
        this -> data = data;
        arrayIndex = i;
        eleIndex = j;
    }
};

class compare{
    public:
    bool operator()(Node* a , Node* b){
        return (a->data > b->data);
    }
};

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Create a minHeap in Node Format
        priority_queue<Node* , vector<Node*> , compare>pq;
        int k = mat.size();
        for(int i=0 ; i<k ; i++){
            Node* temp = new Node(mat[i][0] , i , 0);
            pq.push(temp);
        }
        vector<int> ans;
        while(pq.size() > 0){
            Node* tem = pq.top();
            pq.pop();
            ans.push_back(tem -> data);
            int i = tem -> arrayIndex;
            int j = tem -> eleIndex;
            if(j+1 < mat[i].size()){
                Node* next = new Node(mat[i][j+1] , i , j+1);
                pq.push(next);
            }
        }
        return ans;
    } TC-> O(N*K logK) SC -> O(k)
