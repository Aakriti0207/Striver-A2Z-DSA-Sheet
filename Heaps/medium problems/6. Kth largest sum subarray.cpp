//Kth largest sum subarray
Given an array arr[] of size n, find the sum of the K-th largest sum among all contiguous subarrays. In other words, identify the K-th largest sum from all possible subarrays and return it.
//Brute Force Approach
//Generate all subarrays-
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n=arr.size();
        vector<int>sums;
        for(int i=0 ; i<n ; i++){
            int sum = 0;
            for(int j=i ; j<n ; j++){
                sum += arr[j];
                sums.push_back(sum);
            }
        }
        sort(sums.begin() , sums.end());
        return sums[sums.size()-k];
    }
}; TC -> O(n^2logn) SC -> O(n^2)

  //Better Approach-
    //use min heap of size k, push sums into it and when it exceeds size pop the smallest element
      //top of the minheap- kth largest

  //code-
  class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i=0 ; i<n ; i++){
            int sum = 0;
            for(int j=i ; j<n ; j++){
                sum += arr[j];
                pq.push(sum);
                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
        
    }
}; TC -> O(n^2logk) SC-> O(K)

  
