//75. Sort Colors
/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
*/

//BRUTE FORCE - Sorting 
// TIME COMPLEXITY - O(NlogN) SPACE COMPLEXITY - O(1)

//BETTER APPROACH -
keep count of values
//CODE-
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0 , count1 = 0, count2 = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 0) count0++;
            if(nums[i] == 1) count1++;
            if(nums[i] == 2) count2++;
        }
        for(int i=0 ; i<count0 ; i++){
            nums[i] = 0;
        }
        for(int i=count0 ; i<count0+count1 ; i++){
            nums[i] = 1;
        }
        for(int i=count0+count1 ; i<n ; i++){
            nums[i] = 2;
        }
    }
};
//TIME COMPLEXITY - O(N) + O(N) -> traversing entire array twice

//OPTIMAL APPROACH-
We try to solve the entire problem in a single pass, we use 3 pointers low,mid and high - low and mid initialised to 0 and high initialied to n-1
  If we encouter '2' we'll swap it with high and high--
  If we encounter '1' we'll swap it with mid and mid++
  else if its zero - swap it with low

This is called DUTCH NATIONAL FLAG ALGORITHM

//CODE-
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        //Dutch Sort Algorithm
        int low = 0 , mid = 0 , high = n-1;
        while(mid < high){
            for(int i=0 ; i<n ; i++){
                if(nums[mid]==0){
                    swap(nums[mid] , nums[low]);
                    mid++;
                    low++;
                }else if(nums[mid]==1){
                    mid++;
                }else{
                    swap(nums[mid] , nums[high]);
                    high--;
                }
            }
        }
    }
};

//TIME COMPLEXITY - O(n) SPACE COMPLEXITY - O(1) -> MOST OPTIMAL
