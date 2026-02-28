// Subset sum equal to target-

/*
Given - Array of integers & a number "target"
Find - if there's any subset of array that generates target

IMPORTANT-> subset != subsequence
which is why we cannot use 2 loops

We use the "take-notTake" approach of recursion
*/

//Simple Recursion
class Solution {
private:
    bool recur(int index, int target, vector<int>& arr){

        if(target == 0) return true;

        if(index == 0)
            return arr[0] == target;

        bool notTake = recur(index-1, target, arr);

        bool take = false;
        if(arr[index] <= target)
            take = recur(index-1, target-arr[index], arr);

        return take || notTake;
    }

public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return recur(n-1, sum, arr);
    }
};


//Memoization

class Solution {
  private:
    bool memoi(int index, int target, vector<int>&arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(index == 0) return (arr[index] == target);
        if(dp[index][target] != -1) return dp[index][target];
        bool notTaken = memoi(index-1, target, arr, dp);
        bool taken = false;
        if(arr[index] <= target){
            taken = memoi(index-1, target-arr[index], arr, dp);
        }
        return dp[index][target] = notTaken || taken;
    }
  public:
    //Memoization
    bool isSubsetSum(vector<int>& arr, int sum) {
        //Create a 2-D DP
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return memoi(n-1,sum,arr,dp);
    }
};
//TC -> O(N*K) SC -> O(N*K) + O(N)

//Tabulation

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // Tabulation
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        //Base Cases- 
        //1. If target sum is 0
        for(int i=0 ; i<n ; i++){
            dp[i][0] = true;
        }
        //2. If index = 0
        if(arr[0] <= sum) dp[0][arr[0]] = true;  //Careful
        //Filling dp array-
        for(int index=1 ; index<n ; index++){
            for(int target = 1 ; target <= sum ; target++){
                bool notTaken = dp[index-1][target];
                bool taken = false;
                if(arr[index] <= target){
                    taken = dp[index-1][target-arr[index]];
                }
                dp[index][target] = (taken || notTaken); // BRACKETS ARE IMPORTANT
            }
        }
        return dp[n-1][sum];
    }
};
//TC -> O(N*K) SC -> O(N*K)


//Space Optimisation
/* 
We observe 
dp[index][target] = taken || not taken 
                  = dp[ind-1][target] || dp[ind-1][target-arr[i]]
We just need to store the previous row & the curr row
*/

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1,false);
        //If target is 0
        prev[0] = true;
        //For zeroth index-
        if(arr[0] <= sum) prev[arr[0]] = true;
        for(int ind = 1; ind<n ; ind++){
            vector<bool> curr(sum+1, false);
            curr[0] = true;
            for(int target = 1 ; target<=sum ; target++){
                bool notTaken = prev[target];
                bool taken = false;
                if(arr[ind] <= target){
                    taken = prev[target-arr[ind]];
                }
                curr[target] = (taken || notTaken);
            }
            prev = curr;
        }
        return prev[sum];
    }
};
//TC -> O(N*K) SC -> O(K)
