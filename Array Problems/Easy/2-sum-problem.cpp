// Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        for(int i=0 ; i<n ; i++){
            for (int j=i+1 ; j<n ; j++){
                if (nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
        
    }
};

//Better Approach- HashMaps
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int left_over = target - nums[i];

            if (mpp.find(left_over) != mpp.end()) {
                return {mpp[left_over], i};
            }

            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }
};

//Optimal Approach
// 2 pointer- ONLY for SORTED arrays

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums[0],nums[n-1]);
        int left=0;
        int right=n-1;
        while(left < right){
            long long sum= nums[left] + nums[right];
            if(sum == target){
                return {left,right};
            }else if(sum < target) left++;
            else right--;
        }
        return{-1,-1};
    }
};

