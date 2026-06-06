//493. Reverse Pairs

BRUTE FORCE-
  2 loops

class Solution {
    //Brute Force
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0 ; i<n ;i++){
            for(int j=i+1 ; j<n ; j++){
                if(nums[i] > 2*nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};

//TIME COMPLEXITY : O(n^2) TLE

OPTIMAL APPROACH : MERGE SORT
  /*
    Main Trick
      For every left element: Move right pointer
      While - arr[i] > 2LL * arr[right] increase: right++
      Then: Count: right - (mid+1)
  */

  class Solution {
public:
    //OPTIMAL SOLUTION : MERGE SORT
    void merge(vector<int>& nums,int low,int mid,int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high;i++) {
            nums[i] =
            temp[i-low];
        }
    }

    int countPairs(
        vector<int>& nums,
        int low,
        int mid,
        int high) {

        int right =
        mid + 1;

        int count = 0;

        for(int i = low;
            i <= mid;
            i++) {

            while(right <= high &&
                  nums[i] >
                  2LL *
                  nums[right]) {

                right++;
            }

            count +=
            (right -
            (mid + 1));
        }

        return count;
    }

    int mergeSort(
        vector<int>& nums,
        int low,
        int high) {

        if(low >= high)
            return 0;

        int mid =
        (low + high) / 2;

        int count = 0;

        count +=
        mergeSort(
            nums,
            low,
            mid
        );

        count +=
        mergeSort(
            nums,
            mid+1,
            high
        );

        count +=
        countPairs(
            nums,
            low,
            mid,
            high
        );

        merge(
            nums,
            low,
            mid,
            high
        );

        return count;
    }

    int reversePairs(
        vector<int>& nums) {

        return mergeSort(
            nums,
            0,
            nums.size()-1
        );
    }
};
