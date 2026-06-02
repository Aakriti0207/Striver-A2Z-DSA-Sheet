//53. Maximum Subarray

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

//BRUTE FORCE-
//2 pointer approach - intialize i and j, calculate sum of arr[i] and arr[j] 

//CODE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int maxi = INT_MIN;
        for(int i=0 ; i<n ; i++){
            int sum = 0;
            for(int j=i ; j<n ; j++){
                sum += nums[j];
                maxi = max(maxi , sum);
            }
        }
        return maxi;
    }
};

//TIME COMPLEXITY - O(N^2) SPACE COMPLEXITY - O(1)

We need to optimise time - N^2 is not feasible
to do so we try to calculate sum off all elements in a single pass-
  this leads us to - KADANE's ALGORITHM

//KADANE's ALGORITHM
  Intuition is to not consider subarray as a part of answer if its sum is less than 0, since it will ALWAYS reduce our answer


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LONG_MIN;
        long long sum = 0;
        for(int i=0 ; i<nums.size() ; i++){
            sum = sum + nums[i];
            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};
//TIME COMPLEXITY - O(N) SPACE COMPLEXITY - O(1) - most optimal

FOLLOW UP QUESTION-
  What if there are more than one subarray with max sum - we need to print any of them

//Intuition-
  Store starting index and ending index, thus we can easily get the subarray
Starting index is always at index where sum = 0 and ending always crosses previous max sum - maxi rest solution remains same as Kadane

//CODE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LONG_MIN;
        long long sum = 0;
        int start = 0 , ansStart=0 , ansEnd = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(sum == 0) start = i;
            sum = sum + nums[i];
            if(sum > maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum < 0){
                sum = 0;
            }

        }
        return maxi;
    }
};
