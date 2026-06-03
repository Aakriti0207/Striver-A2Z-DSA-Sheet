//88. Merge Sorted Array

// Given sorted nums1 and nums2 - we need to merge them together and modify num1 itself

//BRUTE FORCE
//create another array and entire all elements of num1 as well as num2 -> sort and copy back

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        for(int i=0 ; i<m ; i++){
            ans.push_back(nums1[i]);
        }
        for(int j=0 ; j<n ; j++){
            ans.push_back(nums2[j]);
        }
        sort(ans.begin(),ans.end());
        for(int i=0 ; i<m+n ; i++){
            nums1[i] = ans[i];
        }
    }
};

//TIME COMPLEXITY => O(2* N+M + (N+M)log(N+M))
//SPACE COMPLEXITY => O(N+M)

//BETTER APPROACH-
//Since arrays already sorted: Use two pointers, Create tempprary array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int left = 0 , right = 0;
        while(left < m && right < n){
            if(nums1[left] < nums2[right]){
                ans.push_back(nums1[left]);
                left++;
            }else{
                ans.push_back(nums2[right]);
                right++;
            }
        }
        //Adding leftover elements
        while(left < m){
            ans.push_back(nums1[left]);
            left++;
        }
        while(right < n){
            ans.push_back(nums2[right]);
            right++;
        }
        for(int i=0 ; i<m+n ; i++){
            nums1[i] = ans[i];
        }
    }
};
//TIME COMPLEXITY => O(m+n)
//SPACE COMPLEXITY => O(m+n)

//OPTIMAL APPROACH
/*
We use 3 pointers-
  i = m-1 (nums1 end) , j = n-1 (num2 end) , k = m+n-1(final insert position)
MAIN IDEA => Merge from end 
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        //remaining j
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
//TIME COMPLEXITY => O(m+n)
//SPACE COMPLEXITY => O(1)
