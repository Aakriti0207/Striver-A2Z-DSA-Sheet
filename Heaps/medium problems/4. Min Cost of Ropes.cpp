//Min Cost of Ropes
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 
//See examples for better understanding

  //Code
  class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        //Create a minHeap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0 ; i<n ; i++){
            pq.push(arr[i]);
        }
        int cost = 0;
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int sum = a + b;
            cost = cost + sum;
            pq.push(sum);
        }
        return cost;
    }
}; TC -> O(nlogn) SC -> O(n)
