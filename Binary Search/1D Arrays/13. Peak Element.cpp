//Find Peak Element
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.


//BRUTE FORCE
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        for(int i=1 ; i<n-1 ; i++){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                return i;
            }
        }
        return -1;
    }
};

//OPTIMAL->
observation-
    we know if the array is sorted or rotated the left half of peak element will be increasing and right half of peak element will be decreasing
        check left half- nums[i] > nums[i-1] -> eliminate left half- peak element will be in right
        check right half- nums[i] > nums[i+1] -> eliminate right half- peak element will be in left
        

//code
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        //EDGE CASES
        if(n==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low = 1 , high = n-2;
        while(low <= high){
            int mid = low + (high-low)/2;
            //check for mid
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }else if(nums[mid-1] < nums[mid]){ //left half
                low = mid + 1; //ELIMINATE LEFT HALF
            }else{   //NOT WRITING ANY CONDITION HERE WILL TAKE CARE OF ANOTHER EDGE CASE -> mid is the lowest element...
                high = mid-1; //ELIMINATE RIGHT HALF
            }
        }
        return -1;
    }
}; O(LogN)
