Given an array arr[], where each element is at most k positions away from its correct position in the sorted order.
Your task is to restore the sorted order of arr[] by rearranging the elements in place.

//Brute Force Approach-
Just sort the array
//Optimal Approach
we use a min heap 
1. Create a min heap and push all elements
2. When size of heap is > k pop the top element and push it into the given array
//Code
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int , vector<int> , greater<int>>pq;
        int index = 0;
        for(int i=0 ; i<arr.size() ; i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                int temp = pq.top();
                pq.pop();
                arr[index] = temp;
                index++;
            }
        }
        while(!pq.empty()){
            arr[index] = pq.top();
            pq.pop();
            index++;
        }
    }
}; TC -> O(NlogK) //Push and pop operations takes log k time
   SC -> O(k)
