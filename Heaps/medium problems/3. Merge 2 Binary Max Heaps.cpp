 //Just merge the arrays and then heapify them-

class Solution {
  public:
    void swap(int &x , int &y){
        int temp = x;
        x=y;
        y=temp;
    }
    void heapify(vector<int> &ans , int i ){
        int len = ans.size();
        int largest = i;
        int leftChild = 2*i+1 , rightChild = 2*i+2;
        if(leftChild < len && ans[leftChild] >= ans[largest]){
            largest = leftChild;
        }
        if(rightChild < len && ans[rightChild] >= ans[largest]){
            largest = rightChild;
        }
        if(largest != i){
            swap(ans[i] , ans[largest]);
            heapify(ans , largest);
        }
        
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            ans.push_back(a[i]);
        }
        for(int j=0 ; j<m ; j++){
            ans.push_back(b[j]);
        }
        for(int i=(n+m)/2 - 1 ; i>=0 ; i--){
            heapify(ans , i);
        }
        return ans;
    }
}; TC-> O(n+m) SC-> O(n+m)
