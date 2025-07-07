//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

//BRUTE- 2 loops
for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
        if (nums[i] == nums[j])
            return true;
    }
}
return false;
//TC- O(n^2) 

//BETTER- Maps
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;
        }
        for(auto i:mpp){
            if(i.second >= 2){
                return true;
            }
        }
        return false;
    }
};
//TC- O(n)

//OPTIMAL- Sorting
sort(nums.begin(), nums.end());
for (int i = 0; i < nums.size()-1; i++) {
    if (nums[i] == nums[i+1])
        return true;
}
return false;
//TC- O(nlogn)
