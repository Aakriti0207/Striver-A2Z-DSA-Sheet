//18. 4Sum

BRUTE FORCE - 4 loops
  
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<4) return {};
        set<vector<int>> st;  //to avoid duplicates
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                for(int k=j+1 ; k<n ; k++){
                    for(int l=k+1 ; l<n ; l++){
                        long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                        if(sum == target){
                            vector<int> ele = {nums[i] , nums[j] , nums[k] , nums[l]};
                            sort(ele.begin() , ele.end());
                            st.insert(ele);
                        }
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end()); //conversion
    }
};
//Time: O(n⁴) Too much

Better Approach - Hashing
//Fix 2 numbers - i and j then find the other 2 k and l - bit like 2 sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin() , nums.end());
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                set<long long> hashset;
                for(int k=j+1 ; k<n ; k++){
                    long long sum = nums[i] + nums[j] + nums[k];
                    long long difference = (long long) target - sum;
                    if(hashset.find(difference) != hashset.end()){
                        vector<int> temp = {nums[i] , nums[j] , nums[k] , (int)difference};
                        sort(temp.begin() , temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>> (st.begin() , st.end());
    }
};

/*
  TIME COMPLEXITY: 
Outer loops: O(n^2) 
Inner traversal: O(n)
Hash lookup: O(log n)
Total ≈ O(n³)
*/

//SPACE COMPLEXITY : O(n)

OPTIMAL APPROACH - Sorting + Two Pointers

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        for(int i=0 ; i<n ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1 ; j<n ; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1;
                int right = n-1;
                while(left < right){
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        ans.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[right] == nums[right+1]){
                            right--;
                        }
                        while(left < right && nums[left] == nums[left-1]){
                            left++;
                        }
                    }else if(sum < target){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
  
