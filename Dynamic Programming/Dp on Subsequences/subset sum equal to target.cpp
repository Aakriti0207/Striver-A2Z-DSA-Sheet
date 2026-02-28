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
        if(index == 0) return(arr[index] == target);
        bool notTake = recur(index-1, target, arr);
        bool take = false;
        take = recur(index-1, target-arr[index], arr);
        return take || notTake;
    }
  public:
    //take or not take recursion
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return recur(n-1,sum,arr);
        
    }
};