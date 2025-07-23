//Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

//THERE ARE MULTIPLE BRUTE FORCE SOLUTIONS TO SOLVE THIS PROBLEM-

//1. Hashing
//2. Linear Search and count
//3. XOR -> a^a=0 , a^0=a


//4. 
OBSERVATIONS->
    if it contains 1 single element then every element other than 1 should be equal to either the element before it or after it- if both the conditions are not true- we have our answer.
//CODE->
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0 ; i<n ; i++){
            if(i == 0){ //EDGE CASES 
                if(nums[i] != nums[i+1]) return nums[i];
            }else if(i == n-1){
                if(nums[i] != nums[i-1]) return nums[i];
            }else{
                if(nums[i] != nums[i+1] && nums[i] != nums[i-1]){
                    return nums[i];
                }
            }
            
        }
        return -1;
    }
};//TC -> O(N)


//OPTIMAL SOLUTION->
//BINARY SEARCH 
OBSERVATIONS->
      find mid - check if mid is our desired element- if not-
            we see that the left half of mid contains elements in order (even , odd) - if our index is in left half - ELIMINATE left half 
            if it is of the order (odd , even) our index is in right half - ELIMINATE right half- desired element is in left

//CODE->
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        //EDGE CASES->
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        int low = 1 , high = n-2;
        while(low <= high){
            int mid = low + (high-low)/2;
            //Check for mid
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            //If we are in left half
            if((mid % 2 == 1 /* odd index */ && nums[mid] == nums[mid-1]) /* equal to even index*/ || mid % 2 == 0 /*even index*/ && nums[mid] == nums[mid+1] /*equal to odd index*/ ){
                low = mid + 1; //Eliminate left half
            }else{
                high = mid - 1; //Eliminate right half
            }
        }
        return -1;
    }
};
