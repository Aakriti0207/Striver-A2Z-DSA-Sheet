//26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0 ; i<n ; i++){
            if(ans.empty() || ans.back() != nums[i]){
                ans.push_back(nums[i]);
            }
        }
        for(int i=0 ; i<ans.size() ; i++){
            nums[i] = ans[i];
        }
        return ans.size();
    }
};