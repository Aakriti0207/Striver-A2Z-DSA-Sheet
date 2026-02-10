//198. House Robber

/* We can rob houses- each element of the array given states the money present in those houses
Contraint- We cannot rob 2 ADJACENT houses */


// We'll use the pick/ignore method here in recursion, since we need to find which element to take and which to not


Recursion: 

class Solution {
private:
    int findHouses(int index , vector<int>& nums){
        //Base Case- 
        if(index < 0) return 0;
        if(index == 0) return nums[index];
        if(index == 1) return max(nums[0] , nums[1]);
        //Recursive Call-
        int pick = nums[index] + findHouses(index-2,nums);
        int drop = findHouses(index-1,nums);
        return max(pick,drop);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //Recursion
        return findHouses(n-1,nums);
    }
};

// The branching here, leads to exponential time complexity
//TC : 2^n SC: O(n)


DP - Memoization:

class Solution {
    //Memoization
private:
    int findHouses(int index, vector<int>& nums, vector<int>& dp){
        if(dp[index] != -1) return dp[index];
        if(index == 0) return nums[index];
        if(index<0) return 0;
        if(index == 1) return max(nums[0],nums[1]);

        int pick = nums[index] + findHouses(index-2, nums, dp);
        int drop = findHouses(index-1, nums, dp);

        return dp[index] = max(pick,drop);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return findHouses(n-1,nums,dp);
    }
};
TC - O(N) SC - O(N) + O(N)

DP - Tabulation:
  
class Solution {
    //Tabulation
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        if(n == 1) return nums[0];
        dp[1] = max(nums[0] , nums[1]);

        for(int i=2 ; i<n ; i++){
            int pick = nums[i] + dp[i-2];
            int drop = dp[i-1];

            dp[i] = max(pick,drop);
        }
        return dp[n-1];
    }
};
TC- O(N) SC- O(N)


Space optimisation- 

class Solution {
    //Space Optimisation
        // We do not need the whole sum of privious houses, we just need end count and for end count, we need sum of previous 2
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for(int i=2 ; i<n ; i++){
            int pick = prev2 + nums[i];
            int drop = prev1;
            int curr = max(pick,drop);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

TC- O(N) SC- O(1)
