//Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

//Brute Force Approach - Sorting
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        return nums[n-k];
    }
}; TC -> O(nlogn)


    //Better Approach-
    // Create a minHeap till the size k, after which pop until k-1 == 0, the top element will then be the kth Largest element

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int , vector<int> , greater<int>> minHeap;
        for(int i=0 ; i<n ; i++){
            minHeap.push(nums[i]);
            if(minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
}; TC -> O(NlogK) SC -> O(k)

    //Optimal Approach
        //QuickSelect
class Solution {
public:
    int partition(vector<int>& nums , int low , int high){
        int pivot = nums[high];
        int i = low;
        for(int j=low ; j<high ; j++){
            if(nums[j] <= pivot){
                swap(nums[i] , nums[j]);
                i++;
            }
        }
        swap(nums[i] , nums[high]);
        return i;
    }
    int quickSelect(vector<int>& nums , int k , int low , int high){
        int pos = partition(nums,low,high);
        int n=nums.size();
        if(pos == n-k) return nums[pos];
        else if(pos < n-k) return quickSelect(nums,k,pos+1,high);
        else return quickSelect(nums,k,low,pos-1);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,k,0,nums.size());
    }
}; TC-> O(n)/O(n^2) SC -> O(1)


