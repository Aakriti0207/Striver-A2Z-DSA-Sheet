//Next Greater Element II
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

//BRUTE FORCE APPROACH- 
  //We use Circular Array. We imagine doubling the array that is rewriting the entire array after the last element of original array
    //Index of this can be determined by- INDEX = i % N 
      // Then we check if this index' element is greater or not
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n , -1);  //Default ans-> -1 ke liye
        for(int i=0 ; i<n ; i++){
            for(int j = i+1 ; j<= i+n-1 ; j++){
                int ind = j % n;
                if(nums[ind] > nums[i]){
                    nge[i] = nums[ind];    //Rewriting on -1
                    break;
                }
            }
        }
        return nge;
    }
}; TC-> O(n^2) SC -> O(N)

//OPTIMAL APPROACH ->
  //Using Monotonic Stack- We double the array first and then create a stack and push elements in it. If any element is greater than st.top() pop till greater element in stack is achieved and push the current element
  class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack <int> st;
        vector<int> NGE(n , -1);
        for(int i=2*n-1 ; i>=0 ; i--){
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            if(i < n){
                if(!st.empty()){
                    NGE[i] = st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return NGE;
    }
};TC -> O(N) SC -> O(1)
