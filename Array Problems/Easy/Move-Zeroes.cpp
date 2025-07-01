//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

//Note that you must do this in-place without making a copy of the array.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp; //New array for non-zero numbers
        for(int i=0 ; i<n ; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }
        int nz=temp.size(); 
        for(int i=0 ; i<nz ; i++){
            nums[i] = temp[i]; //replacing original array with non-zero numbers
        }
        for(int i=nz ; i<n ; i++){ //adding zeroes to leftover places in original array
            nums[i] = 0;
        }
    }
};
