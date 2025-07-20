//Search in Rotated Sorted Array II

Only Difference -> CONTAINS DUPLICATES

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0 , high=n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            //If mid is the target
            if(nums[mid] == target) return true;
            //Edge case -> nums[mid] == nums[low] == nums[high]
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }
            if(nums[low] <= nums[mid]){ //Left part sorted  CORRECTION -> <=
                if(nums[low] <= target && target < nums[mid]){  //target is present
                    high = mid - 1;
                }else{
                    //target is absent
                    low = mid+1;
                }
            }else{  //right part sorted
                if(nums[mid] < target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};

//BEST AND AVERAGE CASE -> O(logn)
//WORSE CASE -> O(n) When it contains duplicates
