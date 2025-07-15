class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n=nums.size();
       int low=0 , high=n-1;
        while(low<=high){
            int mid=(low+high)/2; 
            if(target == nums[mid]) return mid;
            else(target < nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};


//only applicable in sorted search space
// Time Complexity- O(logn)