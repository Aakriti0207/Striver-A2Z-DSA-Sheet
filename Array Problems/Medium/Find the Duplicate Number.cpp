//287. Find the Duplicate Number

//BRUTE FORCE - 2 loops 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            int repeated = -1;
            for(int j = i+1 ; j<n ; j++){
                if(nums[j] == nums[i]){
                    repeated = nums[i];
                    return repeated;
                }
            }
        }
        return -1;
    }
};

//TIME COMPLEXITY -  O(n^2) it wouldn't accepted due to timeout.

//BETTER APPROACH -
//we can either count the frequecy using loop or use hash maps
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        for(auto [num,count] : freq){
            if(count > 1) return num;
        }
        return 0;
    }
};
//Time Complexity: O(n)
//Space Complexity: O(n)

//OPTIMAL APPROACH -
//We can also solve this question by the "TORTOISE AND HARE ALGORITHM" that we learnt in linkedlist
/*
We initialise slow and fast pointers - slow pointer moves 1 step fast moves 2 steps
If both of the pointers meet - we initialise fast pointer at first element again and iterate one step at a time, NOW when these pointers meet - that element is the repeted element

WHY THIS ALGO? - because duplicate numbers form a cycle - 2 indexes pointing on the same element
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (slow != fast);
        //phase 2
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
//TIME COMPLEXITY -> O(N) SPACE COMPLEXITY -> O(1)
