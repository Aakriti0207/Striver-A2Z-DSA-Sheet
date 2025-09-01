//Next Greater Element I
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

//Brute Force- Nested Loops approach
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        for(int i=0 ; i<n1 ; i++){
            int nextGreater = -1;
            for(int j=0 ; j<n2 ; j++){
                if(nums2[j] == nums1[i]){
                    for(int k=j+1 ; k<n2 ; k++){
                        if(nums2[k] > nums2[j]){
                            nextGreater = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};