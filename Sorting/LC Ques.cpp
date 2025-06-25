//Given an integer array nums and an integer k, return the kth largest element in the array.

//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//QuickSort

class Solution {
public:
    int partition(vector<int>& nums, int low , int high){
        int pivot=nums[low];
        int i=low;
        int j=high;
        while(i<j){
            while(nums[i] <= pivot && i<=high-1){
                i++;
            }
            while(nums[j] >= pivot && j>=low+1){
                j--;
            }
            if(i<j) swap(nums[i] , nums[j]);
        }
        swap(nums[low] , nums[j]);
        return j;
    }
    void quicksort(vector<int>nums, int low, int high){
        if(low >= high) return;
        while(low<high){
            int pIndex=partition(nums,low,high);
            quicksort(nums,low,pIndex-1);
            quicksort(nums,pIndex+1,high);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        quicksort(nums , low , high);
        return nums[n-k];
    }
};

//The ques says to solve it without sorting but I have for practice...