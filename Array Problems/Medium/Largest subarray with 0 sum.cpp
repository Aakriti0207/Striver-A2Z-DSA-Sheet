//Largest subarray with 0 sum

BRUTE FORCE - 2 loops

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            int sum = 0;
            for(int j=i ; j<n ; j++){
                sum += arr[j];
                if(sum == 0){
                    ans = max(ans , j-i+1);
                }
            }
        }
        return ans;
    }
};

TC => O(n^2) TLE

OPTIMAL APPROACH - Prefix Sum + HashMap
/*
  We maintain sum and hashmap - prefix sum -> first index
  Case 1
    If: sum == 0
    Then: Entire array till current index.
    Length: i+1
  Case 2
    If prefix sum seen before: sum exists in map
    Then: Length: i - previousIndex
  Case 3
    Not seen: Store first occurrence.
      Why first?
      Because: first occurrence gives maximum length 
*/

  class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        int sum = 0;
        int maxi = 0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
            if(sum == 0){
                maxi = i+1;
            }
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi , i-mpp[sum]);
            }else{
                mpp[sum] = i;
            }
        }
        return maxi;
    }
};

//TIME COMPLEXITY : O(n)
//SPACE COMPLEXITY : O(n)
